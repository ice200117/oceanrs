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
    setFixedSize(QPixmap(Icon_path).size());//���ð�ť��ͼƬһ���Ĵ�С
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
    //�����������
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
        status = PRESS;
        update();
    }
}
void PushButton::mouseReleaseEvent(QMouseEvent *event)
{
    //�������������Ӧ
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
        setFixedSize(QPixmap(icon_path).size());//���ð�ť��ͼƬһ���Ĵ�С
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


        // move(getPbX()-20,getPbY()-5); //���ͼƬ�Ŵ󣬻�����Сͼ�����꣬��ôͼƬ�Ŵ��λ�������Ͻǣ����������ķŴ������Ļ����Ŵ�֮���ͼƬ
        //�ᷢ��ƫ�ƣ������Ҫ��������������Ĺ�λ���������Ĺ�λ��ʱ�򣬲�֪��x��y����������ٲŻ���зŴ󣬶��ң������Ļ�������һ�����ݵ�ͼ���λ��
        //����Ч����������ͼ���Ͼ��ǱȽϿ���
        pixmap.load(icon_path + QString("_hover"));
        //setFixedSize(QPixmap(icon_path + QString("_hover")).size());//���ð�ť��ͼƬһ���Ĵ�С
        //������ӡ�Cen��������ֱ�Ӵ����Ͻǡ�ƫ�ƷŴ󡱣����ϡ�Cen�����������зŴ󡱡���Ҫ����Դ�ļ�����׼��������_hover���ļ���

        break;
    }
    case PRESS:
    {

        QSound sound(voice_2_path);
        sound.play();


        pixmap.load(icon_path + QString("_press"));
        //setFixedSize(QPixmap(icon_path + QString("_press")).size());//���ð�ť��ͼƬһ���Ĵ�С
        break;
    }
    default:
        pixmap.load(icon_path);
    }
    painter.drawPixmap(rect(), pixmap);
    painter.drawText(this->rect(), Qt::AlignCenter, this->text());
}
