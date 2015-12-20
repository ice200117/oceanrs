#include "demo.h"
#include "ui_demo.h"
#include<QBitmap>
#include<QMouseEvent>
#include<QPropertyAnimation>
Demo::Demo(QWidget *parent) :
    QDialog(parent),currentHeight(1),
    ui(new Ui::Demo)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_selectfile.png");//加载掩码图像
    setMask(QBitmap(mask.mask())); //设置窗体的掩码图像,抠除图像的白色区域实现不规则窗体
    QPalette p;//设置调色板
    p.setBrush(QPalette::Window, QBrush(mask));//将调色板的画刷设置为掩码位图,在不规则窗体上显示出掩码位图
    setPalette(p);
    //添加渐变动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity"); //动画对象类型：渐变
    animation->setDuration(1000); //维持1秒
    animation->setStartValue(0);  //起始α值
    animation->setEndValue(1);    //结束α值
    animation->start();           //动画开始

    ui->label_5->hide();
    loadMovieDemo = new QMovie(":/Images/images/loading_2.gif");
    ui->label_5->setMovie( loadMovieDemo );

    ui->pushButton_4->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_select_work_normal.png);}"
                                    "QPushButton:hover{border-image: url(:/Images/images/pb_select_work_hover.png);}"
                                    "QPushButton:pressed{border-image: url(:/Images/images/pb_select_work_press.png);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_close_normal.png);}"
                                    "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_close_hover.png);}"
                                    "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_close_press.png);}");
    timer_showLoading = new QTimer() ;
    connect(timer_showLoading,SIGNAL(timeout()),this,SLOT(endLoading()));

    timer_Expand = new QTimer() ;
    timer_Expand->start(5);
    connect(timer_Expand,SIGNAL(timeout()),this,SLOT(showFlash()));
}

Demo::~Demo()
{
    delete ui;
}
void Demo::showFlash()
{
    if(this->width()<763)
    {
        currentHeight += 10;
        this->resize(currentHeight , 429);
    }
    else
    {
        this->resize(763,429);
        timer_Expand->stop();
    }
}

void Demo::on_pushButton_5_clicked()
{
    //界面消失动画——渐隐
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(400);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));

}
void  Demo::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void Demo::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}
void Demo::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void Demo::on_pushButton_4_clicked()
{
    timer_showLoading->start(3000) ;
    ui->label_5->show();
    loadMovieDemo->start();
}

void Demo::endLoading()
{
    ui->label_5->hide();
    loadMovieDemo->stop();
    timer_showLoading->stop();
}
