#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


#include "display.h"
#include "ui_display.h"
//#include <QWebFrame>
#include<QLabel>
#include<QPixmap>
#include<QBitmap>
#include<QPainter>
#include<QMouseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QProcess>

extern QString file_date;

Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);


    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_display.png");
    setMask(QBitmap(mask.mask()));
    QPalette p;
    p.setBrush(QPalette::Window, QBrush(mask));
    setPalette(p);

    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_close_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_close_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_close_press.png);}");

    ui->pushButton_bf->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_play_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_play_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_play_press.png);}");
    ui->pushButton_zt->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pause_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pause_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pause_press.png);}");
    ui->pushButton_jias->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_foreward_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_foreward_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_foreward_press.png);}");
    ui->pushButton_jians->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_back_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_back_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_back_press.png);}");

    ui->pushButton_bf->hide();
    ui->pushButton_zt->hide();
    ui->pushButton_jias->hide();
    ui->pushButton_jians->hide();

    ui->label_16->hide();
    ui->lineEdit->hide();
    ui->label_17->hide();



    //QUrl url("file:///C:/share/src/OceanRS/build-OceanRS-Desktop_Qt_5_5_0_MSVC2013_64bit-Release/release/web/map.html");
    //ui->webView->setUrl(url);
    m_x1=m_y1=m_x2=m_y2=30;



    timer = new QTimer;
    speed = 500;
    label = NULL;
    iterator = NULL;
    connect(timer,SIGNAL(timeout()),this,SLOT(nextPicture()));





}

void Display::init(QStringList files)
{
    QString f;
    iterator = new QStringListIterator(files);
    label = ui->label_14;

    if(timer->isActive()) timer->stop();
    timer->start(speed);

    ui->pushButton_bf->show();
    ui->pushButton_zt->show();
    ui->pushButton_jias->show();
    ui->pushButton_jians->show();

    foreach(f,files)
        init(f);

}

void Display::init(QString file)
{
    // Read basic infomation from same name txt of picture.
    QString date = file_date;
    float x1=160;
    float y1=10;
    float x2=-120;
    float y2=40;
    float maxt=30,mint=10;
    QString data_src="HY-2";
    float resolution = 0.25;


    qDebug() << "==============" << file << "---------" << "C:/pic/HW";

    m_path = file.mid(0,file.lastIndexOf('/'));
    qDebug() << m_path;

    PIC_TYPE pt=HW;
    if (m_path=="C:/pic/HW"){
        pt = HW;
    }else if(m_path=="C:/pic/FC"){
        pt = FC;
    }else if(m_path=="C:/pic/HL"){
        pt = HL;
    }else if(m_path.contains("SWWYL")){
        pt = SWWYL;
        ui->label_16->show();
        ui->lineEdit->show();
        ui->label_17->show();
        if(m_path=="C:/pic/SWWYL_3d")        wyl_type = file.mid(file.lastIndexOf('/')+5,4);

    }else if(m_path=="C:/pic/WYC"){
        pt = WYC;
    }else if(m_path=="C:/pic/ZCDW"){
        pt = ZCDW;
    }else if(m_path=="C:/pic/HYFM"){
        pt = HYFM;

        date = "20130102";
        y1=3; y2=25; x1=105; x2=121;
    }



    init(date,x1,y1,x2,y2,maxt,mint,data_src,resolution,file,pt);


}

