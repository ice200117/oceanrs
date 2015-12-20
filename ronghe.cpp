#include "ronghe.h"
#include "ui_ronghe.h"
#include <QDir>
#include <QProcess>
#include <QFileDialog>
#include<QBitmap>
#include<QMouseEvent>
#include <QImageReader>
#include <QByteArray>
#include <QStringList>
//#include <QtWidgets>
#include<QTimer>
#include<QMessageBox>
//#include <QtWidgets>
//#include <QtGui/QApplication>
#include<QApplication>
#include<QtDebug>
#include<QDesktopWidget>
#include<display.h>
#include<demo.h>

#include "mainwindow.h"

extern MainWindow *mw;

RongHe::RongHe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RongHe)
{
    ui->setupUi(this);
    //脡猫脰脙脭虏陆脟麓掳脤氓
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_fix_min3.png");//录脫脭脴脩脷脗毛脥录脧帽
    setMask(QBitmap(mask.mask())); //脡猫脰脙麓掳脤氓碌脛脩脷脗毛脥录脧帽,驴脵鲁媒脥录脧帽碌脛掳脳脡芦脟酶脫貌脢碌脧脰虏禄鹿忙脭貌麓掳脤氓
    QPalette p;//脡猫脰脙碌梅脡芦掳氓
    p.setBrush(QPalette::Window, QBrush(mask));//陆芦碌梅脡芦掳氓碌脛禄颅脣垄脡猫脰脙脦陋脩脷脗毛脦禄脥录,脭脷虏禄鹿忙脭貌麓掳脤氓脡脧脧脭脢戮鲁枚脩脷脗毛脦禄脥录
    setPalette(p);
    //QPainter painter(this);
    //painter.drawPixmap(0,0,width(),height(),QPixmap(":/Images/images/ui_fix.png"));

    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_fix_work_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_fix_work_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_fix_work_press.png);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_windwork_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_windwork_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_windwork_press.png);}");
//    ui->pushButton_8->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_wavework_normal.png);}"
//                                   "QPushButton:hover{border-image: url(:/Images/images/pb_wavework_hover.png);}"
//                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_wavework_press.png);}");
    //显示结果样式

    ui->pushButton_8->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_datatrans_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_datatrans_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_datatrans_press.png);}");
    ui->pushButton_9->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_fix_result_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_fix_result_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_fix_result_press.png);}");
    ui->pushButton_10->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_datamix_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_datamix_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_datamix_press.png);}");
    ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_return_normal2.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_return_hover2.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_return_press2.png);}");
    /*source button
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
    */

	timer = new QTimer;
    speed = 500;
    label = NULL;
    iterator = NULL;
    connect(timer,SIGNAL(timeout()),this,SLOT(nextPicture()));
}

RongHe::~RongHe()
{
    delete label;
    delete ui;
    disconnect(timer,SIGNAL(timeout()),this,SLOT(nextPicture()));
    delete iterator;
    delete timer;

}

void RongHe::on_pushButton_clicked()
{
    QString path;
        QDir dir;
        path=dir.currentPath();

    //    QStringList files = QFileDialog::getOpenFileNames(
    //                            this,
    //                            "Select one or more files to open",
    //                            "/home",
    //                            tr("All Files (*);;HDF5 Files (*.h5)"));


        QDir::setCurrent(path+"\\SST");

        QProcess::startDetached("InverseDistance.exe",QStringList());
        QDir::setCurrent(path);

        /*//测试Demo窗体，解注释即可查看效果
        Demo *demoDlg = new Demo() ;
        QDesktopWidget* desktop = QApplication::desktop();
        int x,y;
        x=(desktop->width() - demoDlg->width())/2;
        y=(desktop->height() - demoDlg->height())/2-20;
        demoDlg->setGeometry(x,y,1,429);
        demoDlg->setModal(true);
        demoDlg->show();
        */

}

void RongHe::on_pushButton_3_clicked()
{
        QString path;
        QDir dir;
        path=dir.currentPath();
        QDir::setCurrent(path+"\\rain");

        QProcess::execute("rain.exe");
        QDir::setCurrent(path);
}

void RongHe::on_pushButton_2_clicked()
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*);;bmpfile(*.bmp)"));
//    QPixmap pix(fileName);
//    ui->label_hw->setPixmap(pix);

    // Open single image.
