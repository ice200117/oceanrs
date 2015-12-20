#include "pushbutton.h"
#include <QSound>

PushButton::PushButton(QWidget *parent)
    :QPushButton(parent)
{
    //tank_UI=new tankUI();
    status = NORMAL;
    mouse_press = false;
    btnFoucs=1;
    //    label=new QLabel();
    //    label->setGeometry(110,420,48,49);
    //connect(this,SIGNAL(submitBtn(int i)),tank_UI,SLOT(moveTankIco(int btnCount)));

}
PushButton::~PushButton()
{
}
void PushButton::getIconPath(QString Icon_path)
{
    this->icon_path = Icon_path;
    setFixedSize(QPixmap(Icon_path).size());//设置按钮与图片一样的大小
}
void PushButton::getVoicePath(QString Voice_path)
{
    this->voice_path=Voice_path;
}
void PushButton::getVoice_2Path(QString Voice_2_path)
{
    this->voice_2_path=Voice_2_path;
}
void PushButton::enterEvent(QEvent *)
{
    status = HOVER;
    update();
}
void PushButton::mousePressEvent(QMouseEvent *event)
{
    //若点击鼠标左键
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}
void PushButton::mouseReleaseEvent(QMouseEvent *event)
{
    //若点击鼠标左键响应
    if(mouse_press&&this->rect().contains(event->pos()))
    {
        mouse_press = false;
        status = HOVER;
        update();
        emit clicked();
    }
}
void PushButton::leaveEvent(QEvent *)
{
    status = NORMAL;
    update();
}
void PushButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap;
    switch(status)
    {
    case NORMAL:
    {
        pixmap.load(icon_path);
        setFixedSize(QPixmap(icon_path).size());//设置按钮与图片一样的大小
        // move(getPbX(),getPbY());
        break;
    }
    case HOVER:
    {
//        switch(btnFoucs)
//        {
//        case 1: emit submitBtn(1);break;
//        case 2: emit submitBtn(2);break;
//        case 3: emit submitBtn(3);break;
//        case 4: emit submitBtn(4);break;
//        default:break;
//        }


        QSound sound(voice_path);
        sound.play();


        // move(getPbX()-20,getPbY()-5); //如果图片放大，还依照小图的坐标，那么图片放大的位置在左上角，而不是中心放大，这样的话，放大之后的图片
        //会发生偏移，因此需要这个函数进行中心归位，但是中心归位的时候，不知道x和y坐标调整多少才会居中放大，而且，这样的话，还有一个短暂的图标归位的
        //动画效果，表现在图像上就是比较卡！
        pixmap.load(icon_path + QString("_hover"));
        //setFixedSize(QPixmap(icon_path + QString("_hover")).size());//设置按钮与图片一样的大小
        //这里，不加“Cen”，代表直接从左上角“偏移放大”，加上“Cen”，代表“居中放大”。需要在资源文件里面准备两个“_hover”文件。

        break;
    }
    case PRESS:
    {

        QSound sound(voice_2_path);
        sound.play();


        pixmap.load(icon_path + QString("_press"));
        //setFixedSize(QPixmap(icon_path + QString("_press")).size());//设置按钮与图片一样的大小
        break;
    }
    default:
        pixmap.load(icon_path);
    }
    painter.drawPixmap(rect(), pixmap);
    painter.drawText(this->rect(), Qt::AlignCenter, this->text());
}
