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
    QPixmap mask(":/Images/images/ui_selectfile.png");//加载掩码图像
    setMask(QBitmap(mask.mask())); //设置窗体的掩码图像,抠除图像的白色区域实现不规则窗体
    QPalette p;//设置调色板
    p.setBrush(QPalette::Window, QBrush(mask));//将调色板的画刷设置为掩码位图,在不规则窗体上显示出掩码位图
    setPalette(p);

    //添加渐变动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity"); //动画对象类型：渐变
    animation->setDuration(1000); //维持1秒
    animation->setStartValue(0);  //起始α值
    animation->setEndValue(1);    //结束α值
    animation->start();           //动画开始

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
        ui->label_4->setText(QStringLiteral("请选择三维温盐流的输入文件和输出路径"));

        ui->label_2->hide();
        ui->lineEdit_2->hide();
        ui->pushButton_2->hide();

        break;
    case HYFM:

        ui->label_4->setText(QStringLiteral("请选择海洋锋面的输入文件和输出路径"));

        ui->label_2->hide();
        ui->lineEdit_2->hide();
        ui->pushButton_2->hide();

        break;
    case ZCDW:

        ui->label_4->setText(QStringLiteral("请选择中尺度涡的输入文件和输出路径"));
        break;
    case WYC:

        ui->label_4->setText(QStringLiteral("请选择温跃层的输入文件和输出路径"));
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
    if(!targetDir.exists()){    /**< 如果目标目录不存在，则进行创建 */
        if(!targetDir.mkdir(targetDir.absolutePath()))
            return false;
    }

    QFileInfoList fileInfoList = sourceDir.entryInfoList();
    foreach(QFileInfo fileInfo, fileInfoList){
        if(fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            continue;

        if(fileInfo.isDir()){    /**< 当为目录时，递归的进行copy */
            if(!copyDirectoryFiles(fileInfo.filePath(),
                                   targetDir.filePath(fileInfo.fileName()),
                                   coverFileIfExist))
                return false;
        }
        else{            /**< 当允许覆盖操作时，将旧文件进行删除操作 */
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

            /// 进行文件copy
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

    // 复制结果文件到程序用户选择的输出目录
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




    // 防止filewatcher在删除和生成图片时弹出2次
    m_first_change = true;

    switch (m_pt) {
    case SWWYL:
        // TODO  write config file and call 三维温盐流 program.
        callSWWYL();

        break;
    case HYFM:

        // Write config file and call 海洋锋面 program.

        inFile = ui->lineEdit->text();
        outPath = ui->lineEdit_3->text();
        if(inFile.isEmpty() || outPath.isEmpty()){
            QMessageBox::warning(0,"Warning",QStringLiteral("请选择输入文件和输出路径"),QMessageBox::Yes);//查看路径
        }else {
            //载入loading…动画
            loadMovie->start();
            ui->label_5->show();

            // 清空原文件，复制用户选择的文件到程序运行目录，并重命名
            QFile::remove(root_path+"/yubao/hyfm/ocean_his_4750.nc");
            QFile::remove(root_path+"/yubao/hyfm/pic/1.jpg");
//            QMessageBox::warning(0,"PATH",path+"/yubao/hyfm/ocean_his_4750.nc",QMessageBox::Yes);
            QFile::copy(inFile, root_path+"/yubao/hyfm/ocean_his_4750.nc");

            //m_fsw->removePaths(m_fsw->directories());
            m_outPath = outPath;
            m_fsw->addPath( root_path+"/yubao/hyfm/pic/");

            // 调用海洋锋面程序
            QDir::setCurrent(root_path+"/yubao/hyfm/");
            QProcess::startDetached("frontdetect_example.exe");
//            QProcess::execute("frontdetect_example.exe");

            // 还原系统路径
            QDir::setCurrent(root_path);

        }

        break;
    case ZCDW:

        // TODO write config file and call 中尺度涡 program.
        break;
    case WYC:

        // TODO write config file and call 温跃层 program.
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
        QMessageBox::warning(0,"Warning",QStringLiteral("请选择输入文件和输出路径"),QMessageBox::Yes);//查看路径
    }else {

        file_date = fi.fileName().mid(12,8);
        qDebug() << file_date << "1111111";
//        return;
        //载入loading…动画
        loadMovie->start();
        ui->label_5->show();

        // 清空原文件，复制用户选择的文件到程序运行目录，并重命名
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

        // 写配置文件 initial1.txt 调用程序
        qDebug() << root_path;
        QDir::setCurrent(root_path+"/yubao/wenyanliu/");

        file_init.open(QIODevice::WriteOnly);
        fileOut << file_date << "\n";
        file_init.close();

        QProcess::startDetached("swwyl.exe");
//            QProcess::execute("swwyl.exe");

        // 还原系统路径
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
    //界面消失动画——渐隐
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
