#include "forecast.h"
#include "ui_forecast.h"
#include<QPainter>
#include<QBitmap>
#include<QMouseEvent>
#include<QTimer>
#include<QDebug>
#include<QDir>
#include<QProcess>
#include<QFileDialog>
#include<QDesktopWidget>
#include "display.h"
#include "mainwindow.h"

extern MainWindow *mw;

Forecast::Forecast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forecast)
{
    ui->setupUi(this);

    //ÉèÖÃ´°Ìå
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_pre_min2.png");
    setMask(QBitmap(mask.mask()));
    QPalette p;
    p.setBrush(QPalette::Window, QBrush(mask));
    setPalette(p);
    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pre_3dstream_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pre_3dstream_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pre_3dstream_press.png);}");
    ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_return_normal2.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_return_hover2.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_return_press2.png);}");
    ui->pushButton_hyf->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pre_workocean_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pre_workocean_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pre_workocean_press.png);}");
    ui->pushButton_xw->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pre_workoral_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pre_workoral_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pre_workoral_press.png);}");
    ui->pushButton_yc->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pre_uplayer_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pre_uplayer_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pre_uplayer_press.png);}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_fix_result_normal2.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_fix_result_hover2.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_fix_result_press2.png);}");
//    ui->pushButton_bf->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_play_normal.png);}"
//                                   "QPushButton:hover{border-image: url(:/Images/images/pb_play_hover.png);}"
//                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_play_press.png);}");
//    ui->pushButton_zt->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_pause_normal.png);}"
//                                   "QPushButton:hover{border-image: url(:/Images/images/pb_pause_hover.png);}"
//                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_pause_press.png);}");
//    ui->pushButton_jias->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_foreward_normal.png);}"
//                                   "QPushButton:hover{border-image: url(:/Images/images/pb_foreward_hover.png);}"
//                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_foreward_press.png);}");
//    ui->pushButton_jians->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_back_normal.png);}"
//                                   "QPushButton:hover{border-image: url(:/Images/images/pb_back_hover.png);}"
//                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_back_press.png);}");

    timer = new QTimer;
    speed = 500;
    label = NULL;
    iterator = NULL;
    connect(timer,SIGNAL(timeout()),this,SLOT(nextPicture()));

    select_window=NULL;
}

Forecast::~Forecast()
{
    delete ui;
}
//void Forecast::paintEvent(QPaintEvent *e)
//{
//    QPainter painter(this);
//    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/Images/images/ui_fix.png"));
//}

void Forecast::on_pushButton_6_clicked()
{
    close() ;
}