void Display::init(QString date,float x1,float y1,float x2,float y2,float maxt,float mint,QString data_src,float resolution, QString pic, PIC_TYPE pt)
{
     m_x1=x1; m_y1=y1; m_x2=x2; m_y2=y2;
     ui->label_2->setText(date);
     m_pt = pt;
     QString unit = "°";
     switch (pt) {
     case HW:
         unit = "°";
//         ui->label_5->setText(QString("\346\234\200\345\244\247\346\265\267\350\241\250\346\270\251\345\272\246\357\274\232"));
//         ui->label_7->setText(QString("\346\234\200\345\260\217\346\265\267\350\241\250\346\270\251\345\272\246\357\274\232"));
         ui->label_5->setText(QString::fromUtf8("最大海表温度："));
         ui->label_7->setText(QString::fromUtf8("最小海表温度："));

         break;
     case FC:
         unit = "m/s";
         ui->label_5->setText(QString::fromUtf8("最大风速："));
         ui->label_7->setText(QString::fromUtf8("最小风速："));
         break;
     case HL:
         unit = "m";
         ui->label_5->setText(QString::fromUtf8("最大浪高："));
         ui->label_7->setText(QString::fromUtf8("最小浪高："));
         break;
     case SWWYL:
         unit = "m";
         ui->label_5->setText(QString::fromUtf8("最大三维温盐流："));
         ui->label_7->setText(QString::fromUtf8("最小三维温盐流："));
         break;
     case HYFM:
         unit = "m";
         ui->label_5->setText(QString::fromUtf8("最大锋面："));
         ui->label_7->setText(QString::fromUtf8("最小锋面："));
         break;
     case WYC:
         unit = "m";
         ui->label_5->setText(QString::fromUtf8("最大温跃层："));
         ui->label_7->setText(QString::fromUtf8("最小温跃层："));
         break;
     case ZCDW:
         unit = "m";
         ui->label_5->setText(QString::fromUtf8("最大中尺度涡："));
         ui->label_7->setText(QString::fromUtf8("最小中尺度涡："));
         break;

     default:
         break;
     }


     QString lon_range = QString("%1° ~ %2°").arg(x1).arg(x2);
     QString lat_range = QString("%1° ~ %2°").arg(y1).arg(y2);
     ui->label_4->setText(lon_range);
     ui->label_6->setText(lat_range);
     ui->label_8->setText(QString("%1%2").arg(maxt).arg(unit));
     ui->label_9->setText(QString("%1%2").arg(mint).arg(unit));
     ui->label_11->setText(data_src);
     ui->label_12->setText(QString("%1°").arg(resolution));





     if(pic.endsWith("swf")){
         qDebug() << "************************";
         ui->axWidget->setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}"));
         ui->axWidget->dynamicCall("LoadMovie(long,string)",0,pic);
     }else{
         ui->axWidget->hide();
         QImage image(pic);
         QPixmap myPic = QPixmap::fromImage(image);
         QPixmap scaledPic(myPic.scaled(ui->label_14->width(),ui->label_14->height()));
         ui->label_14->setPixmap(scaledPic);
     }

     bool isCross = false;

     QString dt;
     if(x1>0 && x2<0){
         isCross = true;
        dt = ":/Images/images/sjdt2.jpg";
     }else{
        dt = ":/Images/images/sjdt.jpg";
     }
     QImage image2(dt);
     QPixmap myPic2 = QPixmap::fromImage(image2);
     QPixmap scaledPic2(myPic2.scaled(ui->label_18->width(),ui->label_18->height()));
     QPainter painter(&scaledPic2);
     painter.setPen(QPen(Qt::red, 3));
     // log lat 360 180 , pix 291 151
     int xs, ys, xl, yl;
     if(isCross){
         xs = (x1)/360*291;
         ys = (90-y1)/180*151;
         xl = (360+x2-x1)/360*291;
         yl = (y1-y2)/180*151;
         painter.drawRect(xs, ys, xl, yl);
     }
     else {
         xs = (x1+180)/360*291;
         ys = (90-y1)/180*151;
         xl = (x2-x1)/360*291;
         yl = (y1-y2)/180*151;
        painter.drawRect(xs, ys, xl, yl);
     }
     ui->label_18->setPixmap(scaledPic2);

}


