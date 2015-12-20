#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDir>
#include <QMessageBox>
#include <QStringList>
#include <QFileDialog>

#include<QBitmap>
#include<QMouseEvent>
#include<QDesktopWidget>

#include<QPainter>
#include<QPixmap>
#include "display.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //??????????
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_main3.png");//???????????
    setMask(QBitmap(mask.mask())); //????????????????,??????????????????????????
    QPalette p;//????????
    p.setBrush(QPalette::Window, QBrush(mask));//????????????????????λ?,??????????????????????λ?
    setPalette(p);

//    QPixmap pix1("ronghe.png");
//    QIcon icon1(pix1);
//    ui->pushButton->setIconSize((QSize(330,330)));
//    ui->pushButton->setIcon(icon1);

    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_fix_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_fix_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_fix_press.png);}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_3dsound_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_3dsound_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_3dsound_press.png);}");
    ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_preshow_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_preshow_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_preshow_press.png);}");
    ui->pushButton_4->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_min_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_min_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_min_press.png);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_close_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_close_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_close_press.png);}");
    ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_con_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_con_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_con_press.png);}");

//    QPixmap pix2("声场.png");
//    ui->label_s->setPixmap(pix2);

//    QPixmap pix3("预报系统.jpg");
//    ui->label_y->setPixmap(pix3);

    m_fsw = new QFileSystemWatcher;
    m_fsw->addPath("C:/pic/HW/");
    m_fsw->addPath("C:/pic/FC/");
    m_fsw->addPath("C:/pic/HL/");
    m_fsw->addPath("C:/pic/SWWYL_3d/");
//    m_fsw->addPath("C:/pic/SWWYL_2d/");
    m_fsw->addPath("C:/pic/HYFM/");
    m_fsw->addPath("C:/pic/WYC/");
    m_fsw->addPath("C:/pic/ZCDW/");



    connect(m_fsw, SIGNAL(directoryChanged(QString)), this,SLOT(loadPicture(QString)));


    m_pictures.append(findFile("C:/pic/HW/"));
    m_pictures.append(findFile("C:/pic/FC/"));
    m_pictures.append(findFile("C:/pic/HL/"));
    m_pictures.append(findFile("C:/pic/SWWYL_3d/"));
//    m_pictures.append(findFile("C:/pic/SWWYL_2d/"));
    m_pictures.append(findFile("C:/pic/HYFM/"));
    m_pictures.append(findFile("C:/pic/WYC/"));
    m_pictures.append(findFile("C:/pic/ZCDW/"));

    // 实现程序运行时长的统计
    elapsed_timer= new QTimer ;
    connect(elapsed_timer,SIGNAL(timeout()),this,SLOT(add_elapsed_time()));

    swl_firstime = true;
    zcdw_firstime = true;

}

MainWindow::~MainWindow()
{
    delete ui;
    disconnect(m_fsw, SIGNAL(directoryChanged(QString)), this,SLOT(loadPicture(QString)));
    delete m_fsw;
    delete fc;
    delete rh;
    disconnect(elapsed_timer,SIGNAL(timeout()),this,SLOT(add_elapsed_time()));
    delete elapsed_timer;

    for(int i=0; i<m_display_windows_list.length(); i++){
        delete m_display_windows_list[i];
    }

}


void MainWindow::on_pushButton_clicked()
{
    rh = new RongHe();
    //this->hide();
    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - rh->width())/2;
    y=(desktop->height() - rh->height())/2-20;
    rh->setGeometry(x,y,rh->width(),rh->height());
//    rh->setModal(true);
    rh->show();

}



//void MainWindow::on_pushButton_clicked()
//{
//    QString path;
//    QDir dir;
//    path=dir.currentPath();
//    QDir::setCurrent(path+"/rain");

//    QProcess::execute("rain.exe");
//    QDir::setCurrent(path);
////    QMessageBox::warning(0,"PATH",path,QMessageBox::Yes);//查看路径
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    QString path;
//    QDir dir;
//    path=dir.currentPath();

////    QStringList files = QFileDialog::getOpenFileNames(
////                            this,
////                            "Select one or more files to open",
////                            "/home",
////                            tr("All Files (*);;HDF5 Files (*.h5)"));


//    QDir::setCurrent(path+"/SST融合");

//    QProcess::startDetached("InverseDistance.exe",QStringList());
//    QDir::setCurrent(path);
//}

void MainWindow::on_pushButton_5_clicked()
{
    close() ;
}