void  Forecast::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void Forecast::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}
void Forecast::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void Forecast::nextPicture()
{

    if(iterator->hasNext())
    {

//        label->setPixmap(QPixmap(iterator->next()));
//        QMessageBox::warning(0,"PATH","111",QMessageBox::Yes);//鏌ョ湅璺緞
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

bool Forecast::displayImages(const QStringList sl, QLabel *lb)
{
//    // Method 1 : loop display image.
//    QString s;
////    while(true){
//    foreach(s, sl){
//        QMessageBox::warning(0,"PATH",s,QMessageBox::Yes);//鏌ョ湅璺緞
//        loadFile(s, lb);
//        QThread::usleep(100);
//    }
////    }

    // Method 2 : timer.

    iterator = new QStringListIterator(sl);
    label = lb;

    if(timer->isActive()) timer->stop();
    timer->start(speed);
    return true;
}

bool Forecast::loadFile(const QString &fileName, QLabel *lb)
{
    QImage image(fileName);
    if (image.isNull()) {
        //QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                // tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        qDebug()<<"Cannot load~~~";
        setWindowFilePath(QString());
        lb->setPixmap(QPixmap());
        lb->adjustSize();
        return false;
    }
//! [2] //! [3]
    QPixmap myPic = QPixmap::fromImage(image);
    QPixmap scaledPic(myPic.scaled(lb->width(),lb->height()));
    lb->setPixmap(scaledPic);
//! [3] //! [4]
//    scaleFactor = 1.0;

//    printAct->setEnabled(true);
//    fitToWindowAct->setEnabled(true);
//    updateActions();

//    if (!fitToWindowAct->isChecked())
    //ui->label_hw->adjustSize();

   // scrollArea->setWidgetResizable(true);
//    setWindowFilePath(fileName);
    return true;
}

bool Forecast::hasFiles(){
    if(iterator != NULL && label != NULL) return true;
    else return false;
}


bool Forecast::displayYuBao(const QStringList sl)
{
    //displayImages(sl, ui->label_yb);
    return true;
}

void Forecast::on_pushButton_2_clicked()
{
    // Open multi image.
   QString path;
   QDir dir;
   path=dir.currentPath();
   QStringList files = QFileDialog::getOpenFileNames(
                           this,
                           "Select one or more files to open",
                           path,
                           "Images (*.png *.png *.jpg *.bmp)");

   if(files.count()>0){
       files.sort();
       //displayYuBao(files);
         Display *fc = new Display();
         fc->init(files);
         QDesktopWidget* desktop = QApplication::desktop();
         int x,y;
         x=(desktop->width() - fc->width())/2;
         y=(desktop->height() - fc->height())/2-20;
         fc->setGeometry(x,y,fc->width(),fc->height());
         fc->setModal(true);
         fc->show();
       
         mw->m_display_windows_list.append(fc);
   }

}

void Forecast::on_pushButton_hyf_clicked()
{
//    QString path;
//    QDir dir;
//    path=dir.currentPath();
//    QDir::setCurrent(path+"\\yubao\\hyfm");

//    QProcess::startDetached("frontdetect_example.exe");
//    QDir::setCurrent(path);

    // Show file select Dialog.
    if(select_window!=NULL) {
        delete select_window;
    }
    select_window = new SelectFile();
    select_window->init(HYFM);

    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - select_window->width())/2;
    y=(desktop->height() - select_window->height())/2;
    select_window->setGeometry(x,y,1,429);
//    select_window->setModal(true) ;
    select_window->show();
}

void Forecast::on_pushButton_xw_clicked()
{
//    QString path;
//    QDir dir;
//    path=dir.currentPath();
//    QDir::setCurrent(path+"\\yubao\\zcdw");

//    QProcess::startDetached("runscript.exe");
//    QDir::setCurrent(path);

    // Show file select Dialog.
    if(select_window!=NULL) {
        delete select_window;
    }
    select_window = new SelectFile();
    select_window->init(ZCDW);

    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - select_window->width())/2;
    y=(desktop->height() - select_window->height())/2;
    select_window->setGeometry(x,y,1,429);
//    select_window->setModal(true);
    select_window->show();
}

void Forecast::on_pushButton_yc_clicked()
{
//    QString path;
//    QDir dir;
//    path=dir.currentPath();
//    QDir::setCurrent(path+"\\yubao\\wyc");

//    QProcess::execute("yueceng.exe");
//    QDir::setCurrent(path);

    // Show file select Dialog.
    if(select_window!=NULL) {
        delete select_window;
    }
    select_window = new SelectFile();
    select_window->init(WYC);

    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - select_window->width())/2;
    y=(desktop->height() - select_window->height())/2;
    select_window->setGeometry(x,y,1,429);
//    select_window->setModal(true);
    select_window->show();
}


void  Forecast::on_pushButton_bf_clicked()
{
    if(hasFiles() && !timer->isActive()) timer->start();
}


void  Forecast::on_pushButton_zt_clicked()
{
    if (hasFiles()&& timer->isActive())  timer->stop();
}

void  Forecast::on_pushButton_jias_clicked()
{
    speed -= 100;
        if(speed<0) speed=0;
        if(hasFiles()&& timer->isActive()) {
            timer->stop();
            timer->start(speed);
        }
}

void  Forecast::on_pushButton_jians_clicked()
{
    speed += 200;
       if(hasFiles()&& timer->isActive()) {
           timer->stop();
           timer->start(speed);
       }
}

void Forecast::on_pushButton_clicked()
{
    QString path;
    QDir dir;
    path=dir.currentPath();

     //Show file select Dialog.
    if(select_window!=NULL) {
        delete select_window;
    }
    select_window = new SelectFile();
    select_window->init(SWWYL);

    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - select_window->width())/2;
    y=(desktop->height() - select_window->height())/2;
    select_window->setGeometry(x,y,1,429);
//    select_window->setModal(true);
    select_window->show();

    // MPlayer 播放视频
//    QProcess::execute("C:\\MPlayer_Windows\\mplayer\\MPlayer.exe "+path+"\\yubao\\wenyanliu\\nwp_3dvar.mp4");
//    QProcess::execute("C:\\wmplayer\\wmplayer.exe "+path+"\\yubao\\wenyanliu\\nwp_3dvar.mp4");


}


void Forecast::stop_loading()
{
    if(select_window){
        select_window->stop_loading();
    }
}