Display::~Display()
{
    delete ui;
    disconnect(timer,SIGNAL(timeout()),this,SLOT(nextPicture()));

    delete label;
    delete iterator;
    delete timer;
}
/*
void Display::on_webView_loadFinished(bool arg1)
{
    QWebFrame *frame = ui->webView->page()->mainFrame();
    QString method = QString("addPolygon(%1, %2, %3, %4)").arg(m_x1).arg(m_y1).arg(m_x2).arg(m_y2);
//    QString method = QString("addPolygon()");

    frame->evaluateJavaScript(method);
}
*/

void Display::on_pushButton_clicked()
{
    close() ;
}

void  Display::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void Display::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}
void Display::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void Display::nextPicture()
{

    if(iterator->hasNext())
    {
        QImage image(iterator->next());
        QPixmap myPic = QPixmap::fromImage(image);
        QPixmap scaledPic(myPic.scaled(label->width(),label->height()));
        label->setPixmap(scaledPic);
    }else{
        iterator->toFront();
        QImage image(iterator->next());
        QPixmap myPic = QPixmap::fromImage(image);
        QPixmap scaledPic(myPic.scaled(label->width(),label->height()));
        label->setPixmap(scaledPic);
    }
}


bool Display::hasFiles(){
    if(iterator != NULL && label != NULL) return true;
    else return false;
}

void Display::on_pushButton_bf_clicked()
{
    if(hasFiles() && !timer->isActive()) timer->start();
}


void Display::on_pushButton_zt_clicked()
{
    if (hasFiles()&& timer->isActive())  timer->stop();
}

void Display::on_pushButton_jias_clicked()
{
    speed -= 100;
        if(speed<0) speed=0;
        if(hasFiles()&& timer->isActive()) {
            timer->stop();
            timer->start(speed);
        }
}

void Display::on_pushButton_jians_clicked()
{
    speed += 200;
       if(hasFiles()&& timer->isActive()) {
           timer->stop();
           timer->start(speed);
       }
}



//void Display::on_lineEdit_editingFinished()
//{
////    int depth = ui->lineEdit->text().toInt();
////    QString file;

////    file = m_path+QString("/%1.png").arg(depth);
////    qDebug() << file;

////    QImage image(file);
////    QPixmap myPic = QPixmap::fromImage(image);
////    QPixmap scaledPic(myPic.scaled(ui->label_14->width(),ui->label_14->height()));
////    ui->label_14->setPixmap(scaledPic);
////    qDebug() << "before show";
////    this->show();
////    qDebug() << "after show";
//}

void Display::on_lineEdit_returnPressed()
{

    QFile file_init("initial1.txt");
    QString path = QDir::currentPath();
    QTextStream fileOut(&file_init);

    QFile file_pic;


    QString file;
    int depth = ui->lineEdit->text().toInt();

    switch (depth) {
    case 0:

        break;
    case 10:

        break;
    case 20:

        break;
    case 50:


        break;
    default:
//        qDebug() << "Depth must be 0,10,20,50 meter!";
        QMessageBox::information(0,QStringLiteral("警告"),QStringLiteral("输入深度必须是 0,10,20,50 米!"),QMessageBox::Ok);
        return;
        break;

    }

    file = m_path+QString("/../SWWYL_2d/%1_%2_024.jpg").arg(wyl_type).arg(depth, 3, 10, QChar('0'));;

    file_pic.setFileName(file);
    if(!file_pic.exists()){
        QDir::setCurrent(path+"/yubao/wenyanliu/");
        // 写配置文件 initial1.txt
        file_init.open(QIODevice::WriteOnly);

        fileOut << depth << "\n";
        fileOut << file_date << "\n";
        file_init.close();

        QProcess::execute("wyl_2d.exe");

        QDir::setCurrent(path);
    }

    qDebug() << file;

    init(file);
//    QImage image(file);
//    QPixmap myPic = QPixmap::fromImage(image);
//    QPixmap scaledPic(myPic.scaled(ui->label_14->width(),ui->label_14->height()));
//    ui->label_14->setPixmap(scaledPic);

    ui->axWidget->hide();
    on_pushButton_zt_clicked();

}


