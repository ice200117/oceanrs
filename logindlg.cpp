#include "logindlg.h"
#include "ui_logindlg.h"
#include<QBitmap>
#include<QMouseEvent>


MainWindow *mw;

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    //QPixmap pix("welcome.jpg");
    //ui->label_pic->setPixmap(pix);
    //setFixedSize(600,430);
    //设置圆角窗体
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_welcome_2.png");//加载掩码图像
    setMask(QBitmap(mask.mask())); //设置窗体的掩码图像,抠除图像的白色区域实现不规则窗体
    QPalette p;//设置调色板
    p.setBrush(QPalette::Window, QBrush(mask));//将调色板的画刷设置为掩码位图,在不规则窗体上显示出掩码位图
    setPalette(p);

    ui->pushButton->hide() ; //不需要用户点击进入
    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_enter_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_enter_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_enter_press.png);}");

    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_close_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_close_hover.png);}"
                                   "QPushButton:pressed{border-image: url(:/Images/images/pb_close_press.png);}");

    //载入loading…动画
    loadMovie=new QMovie(":/Images/images/process.gif");
    ui->label->setMovie(loadMovie);
    loadMovie->start();
    //3秒后自动启动主界面
    timerWelcom=new QTimer(this);
    timerWelcom->start(3000);
    connect(timerWelcom,SIGNAL(timeout()),this,SLOT(startUI()));
}

LoginDlg::~LoginDlg()
{
    delete ui;
    delete loadMovie;
    delete timerWelcom;
}


//**********定义鼠标拖动事件*********//

void  LoginDlg::mouseMoveEvent(QMouseEvent *event)//鼠标按下并移动则移动不规则窗体
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void LoginDlg::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();
//    accept();

}
void LoginDlg::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void LoginDlg::on_pushButton_2_clicked()
{
    timerWelcom->stop();
    close() ;
}
void LoginDlg::startUI()
{
    timerWelcom->stop();
    this->close() ;
    mw = new MainWindow() ;
    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - mw->width())/2;
    y=(desktop->height() - mw->height())/2;
    mw->setGeometry(x,y,mw->width(),mw->height());
    mw->show();
}
