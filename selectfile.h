#ifndef SELECTFILE_H
#define SELECTFILE_H

#include <QDialog>
#include "display.h"
#include<QMovie>
#include<QTimer>
#include<QMouseEvent>
#include <QFileSystemWatcher>

namespace Ui {
class SelectFile;
}

class SelectFile : public QDialog
{
    Q_OBJECT

public:
    explicit SelectFile(QWidget *parent = 0);
    void init(PIC_TYPE);
    void stop_loading();
    ~SelectFile();

    bool copyDirectoryFiles(QString sourceDir ,QString toDir, bool coverFileIfExist);
    bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist);

    void callSWWYL();
    void callZCDW();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void showFlash() ; //展示擦除动画：由左向右

    void on_pushButton_5_clicked();

    void copyFile(QString path);



protected:
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);
private:
    Ui::SelectFile *ui;
    PIC_TYPE m_pt;

    QMovie *loadMovie ;

    QTimer *timer_Expand ;
    int currentHeight ;

    QPoint mouseMovePos;

    QFileSystemWatcher *m_fsw;

    QString m_outPath;

    bool m_first_change;

    QString root_path;

};

#endif // SELECTFILE_H
