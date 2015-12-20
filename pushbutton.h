//�Զ��尴ť��ʵ��Normal��Hover��Press
#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include<QLabel>

class PushButton:public QPushButton
{
    Q_OBJECT
public:
   explicit PushButton(QWidget *parent = 0);
   ~PushButton();
   void getIconPath(QString icon_path);//�õ�ͼƬ��·�����֣��������ð�ťΪͼƬ�Ĵ�С
   void getVoicePath(QString voice_path);//�õ���Ч��·������
   void getVoice_2Path(QString voice_2_path);//�õ���Ч��·������
//   void getbtnFoucs(int i)
//   {
//       btnFoucs=i;
//   }

//   int getFoucs(int i)
//   {
//       return i;
//   }

   void enterEvent(QEvent *);//�����¼�
   void leaveEvent(QEvent *);//�뿪�¼�
   void mousePressEvent(QMouseEvent *event);  //��갴���¼�
   void mouseReleaseEvent(QMouseEvent *event); //����ͷ��¼�
   void paintEvent(QPaintEvent *);//��ť��ͼ�¼�
   void setPbPos(double x,double y)
   {
       pbX=x;
       pbY=y;
   }
   double getPbX()
   {
       return pbX;
   }
   double getPbY()
   {
       return pbY;
   }
signals:
   void  submitBtn(int i);


private:
   enum ButtonStatus{NORMAL, HOVER, PRESS}; //ö�ٰ�ť�ļ���״̬
   ButtonStatus status;
   QString icon_path;  //ͼ��·����
   QString voice_path; //��Ч·����
   QString voice_2_path;//���µ���Ч
   bool mouse_press;  //��ť����Ƿ���
   double pbX,pbY;
   //QLabel *label;
   //tankUI *tank_UI;
   int btnFoucs;
};
#endif // PUSHBUTTON_H
