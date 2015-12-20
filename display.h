#ifndef DISPLAY_H
#define DISPLAY_H
#include <QDialog>
#include <QLabel>
#include <QTimer>

namespace Ui {
class Display;
}

enum PIC_TYPE{FC, HL, HW, HYFM, SWWYL, WYC, ZCDW};



class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    void init(QString,float,float,float,float,float,float,QString,float,QString,PIC_TYPE);
    void init(QStringList files);
    void init(QString file);

    ~Display();

private slots:
    //void on_webView_loadFinished(bool arg1);

    void on_pushButton_clicked();

    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);


    void  nextPicture();


    void on_pushButton_bf_clicked();

    void on_pushButton_zt_clicked();

    void on_pushButton_jias_clicked();

    void on_pushButton_jians_clicked();



    void on_lineEdit_returnPressed();

private:
    Ui::Display *ui;
    float m_x1,m_y1,m_x2,m_y2;

    QString m_path;
    PIC_TYPE m_pt;
    QPoint mouseMovePos;

    QLabel *label;
    QStringListIterator *iterator;
    QTimer *timer;
    int speed;

    bool hasFiles();

    QString wyl_type;

};

#endif // DISPLAY_H
