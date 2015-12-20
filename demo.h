#ifndef DEMO_H
#define DEMO_H
#include<QTimer>
#include <QDialog>
#include<QMovie>
namespace Ui {
class Demo;
}

class Demo : public QDialog
{
    Q_OBJECT

public:
    explicit Demo(QWidget *parent = 0);
    ~Demo();
public slots:
    void showFlash() ;
    void endLoading() ;
private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();

protected:
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::Demo *ui;

    QTimer *timer_Expand ;
    int currentHeight ;

    QPoint mouseMovePos;

    QTimer *timer_showLoading ;
    QMovie *loadMovieDemo ;

};

#endif // DEMO_H
