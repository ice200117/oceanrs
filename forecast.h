#ifndef FORECAST_H
#define FORECAST_H

#include <QDialog>
#include <QLabel>
#include "selectfile.h"

namespace Ui {
class Forecast;
}

class Forecast : public QDialog
{
    Q_OBJECT

public:
    explicit Forecast(QWidget *parent = 0);

    bool displayYuBao(const QStringList sl);

    bool  loadFile(const QString &fileName, QLabel* lb);
    bool  displayImages(const QStringList sl, QLabel *lb);

    //Stop loading movie.
    void stop_loading();

    ~Forecast();
//    void paintEvent(QPaintEvent *) ;
private slots:



    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_hyf_clicked();

    void on_pushButton_xw_clicked();

    void on_pushButton_yc_clicked();

    void nextPicture();


    void on_pushButton_bf_clicked();

    void on_pushButton_zt_clicked();

    void on_pushButton_jias_clicked();

    void on_pushButton_jians_clicked();

    void on_pushButton_clicked();

protected:

    //��ק����
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::Forecast *ui;

    QPoint mouseMovePos;

    QLabel *label;
    QStringListIterator *iterator;
    QTimer *timer;
    int speed;

    bool hasFiles();

    SelectFile *select_window;
};

#endif // FORECAST_H
