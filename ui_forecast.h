/********************************************************************************
** Form generated from reading UI file 'forecast.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORECAST_H
#define UI_FORECAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Forecast
{
public:
    QPushButton *pushButton_6;
    QPushButton *pushButton_xw;
    QPushButton *pushButton_yc;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_hyf;

    void setupUi(QDialog *Forecast)
    {
        if (Forecast->objectName().isEmpty())
            Forecast->setObjectName(QStringLiteral("Forecast"));
        Forecast->resize(1000, 560);
        pushButton_6 = new QPushButton(Forecast);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(925, 482, 79, 80));
        pushButton_xw = new QPushButton(Forecast);
        pushButton_xw->setObjectName(QStringLiteral("pushButton_xw"));
        pushButton_xw->setGeometry(QRect(510, 150, 216, 282));
        pushButton_yc = new QPushButton(Forecast);
        pushButton_yc->setObjectName(QStringLiteral("pushButton_yc"));
        pushButton_yc->setGeometry(QRect(740, 150, 216, 282));
        pushButton_2 = new QPushButton(Forecast);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(740, 470, 160, 43));
        pushButton = new QPushButton(Forecast);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 150, 216, 282));
        pushButton_hyf = new QPushButton(Forecast);
        pushButton_hyf->setObjectName(QStringLiteral("pushButton_hyf"));
        pushButton_hyf->setGeometry(QRect(280, 150, 216, 282));

        retranslateUi(Forecast);

        QMetaObject::connectSlotsByName(Forecast);
    } // setupUi

    void retranslateUi(QDialog *Forecast)
    {
        Forecast->setWindowTitle(QApplication::translate("Forecast", "\344\270\211\347\273\264\346\270\251\347\233\220\346\265\201\346\225\260\345\200\274\345\220\214\345\214\226\351\242\204\346\212\245", 0));
        pushButton_6->setText(QString());
        pushButton_xw->setText(QString());
        pushButton_yc->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        pushButton_hyf->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Forecast: public Ui_Forecast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORECAST_H
