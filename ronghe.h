#ifndef RONGHE_H
#define RONGHE_H

#include <QDialog>
#include <QLabel>


namespace Ui {
class RongHe;
}

class RongHe : public QDialog
{
    Q_OBJECT

public:
    explicit RongHe(QWidget *parent = 0);

    bool loadFile(const QString &fileName, QLabel* lb);
    bool displayHaiwen(const QStringList sl);
    bool displayFeng(const QStringList sl);
    bool displayHaiLang(const QStringList sl);
    bool displayImages(const QStringList sl, QLabel *lb);


    ~RongHe();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void nextPicture();

    void on_pushButton_6_clicked();

    void on_pushButton_bf_clicked();

    void on_pushButton_zt_clicked();

    void on_pushButton_jias_clicked();

    void on_pushButton_jians_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_jians_2_clicked();

    void on_pushButton_bf_2_clicked();

    void on_pushButton_zt_2_clicked();

    void on_pushButton_jias_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_jians_3_clicked();

    void on_pushButton_bf_3_clicked();

    void on_pushButton_zt_3_clicked();

    void on_pushButton_jias_3_clicked();

protected:

    //���������϶��¼�
    void  mouseMoveEvent(QMouseEvent *event);
    void  mousePressEvent(QMouseEvent *event);
    void  mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::RongHe *ui;


    QPoint mouseMovePos;
	
	QLabel *label;
    QStringListIterator *iterator;
    QTimer *timer;
    int speed;

    bool hasFiles();



};

#endif // RONGHE_H
