#include "historypic.h"
#include "ui_historypic.h"

HistoryPic::HistoryPic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoryPic)
{
    ui->setupUi(this);
}

HistoryPic::~HistoryPic()
{
    delete ui;
}
