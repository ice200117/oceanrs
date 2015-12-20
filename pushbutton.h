//自定义按钮，实现Normal、Hover、Press
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
   void getIconPath(QString icon_path);//得到图片的路径名字，并且设置按钮为图片的大小
   void getVoicePath(QString voice_path);//得到音效的路径名字
   void getVoice_2Path(QString voice_2_path);//得到音效的路径名字
//   void getbtnFoucs(int i)
//   {
//       btnFoucs=i;
//   }

//   int getFoucs(int i)
//   {
//       return i;
//   }

   void enterEvent(QEvent *);//进入事件
   void leaveEvent(QEvent *);//离开事件
   void mousePressEvent(QMouseEvent *event);  //鼠标按下事件
   void mouseReleaseEvent(QMouseEvent *event); //鼠标释放事件
   void paintEvent(QPaintEvent *);//按钮绘图事件
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
   enum ButtonStatus{NORMAL, HOVER, PRESS}; //枚举按钮的几种状态
   ButtonStatus status;
   QString icon_path;  //图标路径名
   QString voice_path; //音效路径名
   QString voice_2_path;//按下的音效
   bool mouse_press;  //按钮左键是否按下
   double pbX,pbY;
   //QLabel *label;
   //tankUI *tank_UI;
   int btnFoucs;
};
#endif // PUSHBUTTON_H
