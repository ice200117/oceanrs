#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QList>

#include "forecast.h"
#include "ronghe.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QStringList findFile(const QString & path);

    int elapsed_time;

    QTimer *elapsed_timer;

    // List container  of result picture display window pointers.
    QList<Display*> m_display_windows_list;

    QStringList m_pictures;

private slots:

    void  add_elapsed_time();


    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void loadPicture(QString path);

protected:

    //���������϶��¼�
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;

    //ʵ�����������϶�
    QPoint mouseMovePos;

    QFileSystemWatcher *m_fsw;



    RongHe *rh;
    Forecast *fc;

    bool swl_firstime;



};

#endif // MAINWINDOW_H