//    QStringList mimeTypeFilters;
//    foreach (const QByteArray &mimeTypeName, QImageReader::supportedMimeTypes())
//        mimeTypeFilters.append(mimeTypeName);
//    mimeTypeFilters.sort();
//    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
//    QFileDialog dialog(this, tr("Open File"),
//                       picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.first());
//    dialog.setAcceptMode(QFileDialog::AcceptOpen);
//    dialog.setMimeTypeFilters(mimeTypeFilters);
//    dialog.selectMimeTypeFilter("image/jpeg");
//    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first(), ui->label_hw)) {}

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
        displayHaiwen(files);
    }else{
//         if(timer->isActive())  timer->stop();
    }
}
void RongHe::on_pushButton_6_clicked()
{
    close() ;
}

//**********露篓脪氓脢贸卤锚脥脧露炉脢脗录镁*********//

void  RongHe::mouseMoveEvent(QMouseEvent *event)//脢贸卤锚掳麓脧脗虏垄脪脝露炉脭貌脪脝露炉虏禄鹿忙脭貌麓掳脤氓
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void RongHe::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}

void RongHe::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}


bool RongHe::displayHaiwen(const QStringList sl)
{
    //displayImages(sl, ui->label_hw);
    return true;
}

//And the slot nextPicture is defined as:
void RongHe::nextPicture()
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

bool RongHe::displayImages(const QStringList sl, QLabel *lb)
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

bool RongHe::loadFile(const QString &fileName, QLabel *lb)
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

bool RongHe::hasFiles(){
    if(iterator != NULL && label != NULL) return true;
    else return false;
}

void RongHe::on_pushButton_bf_clicked()
{
    if(hasFiles() && !timer->isActive()) timer->start();
}


void RongHe::on_pushButton_zt_clicked()
{
    if (hasFiles()&& timer->isActive())  timer->stop();
}

void RongHe::on_pushButton_jias_clicked()
{
    speed -= 100;
        if(speed<0) speed=0;
        if(hasFiles()&& timer->isActive()) {
            timer->stop();
            timer->start(speed);
        }
}

void RongHe::on_pushButton_jians_clicked()
{
    speed += 200;
       if(hasFiles()&& timer->isActive()) {
           timer->stop();
           timer->start(speed);
       }
}


void RongHe::on_pushButton_5_clicked()
{
    QString path;
    QDir dir;
    path=dir.currentPath();
    QDir::setCurrent(path+"\\Merge3p\\testd\\swp\\MergeSWP");

    QProcess::execute("MergeSWP.exe");
    QDir::setCurrent(path);
}

void RongHe::on_pushButton_8_clicked()
{
    QString path;
    QDir dir;
    path=dir.currentPath();
    QDir::setCurrent(path+"\\Merge3p\\testd\\swh\\SWH");

    QProcess::execute("数据转换.exe");
    QDir::setCurrent(path);
}

void RongHe::on_pushButton_10_clicked()
{
    QString path;
    QDir dir;
    path=dir.currentPath();
    QDir::setCurrent(path+"\\Merge3p\\testd\\swh\\SWH");

    QProcess::execute("数据融合.exe");
    QDir::setCurrent(path);
}

bool RongHe::displayFeng(const QStringList sl)
{
    //displayImages(sl, ui->label_hw_2);
    return true;
}

void RongHe::on_pushButton_7_clicked()
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
       displayFeng(files);
   }
}

void RongHe::on_pushButton_bf_2_clicked()
{
    if(hasFiles() && !timer->isActive()) timer->start();
}


void RongHe::on_pushButton_zt_2_clicked()
{
    if (hasFiles()&& timer->isActive())  timer->stop();
}

void RongHe::on_pushButton_jias_2_clicked()
{
    speed -= 100;
        if(speed<0) speed=0;
        if(hasFiles()&& timer->isActive()) {
            timer->stop();
            timer->start(speed);
        }
}

void RongHe::on_pushButton_jians_2_clicked()
{
    speed += 200;
       if(hasFiles()&& timer->isActive()) {
           timer->stop();
           timer->start(speed);
       }
}

bool RongHe::displayHaiLang(const QStringList sl)
{
    //displayImages(sl, ui->label_hw_3);
    return true;
}

void RongHe::on_pushButton_9_clicked()
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
       //QMessageBox::warning(0,"PATH",f,QMessageBox::Yes);

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

void RongHe::on_pushButton_bf_3_clicked()
{
    if(hasFiles() && !timer->isActive()) timer->start();
}


void RongHe::on_pushButton_zt_3_clicked()
{
    if (hasFiles()&& timer->isActive())  timer->stop();
}

void RongHe::on_pushButton_jias_3_clicked()
{
    speed -= 100;
        if(speed<0) speed=0;
        if(hasFiles()&& timer->isActive()) {
            timer->stop();
            timer->start(speed);
        }
}

void RongHe::on_pushButton_jians_3_clicked()
{
    speed += 200;
       if(hasFiles()&& timer->isActive()) {
           timer->stop();
           timer->start(speed);
       }
}



