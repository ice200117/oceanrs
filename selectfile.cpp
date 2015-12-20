#include "selectfile.h"
#include "ui_selectfile.h"
#include <QFileDialog>
#include "mainwindow.h"
#include<QBitmap>
#include<QPropertyAnimation>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>
#include <QThread>
#include <QDir>

extern MainWindow *mw;

QString file_date;

SelectFile::SelectFile(QWidget *parent) :
    QDialog(parent),currentHeight(1),
    ui(new Ui::SelectFile)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    QPixmap mask(":/Images/images/ui_selectfile.png");//��������ͼ��
    setMask(QBitmap(mask.mask())); //���ô��������ͼ��,�ٳ�ͼ��İ�ɫ����ʵ�ֲ�������
    QPalette p;//���õ�ɫ��
    p.setBrush(QPalette::Window, QBrush(mask));//����ɫ��Ļ�ˢ����Ϊ����λͼ,�ڲ�����������ʾ������λͼ
    setPalette(p);

    //��ӽ��䶯��
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity"); //�����������ͣ�����
    animation->setDuration(1000); //ά��1��
    animation->setStartValue(0);  //��ʼ��ֵ
    animation->setEndValue(1);    //������ֵ
    animation->start();           //������ʼ

    ui->label_5->hide();
    loadMovie=new QMovie(":/Images/images/loading_2.gif");
    ui->label_5->setMovie(loadMovie);

    ui->pushButton_4->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_select_work_normal.png);}"
                                   "QPushButton:hover{border-image: url(:/Images/images/pb_select_work_hover.png);}"
                                     "QPushButton:pressed{border-image: url(:/Images/images/pb_select_work_press.png);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/Images/images/pb_mainui_close_normal.png);}"
                                    "QPushButton:hover{border-image: url(:/Images/images/pb_mainui_close_hover.png);}"
                                    "QPushButton:pressed{border-image: url(:/Images/images/pb_mainui_close_press.png);}");

    timer_Expand = new QTimer() ;
    timer_Expand->start(5);
    connect(timer_Expand,SIGNAL(timeout()),this,SLOT(showFlash()));

    m_fsw = new QFileSystemWatcher;
    connect(m_fsw, SIGNAL(directoryChanged(QString)), this,SLOT(copyFile(QString)));


    QDir dir;
    root_path = QDir::currentPath() + "//release"; ;
}

SelectFile::~SelectFile()
{
    disconnect(m_fsw, SIGNAL(directoryChanged(QString)), this,SLOT(copyFile(QString)));
    delete ui;
    delete loadMovie;
    delete m_fsw;
    delete timer_Expand;

}


void SelectFile::init(PIC_TYPE pt)
{
    m_pt = pt;


    switch (m_pt) {
    case SWWYL:
        ui->label_4->setText(QStringLiteral("��ѡ����ά�������������ļ������·��"));

        ui->label_2->hide();
        ui->lineEdit_2->hide();
        ui->pushButton_2->hide();

        break;
    case HYFM:

        ui->label_4->setText(QStringLiteral("��ѡ�������������ļ������·��"));

        ui->label_2->hide();
        ui->lineEdit_2->hide();
        ui->pushButton_2->hide();

        break;
    case ZCDW:

        ui->label_4->setText(QStringLiteral("��ѡ���г߶��е������ļ������·��"));
        break;
    case WYC:

        ui->label_4->setText(QStringLiteral("��ѡ����Ծ��������ļ������·��"));
        break;
    default:
        break;
    }
}

bool SelectFile::copyDirectoryFiles(QString fromDir ,QString toDir, bool coverFileIfExist)
{
    QDir sourceDir(fromDir);
    QDir targetDir(toDir);
    QString toFile;
    if(!targetDir.exists()){    /**< ���Ŀ��Ŀ¼�����ڣ�����д��� */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< ��ΪĿ¼ʱ���ݹ�Ľ���copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                                   targetDir.filePath(fileInfo.fileName()),
                                   coverFileIfExist))
                return false;
        }
        else{            /**< �������ǲ���ʱ�������ļ�����ɾ������ */
            toFile = targetDir.filePath(fileInfo.fileName());
//            QMessageBox::warning(0,"PATH1",toFile,QMessageBox::Yes);
            if(coverFileIfExist && targetDir.exists(fileInfo.fileName())){
                targetDir.remove(fileInfo.fileName());
            }
            toFile = toDir+"\\"+fileInfo.fileName();
            qDebug() << toFile << "  remove from m_pictures";
             if(mw->m_pictures.contains(toFile)){
//                 QMessageBox::warning(0,"PATH2",toFile,QMessageBox::Yes);
                 mw->m_pictures.removeAll(toFile);
             }

            /// �����ļ�copy
            if(!QFile::copy(fileInfo.filePath(),
                            targetDir.filePath(fileInfo.fileName()))){
                return false;
            }
        }
    }
    return true;
}

