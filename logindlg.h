#ifndef LOGINDLG_H
#define LOGINDLG_H
#include<QDesktopWidget>
#include<QTimer>
#include<QMovie>
#include<mainwindow.h>
#include <QDialog>

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();

private slots:

    void on_pushButton_2_clicked();
    void startUI() ;
protected:

    //声明鼠标拖动事件
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);



private:
    Ui::LoginDlg *ui;

    //实现主界面的拖动
    QPoint mouseMovePos;
    QTimer *timerWelcom ;

    QMovie *loadMovie ;

};

#endif // LOGINDLG_H