void MainWindow::on_pushButton_4_clicked()
{
    showMinimized() ;
}
//**********??????????????*********//

void  MainWindow::mouseMoveEvent(QMouseEvent *event)//?????2???????????????????
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void MainWindow::on_pushButton_3_clicked()
{    
    fc = new Forecast();

    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - fc->width())/2;
    y=(desktop->height() - fc->height())/2-20;
    fc->setGeometry(x,y,fc->width(),fc->height());
//    fc->setModal(true);

    fc->show();
}

void MainWindow::on_pushButton_2_clicked()
{

    QString path;
    QDir dir;
    path=dir.currentPath();
    QDir::setCurrent(path+"/sc/ReleaseV4");

//    QMessageBox::warning(0,"PATH",dir.currentPath(),QMessageBox::Yes);
//    qDebug() << dir.currentPath();
    int i = QProcess::execute("PFOR3D.exe");
//     qDebug() << i;

     QDir::setCurrent(path);

    // MPlayer 播放视频
//    int i = QProcess::execute("C:\\MPlayer_Windows\\mplayer\\MPlayer.exe "+path+"\\yubao\\wenyanliu\\nwp_3dvar.mp4");

//    qDebug() << i;
//    QStringList sl = QProcessEnvironment::systemEnvironment().toStringList();
////    QString s;
////    foreach(s,sl)
////        qDebug() << s;
//    QProcess process;
//    bool ret = QProcess::startDetached(dir.currentPath()+"release\\sc\\ReleaseV4\\PFOR3D.exe");
//    qDebug() << ret;

//    QProcess pro;
////       pro.start(dir.currentPath()+"release\\sc\ReleaseV4\PFOR3D.exe");
//    pro.start("cmd");
//       pro.waitForStarted();
//       pro.write("release\\sc\ReleaseV4\PFOR3D.exe\n");
//       pro.closeWriteChannel();

//       pro.waitForFinished();

//    qDebug()<<QString::fromLocal8Bit(pro.readAllStandardOutput());

//    qDebug() << pro.exitStatus();
//    qDebug() << pro.exitCode();
//     QDir::setCurrent(path);
//    QMessageBox::warning(0,"PATH",pro.readAllStandardOutput(),QMessageBox::Yes);

}