bool SelectFile::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile     = new QDir;
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    QFileInfo fi(sourceDir);

 qDebug() << sourceDir << toDir+fi.fileName();
    if(!QFile::copy(sourceDir, toDir+fi.fileName()))
    {
        delete createfile;
        return false;
    }
    delete createfile;

    return true;
}

void SelectFile::copyFile(QString path)
{
    QDir dir(path);
    QFileInfoList list;
    QDir flash_dir("C:/pic/SWWYL");

    // ���ƽ���ļ��������û�ѡ������Ŀ¼
    switch (m_pt) {
    case HYFM:
//        if(m_first_change) {
//            m_first_change = false;
//            QMessageBox::warning(0,"PATH",path,QMessageBox::Yes);
            QThread::sleep(1);
            copyDirectoryFiles(path, m_outPath, true );
            copyDirectoryFiles(path, "C:/pic/HYFM/", true );
//        }
        break;
    case SWWYL:

        list = dir.entryInfoList();
        qDebug() << list.size();
        if (list.size() == 30+2){
            QDir::setCurrent(root_path+"/yubao/wenyanliu/");


            QThread::sleep(1);
            copyDirectoryFiles(path, m_outPath, true );

            // call qie ge program.
            QProcess::execute("./QIEGE.exe");

            // copy 0,1,2,3,4,5 pic to flash dir.
            QDir::setCurrent(root_path+"/yubao/wenyanliu/");
            copyDirectoryFiles("./3d_qiege/", "C:/pic/SWWYL_3d/", true );
//            copyDirectoryFiles("./flash/", "C:/pic/SWWYL_2d/", true );


            QDir::setCurrent(root_path);
        }
        break;
    default:
        break;
    }

}

void SelectFile::on_pushButton_4_clicked()
{

    mw->elapsed_time=0;
    if(!mw->elapsed_timer->isActive()){
        mw->elapsed_timer->start(1000);
    }

    QString inFile;
    QString outPath;
    QString deepFile;




    // ��ֹfilewatcher��ɾ��������ͼƬʱ����2��
    m_first_change = true;

    switch (m_pt) {
    case SWWYL:
        // TODO  write config file and call ��ά������ program.
        callSWWYL();

        break;
    case HYFM:

        // Write config file and call ������� program.

        inFile = ui->lineEdit->text();
        outPath = ui->lineEdit_3->text();
        if(inFile.isEmpty() || outPath.isEmpty()){
            QMessageBox::warning(0,"Warning",QStringLiteral("��ѡ�������ļ������·��"),QMessageBox::Yes);//�鿴·��
        }else {
            //����loading������
            loadMovie->start();
            ui->label_5->show();

            // ���ԭ�ļ��������û�ѡ����ļ�����������Ŀ¼����������
            QFile::remove(root_path+"/yubao/hyfm/ocean_his_4750.nc");
            QFile::remove(root_path+"/yubao/hyfm/pic/1.jpg");
//            QMessageBox::warning(0,"PATH",path+"/yubao/hyfm/ocean_his_4750.nc",QMessageBox::Yes);
            QFile::copy(inFile, root_path+"/yubao/hyfm/ocean_his_4750.nc");

            //m_fsw->removePaths(m_fsw->directories());
            m_outPath = outPath;
            m_fsw->addPath( root_path+"/yubao/hyfm/pic/");

            // ���ú���������
            QDir::setCurrent(root_path+"/yubao/hyfm/");
            QProcess::startDetached("frontdetect_example.exe");
//            QProcess::execute("frontdetect_example.exe");

            // ��ԭϵͳ·��
            QDir::setCurrent(root_path);

        }

        break;
    case ZCDW:

        // TODO write config file and call �г߶��� program.
        break;
    case WYC:

        // TODO write config file and call ��Ծ�� program.
        break;
    default:
        break;
    }
}

