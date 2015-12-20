#ifndef HISTORYPIC_H
#define HISTORYPIC_H

#include <QDialog>

namespace Ui {
class HistoryPic;
}

class HistoryPic : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryPic(QWidget *parent = 0);
    ~HistoryPic();

private:
    Ui::HistoryPic *ui;
};

#endif // HISTORYPIC_H