void MainWindow::loadPicture(QString path)
{
    QStringList fl = findFile(path);
    QString f;

    QDir dir(path);
    QFileInfoList list;
    QStringList files;
    QFileInfo l;

    qDebug() << path << "pppppppppppppppppppppppppppp";


    if(path.contains("SWWYL_3d")){
        qDebug() << "in SWWYL_3d";

        foreach(f, fl)
            if(!m_pictures.contains(f)){

                if(f.endsWith("swf")){
                    qDebug() << f << "ffffffffffffff";
                    // Stop loading gif in select window.
                    if(fc && swl_firstime)   {
                        swl_firstime = false;
                        if(elapsed_timer->isActive()){
                            elapsed_timer->stop();
                              QMessageBox::information(0,QStringLiteral("时间统计"),QStringLiteral("运行时间为")+QString(" %1 ").arg(elapsed_time)+QStringLiteral("秒！"),QMessageBox::Ok);

                              // Display curr 3d.
                              Display *d = new Display();
                              d->init(f);
                              QDesktopWidget* desktop = QApplication::desktop();
                              int x,y;
                              x=(desktop->width() - d->width())/2;
                              y=(desktop->height() - d->height())/2-20;
                              d->setGeometry(x,y,d->width(),d->height());
                              fc->setModal(true);
                              d->show();
                              m_display_windows_list.append(d);
                              m_pictures.append(f);

                              // Display salt 3d.
                              f.replace("curr", "salt");
                              d = new Display();
                              d->init(f);
                              desktop = QApplication::desktop();

                              x=(desktop->width() - d->width())/2;
                              y=(desktop->height() - d->height())/2-20;
                              d->setGeometry(x,y,d->width(),d->height());
                              fc->setModal(true);
                              d->show();
                              m_display_windows_list.append(d);
                              m_pictures.append(f);

                              // Display temp 3d.
                              f.replace("salt", "temp");
                              d = new Display();
                              d->init(f);
                              desktop = QApplication::desktop();

                              x=(desktop->width() - d->width())/2;
                              y=(desktop->height() - d->height())/2-20;
                              d->setGeometry(x,y,d->width(),d->height());
                              fc->setModal(true);
                              d->show();
                              m_display_windows_list.append(d);
                              m_pictures.append(f);



                              swl_firstime = true;

//                            QMessageBox msgBox(QMessageBox::Information, QStringLiteral("时间统计"),QStringLiteral("运行时间为")+QString(" %1 ").arg(elapsed_time)+QStringLiteral("秒！"),QMessageBox::Ok);
//                            msgBox.setModal(false);
//                            msgBox.show();
                        }
                        fc->stop_loading();

                    }



                }

             }

        return;
    }


    if(path.contains("ZCDW")){
        list = dir.entryInfoList();
        qDebug() << list.size();
        if (list.size() == 101+2){
            if(fc && zcdw_firstime)   {
                zcdw_firstime = false;

            if(fc)   {
                if(elapsed_timer->isActive()){
                    elapsed_timer->stop();
                    QMessageBox::warning(0,QStringLiteral("时间统计"),QStringLiteral("运行时间为")+QString(" %1 ").arg(elapsed_time)+QStringLiteral("秒！"),QMessageBox::Yes);
                }
                fc->stop_loading();
            }

            foreach (l, list) {
                if(l.fileName() == "." || l.fileName() == "..")
                    continue;
                files << l.filePath();
            }

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

              zcdw_firstime = true;
            }
        }
        return;
    }


    // Stop loading gif in select window.
    if(fc)   {
        if(elapsed_timer->isActive()){
            elapsed_timer->stop();
            QMessageBox::warning(0,QStringLiteral("时间统计"),QStringLiteral("运行时间为")+QString(" %1 ").arg(elapsed_time)+QStringLiteral("秒！"),QMessageBox::Yes);
        }
        fc->stop_loading();
    }

    // Get elapsed time of process run.
//    if(elapsed_timer->isActive()){
//        elapsed_timer->stop();

//        elapsed_time=0;
//    }



//    PIC_TYPE pt;


//    if (path=="C:\\pic\\HW"){
//        pt = HW;
//    }else if(path=="C:\\pic\\FC"){
//        pt = FC;
//    }else if(path=="C:\\pic\\HL"){
//        pt = HL;
//    }else if(path=="C:\\pic\\SWWYL"){
//        pt = SWWYL;
//    }else if(path=="C:\\pic\\WYC"){
//        pt = WYC;
//    }else if(path=="C:\\pic\\ZCDW"){
//        pt = ZCDW;
//    }else if(path=="C:\\pic\\HYFM"){
//        pt = HYFM;
//    }

    foreach(f, fl)
        if(!m_pictures.contains(f)){

//            QMessageBox::warning(0,"PATH",f,QMessageBox::Yes);
//           QString date = "20151031";
//           float x1=160;
//           float y1=10;
//           float x2=-120;
//           float y2=40;
//           float maxt=30,mint=10;
//           QString data_src="HY-2";
//           float resolution = 0.25;
           Display *d = new Display();
           d->init(f);

           QDesktopWidget* desktop = QApplication::desktop();
           int x,y;
           x=(desktop->width() - d->width())/2;
           y=(desktop->height() - d->height())/2-20;
           d->setGeometry(x,y,d->width(),d->height());
//           fc->setModal(true);
           d->show();

           m_display_windows_list.append(d);
           m_pictures.append(f);

        }
}


QStringList MainWindow::findFile(const QString & path)
{
    qDebug() << path;
  QDir dir(path);
  QStringList sl;
  if (!dir.exists()) return sl;
  dir.setFilter(QDir::Dirs|QDir::Files);
  dir.setSorting(QDir::DirsFirst);
  QFileInfoList list = dir.entryInfoList();
  int i = 0;
  bool bIsDir;
  do{
    QFileInfo fileInfo = list.at(i);
    if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
    {
      i++;
      continue;
    }
    bIsDir = fileInfo.isDir();
    if (bIsDir){
      //nFiles++;                //对文件属性进行处理
      //fileInfo.size(),fileInfo.fileName(),fileInfo.path()
      findFile(fileInfo.filePath());
    }
    else
    {
//      nFiles++;
      qDebug() << path+"\\"+fileInfo.fileName();
      sl.append(path+"\\"+fileInfo.fileName());  // 必须用 “\\", 改成 ”/" 后导致 flash调用3d swp失败，一下午时间的教训。
    }
    i++;
  }while(i<list.size());
  return sl;
}

void  MainWindow::add_elapsed_time()
{
    elapsed_time++;

}