void SelectFile::callSWWYL()
{

    QString inFile;
    QString inFile_2d;
    QString outPath;
    QDir dir(root_path+"/yubao/wenyanliu/3d_pic/");
    QFileInfoList list;
    QFile file_init("initial.txt");
    QTextStream fileOut(&file_init);


    inFile = ui->lineEdit->text();
    outPath = ui->lineEdit_3->text();

    QFileInfo fi(inFile);

    if(inFile.isEmpty() || outPath.isEmpty()){
        QMessageBox::warning(0,"Warning",QStringLiteral("��ѡ�������ļ������·��"),QMessageBox::Yes);//�鿴·��
    }else {

        file_date = fi.fileName().mid(12,8);
        qDebug() << file_date << "1111111";
//        return;
        //����loading������
        loadMovie->start();
        ui->label_5->show();

        // ���ԭ�ļ��������û�ѡ����ļ�����������Ŀ¼����������
//        QFile::remove(root_path+"/yubao/wenyanliu/ocean_his_4750.nc");

        list = dir.entryInfoList();
        for(int i=0; i<list.size(); i++)
        {
//            QMessageBox::warning(0,"PATH",list.at(i).filePath(),QMessageBox::Yes);
            QFile::remove(list.at(i).filePath());
        }

//        dir = QDir("C:/pic/SWWYL_3d");
//        list = dir.entryInfoList();
//        for(int i=0; i<list.size(); i++)
//        {
////            QMessageBox::warning(0,"PATH",list.at(i).filePath(),QMessageBox::Yes);
//            QFile::remove(list.at(i).filePath());
//        }

//        dir = QDir("C:/pic/SWWYL_2d");
//        list = dir.entryInfoList();
//        for(int i=0; i<list.size(); i++)
//        {
////            QMessageBox::warning(0,"PATH",list.at(i).filePath(),QMessageBox::Yes);
//            QFile::remove(list.at(i).filePath());
//        }

        copyFileToPath(inFile, root_path+"/yubao/wenyanliu/",true);
        inFile_2d = fi.absolutePath()+"/2d/ecs_new_"+file_date+".nc";
        qDebug() << inFile_2d;
        copyFileToPath(inFile_2d, root_path+"/yubao/wenyanliu/",true);


        //m_fsw->removePaths(m_fsw->directories());
        m_outPath = outPath;
        m_fsw->addPath( root_path+"/yubao/wenyanliu/3d_pic/");

        // д�����ļ� initial1.txt ���ó���
        qDebug() << root_path;
        QDir::setCurrent(root_path+"/yubao/wenyanliu/");

        file_init.open(QIODevice::WriteOnly);
        fileOut << file_date << "\n";
        file_init.close();

        QProcess::startDetached("swwyl.exe");
//            QProcess::execute("swwyl.exe");

        // ��ԭϵͳ·��
        QDir::setCurrent(root_path);

    }
}


void SelectFile::stop_loading()
{
    ui->label_5->hide();
    loadMovie->stop();

    mw->elapsed_time=0;
    if(mw->elapsed_timer->isActive()){
        mw->elapsed_timer->stop();
    }
}

void SelectFile::on_pushButton_clicked()
{
    stop_loading();
    QString fileName = QFileDialog::getOpenFileName(this, "open file", " ",  "Allfile(*.*);;ncfile(*.nc)");
    ui->lineEdit->setText(fileName);
}

void SelectFile::on_pushButton_2_clicked()
{
    stop_loading();
    QString fileName = QFileDialog::getOpenFileName(this, "open file", " ",  "Allfile(*.*);;ncfile(*.nc)");
    ui->lineEdit_2->setText(fileName);
}

void SelectFile::on_pushButton_3_clicked()
{
    stop_loading();
    QString output_path = QFileDialog::getExistingDirectory();
    ui->lineEdit_3->setText(output_path);
}
void SelectFile::showFlash()
{
    if(this->width()<763)
    {
        currentHeight += 10;
        this->resize(currentHeight , 429);
    }
    else
    {
        this->resize(763,429);
        timer_Expand->stop();
    }
}

void SelectFile::on_pushButton_5_clicked()
{
    //������ʧ������������
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(400);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
}

void  SelectFile::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseMovePos != QPoint(0, 0))
    {
        move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
        mouseMovePos = event->globalPos();
    }
}

void SelectFile::mousePressEvent(QMouseEvent *event)
{
    mouseMovePos = event->globalPos();

}
void SelectFile::mouseReleaseEvent(QMouseEvent *event)
{
    mouseMovePos = QPoint(0, 0);

}
