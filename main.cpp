#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QTextCodec> //添加头文件

#include<QDesktopWidget>

#include <QThread>

#include "logindlg.h" //添加头文件
#include "display.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QFile file("style.qss");
//    QString styleSheet = file.readAll().data();
//    QMessageBox::warning(0,"PATH",styleSheet,QMessageBox::Yes);//查看路径
//    a.setStyleSheet(styleSheet);

    QFile data("style.qss");
    QString qssFile;

    if(data.open(QFile::ReadOnly))
    {
        QTextStream styleIn(&data);
        qssFile = styleIn.readAll();
        data.close();
       // QMessageBox::warning(0,"PATH",qssFile,QMessageBox::Yes);//查看路径
        a.setStyleSheet(qssFile);
    }




    LoginDlg dlg;                        // 建立自己新建的类的对象dlg
    //设置窗体居中显示
    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - dlg.width())/2;
    y=(desktop->height() - dlg.height())/2;
    dlg.setGeometry(x,y,dlg.width(),dlg.height());
    dlg.exec();
    return a.exec();


//       if(dlg.exec() == QDialog::Accepted) // 利用Accepted返回值判断按钮是否被按下
//        {

//            w.show();                      // 如果被按下，显示主窗口

//           QString date = "20151031";
//           float x1=60;
//           float y1=10;
//           float x2=120;
//           float y2=40;
//           float maxt=30,mint=10;
//           QString data_src="HY-2";
//           float resolution = 0.25;
//           Display *fc = new Display();
//           fc->init(date,x1,y1,x2,y2,maxt,mint,data_src,resolution);
//           QDesktopWidget* desktop = QApplication::desktop();
//           int x,y;
//           x=(desktop->width() - fc->width())/2;
//           y=(desktop->height() - fc->height())/2-20;
//           fc->setGeometry(x,y,fc->width(),fc->height());
//           fc->setModal(true);
//           fc->show();



//           return a.exec();               // 程序一直执行，直到主窗口关闭
//       }
//       else return 0;  //如果没被按下，则不会进入主窗口，整个程序结束运行

}
