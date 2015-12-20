#include "logindlg.h"
#include "ui_logindlg.h"
#include<QBitmap>
#include<QMouseEvent>


MainWindow *mw;

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    //QPixmap pix("welcome.jpg");
    //ui->label_pic->setPixmap(pix);
    //setFixedSize(600,430);
    //����Բ�Ǵ���
    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_welcome_2.png");//��������ͼ��
    setMask(QBitmap(mask.mask())); //���ô��������ͼ��,�ٳ�ͼ��İ�ɫ����ʵ�ֲ�������
    QPalette p;//���õ�ɫ��
    p.setBrush(QPalette::Window, QBrush(mask));//����ɫ��Ļ�ˢ����Ϊ����λͼ,�ڲ�����������ʾ������λͼ
    setPalette(p);

    ui->pushButton->hide() ; //����Ҫ�û��������
    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_enter_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_enter_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_enter_press.png);}");

    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_close_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_close_hover.png);}"
                                   "QPushButton:pressed{border-image: url(:/Images/images/pb_close_press.png);}");

    //����loading������
    loadMovie=new QMovie(":/Images/images/process.gif");
    ui->label->setMovie(loadMovie);
    loadMovie->start();
    //3����Զ�����������
    timerWelcom=new QTimer(this);
    timerWelcom->start(3000);
    connect(timerWelcom,SIGNAL(timeout()),this,SLOT(startUI()));
}

LoginDlg::~LoginDlg()
{
    delete ui;
    delete loadMovie;
    delete timerWelcom;
}


//**********��������϶��¼�*********//

void  LoginDlg::mouseMoveEvent(QMouseEvent *event)//��갴�²��ƶ����ƶ���������
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void LoginDlg::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();
//    accept();

}
void LoginDlg::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}

void LoginDlg::on_pushButton_2_clicked()
{
    timerWelcom->stop();
    close() ;
}
void LoginDlg::startUI()
{
    timerWelcom->stop();
    this->close() ;
    mw = new MainWindow() ;
    QDesktopWidget* desktop = QApplication::desktop();
    int x,y;
    x=(desktop->width() - mw->width())/2;
    y=(desktop->height() - mw->height())/2;
    mw->setGeometry(x,y,mw->width(),mw->height());
    mw->show();
}
