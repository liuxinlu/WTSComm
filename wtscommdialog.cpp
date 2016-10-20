#include "wtscommdialog.h"
#include "ui_wtscommdialog.h"

WTSCommDialog::WTSCommDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WTSCommDialog)
{
    ui->setupUi(this);
    ui->tab->installEventFilter(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            ui->comboBox_CommPort->addItem(info.portName());
//                ui->textBrowserRecvText->append(tr("检测到端口列表:"));
//                ui->textBrowserRecvText->append(info.portName());
//                ui->textBrowserRecvText->append(info.description());
//                ui->textBrowserRecvText->append(info.manufacturer());
            serial.close();
        }
    }
    WTS_SerialPort= new QSerialPort();
    ui->pushButton_CloseComm->setEnabled(false);
    ui->comboBox_CommBaud->setCurrentIndex(2);//默认19200
    InitMainDlgItem();
    update();
    QPixmap pixmap(":/image/image/diconnect.png");
    QPixmap fitpixmap=pixmap.scaled(ui->label_ReaderStatus->width(), ui->label_ReaderStatus->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label_ReaderStatus->setPixmap(fitpixmap);
    ui->label_ReaderStatus->show();
    InitSystemParm();
    connect(ui->comboBox_ReaderID,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_ReaderID_currentIndexChanged(int)));

    int size=11;
    ui->label_Ant1Sensor01Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor01Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor01Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor02Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor02Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor02Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor03Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor03Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor03Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor04Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor04Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor04Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor05Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor05Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor05Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor06Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor06Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor06Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor07Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor07Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor07Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor08Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor08Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor08Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor09Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor09Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor09Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor10Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor10Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor10Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor11Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor11Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor11Temp->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor12Freq->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor12Power->setFont(QFont("Timers" , size));
    ui->label_Ant1Sensor12Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor01Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor01Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor01Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor02Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor02Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor02Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor03Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor03Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor03Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor04Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor04Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor04Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor05Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor05Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor05Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor06Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor06Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor06Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor07Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor07Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor07Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor08Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor08Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor08Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor09Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor09Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor09Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor10Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor10Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor10Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor11Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor11Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor11Temp->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor12Freq->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor12Power->setFont(QFont("Timers" , size));
    ui->label_Ant2Sensor12Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor01Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor01Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor01Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor02Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor02Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor02Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor03Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor03Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor03Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor04Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor04Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor04Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor05Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor05Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor05Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor06Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor06Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor06Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor07Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor07Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor07Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor08Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor08Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor08Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor09Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor09Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor09Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor10Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor10Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor10Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor11Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor11Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor11Temp->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor12Freq->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor12Power->setFont(QFont("Timers" , size));
    ui->label_Ant3Sensor12Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor01Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor01Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor01Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor02Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor02Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor02Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor03Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor03Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor03Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor04Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor04Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor04Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor05Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor05Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor05Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor06Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor06Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor06Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor07Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor07Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor07Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor08Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor08Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor08Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor09Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor09Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor09Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor10Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor10Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor10Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor11Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor11Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor11Temp->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor12Freq->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor12Power->setFont(QFont("Timers" , size));
    ui->label_Ant4Sensor12Temp->setFont(QFont("Timers" , size));
}

WTSCommDialog::~WTSCommDialog()
{
    delete ui;
}

bool WTSCommDialog::eventFilter(QObject *obj, QEvent *e)
{
    if(obj == ui->tab)
    {
        if(e->type() == QEvent::Paint)
        {
            QPainter p(ui->tab);
            p.drawLine(4,24,1000,24);
            p.drawLine(4,150,1000,150);
            p.drawLine(4,274,1000,274);
            p.drawLine(4,399,1000,399);

            p.drawLine(79,4,79,518);
            p.drawLine(140,4,140,518);
            p.drawLine(210,4,210,518);
            p.drawLine(280,4,280,518);
            p.drawLine(350,4,350,518);
            p.drawLine(420-1,4,420-1,518);
            p.drawLine(490-1,4,490-1,518);
            p.drawLine(560-2,4,560-2,518);
            p.drawLine(630-2,4,630-2,518);
            p.drawLine(700-3,4,700-3,518);
            p.drawLine(770-3,4,770-3,518);
            p.drawLine(840-3,4,840-3,518);
            p.drawLine(910-4,4,910-4,518);
            return true;
        }
    }
//    return WTSCommDialog::eventFilter(obj,e);
}

void WTSCommDialog::InitSystemParm()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            iSensorSet[i][j]=0;
            iSensorRead[i][j]=0;
            iRFReadData[i][j]=0;
            iRFSetData[i][j]=0;
        }
    }
    bSendStopCMDRequestTimeout=false;

    bSendStopCMDRequest=false;

    iSendPackageCount=0;

    iRecvPackageCount=0;

    ReceiveDataCount=0;

    CommOpenFlag=false;

    bRecvReaderStatusFlag=false;

    FlagForDebugButton=true;

    FlagForGetTempButton=true;

    SetReaderIDCheckStatusFlag=false;//true is checking,false is check over

    singleShotFlag=true;//true is can be start ,false is stop timer

    ui->lineEdit_ParmFileName->setText("Config"+QDateTime::currentDateTime().toString("yyyy-MM-dd"));

    StatusSensor1_1="0";
    StatusSensor1_2="0";
    StatusSensor1_3="0";
    StatusSensor1_4="0";
    StatusSensor1_5="0";
    StatusSensor1_6="0";
    StatusSensor1_7="0";
    StatusSensor1_8="0";
    StatusSensor1_9="0";
    StatusSensor1_10="0";
    StatusSensor1_11="0";
    StatusSensor1_12="0";
    StatusSensor2_1="0";
    StatusSensor2_2="0";
    StatusSensor2_3="0";
    StatusSensor2_4="0";
    StatusSensor2_5="0";
    StatusSensor2_6="0";
    StatusSensor2_7="0";
    StatusSensor2_8="0";
    StatusSensor2_9="0";
    StatusSensor2_10="0";
    StatusSensor2_11="0";
    StatusSensor2_12="0";
    StatusSensor3_1="0";
    StatusSensor3_2="0";
    StatusSensor3_3="0";
    StatusSensor3_4="0";
    StatusSensor3_5="0";
    StatusSensor3_6="0";
    StatusSensor3_7="0";
    StatusSensor3_8="0";
    StatusSensor3_9="0";
    StatusSensor3_10="0";
    StatusSensor3_11="0";
    StatusSensor3_12="0";
    StatusSensor4_1="0";
    StatusSensor4_2="0";
    StatusSensor4_3="0";
    StatusSensor4_4="0";
    StatusSensor4_5="0";
    StatusSensor4_6="0";
    StatusSensor4_7="0";
    StatusSensor4_8="0";
    StatusSensor4_9="0";
    StatusSensor4_10="0";
    StatusSensor4_11="0";
    StatusSensor4_12="0";
}

void WTSCommDialog::InitMainDlgItem()
{
    ui->label_Ant1Sensor01Freq->clear();
    ui->label_Ant1Sensor02Freq->clear();
    ui->label_Ant1Sensor03Freq->clear();
    ui->label_Ant1Sensor04Freq->clear();
    ui->label_Ant1Sensor05Freq->clear();
    ui->label_Ant1Sensor06Freq->clear();
    ui->label_Ant1Sensor07Freq->clear();
    ui->label_Ant1Sensor08Freq->clear();
    ui->label_Ant1Sensor09Freq->clear();
    ui->label_Ant1Sensor10Freq->clear();
    ui->label_Ant1Sensor11Freq->clear();
    ui->label_Ant1Sensor12Freq->clear();
    ui->label_Ant2Sensor01Freq->clear();
    ui->label_Ant2Sensor02Freq->clear();
    ui->label_Ant2Sensor03Freq->clear();
    ui->label_Ant2Sensor04Freq->clear();
    ui->label_Ant2Sensor05Freq->clear();
    ui->label_Ant2Sensor06Freq->clear();
    ui->label_Ant2Sensor07Freq->clear();
    ui->label_Ant2Sensor08Freq->clear();
    ui->label_Ant2Sensor09Freq->clear();
    ui->label_Ant2Sensor10Freq->clear();
    ui->label_Ant2Sensor11Freq->clear();
    ui->label_Ant2Sensor12Freq->clear();
    ui->label_Ant3Sensor01Freq->clear();
    ui->label_Ant3Sensor02Freq->clear();
    ui->label_Ant3Sensor03Freq->clear();
    ui->label_Ant3Sensor04Freq->clear();
    ui->label_Ant3Sensor05Freq->clear();
    ui->label_Ant3Sensor06Freq->clear();
    ui->label_Ant3Sensor07Freq->clear();
    ui->label_Ant3Sensor08Freq->clear();
    ui->label_Ant3Sensor09Freq->clear();
    ui->label_Ant3Sensor10Freq->clear();
    ui->label_Ant3Sensor11Freq->clear();
    ui->label_Ant3Sensor12Freq->clear();
    ui->label_Ant4Sensor01Freq->clear();
    ui->label_Ant4Sensor02Freq->clear();
    ui->label_Ant4Sensor03Freq->clear();
    ui->label_Ant4Sensor04Freq->clear();
    ui->label_Ant4Sensor05Freq->clear();
    ui->label_Ant4Sensor06Freq->clear();
    ui->label_Ant4Sensor07Freq->clear();
    ui->label_Ant4Sensor08Freq->clear();
    ui->label_Ant4Sensor09Freq->clear();
    ui->label_Ant4Sensor10Freq->clear();
    ui->label_Ant4Sensor11Freq->clear();
    ui->label_Ant4Sensor12Freq->clear();
    ui->label_Ant1Sensor01Power->clear();
    ui->label_Ant1Sensor02Power->clear();
    ui->label_Ant1Sensor03Power->clear();
    ui->label_Ant1Sensor04Power->clear();
    ui->label_Ant1Sensor05Power->clear();
    ui->label_Ant1Sensor06Power->clear();
    ui->label_Ant1Sensor07Power->clear();
    ui->label_Ant1Sensor08Power->clear();
    ui->label_Ant1Sensor09Power->clear();
    ui->label_Ant1Sensor10Power->clear();
    ui->label_Ant1Sensor11Power->clear();
    ui->label_Ant1Sensor12Power->clear();
    ui->label_Ant2Sensor01Power->clear();
    ui->label_Ant2Sensor02Power->clear();
    ui->label_Ant2Sensor03Power->clear();
    ui->label_Ant2Sensor04Power->clear();
    ui->label_Ant2Sensor05Power->clear();
    ui->label_Ant2Sensor06Power->clear();
    ui->label_Ant2Sensor07Power->clear();
    ui->label_Ant2Sensor08Power->clear();
    ui->label_Ant2Sensor09Power->clear();
    ui->label_Ant2Sensor10Power->clear();
    ui->label_Ant2Sensor11Power->clear();
    ui->label_Ant2Sensor12Power->clear();
    ui->label_Ant3Sensor01Power->clear();
    ui->label_Ant3Sensor02Power->clear();
    ui->label_Ant3Sensor03Power->clear();
    ui->label_Ant3Sensor04Power->clear();
    ui->label_Ant3Sensor05Power->clear();
    ui->label_Ant3Sensor06Power->clear();
    ui->label_Ant3Sensor07Power->clear();
    ui->label_Ant3Sensor08Power->clear();
    ui->label_Ant3Sensor09Power->clear();
    ui->label_Ant3Sensor10Power->clear();
    ui->label_Ant3Sensor11Power->clear();
    ui->label_Ant3Sensor12Power->clear();
    ui->label_Ant4Sensor01Power->clear();
    ui->label_Ant4Sensor02Power->clear();
    ui->label_Ant4Sensor03Power->clear();
    ui->label_Ant4Sensor04Power->clear();
    ui->label_Ant4Sensor05Power->clear();
    ui->label_Ant4Sensor06Power->clear();
    ui->label_Ant4Sensor07Power->clear();
    ui->label_Ant4Sensor08Power->clear();
    ui->label_Ant4Sensor09Power->clear();
    ui->label_Ant4Sensor10Power->clear();
    ui->label_Ant4Sensor11Power->clear();
    ui->label_Ant4Sensor12Power->clear();
    ui->label_Ant1Sensor01Temp->clear();
    ui->label_Ant1Sensor02Temp->clear();
    ui->label_Ant1Sensor03Temp->clear();
    ui->label_Ant1Sensor04Temp->clear();
    ui->label_Ant1Sensor05Temp->clear();
    ui->label_Ant1Sensor06Temp->clear();
    ui->label_Ant1Sensor07Temp->clear();
    ui->label_Ant1Sensor08Temp->clear();
    ui->label_Ant1Sensor09Temp->clear();
    ui->label_Ant1Sensor10Temp->clear();
    ui->label_Ant1Sensor11Temp->clear();
    ui->label_Ant1Sensor12Temp->clear();
    ui->label_Ant2Sensor01Temp->clear();
    ui->label_Ant2Sensor02Temp->clear();
    ui->label_Ant2Sensor03Temp->clear();
    ui->label_Ant2Sensor04Temp->clear();
    ui->label_Ant2Sensor05Temp->clear();
    ui->label_Ant2Sensor06Temp->clear();
    ui->label_Ant2Sensor07Temp->clear();
    ui->label_Ant2Sensor08Temp->clear();
    ui->label_Ant2Sensor09Temp->clear();
    ui->label_Ant2Sensor10Temp->clear();
    ui->label_Ant2Sensor11Temp->clear();
    ui->label_Ant2Sensor12Temp->clear();
    ui->label_Ant3Sensor01Temp->clear();
    ui->label_Ant3Sensor02Temp->clear();
    ui->label_Ant3Sensor03Temp->clear();
    ui->label_Ant3Sensor04Temp->clear();
    ui->label_Ant3Sensor05Temp->clear();
    ui->label_Ant3Sensor06Temp->clear();
    ui->label_Ant3Sensor07Temp->clear();
    ui->label_Ant3Sensor08Temp->clear();
    ui->label_Ant3Sensor09Temp->clear();
    ui->label_Ant3Sensor10Temp->clear();
    ui->label_Ant3Sensor11Temp->clear();
    ui->label_Ant3Sensor12Temp->clear();
    ui->label_Ant4Sensor01Temp->clear();
    ui->label_Ant4Sensor02Temp->clear();
    ui->label_Ant4Sensor03Temp->clear();
    ui->label_Ant4Sensor04Temp->clear();
    ui->label_Ant4Sensor05Temp->clear();
    ui->label_Ant4Sensor06Temp->clear();
    ui->label_Ant4Sensor07Temp->clear();
    ui->label_Ant4Sensor08Temp->clear();
    ui->label_Ant4Sensor09Temp->clear();
    ui->label_Ant4Sensor10Temp->clear();
    ui->label_Ant4Sensor11Temp->clear();
    ui->label_Ant4Sensor12Temp->clear();
}

unsigned char WTSCommDialog::GetReaderID(unsigned char High, unsigned char Low)
{
    unsigned char IDHigh,IDLow;
    if(High>0x60)
    {
        IDHigh=High-0x61+10;
    }
    else if(High>0x40&&High<0x60)
    {
        IDHigh=High-0x41+10;
    }
    else
    {
        IDHigh=High-0x30;
    }
    if(Low>0x60)
    {
        IDLow=Low-0x61+10;
    }
    else if(Low>0x40&&Low<0x60)
    {
        IDLow=Low-0x41+10;
    }
    else
    {
        IDLow=Low-0x30;
    }

    return (IDHigh*16+IDLow);
}


QString WTSCommDialog::ReaderID_Int2CString(int nIndex)
{
    switch (nIndex)
    {
    case 0:
        return "01";
        break;
    case 1:
        return "02";
        break;
    case 2:
        return "03";
        break;
    case 3:
        return "04";
        break;
    case 4:
        return "05";
        break;
    case 5:
        return "06";
        break;
    case 6:
        return "07";
        break;
    case 7:
        return "08";
        break;
    case 8:
        return "09";
        break;
    case 9:
        return "0a";
        break;
    case 10:
        return "0b";
        break;
    case 11:
        return "0c";
        break;
    case 12:
        return "0d";
        break;
    case 13:
        return "0e";
        break;
    case 14:
        return "0f";
        break;
    case 15:
        return "10";
        break;
    case 16:
        return "11";
        break;
    case 17:
        return "12";
        break;
    case 18:
        return "13";
        break;
    case 19:
        return "14";
        break;
    case 20:
        return "15";
        break;
    case 21:
        return "16";
        break;
    case 22:
        return "17";
        break;
    case 23:
        return "18";
        break;
    case 24:
        return "19";
        break;
    case 25:
        return "1a";
        break;
    case 26:
        return "1b";
        break;
    case 27:
        return "1c";
        break;
    case 28:
        return "1d";
        break;
    case 29:
        return "1e";
        break;
    case 30:
        return "1f";
        break;
    case 31:
        return "20";
        break;
    case 32:
        return "21";
        break;
    case 33:
        return "22";
        break;
    case 34:
        return "23";
        break;
    case 35:
        return "24";
        break;
    case 36:
        return "25";
        break;
    case 37:
        return "26";
        break;
    case 38:
        return "27";
        break;
    case 39:
        return "28";
        break;
    case 40:
        return "29";
        break;
    case 41:
        return "2a";
        break;
    case 42:
        return "2b";
        break;
    default:
        return "+";
        break;
    }
}

/************************************************************************/
/* LRC校验计算                                                          */
/*输入除起始、结束、LRC校验外的数据进行计算                             */
/************************************************************************/
unsigned char WTSCommDialog::LRC_Calculate(unsigned char * auchMsg, unsigned short usDataLen)
{
    unsigned char uchLRC = 0 ;	/* LRC char initialized   */
    for(int i=0;i<usDataLen;i++)
    {
        if(auchMsg[i]>0x60)
        {
            LrcDataArray[i]=auchMsg[i]-0x61+10;
        }
        else if(auchMsg[i]>0x40&&auchMsg[i]<0x60)
        {
            LrcDataArray[i]=auchMsg[i]-0x41+10;
        }
        else if (auchMsg[i]>=0x30)
        {
            LrcDataArray[i]=auchMsg[i]-0x30;
        }
        else
        {
            LrcDataArray[i]=auchMsg[i]&0x0f;
        }
    }
    for(int i=0;i<usDataLen/2;i++)
    {
        uchLRC+=(LrcDataArray[2*i]*16+LrcDataArray[2*i+1]);
    }
    return ((unsigned char)(-((char)uchLRC))) ;
}
QString WTSCommDialog::LRC_Calculate(QString auchMsg)
{
//    unsigned char CharCmd[10]={0};
    unsigned char ch[2]={0};
    unsigned char*  CharCmd;
    QByteArray ba = auchMsg.toLatin1();
    CharCmd=(unsigned char*)ba.data();
    if ((LRC_Calculate(CharCmd,10)&0x0f)>0x09)
    {
        ch[1]=(LRC_Calculate(CharCmd,10)&0x0f)+0x61-10;
    }
    else
    {
        ch[1]=(LRC_Calculate(CharCmd,10)&0x0f)+0x30;
    }
    if (((LRC_Calculate(CharCmd,10)&0xf0)>>4)>0x09)
    {
        ch[0]=((LRC_Calculate(CharCmd,10)&0xf0)>>4)+0x61-10;
    }
    else
    {
        ch[0]=((LRC_Calculate(CharCmd,10)&0xf0)>>4)+0x30;
    }
    QString StrLRC="";
    StrLRC+=ch[0];
    StrLRC+=ch[1];
    return StrLRC;
}
bool WTSCommDialog::LRC_Check(unsigned char RecLRCHigh,unsigned char RecLRCLow,unsigned char LRC_Calculate)
{
    unsigned char RecLRC=0;
    if(RecLRCLow>0x60)
        RecLRC=RecLRCLow-0x61+10;
    else if(RecLRCLow>0x40&&RecLRCLow<0x60)
        RecLRC=RecLRCLow-0x41+10;
    else if(RecLRCLow>=0x30)
        RecLRC=RecLRCLow-0x30;
    else RecLRC=RecLRCLow&0x0f;

    if(RecLRCHigh>0x60)
        RecLRC=(RecLRCHigh-0x61+10)*16+RecLRC;
    else if(RecLRCHigh>0x40&&RecLRCHigh<0x60)
        RecLRC=(RecLRCHigh-0x41+10)*16+RecLRC;
    else if(RecLRCHigh>=0x30)
        RecLRC=(RecLRCHigh-0x30)*16+RecLRC;
    else RecLRC=(RecLRCHigh&0x0f)*16+RecLRC;

    if (RecLRC==LRC_Calculate)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void WTSCommDialog::WTS_ReadUart()
{
    QString cmd;
    QString temper,power,frequence;

    BufferData = WTS_SerialPort->readAll();
    //异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
    if ((!BufferData.contains(":"))&(PasteData.isNull()))
    {
        return;
    }
    //第一种：有头无尾，先清空原有内容，再附加
    if ((BufferData.contains(":"))&(!BufferData.contains("\n")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
    }
    //第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
    if ((!BufferData.contains(":"))&(!BufferData.contains("\n"))&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
    }
    //第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
    if ((!BufferData.contains(":"))&(BufferData.contains("\n"))&(!PasteData.isNull()))
    {
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();

        //接收到的字节数以初始的bytes为依据
        ReceiveDataCount=ReadData.size();
        rxdata=(unsigned char*)ReadData.data();
        if (ReceiveDataCount==15)//15字节数据包
        {
            unsigned char data[10]={0};
            for (int i=0;i<10;i++)
            {
                data[i]=rxdata[i+1];
            }
            if (LRC_Check(rxdata[11],rxdata[12],LRC_Calculate(data,10)))
            {
                iRecvPackageCount++;
                ui->label_RecvPackage->setText("接收包："+QString::number(iRecvPackageCount,10));
                if (rxdata[3]=='4'&&rxdata[4]=='4')//收到传感器使能ACK
                {
    //                m_MSComm.SetOutput(COleVariant(LastSendCmd));
    //                LastSendCmd.FreeExtra();
    //                LastSendCmd.Empty();
    //                m_MSComm.SetInBufferCount(0);
                }else if (rxdata[3]=='6'&&rxdata[4]=='6')//收到读取器状态信息包
                {
                    bRecvReaderStatusFlag=true;
                    ShowReaderStatus(rxdata[5]);
                }
            }
            else
            {
                cmd+=rxdata[1];
                cmd+=rxdata[2];
                cmd=cmd+"44444444";
                cmd=":"+cmd+(LRC_Calculate(cmd)).left(2)+"\r\n";
                WTS_SerialPort->write(cmd.toLatin1());
                iSendPackageCount++;
                ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
            }
            ReceiveDataCount=0;
        }else if (ReceiveDataCount==45)//45字节数据包
        {
            unsigned char data[40]={0};
            for (int i=0;i<40;i++)
            {
                data[i]=rxdata[i+1];
            }
            if (LRC_Check(rxdata[41],rxdata[42],LRC_Calculate(data,40)))//
            {
                iRecvPackageCount++;
                ui->label_RecvPackage->setText("接收包："+QString::number(iRecvPackageCount,10));
                if (rxdata[3]=='6'&&rxdata[4]=='5')//收到--衰减读取数据包
                {
                    for (int i = 0; i < 12; i++)
                    {
                        iRFReadData[rxdata[5]-0x30][i]=(rxdata[2*i+6]<0x60?(rxdata[2*i+6]-0x30):(rxdata[2*i+6]-0x57))*0x10+(rxdata[2*i+7]<0x60?(rxdata[2*i+7]-0x30):(rxdata[2*i+7]-0x57));
                    }
                    ShowLossData(rxdata[5],iRFReadData);
                }else if (rxdata[3]=='6'&&rxdata[4]=='3')//收到端口使能数据包
                {
                    for(int i=0;i<12;i++)
                    {
                        iSensorRead[rxdata[5]-0x30][i]=rxdata[6+i]-0x30;
                    }
                    SetSensorStatus(rxdata[5],rxdata[6],rxdata[7],rxdata[8],rxdata[9],rxdata[10],rxdata[11],rxdata[12],rxdata[13],rxdata[14],rxdata[15],rxdata[16],rxdata[17]);
                }else if (rxdata[3]=='0'&&rxdata[4]=='1')//收到调试校准数据包
                {
                    if(bSendStopCMDRequest)
                    {
                        bSendStopCMDRequest=false;
                        bSendStopCMDRequestTimeout=false;
                        SendCMDByReader(ui->comboBox_ReaderID->currentIndex(),"54");//stop
                    }
                    bool ok;
                    if(rxdata[11]=='.')
                    {
                        //收功率数据，并转换
                        for(int i=13;i<17;i++)
                        {
                            power+=rxdata[i];
                        }
                        Power_Data=power.toUInt(&ok,16);
                        //收频率数据，并转换
                        for(int i=17;i<25;i++)
                        {
                            frequence+=rxdata[i];
                        }
                        Freq_Data=frequence.toUInt(&ok,16);
                        //收温度数据并转换
                        for(int i=8;i<11;i++)
                        {
                            temper+=rxdata[i];
                        }
                        temper+=rxdata[12];
                        Temper_Data=(float)temper.toUInt(&ok,16);
                        Temper_Data=Temper_Data/16.0;
                        switch(rxdata[7])
                        {
                        case '-':
                            Temper_Data=-Temper_Data;
                            break;
                        default:
                            break;
                        }
                        switch (rxdata[6])
                        {
                        case '0':
                            Ant1DataFix(rxdata[5],Temper_Data,Freq_Data,Power_Data);
                            break;
                        case '1':
                            Ant2DataFix(rxdata[5],Temper_Data,Freq_Data,Power_Data);
                            break;
                        case '2':
                            Ant3DataFix(rxdata[5],Temper_Data,Freq_Data,Power_Data);
                            break;
                        case '3':
                            Ant4DataFix(rxdata[5],Temper_Data,Freq_Data,Power_Data);
                            break;
                        default:
                            break;
                        }
                        temper.clear(); //清空内容
                        frequence.clear(); //清空内容
                        power.clear(); //清空内容
                    }//if(bt=='a'&&rxdata[9]=='b')
                    ReceiveDataCount=0;
                }
            }
            else
            {
                cmd+=rxdata[1];
                cmd+=rxdata[2];
                cmd=cmd+"44444444";
                cmd=":"+cmd+(LRC_Calculate(cmd)).left(2)+"\r\n";
                WTS_SerialPort->write(cmd.toLatin1());
                iSendPackageCount++;
                ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
            }
        }
        qDebug()<<ReadData;
    }
    //第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
    if ((BufferData.contains(":"))&(BufferData.contains("\n")))
    {
        PasteData.clear();
        PasteData.append(BufferData);
        ReadData = PasteData;
        PasteData.clear();
    }
}

void WTSCommDialog::Ant1DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData)
{
    int antNo=0;
    switch (SensorID)
    {
    case '0':
        m_FreqData[antNo][0]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor01Temp,ui->label_Ant1Sensor01Power,ui->label_Ant1Sensor01Freq);
        DataForDebug[antNo][0][0]=m_FreqData[antNo][0];
        DataForDebug[antNo][0][1]=GetPowerData;
        break;
    case '1':
        m_FreqData[antNo][1]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor02Temp,ui->label_Ant1Sensor02Power,ui->label_Ant1Sensor02Freq);
        DataForDebug[antNo][1][0]=m_FreqData[antNo][1];
        DataForDebug[antNo][1][1]=GetPowerData;
        break;
    case '2':
        m_FreqData[antNo][2]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor03Temp,ui->label_Ant1Sensor03Power,ui->label_Ant1Sensor03Freq);
        DataForDebug[antNo][2][0]=m_FreqData[antNo][2];
        DataForDebug[antNo][2][1]=GetPowerData;
        break;
    case '3':
        m_FreqData[antNo][3]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor04Temp,ui->label_Ant1Sensor04Power,ui->label_Ant1Sensor04Freq);
        DataForDebug[antNo][3][0]=m_FreqData[antNo][3];
        DataForDebug[antNo][3][1]=GetPowerData;
        break;
    case '4':
        m_FreqData[antNo][4]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor05Temp,ui->label_Ant1Sensor05Power,ui->label_Ant1Sensor05Freq);
        DataForDebug[antNo][4][0]=m_FreqData[antNo][4];
        DataForDebug[antNo][4][1]=GetPowerData;
        break;
    case '5':
        m_FreqData[antNo][5]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor06Temp,ui->label_Ant1Sensor06Power,ui->label_Ant1Sensor06Freq);
        DataForDebug[antNo][5][0]=m_FreqData[antNo][5];
        DataForDebug[antNo][5][1]=GetPowerData;
        break;
    case '6':
        m_FreqData[antNo][6]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor07Temp,ui->label_Ant1Sensor07Power,ui->label_Ant1Sensor07Freq);
        DataForDebug[antNo][6][0]=m_FreqData[antNo][6];
        DataForDebug[antNo][6][1]=GetPowerData;
        break;
    case '7':
        m_FreqData[antNo][7]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor08Temp,ui->label_Ant1Sensor08Power,ui->label_Ant1Sensor08Freq);
        DataForDebug[antNo][7][0]=m_FreqData[antNo][7];
        DataForDebug[antNo][7][1]=GetPowerData;
        break;
    case '8':
        m_FreqData[antNo][8]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor09Temp,ui->label_Ant1Sensor09Power,ui->label_Ant1Sensor09Freq);
        DataForDebug[antNo][8][0]=m_FreqData[antNo][8];
        DataForDebug[antNo][8][1]=GetPowerData;
        break;
    case '9':
        m_FreqData[antNo][9]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor10Temp,ui->label_Ant1Sensor10Power,ui->label_Ant1Sensor10Freq);
        DataForDebug[antNo][9][0]=m_FreqData[antNo][9];
        DataForDebug[antNo][9][1]=GetPowerData;
        break;
    case 'a':
        m_FreqData[antNo][10]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor11Temp,ui->label_Ant1Sensor11Power,ui->label_Ant1Sensor11Freq);
        DataForDebug[antNo][10][0]=m_FreqData[antNo][10];
        DataForDebug[antNo][10][1]=GetPowerData;
        break;
    case 'b':
        m_FreqData[antNo][11]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant1Sensor12Temp,ui->label_Ant1Sensor12Power,ui->label_Ant1Sensor12Freq);
        DataForDebug[antNo][11][0]=m_FreqData[antNo][11];
        DataForDebug[antNo][11][1]=GetPowerData;
        break;
    default:
        break;
    }
}

void WTSCommDialog::Ant2DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData)
{
    int antNo=1;
    switch (SensorID)
    {
    case '0':
        m_FreqData[antNo][0]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor01Temp,ui->label_Ant2Sensor01Power,ui->label_Ant2Sensor01Freq);
        DataForDebug[antNo][0][0]=m_FreqData[antNo][0];
        DataForDebug[antNo][0][1]=GetPowerData;
        break;
    case '1':
        m_FreqData[antNo][1]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor02Temp,ui->label_Ant2Sensor02Power,ui->label_Ant2Sensor02Freq);
        DataForDebug[antNo][1][0]=m_FreqData[antNo][1];
        DataForDebug[antNo][1][1]=GetPowerData;
        break;
    case '2':
        m_FreqData[antNo][2]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor03Temp,ui->label_Ant2Sensor03Power,ui->label_Ant2Sensor03Freq);
        DataForDebug[antNo][2][0]=m_FreqData[antNo][2];
        DataForDebug[antNo][2][1]=GetPowerData;
        break;
    case '3':
        m_FreqData[antNo][3]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor04Temp,ui->label_Ant2Sensor04Power,ui->label_Ant2Sensor04Freq);
        DataForDebug[antNo][3][0]=m_FreqData[antNo][3];
        DataForDebug[antNo][3][1]=GetPowerData;
        break;
    case '4':
        m_FreqData[antNo][4]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor05Temp,ui->label_Ant2Sensor05Power,ui->label_Ant2Sensor05Freq);
        DataForDebug[antNo][4][0]=m_FreqData[antNo][4];
        DataForDebug[antNo][4][1]=GetPowerData;
        break;
    case '5':
        m_FreqData[antNo][5]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor06Temp,ui->label_Ant2Sensor06Power,ui->label_Ant2Sensor06Freq);
        DataForDebug[antNo][5][0]=m_FreqData[antNo][5];
        DataForDebug[antNo][5][1]=GetPowerData;
        break;
    case '6':
        m_FreqData[antNo][6]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor07Temp,ui->label_Ant2Sensor07Power,ui->label_Ant2Sensor07Freq);
        DataForDebug[antNo][6][0]=m_FreqData[antNo][6];
        DataForDebug[antNo][6][1]=GetPowerData;
        break;
    case '7':
        m_FreqData[antNo][7]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor08Temp,ui->label_Ant2Sensor08Power,ui->label_Ant2Sensor08Freq);
        DataForDebug[antNo][7][0]=m_FreqData[antNo][7];
        DataForDebug[antNo][7][1]=GetPowerData;
        break;
    case '8':
        m_FreqData[antNo][8]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor09Temp,ui->label_Ant2Sensor09Power,ui->label_Ant2Sensor09Freq);
        DataForDebug[antNo][8][0]=m_FreqData[antNo][8];
        DataForDebug[antNo][8][1]=GetPowerData;
        break;
    case '9':
        m_FreqData[antNo][9]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor10Temp,ui->label_Ant2Sensor10Power,ui->label_Ant2Sensor10Freq);
        DataForDebug[antNo][9][0]=m_FreqData[antNo][9];
        DataForDebug[antNo][9][1]=GetPowerData;
        break;
    case 'a':
        m_FreqData[antNo][10]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor11Temp,ui->label_Ant2Sensor11Power,ui->label_Ant2Sensor11Freq);
        DataForDebug[antNo][10][0]=m_FreqData[antNo][10];
        DataForDebug[antNo][10][1]=GetPowerData;
        break;
    case 'b':
        m_FreqData[antNo][11]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant2Sensor12Temp,ui->label_Ant2Sensor12Power,ui->label_Ant2Sensor12Freq);
        DataForDebug[antNo][11][0]=m_FreqData[antNo][11];
        DataForDebug[antNo][11][1]=GetPowerData;
        break;
    default:
        break;
    }
}

void WTSCommDialog::Ant3DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData)
{
    int antNo=2;
    switch (SensorID)
    {
    case '0':
        m_FreqData[antNo][0]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor01Temp,ui->label_Ant3Sensor01Power,ui->label_Ant3Sensor01Freq);
        DataForDebug[antNo][0][0]=m_FreqData[antNo][0];
        DataForDebug[antNo][0][1]=GetPowerData;
        break;
    case '1':
        m_FreqData[antNo][1]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor02Temp,ui->label_Ant3Sensor02Power,ui->label_Ant3Sensor02Freq);
        DataForDebug[antNo][1][0]=m_FreqData[antNo][1];
        DataForDebug[antNo][1][1]=GetPowerData;
        break;
    case '2':
        m_FreqData[antNo][2]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor03Temp,ui->label_Ant3Sensor03Power,ui->label_Ant3Sensor03Freq);
        DataForDebug[antNo][2][0]=m_FreqData[antNo][2];
        DataForDebug[antNo][2][1]=GetPowerData;
        break;
    case '3':
        m_FreqData[antNo][3]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor04Temp,ui->label_Ant3Sensor04Power,ui->label_Ant3Sensor04Freq);
        DataForDebug[antNo][3][0]=m_FreqData[antNo][3];
        DataForDebug[antNo][3][1]=GetPowerData;
        break;
    case '4':
        m_FreqData[antNo][4]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor05Temp,ui->label_Ant3Sensor05Power,ui->label_Ant3Sensor05Freq);
        DataForDebug[antNo][4][0]=m_FreqData[antNo][4];
        DataForDebug[antNo][4][1]=GetPowerData;
        break;
    case '5':
        m_FreqData[antNo][5]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor06Temp,ui->label_Ant3Sensor06Power,ui->label_Ant3Sensor06Freq);
        DataForDebug[antNo][5][0]=m_FreqData[antNo][5];
        DataForDebug[antNo][5][1]=GetPowerData;
        break;
    case '6':
        m_FreqData[antNo][6]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor07Temp,ui->label_Ant3Sensor07Power,ui->label_Ant3Sensor07Freq);
        DataForDebug[antNo][6][0]=m_FreqData[antNo][6];
        DataForDebug[antNo][6][1]=GetPowerData;
        break;
    case '7':
        m_FreqData[antNo][7]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor08Temp,ui->label_Ant3Sensor08Power,ui->label_Ant3Sensor08Freq);
        DataForDebug[antNo][7][0]=m_FreqData[antNo][7];
        DataForDebug[antNo][7][1]=GetPowerData;
        break;
    case '8':
        m_FreqData[antNo][8]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor09Temp,ui->label_Ant3Sensor09Power,ui->label_Ant3Sensor09Freq);
        DataForDebug[antNo][8][0]=m_FreqData[antNo][8];
        DataForDebug[antNo][8][1]=GetPowerData;
        break;
    case '9':
        m_FreqData[antNo][9]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor10Temp,ui->label_Ant3Sensor10Power,ui->label_Ant3Sensor10Freq);
        DataForDebug[antNo][9][0]=m_FreqData[antNo][9];
        DataForDebug[antNo][9][1]=GetPowerData;
        break;
    case 'a':
        m_FreqData[antNo][10]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor11Temp,ui->label_Ant3Sensor11Power,ui->label_Ant3Sensor11Freq);
        DataForDebug[antNo][10][0]=m_FreqData[antNo][10];
        DataForDebug[antNo][10][1]=GetPowerData;
        break;
    case 'b':
        m_FreqData[antNo][11]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant3Sensor12Temp,ui->label_Ant3Sensor12Power,ui->label_Ant3Sensor12Freq);
        DataForDebug[antNo][11][0]=m_FreqData[antNo][11];
        DataForDebug[antNo][11][1]=GetPowerData;
        break;
    default:
        break;
    }
}

void WTSCommDialog::Ant4DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData)
{
    int antNo=3;
    switch (SensorID)
    {
    case '0':
        m_FreqData[antNo][0]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor01Temp,ui->label_Ant4Sensor01Power,ui->label_Ant4Sensor01Freq);
        DataForDebug[antNo][0][0]=m_FreqData[antNo][0];
        DataForDebug[antNo][0][1]=GetPowerData;
        break;
    case '1':
        m_FreqData[antNo][1]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor02Temp,ui->label_Ant4Sensor02Power,ui->label_Ant4Sensor02Freq);
        DataForDebug[antNo][1][0]=m_FreqData[antNo][1];
        DataForDebug[antNo][1][1]=GetPowerData;
        break;
    case '2':
        m_FreqData[antNo][2]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor03Temp,ui->label_Ant4Sensor03Power,ui->label_Ant4Sensor03Freq);
        DataForDebug[antNo][2][0]=m_FreqData[antNo][2];
        DataForDebug[antNo][2][1]=GetPowerData;
        break;
    case '3':
        m_FreqData[antNo][3]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor04Temp,ui->label_Ant4Sensor04Power,ui->label_Ant4Sensor04Freq);
        DataForDebug[antNo][3][0]=m_FreqData[antNo][3];
        DataForDebug[antNo][3][1]=GetPowerData;
        break;
    case '4':
        m_FreqData[antNo][4]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor05Temp,ui->label_Ant4Sensor05Power,ui->label_Ant4Sensor05Freq);
        DataForDebug[antNo][4][0]=m_FreqData[antNo][4];
        DataForDebug[antNo][4][1]=GetPowerData;
        break;
    case '5':
        m_FreqData[antNo][5]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor06Temp,ui->label_Ant4Sensor06Power,ui->label_Ant4Sensor06Freq);
        DataForDebug[antNo][5][0]=m_FreqData[antNo][5];
        DataForDebug[antNo][5][1]=GetPowerData;
        break;
    case '6':
        m_FreqData[antNo][6]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor07Temp,ui->label_Ant4Sensor07Power,ui->label_Ant4Sensor07Freq);
        DataForDebug[antNo][6][0]=m_FreqData[antNo][6];
        DataForDebug[antNo][6][1]=GetPowerData;
        break;
    case '7':
        m_FreqData[antNo][7]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor08Temp,ui->label_Ant4Sensor08Power,ui->label_Ant4Sensor08Freq);
        DataForDebug[antNo][7][0]=m_FreqData[antNo][7];
        DataForDebug[antNo][7][1]=GetPowerData;
        break;
    case '8':
        m_FreqData[antNo][8]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor09Temp,ui->label_Ant4Sensor09Power,ui->label_Ant4Sensor09Freq);
        DataForDebug[antNo][8][0]=m_FreqData[antNo][8];
        DataForDebug[antNo][8][1]=GetPowerData;
        break;
    case '9':
        m_FreqData[antNo][9]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor10Temp,ui->label_Ant4Sensor10Power,ui->label_Ant4Sensor10Freq);
        DataForDebug[antNo][9][0]=m_FreqData[antNo][9];
        DataForDebug[antNo][9][1]=GetPowerData;
        break;
    case 'a':
        m_FreqData[antNo][10]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor11Temp,ui->label_Ant4Sensor11Power,ui->label_Ant4Sensor11Freq);
        DataForDebug[antNo][10][0]=m_FreqData[antNo][10];
        DataForDebug[antNo][10][1]=GetPowerData;
        break;
    case 'b':
        m_FreqData[antNo][11]=SensorDataFix(GetTemperData,GetFreqData,GetPowerData,ui->label_Ant4Sensor12Temp,ui->label_Ant4Sensor12Power,ui->label_Ant4Sensor12Freq);
        DataForDebug[antNo][11][0]=m_FreqData[antNo][11];
        DataForDebug[antNo][11][1]=GetPowerData;
        break;
    default:
        break;
    }
}

int WTSCommDialog::SensorDataFix(float GetTemperData,int GetFreqData,int GetPowerData,QLabel* StaticTemper,QLabel* StaticPower,QLabel* StaticFreq)
{
    QString TemperTxt,FreqTxt,PowerTxt;//用于保存txt的变量缓存
    if(GetFreqData==0)
    {
        StaticTemper->setText("");
        StaticFreq->setText("信号差");
        StaticPower->setText(QString::number(GetPowerData, 10));
        return 0;
    }else if(GetFreqData==286331153)//if(GetFreqData==286331153&&GetPowerData==4369)
    {
        StaticTemper->setText("");
        StaticFreq->setText("信号弱");
        StaticPower->setText(QString::number(GetPowerData, 10));
        return 1;
    }else if(GetFreqData==572662306)//if(GetFreqData==572662306&&GetPowerData==8738)
    {
        StaticTemper->setText("");
        StaticFreq->setText("信号弱");
        StaticPower->setText(QString::number(GetPowerData, 10));
        return 2;
    }else if(GetFreqData==0x33333333)//if(GetFreqData==0x33333333&&GetPowerData==0x3333)
    {
        StaticTemper->setText("");
        StaticFreq->setText("温度异常");
        StaticPower->setText(QString::number(GetPowerData, 10));
        return 3;
    }else
    {
        if (GetPowerData<=20000)
        {
            PowerTxt=QString::number(((double)GetPowerData)*0.00284-36.8, 10, 1);
        }
        else
        {
            PowerTxt=QString::number(127.3-((double)GetPowerData)*0.01395+((double)GetPowerData)*((double)GetPowerData)*0.000000432766, 10, 1);
        }
        TemperTxt=QString::number(GetTemperData, 10, 1);
        FreqTxt=QString::number((double)GetFreqData/1000000, 10,1);//修改存储txt的数据格式freq
        StaticTemper->setText(TemperTxt);
        StaticFreq->setText(FreqTxt);
        StaticPower->setText(PowerTxt);
       return GetFreqData;
    }
}

void WTSCommDialog::ShowLossData(unsigned char AntID, int Data[4][12])
{
    switch (AntID)
    {
    case '0':
        ui->comboBox_Ant1Sensor01RF->setCurrentText(QString::number(Data[0][0],10));
        ui->comboBox_Ant1Sensor02RF->setCurrentText(QString::number(Data[0][1],10));
        ui->comboBox_Ant1Sensor03RF->setCurrentText(QString::number(Data[0][2],10));
        ui->comboBox_Ant1Sensor04RF->setCurrentText(QString::number(Data[0][3],10));
        ui->comboBox_Ant1Sensor05RF->setCurrentText(QString::number(Data[0][4],10));
        ui->comboBox_Ant1Sensor06RF->setCurrentText(QString::number(Data[0][5],10));
        ui->comboBox_Ant1Sensor07RF->setCurrentText(QString::number(Data[0][6],10));
        ui->comboBox_Ant1Sensor08RF->setCurrentText(QString::number(Data[0][7],10));
        ui->comboBox_Ant1Sensor09RF->setCurrentText(QString::number(Data[0][8],10));
        ui->comboBox_Ant1Sensor10RF->setCurrentText(QString::number(Data[0][9],10));
        ui->comboBox_Ant1Sensor11RF->setCurrentText(QString::number(Data[0][10],10));
        ui->comboBox_Ant1Sensor12RF->setCurrentText(QString::number(Data[0][11],10));
        break;
    case '1':
        ui->comboBox_Ant2Sensor01RF->setCurrentText(QString::number(Data[1][0],10));
        ui->comboBox_Ant2Sensor02RF->setCurrentText(QString::number(Data[1][1],10));
        ui->comboBox_Ant2Sensor03RF->setCurrentText(QString::number(Data[1][2],10));
        ui->comboBox_Ant2Sensor04RF->setCurrentText(QString::number(Data[1][3],10));
        ui->comboBox_Ant2Sensor05RF->setCurrentText(QString::number(Data[1][4],10));
        ui->comboBox_Ant2Sensor06RF->setCurrentText(QString::number(Data[1][5],10));
        ui->comboBox_Ant2Sensor07RF->setCurrentText(QString::number(Data[1][6],10));
        ui->comboBox_Ant2Sensor08RF->setCurrentText(QString::number(Data[1][7],10));
        ui->comboBox_Ant2Sensor09RF->setCurrentText(QString::number(Data[1][8],10));
        ui->comboBox_Ant2Sensor10RF->setCurrentText(QString::number(Data[1][9],10));
        ui->comboBox_Ant2Sensor11RF->setCurrentText(QString::number(Data[1][10],10));
        ui->comboBox_Ant2Sensor12RF->setCurrentText(QString::number(Data[1][11],10));
        break;
    case '2':
        ui->comboBox_Ant3Sensor01RF->setCurrentText(QString::number(Data[2][0],10));
        ui->comboBox_Ant3Sensor02RF->setCurrentText(QString::number(Data[2][1],10));
        ui->comboBox_Ant3Sensor03RF->setCurrentText(QString::number(Data[2][2],10));
        ui->comboBox_Ant3Sensor04RF->setCurrentText(QString::number(Data[2][3],10));
        ui->comboBox_Ant3Sensor05RF->setCurrentText(QString::number(Data[2][4],10));
        ui->comboBox_Ant3Sensor06RF->setCurrentText(QString::number(Data[2][5],10));
        ui->comboBox_Ant3Sensor07RF->setCurrentText(QString::number(Data[2][6],10));
        ui->comboBox_Ant3Sensor08RF->setCurrentText(QString::number(Data[2][7],10));
        ui->comboBox_Ant3Sensor09RF->setCurrentText(QString::number(Data[2][8],10));
        ui->comboBox_Ant3Sensor10RF->setCurrentText(QString::number(Data[2][9],10));
        ui->comboBox_Ant3Sensor11RF->setCurrentText(QString::number(Data[2][10],10));
        ui->comboBox_Ant3Sensor12RF->setCurrentText(QString::number(Data[2][11],10));
        break;
    case '3':
        ui->comboBox_Ant4Sensor01RF->setCurrentText(QString::number(Data[3][0],10));
        ui->comboBox_Ant4Sensor02RF->setCurrentText(QString::number(Data[3][1],10));
        ui->comboBox_Ant4Sensor03RF->setCurrentText(QString::number(Data[3][2],10));
        ui->comboBox_Ant4Sensor04RF->setCurrentText(QString::number(Data[3][3],10));
        ui->comboBox_Ant4Sensor05RF->setCurrentText(QString::number(Data[3][4],10));
        ui->comboBox_Ant4Sensor06RF->setCurrentText(QString::number(Data[3][5],10));
        ui->comboBox_Ant4Sensor07RF->setCurrentText(QString::number(Data[3][6],10));
        ui->comboBox_Ant4Sensor08RF->setCurrentText(QString::number(Data[3][7],10));
        ui->comboBox_Ant4Sensor09RF->setCurrentText(QString::number(Data[3][8],10));
        ui->comboBox_Ant4Sensor10RF->setCurrentText(QString::number(Data[3][9],10));
        ui->comboBox_Ant4Sensor11RF->setCurrentText(QString::number(Data[3][10],10));
        ui->comboBox_Ant4Sensor12RF->setCurrentText(QString::number(Data[3][11],10));
        break;
    default:
        break;
    }
}

void WTSCommDialog::SetSensorStatus(char AntID, char Sensor1, char Sensor2, char Sensor3, char Sensor4, char Sensor5, char Sensor6, char Sensor7, char Sensor8, char Sensor9, char Sensor10, char Sensor11, char Sensor12)
{
    if (AntID=='0')
    {
        if (Sensor1=='1')
        {
            StatusSensor1_1="1";
            ui->checkBox_Ant1Sensor01Set->setChecked(true);
        }
        else
        {
            StatusSensor1_1="0";
            ui->checkBox_Ant1Sensor01Set->setChecked(false);
        }
        if (Sensor2=='1')
        {
            StatusSensor1_2="1";
            ui->checkBox_Ant1Sensor02Set->setChecked(true);
        }
        else
        {
            StatusSensor1_2="0";
            ui->checkBox_Ant1Sensor02Set->setChecked(false);
        }
        if (Sensor3=='1')
        {
            StatusSensor1_3="1";
            ui->checkBox_Ant1Sensor03Set->setChecked(true);
        }
        else
        {
            StatusSensor1_3="0";
            ui->checkBox_Ant1Sensor03Set->setChecked(false);
        }
        if (Sensor4=='1')
        {
            StatusSensor1_4="1";
            ui->checkBox_Ant1Sensor04Set->setChecked(true);
        }
        else
        {
            StatusSensor1_4="0";
            ui->checkBox_Ant1Sensor04Set->setChecked(false);
        }
        if (Sensor5=='1')
        {
            StatusSensor1_5="1";
            ui->checkBox_Ant1Sensor05Set->setChecked(true);
        }
        else
        {
            StatusSensor1_5="0";
            ui->checkBox_Ant1Sensor05Set->setChecked(false);
        }
        if (Sensor6=='1')
        {
            StatusSensor1_6="1";
            ui->checkBox_Ant1Sensor06Set->setChecked(true);
        }
        else
        {
            StatusSensor1_6="0";
            ui->checkBox_Ant1Sensor06Set->setChecked(false);
        }
        if (Sensor7=='1')
        {
            StatusSensor1_7="1";
            ui->checkBox_Ant1Sensor07Set->setChecked(true);
        }
        else
        {
            StatusSensor1_7="0";
            ui->checkBox_Ant1Sensor07Set->setChecked(false);
        }
        if (Sensor8=='1')
        {
            StatusSensor1_8="1";
            ui->checkBox_Ant1Sensor08Set->setChecked(true);
        }
        else
        {
            StatusSensor1_8="0";
            ui->checkBox_Ant1Sensor08Set->setChecked(false);
        }
        if (Sensor9=='1')
        {
            StatusSensor1_9="1";
            ui->checkBox_Ant1Sensor09Set->setChecked(true);
        }
        else
        {
            StatusSensor1_9="0";
            ui->checkBox_Ant1Sensor09Set->setChecked(false);
        }
        if (Sensor10=='1')
        {
            StatusSensor1_10="1";
            ui->checkBox_Ant1Sensor10Set->setChecked(true);
        }
        else
        {
            StatusSensor1_10="0";
            ui->checkBox_Ant1Sensor10Set->setChecked(false);
        }
        if (Sensor11=='1')
        {
            StatusSensor1_11="1";
            ui->checkBox_Ant1Sensor11Set->setChecked(true);
        }
        else
        {
            StatusSensor1_11="0";
            ui->checkBox_Ant1Sensor11Set->setChecked(false);
        }
        if (Sensor12=='1')
        {
            StatusSensor1_12="1";
            ui->checkBox_Ant1Sensor12Set->setChecked(true);
        }
        else
        {
            StatusSensor1_12="0";
            ui->checkBox_Ant1Sensor12Set->setChecked(false);
        }
    }
    else if(AntID=='1')
    {
        if (Sensor1=='1')
        {
            StatusSensor2_1="1";
            ui->checkBox_Ant2Sensor01Set->setChecked(true);
        }
        else
        {
            StatusSensor2_1="0";
            ui->checkBox_Ant2Sensor01Set->setChecked(false);
        }
        if (Sensor2=='1')
        {
            StatusSensor2_2="1";
            ui->checkBox_Ant2Sensor02Set->setChecked(true);
        }
        else
        {
            StatusSensor2_2="0";
            ui->checkBox_Ant2Sensor02Set->setChecked(false);
        }
        if (Sensor3=='1')
        {
            StatusSensor2_3="1";
            ui->checkBox_Ant2Sensor03Set->setChecked(true);
        }
        else
        {
            StatusSensor2_3="0";
            ui->checkBox_Ant2Sensor03Set->setChecked(false);
        }
        if (Sensor4=='1')
        {
            StatusSensor2_4="1";
            ui->checkBox_Ant2Sensor04Set->setChecked(true);
        }
        else
        {
            StatusSensor2_4="0";
            ui->checkBox_Ant2Sensor04Set->setChecked(false);
        }
        if (Sensor5=='1')
        {
            StatusSensor2_5="1";
            ui->checkBox_Ant2Sensor05Set->setChecked(true);
        }
        else
        {
            StatusSensor2_5="0";
            ui->checkBox_Ant2Sensor05Set->setChecked(false);
        }
        if (Sensor6=='1')
        {
            StatusSensor2_6="1";
            ui->checkBox_Ant2Sensor06Set->setChecked(true);
        }
        else
        {
            StatusSensor2_6="0";
            ui->checkBox_Ant2Sensor06Set->setChecked(false);
        }
        if (Sensor7=='1')
        {
            StatusSensor2_7="1";
            ui->checkBox_Ant2Sensor07Set->setChecked(true);
        }
        else
        {
            StatusSensor2_7="0";
            ui->checkBox_Ant2Sensor07Set->setChecked(false);
        }
        if (Sensor8=='1')
        {
            StatusSensor2_8="1";
            ui->checkBox_Ant2Sensor08Set->setChecked(true);
        }
        else
        {
            StatusSensor2_8="0";
            ui->checkBox_Ant2Sensor08Set->setChecked(false);
        }
        if (Sensor9=='1')
        {
            StatusSensor2_9="1";
            ui->checkBox_Ant2Sensor09Set->setChecked(true);
        }
        else
        {
            StatusSensor2_9="0";
            ui->checkBox_Ant2Sensor09Set->setChecked(false);
        }
        if (Sensor10=='1')
        {
            StatusSensor2_10="1";
            ui->checkBox_Ant2Sensor10Set->setChecked(true);
        }
        else
        {
            StatusSensor2_10="0";
            ui->checkBox_Ant2Sensor10Set->setChecked(false);
        }
        if (Sensor11=='1')
        {
            StatusSensor2_11="1";
            ui->checkBox_Ant2Sensor11Set->setChecked(true);
        }
        else
        {
            StatusSensor2_11="0";
            ui->checkBox_Ant2Sensor11Set->setChecked(false);
        }
        if (Sensor12=='1')
        {
            StatusSensor2_12="1";
            ui->checkBox_Ant2Sensor12Set->setChecked(true);
        }
        else
        {
            StatusSensor2_12="0";
            ui->checkBox_Ant2Sensor12Set->setChecked(false);
        }
    }
    else if(AntID=='2')
    {
        if (Sensor1=='1')
        {
            StatusSensor3_1="1";
            ui->checkBox_Ant3Sensor01Set->setChecked(true);
        }
        else
        {
            StatusSensor3_1="0";
            ui->checkBox_Ant3Sensor01Set->setChecked(false);
        }
        if (Sensor2=='1')
        {
            StatusSensor3_2="1";
            ui->checkBox_Ant3Sensor02Set->setChecked(true);
        }
        else
        {
            StatusSensor3_2="0";
            ui->checkBox_Ant3Sensor02Set->setChecked(false);
        }
        if (Sensor3=='1')
        {
            StatusSensor3_3="1";
            ui->checkBox_Ant3Sensor03Set->setChecked(true);
        }
        else
        {
            StatusSensor3_3="0";
            ui->checkBox_Ant3Sensor03Set->setChecked(false);
        }
        if (Sensor4=='1')
        {
            StatusSensor3_4="1";
            ui->checkBox_Ant3Sensor04Set->setChecked(true);
        }
        else
        {
            StatusSensor3_4="0";
            ui->checkBox_Ant3Sensor04Set->setChecked(false);
        }
        if (Sensor5=='1')
        {
            StatusSensor3_5="1";
            ui->checkBox_Ant3Sensor05Set->setChecked(true);
        }
        else
        {
            StatusSensor3_5="0";
            ui->checkBox_Ant3Sensor05Set->setChecked(false);
        }
        if (Sensor6=='1')
        {
            StatusSensor3_6="1";
            ui->checkBox_Ant3Sensor06Set->setChecked(true);
        }
        else
        {
            StatusSensor3_6="0";
            ui->checkBox_Ant3Sensor06Set->setChecked(false);
        }
        if (Sensor7=='1')
        {
            StatusSensor3_7="1";
            ui->checkBox_Ant3Sensor07Set->setChecked(true);
        }
        else
        {
            StatusSensor3_7="0";
            ui->checkBox_Ant3Sensor07Set->setChecked(false);
        }
        if (Sensor8=='1')
        {
            StatusSensor3_8="1";
            ui->checkBox_Ant3Sensor08Set->setChecked(true);
        }
        else
        {
            StatusSensor3_8="0";
            ui->checkBox_Ant3Sensor08Set->setChecked(false);
        }
        if (Sensor9=='1')
        {
            StatusSensor3_9="1";
            ui->checkBox_Ant3Sensor09Set->setChecked(true);
        }
        else
        {
            StatusSensor3_9="0";
            ui->checkBox_Ant3Sensor09Set->setChecked(false);
        }
        if (Sensor10=='1')
        {
            StatusSensor3_10="1";
            ui->checkBox_Ant3Sensor10Set->setChecked(true);
        }
        else
        {
            StatusSensor3_10="0";
            ui->checkBox_Ant3Sensor10Set->setChecked(false);
        }
        if (Sensor11=='1')
        {
            StatusSensor3_11="1";
            ui->checkBox_Ant3Sensor11Set->setChecked(true);
        }
        else
        {
            StatusSensor3_11="0";
            ui->checkBox_Ant3Sensor11Set->setChecked(false);
        }
        if (Sensor12=='1')
        {
            StatusSensor3_12="1";
            ui->checkBox_Ant3Sensor12Set->setChecked(true);
        }
        else
        {
            StatusSensor3_12="0";
            ui->checkBox_Ant3Sensor12Set->setChecked(false);
        }
    }
    else if(AntID=='3')
    {
        if (Sensor1=='1')
        {
            StatusSensor4_1="1";
            ui->checkBox_Ant4Sensor01Set->setChecked(true);
        }
        else
        {
            StatusSensor4_1="0";
            ui->checkBox_Ant4Sensor01Set->setChecked(false);
        }
        if (Sensor2=='1')
        {
            StatusSensor4_2="1";
            ui->checkBox_Ant4Sensor02Set->setChecked(true);
        }
        else
        {
            StatusSensor4_2="0";
            ui->checkBox_Ant4Sensor02Set->setChecked(false);
        }
        if (Sensor3=='1')
        {
            StatusSensor4_3="1";
            ui->checkBox_Ant4Sensor03Set->setChecked(true);
        }
        else
        {
            StatusSensor4_3="0";
            ui->checkBox_Ant4Sensor03Set->setChecked(false);
        }
        if (Sensor4=='1')
        {
            StatusSensor4_4="1";
            ui->checkBox_Ant4Sensor04Set->setChecked(true);
        }
        else
        {
            StatusSensor4_4="0";
            ui->checkBox_Ant4Sensor04Set->setChecked(false);
        }
        if (Sensor5=='1')
        {
            StatusSensor4_5="1";
            ui->checkBox_Ant4Sensor05Set->setChecked(true);
        }
        else
        {
            StatusSensor4_5="0";
            ui->checkBox_Ant4Sensor05Set->setChecked(false);
        }
        if (Sensor6=='1')
        {
            StatusSensor4_6="1";
            ui->checkBox_Ant4Sensor06Set->setChecked(true);
        }
        else
        {
            StatusSensor4_6="0";
            ui->checkBox_Ant4Sensor06Set->setChecked(false);
        }
        if (Sensor7=='1')
        {
            StatusSensor4_7="1";
            ui->checkBox_Ant4Sensor07Set->setChecked(true);
        }
        else
        {
            StatusSensor4_7="0";
            ui->checkBox_Ant4Sensor07Set->setChecked(false);
        }
        if (Sensor8=='1')
        {
            StatusSensor4_8="1";
            ui->checkBox_Ant4Sensor08Set->setChecked(true);
        }
        else
        {
            StatusSensor4_8="0";
            ui->checkBox_Ant4Sensor08Set->setChecked(false);
        }
        if (Sensor9=='1')
        {
            StatusSensor4_9="1";
            ui->checkBox_Ant4Sensor09Set->setChecked(true);
        }
        else
        {
            StatusSensor4_9="0";
            ui->checkBox_Ant4Sensor09Set->setChecked(false);
        }
        if (Sensor10=='1')
        {
            StatusSensor4_10="1";
            ui->checkBox_Ant4Sensor10Set->setChecked(true);
        }
        else
        {
            StatusSensor4_10="0";
            ui->checkBox_Ant4Sensor10Set->setChecked(false);
        }
        if (Sensor11=='1')
        {
            StatusSensor4_11="1";
            ui->checkBox_Ant4Sensor11Set->setChecked(true);
         }
        else
        {
            StatusSensor4_11="0";
            ui->checkBox_Ant4Sensor11Set->setChecked(false);
       }
        if (Sensor12=='1')
        {
            StatusSensor4_12="1";
            ui->checkBox_Ant4Sensor12Set->setChecked(true);
        }
        else
        {
            StatusSensor4_12="0";
            ui->checkBox_Ant4Sensor12Set->setChecked(false);
        }
    }
}


void WTSCommDialog::ShowReaderStatus(unsigned char ucStatus)
{
    QPixmap pixmapDisconnect(":/image/image/diconnect.png");
    QPixmap fitpixmapDisconnect=pixmapDisconnect.scaled(ui->label_ReaderStatus->width(), ui->label_ReaderStatus->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap pixmapConnect(":/image/image/connect.png");
    QPixmap fitpixmapConnect=pixmapConnect.scaled(ui->label_ReaderStatus->width(), ui->label_ReaderStatus->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    switch (ucStatus)
    {
    case '0':
        update();
        ui->label_ReaderStatus->setPixmap(fitpixmapDisconnect);
        ui->label_ReaderStatus->show();
        if(SetReaderIDCheckStatusFlag)
        {
            SetReaderIDCheckStatusFlag=false;
            ui->lineEdit_CheckSetReaderIDStatus->setText(" ");
            ui->pushButton_SetTargetReaderID->setEnabled(true);
            QMessageBox::critical(this,"注意",tr("读取器ID设定未成功，请检查通信线路或重启读取器！"));
        }
        break;
    case '1':
        update();
        ui->label_ReaderStatus->setPixmap(fitpixmapDisconnect);
        ui->label_ReaderStatus->show();
        if(SetReaderIDCheckStatusFlag)
        {
            SetReaderIDCheckStatusFlag=false;
            ui->lineEdit_CheckSetReaderIDStatus->setText(" ");
            ui->pushButton_SetTargetReaderID->setEnabled(true);
            QMessageBox::critical(this,"注意",tr("读取器ID设定未成功，请检查通信线路或重启读取器！"));
        }
        break;
    case '2':
        update();
        ui->label_ReaderStatus->setPixmap(fitpixmapConnect);
        ui->label_ReaderStatus->show();
        if(SetReaderIDCheckStatusFlag)
        {
            SetReaderIDCheckStatusFlag=false;
            ui->lineEdit_CheckSetReaderIDStatus->setText(" ");
            ui->pushButton_SetTargetReaderID->setEnabled(true);
            QMessageBox::critical(this,"注意",tr("读取器ID设定成功！"));
        }
        break;
    default:
        break;
    }
}

void WTSCommDialog::on_pushButton_OpenComm_clicked()
{
    WTS_SerialPort->setPortName(ui->comboBox_CommPort->currentText());
    WTS_SerialPort->setBaudRate(ui->comboBox_CommBaud->currentText().toInt());
    WTS_SerialPort->setDataBits(QSerialPort::Data8);
    WTS_SerialPort->setParity(QSerialPort::NoParity);
    WTS_SerialPort->setStopBits(QSerialPort::OneStop);
    WTS_SerialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(WTS_SerialPort,SIGNAL(readyRead()),this,SLOT(WTS_ReadUart()));
    if (WTS_SerialPort->open(QIODevice::ReadWrite)) {
        CommOpenFlag=true;
        ui->pushButton_OpenComm->setEnabled(false);//禁止打开串口按钮
        ui->pushButton_CloseComm->setEnabled(true);//允许关闭串口按钮
        ui->comboBox_CommBaud->setEnabled(false);
        ui->comboBox_CommPort->setEnabled(false);
        iRecvPackageCount=0;
        iSendPackageCount=0;
        ui->label_RecvPackage->setText("接收包："+QString::number(iRecvPackageCount,10));
        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
     } else {
         QMessageBox::critical(this, tr("Open error"), WTS_SerialPort->errorString());
     }
}

void WTSCommDialog::on_pushButton_CloseComm_clicked()
{
    if (WTS_SerialPort->isOpen())
    {
        WTS_SerialPort->close();
        CommOpenFlag=false;
        WTS_SerialPort->clear();
        ui->pushButton_OpenComm->setEnabled(true);
        ui->pushButton_CloseComm->setEnabled(false);
        ui->comboBox_CommBaud->setEnabled(true);
        ui->comboBox_CommPort->setEnabled(true);
    }
}

void WTSCommDialog::on_pushButton_Ant1SelectAllSensor_clicked()
{
    ui->checkBox_Ant1Sensor01Set->setChecked(true);
    ui->checkBox_Ant1Sensor02Set->setChecked(true);
    ui->checkBox_Ant1Sensor03Set->setChecked(true);
    ui->checkBox_Ant1Sensor04Set->setChecked(true);
    ui->checkBox_Ant1Sensor05Set->setChecked(true);
    ui->checkBox_Ant1Sensor06Set->setChecked(true);
    ui->checkBox_Ant1Sensor07Set->setChecked(true);
    ui->checkBox_Ant1Sensor08Set->setChecked(true);
    ui->checkBox_Ant1Sensor09Set->setChecked(true);
    ui->checkBox_Ant1Sensor10Set->setChecked(true);
    ui->checkBox_Ant1Sensor11Set->setChecked(true);
    ui->checkBox_Ant1Sensor12Set->setChecked(true);
    for(int i=0;i<12;i++)
    {
        iSensorSet[0][i]=1;
    }
    StatusSensor1_1="1";
    StatusSensor1_2="1";
    StatusSensor1_3="1";
    StatusSensor1_4="1";
    StatusSensor1_5="1";
    StatusSensor1_6="1";
    StatusSensor1_7="1";
    StatusSensor1_8="1";
    StatusSensor1_9="1";
    StatusSensor1_10="1";
    StatusSensor1_11="1";
    StatusSensor1_12="1";

}

void WTSCommDialog::on_pushButton_Ant2SelectAllSensor_clicked()
{
    ui->checkBox_Ant2Sensor01Set->setChecked(true);
    ui->checkBox_Ant2Sensor02Set->setChecked(true);
    ui->checkBox_Ant2Sensor03Set->setChecked(true);
    ui->checkBox_Ant2Sensor04Set->setChecked(true);
    ui->checkBox_Ant2Sensor05Set->setChecked(true);
    ui->checkBox_Ant2Sensor06Set->setChecked(true);
    ui->checkBox_Ant2Sensor07Set->setChecked(true);
    ui->checkBox_Ant2Sensor08Set->setChecked(true);
    ui->checkBox_Ant2Sensor09Set->setChecked(true);
    ui->checkBox_Ant2Sensor10Set->setChecked(true);
    ui->checkBox_Ant2Sensor11Set->setChecked(true);
    ui->checkBox_Ant2Sensor12Set->setChecked(true);
    for(int i=0;i<12;i++)
    {
        iSensorSet[1][i]=1;
    }
    StatusSensor2_1="1";
    StatusSensor2_2="1";
    StatusSensor2_3="1";
    StatusSensor2_4="1";
    StatusSensor2_5="1";
    StatusSensor2_6="1";
    StatusSensor2_7="1";
    StatusSensor2_8="1";
    StatusSensor2_9="1";
    StatusSensor2_10="1";
    StatusSensor2_11="1";
    StatusSensor2_12="1";

}

void WTSCommDialog::on_pushButton_Ant3SelectAllSensor_clicked()
{
    ui->checkBox_Ant3Sensor01Set->setChecked(true);
    ui->checkBox_Ant3Sensor02Set->setChecked(true);
    ui->checkBox_Ant3Sensor03Set->setChecked(true);
    ui->checkBox_Ant3Sensor04Set->setChecked(true);
    ui->checkBox_Ant3Sensor05Set->setChecked(true);
    ui->checkBox_Ant3Sensor06Set->setChecked(true);
    ui->checkBox_Ant3Sensor07Set->setChecked(true);
    ui->checkBox_Ant3Sensor08Set->setChecked(true);
    ui->checkBox_Ant3Sensor09Set->setChecked(true);
    ui->checkBox_Ant3Sensor10Set->setChecked(true);
    ui->checkBox_Ant3Sensor11Set->setChecked(true);
    ui->checkBox_Ant3Sensor12Set->setChecked(true);
    for(int i=0;i<12;i++)
    {
        iSensorSet[2][i]=1;
    }
    StatusSensor3_1="1";
    StatusSensor3_2="1";
    StatusSensor3_3="1";
    StatusSensor3_4="1";
    StatusSensor3_5="1";
    StatusSensor3_6="1";
    StatusSensor3_7="1";
    StatusSensor3_8="1";
    StatusSensor3_9="1";
    StatusSensor3_10="1";
    StatusSensor3_11="1";
    StatusSensor3_12="1";

}

void WTSCommDialog::on_pushButton_Ant4SelectAllSensor_clicked()
{
    ui->checkBox_Ant4Sensor01Set->setChecked(true);
    ui->checkBox_Ant4Sensor02Set->setChecked(true);
    ui->checkBox_Ant4Sensor03Set->setChecked(true);
    ui->checkBox_Ant4Sensor04Set->setChecked(true);
    ui->checkBox_Ant4Sensor05Set->setChecked(true);
    ui->checkBox_Ant4Sensor06Set->setChecked(true);
    ui->checkBox_Ant4Sensor07Set->setChecked(true);
    ui->checkBox_Ant4Sensor08Set->setChecked(true);
    ui->checkBox_Ant4Sensor09Set->setChecked(true);
    ui->checkBox_Ant4Sensor10Set->setChecked(true);
    ui->checkBox_Ant4Sensor11Set->setChecked(true);
    ui->checkBox_Ant4Sensor12Set->setChecked(true);
    for(int i=0;i<12;i++)
    {
        iSensorSet[3][i]=1;
    }
    StatusSensor4_1="1";
    StatusSensor4_2="1";
    StatusSensor4_3="1";
    StatusSensor4_4="1";
    StatusSensor4_5="1";
    StatusSensor4_6="1";
    StatusSensor4_7="1";
    StatusSensor4_8="1";
    StatusSensor4_9="1";
    StatusSensor4_10="1";
    StatusSensor4_11="1";
    StatusSensor4_12="1";
}

void WTSCommDialog::on_pushButton_Ant1SelectNoSensor_clicked()
{
    ui->checkBox_Ant1Sensor01Set->setChecked(false);
    ui->checkBox_Ant1Sensor02Set->setChecked(false);
    ui->checkBox_Ant1Sensor03Set->setChecked(false);
    ui->checkBox_Ant1Sensor04Set->setChecked(false);
    ui->checkBox_Ant1Sensor05Set->setChecked(false);
    ui->checkBox_Ant1Sensor06Set->setChecked(false);
    ui->checkBox_Ant1Sensor07Set->setChecked(false);
    ui->checkBox_Ant1Sensor08Set->setChecked(false);
    ui->checkBox_Ant1Sensor09Set->setChecked(false);
    ui->checkBox_Ant1Sensor10Set->setChecked(false);
    ui->checkBox_Ant1Sensor11Set->setChecked(false);
    ui->checkBox_Ant1Sensor12Set->setChecked(false);
    for(int i=0;i<12;i++)
    {
        iSensorSet[0][i]=0;
    }
    StatusSensor1_1="0";
    StatusSensor1_2="0";
    StatusSensor1_3="0";
    StatusSensor1_4="0";
    StatusSensor1_5="0";
    StatusSensor1_6="0";
    StatusSensor1_7="0";
    StatusSensor1_8="0";
    StatusSensor1_9="0";
    StatusSensor1_10="0";
    StatusSensor1_11="0";
    StatusSensor1_12="0";
}

void WTSCommDialog::on_pushButton_Ant2SelectNoSensor_clicked()
{
    ui->checkBox_Ant2Sensor01Set->setChecked(false);
    ui->checkBox_Ant2Sensor02Set->setChecked(false);
    ui->checkBox_Ant2Sensor03Set->setChecked(false);
    ui->checkBox_Ant2Sensor04Set->setChecked(false);
    ui->checkBox_Ant2Sensor05Set->setChecked(false);
    ui->checkBox_Ant2Sensor06Set->setChecked(false);
    ui->checkBox_Ant2Sensor07Set->setChecked(false);
    ui->checkBox_Ant2Sensor08Set->setChecked(false);
    ui->checkBox_Ant2Sensor09Set->setChecked(false);
    ui->checkBox_Ant2Sensor10Set->setChecked(false);
    ui->checkBox_Ant2Sensor11Set->setChecked(false);
    ui->checkBox_Ant2Sensor12Set->setChecked(false);
    for(int i=0;i<12;i++)
    {
        iSensorSet[1][i]=0;
    }
    StatusSensor2_1="0";
    StatusSensor2_2="0";
    StatusSensor2_3="0";
    StatusSensor2_4="0";
    StatusSensor2_5="0";
    StatusSensor2_6="0";
    StatusSensor2_7="0";
    StatusSensor2_8="0";
    StatusSensor2_9="0";
    StatusSensor2_10="0";
    StatusSensor2_11="0";
    StatusSensor2_12="0";
}

void WTSCommDialog::on_pushButton_Ant3SelectNoSensor_clicked()
{
    ui->checkBox_Ant3Sensor01Set->setChecked(false);
    ui->checkBox_Ant3Sensor02Set->setChecked(false);
    ui->checkBox_Ant3Sensor03Set->setChecked(false);
    ui->checkBox_Ant3Sensor04Set->setChecked(false);
    ui->checkBox_Ant3Sensor05Set->setChecked(false);
    ui->checkBox_Ant3Sensor06Set->setChecked(false);
    ui->checkBox_Ant3Sensor07Set->setChecked(false);
    ui->checkBox_Ant3Sensor08Set->setChecked(false);
    ui->checkBox_Ant3Sensor09Set->setChecked(false);
    ui->checkBox_Ant3Sensor10Set->setChecked(false);
    ui->checkBox_Ant3Sensor11Set->setChecked(false);
    ui->checkBox_Ant3Sensor12Set->setChecked(false);
    for(int i=0;i<12;i++)
    {
        iSensorSet[2][i]=0;
    }
    StatusSensor3_1="0";
    StatusSensor3_2="0";
    StatusSensor3_3="0";
    StatusSensor3_4="0";
    StatusSensor3_5="0";
    StatusSensor3_6="0";
    StatusSensor3_7="0";
    StatusSensor3_8="0";
    StatusSensor3_9="0";
    StatusSensor3_10="0";
    StatusSensor3_11="0";
    StatusSensor3_12="0";
}

void WTSCommDialog::on_pushButton_Ant4SelectNoSensor_clicked()
{
    ui->checkBox_Ant4Sensor01Set->setChecked(false);
    ui->checkBox_Ant4Sensor02Set->setChecked(false);
    ui->checkBox_Ant4Sensor03Set->setChecked(false);
    ui->checkBox_Ant4Sensor04Set->setChecked(false);
    ui->checkBox_Ant4Sensor05Set->setChecked(false);
    ui->checkBox_Ant4Sensor06Set->setChecked(false);
    ui->checkBox_Ant4Sensor07Set->setChecked(false);
    ui->checkBox_Ant4Sensor08Set->setChecked(false);
    ui->checkBox_Ant4Sensor09Set->setChecked(false);
    ui->checkBox_Ant4Sensor10Set->setChecked(false);
    ui->checkBox_Ant4Sensor11Set->setChecked(false);
    ui->checkBox_Ant4Sensor12Set->setChecked(false);
    for(int i=0;i<12;i++)
    {
        iSensorSet[3][i]=0;
    }
    StatusSensor4_1="0";
    StatusSensor4_2="0";
    StatusSensor4_3="0";
    StatusSensor4_4="0";
    StatusSensor4_5="0";
    StatusSensor4_6="0";
    StatusSensor4_7="0";
    StatusSensor4_8="0";
    StatusSensor4_9="0";
    StatusSensor4_10="0";
    StatusSensor4_11="0";
    StatusSensor4_12="0";
}

void WTSCommDialog::on_pushButton_DebugCMD_clicked()
{
    if(FlagForDebugButton)
    {
        FlagForDebugButton=false;
        ui->pushButton_DebugCMD->setText("停止");
        QTimer::singleShot(500, this, SLOT(ScanAnt1ForSensor()));
        singleShotFlag=true;
    }else
    {
        FlagForDebugButton=true;
        ui->pushButton_DebugCMD->setText("开始");
        singleShotFlag=false;
        if(ui->checkBox_SaveParmFile->isChecked()==true) SaveParmToFile(ui->lineEdit_ParmFileName->text());
    }
}

void WTSCommDialog::ScanAnt1ForSensor()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"63","0");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt2ForSensor()));
}

void WTSCommDialog::ScanAnt2ForSensor()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"63","1");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt3ForSensor()));
}

void WTSCommDialog::ScanAnt3ForSensor()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"63","2");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt4ForSensor()));
}

void WTSCommDialog::ScanAnt4ForSensor()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"63","3");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt1ForRF()));
}

void WTSCommDialog::ScanAnt1ForRF()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"65","0");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt2ForRF()));
}

void WTSCommDialog::ScanAnt2ForRF()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"65","1");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt3ForRF()));
}

void WTSCommDialog::ScanAnt3ForRF()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"65","2");
    if(singleShotFlag)
        QTimer::singleShot(500, this, SLOT(ScanAnt4ForRF()));
}

void WTSCommDialog::ScanAnt4ForRF()
{
    SendCMDByReaderAnt(ui->comboBox_ReaderID->currentIndex(),"65","3");
//    FlagForDebugButton=true;
//    ui->pushButton_DebugCMD->setText("开始");
    singleShotFlag=false;
}

void WTSCommDialog::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void WTSCommDialog::on_pushButton_StartGetTemp_clicked()
{
    if(FlagForGetTempButton)
    {
        FlagForGetTempButton=false;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                m_FreqData[i][j]=0;
            }
        }
        ui->pushButton_StartGetTemp->setText("停止测温");
        QTimer::singleShot(250, this, SLOT(SetAnt1ForSensorSelect()));
    }else
    {
        FlagForGetTempButton=true;
        ui->pushButton_StartGetTemp->setText("开始测温");
        bSendStopCMDRequest=true;
        bSendStopCMDRequestTimeout=true;
        QTimer::singleShot(1500, this, SLOT(SendStopCMDTimeout()));
    }
}

void WTSCommDialog::SendStopCMDTimeout()
{
    if(bSendStopCMDRequestTimeout)
    {
        bSendStopCMDRequestTimeout=false;
        SendCMDByReader(ui->comboBox_ReaderID->currentIndex(),"54");//stop
        QMessageBox::critical(this,"注意",tr("停止命令发送超时，读取器已停止或通讯中断！"));
    }
}

void WTSCommDialog::SetAnt1ForSensorSelect()
{
    on_checkBox_Ant1Sensor01Set_clicked();
    on_checkBox_Ant1Sensor02Set_clicked();
    on_checkBox_Ant1Sensor03Set_clicked();
    on_checkBox_Ant1Sensor04Set_clicked();
    on_checkBox_Ant1Sensor05Set_clicked();
    on_checkBox_Ant1Sensor06Set_clicked();
    on_checkBox_Ant1Sensor07Set_clicked();
    on_checkBox_Ant1Sensor08Set_clicked();
    on_checkBox_Ant1Sensor09Set_clicked();
    on_checkBox_Ant1Sensor10Set_clicked();
    on_checkBox_Ant1Sensor11Set_clicked();
    on_checkBox_Ant1Sensor12Set_clicked();

    bool bSensorSetChange=false;
    for(int i=0;i<12;i++)
    {
        if(iSensorRead[0][i]!=iSensorSet[0][i])
        {
            iSensorRead[0][i]=iSensorSet[0][i];
            bSensorSetChange=true;
        }
    }
    if(bSensorSetChange)
    {
        QString StartCmd1,StartCmd2,StartCmd3,StartCmd4;
        StartCmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"620"+StatusSensor1_1+StatusSensor1_2+StatusSensor1_3+StatusSensor1_4+StatusSensor1_5;
        StartCmd1=":"+StartCmd1+LRC_Calculate(StartCmd1).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd1.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor1_6+"0"+StatusSensor1_7+"0"+StatusSensor1_8;
        StartCmd2=":"+StartCmd2+LRC_Calculate(StartCmd2).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd2.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor1_9+"0"+StatusSensor1_10+"0"+StatusSensor1_11;
        StartCmd3=":"+StartCmd3+LRC_Calculate(StartCmd3).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd3.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd4=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor1_12+"00<>";
        StartCmd4=":"+StartCmd4+LRC_Calculate(StartCmd4).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd4.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
    }


    QTimer::singleShot(250, this, SLOT(SetAnt2ForSensorSelect()));
}

void WTSCommDialog::SetAnt2ForSensorSelect()
{
    on_checkBox_Ant2Sensor01Set_clicked();
    on_checkBox_Ant2Sensor02Set_clicked();
    on_checkBox_Ant2Sensor03Set_clicked();
    on_checkBox_Ant2Sensor04Set_clicked();
    on_checkBox_Ant2Sensor05Set_clicked();
    on_checkBox_Ant2Sensor06Set_clicked();
    on_checkBox_Ant2Sensor07Set_clicked();
    on_checkBox_Ant2Sensor08Set_clicked();
    on_checkBox_Ant2Sensor09Set_clicked();
    on_checkBox_Ant2Sensor10Set_clicked();
    on_checkBox_Ant2Sensor11Set_clicked();
    on_checkBox_Ant2Sensor12Set_clicked();

    bool bSensorSetChange=false;
    for(int i=0;i<12;i++)
    {
        if(iSensorRead[1][i]!=iSensorSet[1][i])
        {
            iSensorRead[1][i]=iSensorSet[1][i];
            bSensorSetChange=true;
        }
    }
    if(bSensorSetChange)
    {
        QString StartCmd1,StartCmd2,StartCmd3,StartCmd4;
        StartCmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"621"+StatusSensor2_1+StatusSensor2_2+StatusSensor2_3+StatusSensor2_4+StatusSensor2_5;
        StartCmd1=":"+StartCmd1+LRC_Calculate(StartCmd1).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd1.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor2_6+"0"+StatusSensor2_7+"0"+StatusSensor2_8;
        StartCmd2=":"+StartCmd2+LRC_Calculate(StartCmd2).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd2.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor2_9+"0"+StatusSensor2_10+"0"+StatusSensor2_11;
        StartCmd3=":"+StartCmd3+LRC_Calculate(StartCmd3).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd3.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd4=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor2_12+"00<>";
        StartCmd4=":"+StartCmd4+LRC_Calculate(StartCmd4).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd4.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
    }

    QTimer::singleShot(250, this, SLOT(SetAnt3ForSensorSelect()));
}

void WTSCommDialog::SetAnt3ForSensorSelect()
{
    on_checkBox_Ant3Sensor01Set_clicked();
    on_checkBox_Ant3Sensor02Set_clicked();
    on_checkBox_Ant3Sensor03Set_clicked();
    on_checkBox_Ant3Sensor04Set_clicked();
    on_checkBox_Ant3Sensor05Set_clicked();
    on_checkBox_Ant3Sensor06Set_clicked();
    on_checkBox_Ant3Sensor07Set_clicked();
    on_checkBox_Ant3Sensor08Set_clicked();
    on_checkBox_Ant3Sensor09Set_clicked();
    on_checkBox_Ant3Sensor10Set_clicked();
    on_checkBox_Ant3Sensor11Set_clicked();
    on_checkBox_Ant3Sensor12Set_clicked();

    bool bSensorSetChange=false;
    for(int i=0;i<12;i++)
    {
        if(iSensorRead[2][i]!=iSensorSet[2][i])
        {
            iSensorRead[2][i]=iSensorSet[2][i];
            bSensorSetChange=true;
        }
    }
    if(bSensorSetChange)
    {
        QString StartCmd1,StartCmd2,StartCmd3,StartCmd4;
        StartCmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"622"+StatusSensor3_1+StatusSensor3_2+StatusSensor3_3+StatusSensor3_4+StatusSensor3_5;
        StartCmd1=":"+StartCmd1+LRC_Calculate(StartCmd1).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd1.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor3_6+"0"+StatusSensor3_7+"0"+StatusSensor3_8;
        StartCmd2=":"+StartCmd2+LRC_Calculate(StartCmd2).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd2.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor3_9+"0"+StatusSensor3_10+"0"+StatusSensor3_11;
        StartCmd3=":"+StartCmd3+LRC_Calculate(StartCmd3).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd3.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd4=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor3_12+"00<>";
        StartCmd4=":"+StartCmd4+LRC_Calculate(StartCmd4).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd4.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
    }

    QTimer::singleShot(250, this, SLOT(SetAnt4ForSensorSelect()));
}

void WTSCommDialog::SetAnt4ForSensorSelect()
{
    on_checkBox_Ant4Sensor01Set_clicked();
    on_checkBox_Ant4Sensor02Set_clicked();
    on_checkBox_Ant4Sensor03Set_clicked();
    on_checkBox_Ant4Sensor04Set_clicked();
    on_checkBox_Ant4Sensor05Set_clicked();
    on_checkBox_Ant4Sensor06Set_clicked();
    on_checkBox_Ant4Sensor07Set_clicked();
    on_checkBox_Ant4Sensor08Set_clicked();
    on_checkBox_Ant4Sensor09Set_clicked();
    on_checkBox_Ant4Sensor10Set_clicked();
    on_checkBox_Ant4Sensor11Set_clicked();
    on_checkBox_Ant4Sensor12Set_clicked();

    bool bSensorSetChange=false;
    for(int i=0;i<12;i++)
    {
        if(iSensorRead[3][i]!=iSensorSet[3][i])
        {
            iSensorRead[3][i]=iSensorSet[3][i];
            bSensorSetChange=true;
        }
    }
    if(bSensorSetChange)
    {
        QString StartCmd1,StartCmd2,StartCmd3,StartCmd4;
        StartCmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"623"+StatusSensor4_1+StatusSensor4_2+StatusSensor4_3+StatusSensor4_4+StatusSensor4_5;
        StartCmd1=":"+StartCmd1+LRC_Calculate(StartCmd1).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd1.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor4_6+"0"+StatusSensor4_7+"0"+StatusSensor4_8;
        StartCmd2=":"+StartCmd2+LRC_Calculate(StartCmd2).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd2.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor4_9+"0"+StatusSensor4_10+"0"+StatusSensor4_11;
        StartCmd3=":"+StartCmd3+LRC_Calculate(StartCmd3).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd3.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
        sleep(250);
        StartCmd4=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"62"+"0"+StatusSensor4_12+"00<>";
        StartCmd4=":"+StartCmd4+LRC_Calculate(StartCmd4).left(2)+"\r\n";
        if(CommOpenFlag)
        {
            WTS_SerialPort->write(StartCmd4.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
        }
        else
            QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
    }

    QTimer::singleShot(250, this, SLOT(SetRF()));
}

void WTSCommDialog::SetRF()
{
    bool ok;
    iRFSetData[0][0]=ui->comboBox_Ant1Sensor01RF->currentText().toInt(&ok,10);
    iRFSetData[0][1]=ui->comboBox_Ant1Sensor02RF->currentText().toInt(&ok,10);
    iRFSetData[0][2]=ui->comboBox_Ant1Sensor03RF->currentText().toInt(&ok,10);
    iRFSetData[0][3]=ui->comboBox_Ant1Sensor04RF->currentText().toInt(&ok,10);
    iRFSetData[0][4]=ui->comboBox_Ant1Sensor05RF->currentText().toInt(&ok,10);
    iRFSetData[0][5]=ui->comboBox_Ant1Sensor06RF->currentText().toInt(&ok,10);
    iRFSetData[0][6]=ui->comboBox_Ant1Sensor07RF->currentText().toInt(&ok,10);
    iRFSetData[0][7]=ui->comboBox_Ant1Sensor08RF->currentText().toInt(&ok,10);
    iRFSetData[0][8]=ui->comboBox_Ant1Sensor09RF->currentText().toInt(&ok,10);
    iRFSetData[0][9]=ui->comboBox_Ant1Sensor10RF->currentText().toInt(&ok,10);
    iRFSetData[0][10]=ui->comboBox_Ant1Sensor11RF->currentText().toInt(&ok,10);
    iRFSetData[0][11]=ui->comboBox_Ant1Sensor12RF->currentText().toInt(&ok,10);
    iRFSetData[1][0]=ui->comboBox_Ant2Sensor01RF->currentText().toInt(&ok,10);
    iRFSetData[1][1]=ui->comboBox_Ant2Sensor02RF->currentText().toInt(&ok,10);
    iRFSetData[1][2]=ui->comboBox_Ant2Sensor03RF->currentText().toInt(&ok,10);
    iRFSetData[1][3]=ui->comboBox_Ant2Sensor04RF->currentText().toInt(&ok,10);
    iRFSetData[1][4]=ui->comboBox_Ant2Sensor05RF->currentText().toInt(&ok,10);
    iRFSetData[1][5]=ui->comboBox_Ant2Sensor06RF->currentText().toInt(&ok,10);
    iRFSetData[1][6]=ui->comboBox_Ant2Sensor07RF->currentText().toInt(&ok,10);
    iRFSetData[1][7]=ui->comboBox_Ant2Sensor08RF->currentText().toInt(&ok,10);
    iRFSetData[1][8]=ui->comboBox_Ant2Sensor09RF->currentText().toInt(&ok,10);
    iRFSetData[1][9]=ui->comboBox_Ant2Sensor10RF->currentText().toInt(&ok,10);
    iRFSetData[1][10]=ui->comboBox_Ant2Sensor11RF->currentText().toInt(&ok,10);
    iRFSetData[1][11]=ui->comboBox_Ant2Sensor12RF->currentText().toInt(&ok,10);
    iRFSetData[2][0]=ui->comboBox_Ant3Sensor01RF->currentText().toInt(&ok,10);
    iRFSetData[2][1]=ui->comboBox_Ant3Sensor02RF->currentText().toInt(&ok,10);
    iRFSetData[2][2]=ui->comboBox_Ant3Sensor03RF->currentText().toInt(&ok,10);
    iRFSetData[2][3]=ui->comboBox_Ant3Sensor04RF->currentText().toInt(&ok,10);
    iRFSetData[2][4]=ui->comboBox_Ant3Sensor05RF->currentText().toInt(&ok,10);
    iRFSetData[2][5]=ui->comboBox_Ant3Sensor06RF->currentText().toInt(&ok,10);
    iRFSetData[2][6]=ui->comboBox_Ant3Sensor07RF->currentText().toInt(&ok,10);
    iRFSetData[2][7]=ui->comboBox_Ant3Sensor08RF->currentText().toInt(&ok,10);
    iRFSetData[2][8]=ui->comboBox_Ant3Sensor09RF->currentText().toInt(&ok,10);
    iRFSetData[2][9]=ui->comboBox_Ant3Sensor10RF->currentText().toInt(&ok,10);
    iRFSetData[2][10]=ui->comboBox_Ant3Sensor11RF->currentText().toInt(&ok,10);
    iRFSetData[2][11]=ui->comboBox_Ant3Sensor12RF->currentText().toInt(&ok,10);
    iRFSetData[3][0]=ui->comboBox_Ant4Sensor01RF->currentText().toInt(&ok,10);
    iRFSetData[3][1]=ui->comboBox_Ant4Sensor02RF->currentText().toInt(&ok,10);
    iRFSetData[3][2]=ui->comboBox_Ant4Sensor03RF->currentText().toInt(&ok,10);
    iRFSetData[3][3]=ui->comboBox_Ant4Sensor04RF->currentText().toInt(&ok,10);
    iRFSetData[3][4]=ui->comboBox_Ant4Sensor05RF->currentText().toInt(&ok,10);
    iRFSetData[3][5]=ui->comboBox_Ant4Sensor06RF->currentText().toInt(&ok,10);
    iRFSetData[3][6]=ui->comboBox_Ant4Sensor07RF->currentText().toInt(&ok,10);
    iRFSetData[3][7]=ui->comboBox_Ant4Sensor08RF->currentText().toInt(&ok,10);
    iRFSetData[3][8]=ui->comboBox_Ant4Sensor09RF->currentText().toInt(&ok,10);
    iRFSetData[3][9]=ui->comboBox_Ant4Sensor10RF->currentText().toInt(&ok,10);
    iRFSetData[3][10]=ui->comboBox_Ant4Sensor11RF->currentText().toInt(&ok,10);
    iRFSetData[3][11]=ui->comboBox_Ant4Sensor12RF->currentText().toInt(&ok,10);

    QString strCMD;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(iSensorSet[i][j]==1)
            {
                if(iRFSetData[i][j]!=iRFReadData[i][j])
                {
                    iRFReadData[i][j]=iRFSetData[i][j];
                    if(iRFSetData[i][j]<10)
                    {
                        strCMD=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"51"+QString::number(i, 16).toUpper()+"0"+QString::number(iRFSetData[i][j], 10)+QString::number(j, 16).toUpper()+"<>";
                    }else
                    {
                        strCMD=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"51"+QString::number(i, 16).toUpper()+QString::number(iRFSetData[i][j], 10)+QString::number(j, 16).toUpper()+"<>";
                    }
                    strCMD=":"+strCMD+LRC_Calculate(strCMD).left(2)+"\r\n";
                    WTS_SerialPort->write(strCMD.toLatin1());
                    iSendPackageCount++;
                    ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
                    sleep(150);
                }
            }
        }
    }
    //发送开始测温命令
    SendCMDByReader(ui->comboBox_ReaderID->currentIndex(),"52");//start
}

void WTSCommDialog::on_checkBox_Ant1Sensor01Set_clicked()
{
    if(ui->checkBox_Ant1Sensor01Set->isChecked())
    {
        StatusSensor1_1="1";
        iSensorSet[0][0]=1;
    }
    else
    {
        StatusSensor1_1="0";
        iSensorSet[0][0]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor02Set_clicked()
{
    if(ui->checkBox_Ant1Sensor02Set->isChecked())
    {
        StatusSensor1_2="1";
        iSensorSet[0][1]=1;
    }
    else
    {
        StatusSensor1_2="0";
        iSensorSet[0][1]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor03Set_clicked()
{
    if(ui->checkBox_Ant1Sensor03Set->isChecked())
    {
        StatusSensor1_3="1";
        iSensorSet[0][2]=1;
    }
    else
    {
        StatusSensor1_3="0";
        iSensorSet[0][2]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor04Set_clicked()
{
    if(ui->checkBox_Ant1Sensor04Set->isChecked())
    {
        StatusSensor1_4="1";
        iSensorSet[0][3]=1;
    }
    else
    {
        StatusSensor1_4="0";
        iSensorSet[0][3]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor05Set_clicked()
{
    if(ui->checkBox_Ant1Sensor05Set->isChecked())
    {
        StatusSensor1_5="1";
        iSensorSet[0][4]=1;
    }
    else
    {
        StatusSensor1_5="0";
        iSensorSet[0][4]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor06Set_clicked()
{
    if(ui->checkBox_Ant1Sensor06Set->isChecked())
    {
        StatusSensor1_6="1";
        iSensorSet[0][5]=1;
    }
    else
    {
        StatusSensor1_6="0";
        iSensorSet[0][5]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor07Set_clicked()
{
    if(ui->checkBox_Ant1Sensor07Set->isChecked())
    {
        StatusSensor1_7="1";
        iSensorSet[0][6]=1;
    }
    else
    {
        StatusSensor1_7="0";
        iSensorSet[0][6]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor08Set_clicked()
{
    if(ui->checkBox_Ant1Sensor08Set->isChecked())
    {
        StatusSensor1_8="1";
        iSensorSet[0][7]=1;
    }
    else
    {
        StatusSensor1_8="0";
        iSensorSet[0][7]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor09Set_clicked()
{
    if(ui->checkBox_Ant1Sensor09Set->isChecked())
    {
        StatusSensor1_9="1";
        iSensorSet[0][8]=1;
    }
    else
    {
        StatusSensor1_9="0";
        iSensorSet[0][8]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor10Set_clicked()
{
    if(ui->checkBox_Ant1Sensor10Set->isChecked())
    {
        StatusSensor1_10="1";
        iSensorSet[0][9]=1;
    }
    else
    {
        StatusSensor1_10="0";
        iSensorSet[0][9]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor11Set_clicked()
{
    if(ui->checkBox_Ant1Sensor11Set->isChecked())
    {
        StatusSensor1_11="1";
        iSensorSet[0][10]=1;
    }
    else
    {
        StatusSensor1_11="0";
        iSensorSet[0][10]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant1Sensor12Set_clicked()
{
    if(ui->checkBox_Ant1Sensor12Set->isChecked())
    {
        StatusSensor1_12="1";
        iSensorSet[0][11]=1;
    }
    else
    {
        StatusSensor1_12="0";
        iSensorSet[0][11]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor01Set_clicked()
{
    if(ui->checkBox_Ant2Sensor01Set->isChecked())
    {
        StatusSensor2_1="1";
        iSensorSet[1][0]=1;
    }
    else
    {
        StatusSensor2_1="0";
        iSensorSet[1][0]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor02Set_clicked()
{
    if(ui->checkBox_Ant2Sensor02Set->isChecked())
    {
        StatusSensor2_2="1";
        iSensorSet[1][1]=1;
    }
    else
    {
        StatusSensor2_2="0";
        iSensorSet[1][1]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor03Set_clicked()
{
    if(ui->checkBox_Ant2Sensor03Set->isChecked())
    {
        StatusSensor2_3="1";
        iSensorSet[1][2]=1;
    }
    else
    {
        StatusSensor2_3="0";
        iSensorSet[1][2]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor04Set_clicked()
{
    if(ui->checkBox_Ant2Sensor04Set->isChecked())
    {
        StatusSensor2_4="1";
        iSensorSet[1][3]=1;
    }
    else
    {
        StatusSensor2_4="0";
        iSensorSet[1][3]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor05Set_clicked()
{
    if(ui->checkBox_Ant2Sensor05Set->isChecked())
    {
        StatusSensor2_5="1";
        iSensorSet[1][4]=1;
    }
    else
    {
        StatusSensor2_5="0";
        iSensorSet[1][4]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor06Set_clicked()
{
    if(ui->checkBox_Ant2Sensor06Set->isChecked())
    {
        StatusSensor2_6="1";
        iSensorSet[1][5]=1;
    }
    else
    {
        StatusSensor2_6="0";
        iSensorSet[1][5]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor07Set_clicked()
{
    if(ui->checkBox_Ant2Sensor07Set->isChecked())
    {
        StatusSensor2_7="1";
        iSensorSet[1][6]=1;
    }
    else
    {
        StatusSensor2_7="0";
        iSensorSet[1][6]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor08Set_clicked()
{
    if(ui->checkBox_Ant2Sensor08Set->isChecked())
    {
        StatusSensor2_8="1";
        iSensorSet[1][7]=1;
    }
    else
    {
        StatusSensor2_8="0";
        iSensorSet[1][7]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor09Set_clicked()
{
    if(ui->checkBox_Ant2Sensor09Set->isChecked())
    {
        StatusSensor2_9="1";
        iSensorSet[1][8]=1;
    }
    else
    {
        StatusSensor2_9="0";
        iSensorSet[1][8]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor10Set_clicked()
{
    if(ui->checkBox_Ant2Sensor10Set->isChecked())
    {
        StatusSensor2_10="1";
        iSensorSet[1][9]=1;
    }
    else
    {
        StatusSensor2_10="0";
        iSensorSet[1][9]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor11Set_clicked()
{
    if(ui->checkBox_Ant2Sensor11Set->isChecked())
    {
        StatusSensor2_11="1";
        iSensorSet[1][10]=1;
    }
    else
    {
        StatusSensor2_11="0";
        iSensorSet[1][10]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant2Sensor12Set_clicked()
{
    if(ui->checkBox_Ant2Sensor12Set->isChecked())
    {
        StatusSensor2_12="1";
        iSensorSet[1][11]=1;
    }
    else
    {
        StatusSensor2_12="0";
        iSensorSet[1][11]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor01Set_clicked()
{
    if(ui->checkBox_Ant3Sensor01Set->isChecked())
    {
        StatusSensor3_1="1";
        iSensorSet[2][0]=1;
    }
    else
    {
        StatusSensor3_1="0";
        iSensorSet[2][0]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor02Set_clicked()
{
    if(ui->checkBox_Ant3Sensor02Set->isChecked())
    {
        StatusSensor3_2="1";
        iSensorSet[2][1]=1;
    }
    else
    {
        StatusSensor3_2="0";
        iSensorSet[2][1]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor03Set_clicked()
{
    if(ui->checkBox_Ant3Sensor03Set->isChecked())
    {
        StatusSensor3_3="1";
        iSensorSet[2][2]=1;
    }
    else
    {
        StatusSensor3_3="0";
        iSensorSet[2][2]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor04Set_clicked()
{
    if(ui->checkBox_Ant3Sensor04Set->isChecked())
    {
        StatusSensor3_4="1";
        iSensorSet[2][3]=1;
    }
    else
    {
        StatusSensor3_4="0";
        iSensorSet[2][3]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor05Set_clicked()
{
    if(ui->checkBox_Ant3Sensor05Set->isChecked())
    {
        StatusSensor3_5="1";
        iSensorSet[2][4]=1;
    }
    else
    {
        StatusSensor3_5="0";
        iSensorSet[2][4]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor06Set_clicked()
{
    if(ui->checkBox_Ant3Sensor06Set->isChecked())
    {
        StatusSensor3_6="1";
        iSensorSet[2][5]=1;
    }
    else
    {
        StatusSensor3_6="0";
        iSensorSet[2][5]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor07Set_clicked()
{
    if(ui->checkBox_Ant3Sensor07Set->isChecked())
    {
        StatusSensor3_7="1";
        iSensorSet[2][6]=1;
    }
    else
    {
        StatusSensor3_7="0";
        iSensorSet[2][6]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor08Set_clicked()
{
    if(ui->checkBox_Ant3Sensor08Set->isChecked())
    {
        StatusSensor3_8="1";
        iSensorSet[2][7]=1;
    }
    else
    {
        StatusSensor3_8="0";
        iSensorSet[2][7]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor09Set_clicked()
{
    if(ui->checkBox_Ant3Sensor09Set->isChecked())
    {
        StatusSensor3_9="1";
        iSensorSet[2][8]=1;
    }
    else
    {
        StatusSensor3_9="0";
        iSensorSet[2][8]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor10Set_clicked()
{
    if(ui->checkBox_Ant3Sensor10Set->isChecked())
    {
        StatusSensor3_10="1";
        iSensorSet[2][9]=1;
    }
    else
    {
        StatusSensor3_10="0";
        iSensorSet[2][9]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor11Set_clicked()
{
    if(ui->checkBox_Ant3Sensor11Set->isChecked())
    {
        StatusSensor3_11="1";
        iSensorSet[2][10]=1;
    }
    else
    {
        StatusSensor3_11="0";
        iSensorSet[2][10]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant3Sensor12Set_clicked()
{
    if(ui->checkBox_Ant3Sensor12Set->isChecked())
    {
        StatusSensor3_12="1";
        iSensorSet[2][11]=1;
    }
    else
    {
        StatusSensor3_12="0";
        iSensorSet[2][11]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor01Set_clicked()
{
    if(ui->checkBox_Ant4Sensor01Set->isChecked())
    {
        StatusSensor4_1="1";
        iSensorSet[3][0]=1;
    }
    else
    {
        StatusSensor4_1="0";
        iSensorSet[3][0]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor02Set_clicked()
{
    if(ui->checkBox_Ant4Sensor02Set->isChecked())
    {
        StatusSensor4_2="1";
        iSensorSet[3][1]=1;
    }
    else
    {
        StatusSensor4_2="0";
        iSensorSet[3][1]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor03Set_clicked()
{
    if(ui->checkBox_Ant4Sensor03Set->isChecked())
    {
        StatusSensor4_3="1";
        iSensorSet[3][2]=1;
    }
    else
    {
        StatusSensor4_3="0";
        iSensorSet[3][2]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor04Set_clicked()
{
    if(ui->checkBox_Ant4Sensor04Set->isChecked())
    {
        StatusSensor4_4="1";
        iSensorSet[3][3]=1;
    }
    else
    {
        StatusSensor4_4="0";
        iSensorSet[3][3]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor05Set_clicked()
{
    if(ui->checkBox_Ant4Sensor05Set->isChecked())
    {
        StatusSensor4_5="1";
        iSensorSet[3][4]=1;
    }
    else
    {
        StatusSensor4_5="0";
        iSensorSet[3][4]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor06Set_clicked()
{
    if(ui->checkBox_Ant4Sensor06Set->isChecked())
    {
        StatusSensor4_6="1";
        iSensorSet[3][5]=1;
    }
    else
    {
        StatusSensor4_6="0";
        iSensorSet[3][5]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor07Set_clicked()
{
    if(ui->checkBox_Ant4Sensor07Set->isChecked())
    {
        StatusSensor4_7="1";
        iSensorSet[3][6]=1;
    }
    else
    {
        StatusSensor4_7="0";
        iSensorSet[3][6]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor08Set_clicked()
{
    if(ui->checkBox_Ant4Sensor08Set->isChecked())
    {
        StatusSensor4_8="1";
        iSensorSet[3][7]=1;
    }
    else
    {
        StatusSensor4_8="0";
        iSensorSet[3][7]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor09Set_clicked()
{
    if(ui->checkBox_Ant4Sensor09Set->isChecked())
    {
        StatusSensor4_9="1";
        iSensorSet[3][8]=1;
    }
    else
    {
        StatusSensor4_9="0";
        iSensorSet[3][8]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor10Set_clicked()
{
    if(ui->checkBox_Ant4Sensor10Set->isChecked())
    {
        StatusSensor4_10="1";
        iSensorSet[3][9]=1;
    }
    else
    {
        StatusSensor4_10="0";
        iSensorSet[3][9]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor11Set_clicked()
{
    if(ui->checkBox_Ant4Sensor11Set->isChecked())
    {
        StatusSensor4_11="1";
        iSensorSet[3][10]=1;
    }
    else
    {
        StatusSensor4_11="0";
        iSensorSet[3][10]=0;
    }
}

void WTSCommDialog::on_checkBox_Ant4Sensor12Set_clicked()
{
    if(ui->checkBox_Ant4Sensor12Set->isChecked())
    {
        StatusSensor4_12="1";
        iSensorSet[3][11]=1;
    }
    else
    {
        StatusSensor4_12="0";
        iSensorSet[3][11]=0;
    }
}

void WTSCommDialog::on_pushButton_CheckReaderCommunicate_clicked()
{
    SendCMDByReader(ui->comboBox_ReaderID->currentIndex(),"66");
    bRecvReaderStatusFlag=false;
    QTimer::singleShot(1000, this, SLOT(CheckReaderStatusTimeOut()));
}

void WTSCommDialog::CheckReaderStatusTimeOut()
{
    QPixmap pixmapDisconnect(":/image/image/diconnect.png");
    QPixmap fitpixmapDisconnect=pixmapDisconnect.scaled(ui->label_ReaderStatus->width(), ui->label_ReaderStatus->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    if(!bRecvReaderStatusFlag)
    {
        update();
        ui->label_ReaderStatus->setPixmap(fitpixmapDisconnect);
        ui->label_ReaderStatus->show();
    }
}

void WTSCommDialog::on_pushButton_SetTargetReaderID_clicked()
{
    QString strCMD;
    switch(QMessageBox::question(this,"操作说明",tr("注意！请确保将不需要更改ID的读取器从总线上断开！一旦设置所有挂接在总线上的读取器都会更改！"),
            QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
        {
        case QMessageBox::Ok:
            strCMD="0072"+ReaderID_Int2CString(ui->comboBox_TargetReaderID->currentIndex())+"00<>";
            strCMD=":"+strCMD+LRC_Calculate(strCMD).left(2)+"\r\n";
            if(CommOpenFlag)
            {
                WTS_SerialPort->write(strCMD.toLatin1());
                iSendPackageCount++;
                ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
                ui->lineEdit_CheckSetReaderIDStatus->setText("指令已发送，请等待设定状态检查……");
                ui->pushButton_SetTargetReaderID->setEnabled(false);
                SetReaderIDCheckStatusFlag=true;
                QTimer::singleShot(1000, this, SLOT(SendCheckReaderStatus()));
                QTimer::singleShot(5000, this, SLOT(SendCheckReaderStatusTimeOut()));
            }
            else
                QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
            break;
        case QMessageBox::Cancel:
//            label->setText(" Question button / Cancel ");
            break;
        default:
            break;
        }
        return;
}

void WTSCommDialog::SendCheckReaderStatusTimeOut()
{
    if(SetReaderIDCheckStatusFlag)
    {
        SetReaderIDCheckStatusFlag=false;
        ui->lineEdit_CheckSetReaderIDStatus->setText("读取器设定状态检查超时，请检查通信线路或读取器工作是否正常！");
        ui->pushButton_SetTargetReaderID->setEnabled(true);
    }
}

void WTSCommDialog::SendCheckReaderStatus()
{
    SendCMDByReader(ui->comboBox_TargetReaderID->currentIndex(),"66");
}

//void WTSCommDialog::paintEvent(QPaintEvent *event)
//{
//    update();
//    QPixmap pixmap(":/image/image/diconnect.png");
//    QPixmap fitpixmap=pixmap.scaled(ui->label_ReaderStatus->width(), ui->label_ReaderStatus->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    ui->label_ReaderStatus->setPixmap(fitpixmap);
//    ui->label_ReaderStatus->show();
//}

void WTSCommDialog::SendCMDByReader(int nIndexReader,QString CMD)
{
    QString StartCmd;
    switch (nIndexReader)
    {
    case 0:
        StartCmd="01"+CMD+"0000<>";//"@0631<>1"
        break;
    case 1:
        StartCmd="02"+CMD+"0000<>";
        break;
    case 2:
        StartCmd="03"+CMD+"0000<>";
        break;
    case 3:
        StartCmd="04"+CMD+"0000<>";
        break;
    case 4:
        StartCmd="05"+CMD+"0000<>";
        break;
    case 5:
        StartCmd="06"+CMD+"0000<>";
        break;
    case 6:
        StartCmd="07"+CMD+"0000<>";
        break;
    case 7:
        StartCmd="08"+CMD+"0000<>";
        break;
    case 8:
        StartCmd="09"+CMD+"0000<>";
        break;
    case 9:
        StartCmd="0a"+CMD+"0000<>";
        break;
    case 10:
        StartCmd="0b"+CMD+"0000<>";
        break;
    case 11:
        StartCmd="0c"+CMD+"0000<>";
        break;
    case 12:
        StartCmd="0d"+CMD+"0000<>";
        break;
    case 13:
        StartCmd="0e"+CMD+"0000<>";
        break;
    case 14:
        StartCmd="0f"+CMD+"0000<>";
        break;
    case 15:
        StartCmd="10"+CMD+"0000<>";
        break;
    case 16:
        StartCmd="11"+CMD+"0000<>";
        break;
    case 17:
        StartCmd="12"+CMD+"0000<>";
        break;
    case 18:
        StartCmd="13"+CMD+"0000<>";
        break;
    case 19:
        StartCmd="14"+CMD+"0000<>";
        break;
    case 20:
        StartCmd="15"+CMD+"0000<>";
        break;
    case 21:
        StartCmd="16"+CMD+"0000<>";
        break;
    case 22:
        StartCmd="17"+CMD+"0000<>";
        break;
    case 23:
        StartCmd="18"+CMD+"0000<>";
        break;
    case 24:
        StartCmd="19"+CMD+"0000<>";
        break;
    case 25:
        StartCmd="1a"+CMD+"0000<>";
        break;
    case 26:
        StartCmd="1b"+CMD+"0000<>";
        break;
    case 27:
        StartCmd="1c"+CMD+"0000<>";
        break;
    case 28:
        StartCmd="1d"+CMD+"0000<>";
        break;
    case 29:
        StartCmd="1e"+CMD+"0000<>";
        break;
    case 30:
        StartCmd="1f"+CMD+"0000<>";
        break;
    case 31:
        StartCmd="20"+CMD+"0000<>";
        break;
    case 32:
        StartCmd="21"+CMD+"0000<>";
        break;
    case 33:
        StartCmd="22"+CMD+"0000<>";
        break;
    case 34:
        StartCmd="23"+CMD+"0000<>";
        break;
    case 35:
        StartCmd="24"+CMD+"0000<>";
        break;
    case 36:
        StartCmd="25"+CMD+"0000<>";
        break;
    case 37:
        StartCmd="26"+CMD+"0000<>";
        break;
    case 38:
        StartCmd="27"+CMD+"0000<>";
        break;
    case 39:
        StartCmd="28"+CMD+"0000<>";
        break;
    case 40:
        StartCmd="29"+CMD+"0000<>";
        break;
    case 41:
        StartCmd="2a"+CMD+"0000<>";
        break;
    default:
        break;
    }
    StartCmd=":"+StartCmd+LRC_Calculate(StartCmd).left(2)+"\r\n";
    if(CommOpenFlag)
    {
        WTS_SerialPort->write(StartCmd.toLatin1());
        iSendPackageCount++;
        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
    }
    else
        QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
}

void WTSCommDialog::SendCMDByReaderAnt(int nIndexReader,QString CMD,QString sAnt)
{
    QString StartCmd;
    switch (nIndexReader)
    {
    case 0:
        StartCmd="01"+CMD+sAnt+"000<>";//"@0631<>1"
        break;
    case 1:
        StartCmd="02"+CMD+sAnt+"000<>";
        break;
    case 2:
        StartCmd="03"+CMD+sAnt+"000<>";
        break;
    case 3:
        StartCmd="04"+CMD+sAnt+"000<>";
        break;
    case 4:
        StartCmd="05"+CMD+sAnt+"000<>";
        break;
    case 5:
        StartCmd="06"+CMD+sAnt+"000<>";
        break;
    case 6:
        StartCmd="07"+CMD+sAnt+"000<>";
        break;
    case 7:
        StartCmd="08"+CMD+sAnt+"000<>";
        break;
    case 8:
        StartCmd="09"+CMD+sAnt+"000<>";
        break;
    case 9:
        StartCmd="0a"+CMD+sAnt+"000<>";
        break;
    case 10:
        StartCmd="0b"+CMD+sAnt+"000<>";
        break;
    case 11:
        StartCmd="0c"+CMD+sAnt+"000<>";
        break;
    case 12:
        StartCmd="0d"+CMD+sAnt+"000<>";
        break;
    case 13:
        StartCmd="0e"+CMD+sAnt+"000<>";
        break;
    case 14:
        StartCmd="0f"+CMD+sAnt+"000<>";
        break;
    case 15:
        StartCmd="10"+CMD+sAnt+"000<>";
        break;
    case 16:
        StartCmd="11"+CMD+sAnt+"000<>";
        break;
    case 17:
        StartCmd="12"+CMD+sAnt+"000<>";
        break;
    case 18:
        StartCmd="13"+CMD+sAnt+"000<>";
        break;
    case 19:
        StartCmd="14"+CMD+sAnt+"000<>";
        break;
    case 20:
        StartCmd="15"+CMD+sAnt+"000<>";
        break;
    case 21:
        StartCmd="16"+CMD+sAnt+"000<>";
        break;
    case 22:
        StartCmd="17"+CMD+sAnt+"000<>";
        break;
    case 23:
        StartCmd="18"+CMD+sAnt+"000<>";
        break;
    case 24:
        StartCmd="19"+CMD+sAnt+"000<>";
        break;
    case 25:
        StartCmd="1a"+CMD+sAnt+"000<>";
        break;
    case 26:
        StartCmd="1b"+CMD+sAnt+"000<>";
        break;
    case 27:
        StartCmd="1c"+CMD+sAnt+"000<>";
        break;
    case 28:
        StartCmd="1d"+CMD+sAnt+"000<>";
        break;
    case 29:
        StartCmd="1e"+CMD+sAnt+"000<>";
        break;
    case 30:
        StartCmd="1f"+CMD+sAnt+"000<>";
        break;
    case 31:
        StartCmd="20"+CMD+sAnt+"000<>";
        break;
    case 32:
        StartCmd="21"+CMD+sAnt+"000<>";
        break;
    case 33:
        StartCmd="22"+CMD+sAnt+"000<>";
        break;
    case 34:
        StartCmd="23"+CMD+sAnt+"000<>";
        break;
    case 35:
        StartCmd="24"+CMD+sAnt+"000<>";
        break;
    case 36:
        StartCmd="25"+CMD+sAnt+"000<>";
        break;
    case 37:
        StartCmd="26"+CMD+sAnt+"000<>";
        break;
    case 38:
        StartCmd="27"+CMD+sAnt+"000<>";
        break;
    case 39:
        StartCmd="28"+CMD+sAnt+"000<>";
        break;
    case 40:
        StartCmd="29"+CMD+sAnt+"000<>";
        break;
    case 41:
        StartCmd="2a"+CMD+sAnt+"000<>";
        break;
    default:
        break;
    }
    StartCmd=":"+StartCmd+LRC_Calculate(StartCmd).left(2)+"\r\n";
    if(CommOpenFlag)
    {
        WTS_SerialPort->write(StartCmd.toLatin1());
        iSendPackageCount++;
        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
    }
    else
        QMessageBox::critical(this,"错误",tr("数据发送失败，请先打开通信端口！"));
}

void WTSCommDialog::on_pushButton_CalTemp_clicked()
{
    if(0==ui->comboBox_CalMethod->currentIndex())
    {
        QString SensorFreq,Ant_Cmd,Tab_Cmd;
        for (int i = 0; i < 4; i++)
        {
            if (m_FreqData[i][ui->comboBox_SensorID->currentIndex()]>10)
            {
                SensorFreq=QString::number(m_FreqData[i][ui->comboBox_SensorID->currentIndex()],10);
                Ant_Cmd=QString::number(i+1,16);
                break;
            }
        }
        Tab_Cmd=QString::number(ui->comboBox_SensorID->currentIndex(),16).toLower();

        if (ui->lineEdit_CalTemp->text().length()!=4)
        {
            QMessageBox::critical(this,"错误",tr("请选择正确的传感器，并输入正确的数字格式！（温度为带+-的3位阿拉伯数字）！"));
        }else
        {
            QString FixStr;
            FixStr=Tab_Cmd+SensorFreq+ui->lineEdit_CalTemp->text()+Ant_Cmd+"0";
            QString cmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(0,6);
            cmd1=":"+cmd1+LRC_Calculate(cmd1).left(2)+"\r\n";
            WTS_SerialPort->write(cmd1.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
            sleep(150);
            QString cmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(6,6);
            cmd2=":"+cmd2+LRC_Calculate(cmd2).left(2)+"\r\n";
            WTS_SerialPort->write(cmd2.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
            sleep(150);
            QString cmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(12,4)+"<>";
            cmd3=":"+cmd3+LRC_Calculate(cmd3).left(2)+"\r\n";
            WTS_SerialPort->write(cmd3.toLatin1());
            iSendPackageCount++;
            ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
            QMessageBox::critical(this,"注意",tr("校准命令发送成功！"));
        }
    }else if(1==ui->comboBox_CalMethod->currentIndex())
    {
        if (ui->lineEdit_CalTemp->text().length()==4)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 12; j++)
                {
                    if (m_FreqData[i][j]>10&&iSensorSet[i][j]==1)
                    {
                        QString SensorFreq,Ant_Cmd,Tab_Cmd;
                        SensorFreq=QString::number(m_FreqData[i][j],10);
                        Ant_Cmd=QString::number(i+1,16);
                        Tab_Cmd=QString::number(j,16).toLower();
                        QString FixStr;
                        FixStr=Tab_Cmd+SensorFreq+ui->lineEdit_CalTemp->text()+Ant_Cmd+"0";
                        QString cmd1=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(0,6);
                        cmd1=":"+cmd1+LRC_Calculate(cmd1).left(2)+"\r\n";
                        WTS_SerialPort->write(cmd1.toLatin1());
                        iSendPackageCount++;
                        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
                        sleep(150);
                        QString cmd2=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(6,6);
                        cmd2=":"+cmd2+LRC_Calculate(cmd2).left(2)+"\r\n";
                        WTS_SerialPort->write(cmd2.toLatin1());
                        iSendPackageCount++;
                        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
                        sleep(150);
                        QString cmd3=ReaderID_Int2CString(ui->comboBox_ReaderID->currentIndex())+"58"+FixStr.mid(12,4)+"<>";
                        cmd3=":"+cmd3+LRC_Calculate(cmd3).left(2)+"\r\n";
                        WTS_SerialPort->write(cmd3.toLatin1());
                        iSendPackageCount++;
                        ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
                        sleep(150);
                    }
                }
            }
            QMessageBox::critical(this,"注意",tr("批量校准操作完成！"));
        }
        else
        {
            QMessageBox::critical(this,"错误",tr("请选择正确的传感器，并输入正确的数字格式！（温度为带+-的3位阿拉伯数字）！"));
        }
    }
}

void WTSCommDialog::on_pushButton_ImportParmFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*)"));
    if(!fileName.isNull())
    {
        if(!ReadParmFromFile(fileName))
        {
            QMessageBox::critical(this,"错误",tr("参数文件读取失败，请确认文件路径及文件内容！"));
        }else
        {
            ui->lineEdit_ParmFileName->setText(fileName);
            QMessageBox::critical(this,"提醒",tr("参数文件导入成功！"));
        }
    }
}

void WTSCommDialog::SaveParmToFile(QString FileName)
{
    QFile file(FileName+".txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << "ConfigFile" << "\n";

    out << ui->comboBox_ReaderID->currentIndex() << "\n";

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            out << iSensorSet[i][j];
        }
    }
    out << "\n";

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            if(iRFSetData[i][j]<9)
            {
                out << 0 << iRFSetData[i][j];
            }else
            {
                out << iRFSetData[i][j];
            }
        }
    }
    out << "\n";
}

bool WTSCommDialog::ReadParmFromFile(QString FileName)
{
    QFile file(FileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    QTextStream in(&file);
    QString line = in.readLine();
    if(QString::compare(line,"ConfigFile",Qt::CaseSensitive)!=0) return false;
    line = in.readLine();
    if(!line.isNull()) ui->comboBox_ReaderID->setCurrentIndex(line.toInt());//readerid

    line = in.readLine();//天线使能
    if(!line.isNull())
    {
        iSensorSet[0][0]=line.mid(0,1).toInt();
        iSensorSet[0][1]=line.mid(1,1).toInt();
        iSensorSet[0][2]=line.mid(2,1).toInt();
        iSensorSet[0][3]=line.mid(3,1).toInt();
        iSensorSet[0][4]=line.mid(4,1).toInt();
        iSensorSet[0][5]=line.mid(5,1).toInt();
        iSensorSet[0][6]=line.mid(6,1).toInt();
        iSensorSet[0][7]=line.mid(7,1).toInt();
        iSensorSet[0][8]=line.mid(8,1).toInt();
        iSensorSet[0][9]=line.mid(9,1).toInt();
        iSensorSet[0][10]=line.mid(10,1).toInt();
        iSensorSet[0][11]=line.mid(11,1).toInt();
        iSensorSet[1][0]=line.mid(12,1).toInt();
        iSensorSet[1][1]=line.mid(13,1).toInt();
        iSensorSet[1][2]=line.mid(14,1).toInt();
        iSensorSet[1][3]=line.mid(15,1).toInt();
        iSensorSet[1][4]=line.mid(16,1).toInt();
        iSensorSet[1][5]=line.mid(17,1).toInt();
        iSensorSet[1][6]=line.mid(18,1).toInt();
        iSensorSet[1][7]=line.mid(19,1).toInt();
        iSensorSet[1][8]=line.mid(20,1).toInt();
        iSensorSet[1][9]=line.mid(21,1).toInt();
        iSensorSet[1][10]=line.mid(22,1).toInt();
        iSensorSet[1][11]=line.mid(23,1).toInt();
        iSensorSet[2][0]=line.mid(24,1).toInt();
        iSensorSet[2][1]=line.mid(25,1).toInt();
        iSensorSet[2][2]=line.mid(26,1).toInt();
        iSensorSet[2][3]=line.mid(27,1).toInt();
        iSensorSet[2][4]=line.mid(28,1).toInt();
        iSensorSet[2][5]=line.mid(29,1).toInt();
        iSensorSet[2][6]=line.mid(30,1).toInt();
        iSensorSet[2][7]=line.mid(31,1).toInt();
        iSensorSet[2][8]=line.mid(32,1).toInt();
        iSensorSet[2][9]=line.mid(33,1).toInt();
        iSensorSet[2][10]=line.mid(34,1).toInt();
        iSensorSet[2][11]=line.mid(35,1).toInt();
        iSensorSet[3][0]=line.mid(36,1).toInt();
        iSensorSet[3][1]=line.mid(37,1).toInt();
        iSensorSet[3][2]=line.mid(38,1).toInt();
        iSensorSet[3][3]=line.mid(39,1).toInt();
        iSensorSet[3][4]=line.mid(40,1).toInt();
        iSensorSet[3][5]=line.mid(41,1).toInt();
        iSensorSet[3][6]=line.mid(42,1).toInt();
        iSensorSet[3][7]=line.mid(43,1).toInt();
        iSensorSet[3][8]=line.mid(44,1).toInt();
        iSensorSet[3][9]=line.mid(45,1).toInt();
        iSensorSet[3][10]=line.mid(46,1).toInt();
        iSensorSet[3][11]=line.mid(47,1).toInt();
        ui->checkBox_Ant1Sensor01Set->setChecked(iSensorSet[0][0]);
        ui->checkBox_Ant1Sensor02Set->setChecked(iSensorSet[0][1]);
        ui->checkBox_Ant1Sensor03Set->setChecked(iSensorSet[0][2]);
        ui->checkBox_Ant1Sensor04Set->setChecked(iSensorSet[0][3]);
        ui->checkBox_Ant1Sensor05Set->setChecked(iSensorSet[0][4]);
        ui->checkBox_Ant1Sensor06Set->setChecked(iSensorSet[0][5]);
        ui->checkBox_Ant1Sensor07Set->setChecked(iSensorSet[0][6]);
        ui->checkBox_Ant1Sensor08Set->setChecked(iSensorSet[0][7]);
        ui->checkBox_Ant1Sensor09Set->setChecked(iSensorSet[0][8]);
        ui->checkBox_Ant1Sensor10Set->setChecked(iSensorSet[0][9]);
        ui->checkBox_Ant1Sensor11Set->setChecked(iSensorSet[0][10]);
        ui->checkBox_Ant1Sensor12Set->setChecked(iSensorSet[0][11]);
        ui->checkBox_Ant2Sensor01Set->setChecked(iSensorSet[1][0]);
        ui->checkBox_Ant2Sensor02Set->setChecked(iSensorSet[1][1]);
        ui->checkBox_Ant2Sensor03Set->setChecked(iSensorSet[1][2]);
        ui->checkBox_Ant2Sensor04Set->setChecked(iSensorSet[1][3]);
        ui->checkBox_Ant2Sensor05Set->setChecked(iSensorSet[1][4]);
        ui->checkBox_Ant2Sensor06Set->setChecked(iSensorSet[1][5]);
        ui->checkBox_Ant2Sensor07Set->setChecked(iSensorSet[1][6]);
        ui->checkBox_Ant2Sensor08Set->setChecked(iSensorSet[1][7]);
        ui->checkBox_Ant2Sensor09Set->setChecked(iSensorSet[1][8]);
        ui->checkBox_Ant2Sensor10Set->setChecked(iSensorSet[1][9]);
        ui->checkBox_Ant2Sensor11Set->setChecked(iSensorSet[1][10]);
        ui->checkBox_Ant2Sensor12Set->setChecked(iSensorSet[1][11]);
        ui->checkBox_Ant3Sensor01Set->setChecked(iSensorSet[2][0]);
        ui->checkBox_Ant3Sensor02Set->setChecked(iSensorSet[2][1]);
        ui->checkBox_Ant3Sensor03Set->setChecked(iSensorSet[2][2]);
        ui->checkBox_Ant3Sensor04Set->setChecked(iSensorSet[2][3]);
        ui->checkBox_Ant3Sensor05Set->setChecked(iSensorSet[2][4]);
        ui->checkBox_Ant3Sensor06Set->setChecked(iSensorSet[2][5]);
        ui->checkBox_Ant3Sensor07Set->setChecked(iSensorSet[2][6]);
        ui->checkBox_Ant3Sensor08Set->setChecked(iSensorSet[2][7]);
        ui->checkBox_Ant3Sensor09Set->setChecked(iSensorSet[2][8]);
        ui->checkBox_Ant3Sensor10Set->setChecked(iSensorSet[2][9]);
        ui->checkBox_Ant3Sensor11Set->setChecked(iSensorSet[2][10]);
        ui->checkBox_Ant3Sensor12Set->setChecked(iSensorSet[2][11]);
        ui->checkBox_Ant4Sensor01Set->setChecked(iSensorSet[3][0]);
        ui->checkBox_Ant4Sensor02Set->setChecked(iSensorSet[3][1]);
        ui->checkBox_Ant4Sensor03Set->setChecked(iSensorSet[3][2]);
        ui->checkBox_Ant4Sensor04Set->setChecked(iSensorSet[3][3]);
        ui->checkBox_Ant4Sensor05Set->setChecked(iSensorSet[3][4]);
        ui->checkBox_Ant4Sensor06Set->setChecked(iSensorSet[3][5]);
        ui->checkBox_Ant4Sensor07Set->setChecked(iSensorSet[3][6]);
        ui->checkBox_Ant4Sensor08Set->setChecked(iSensorSet[3][7]);
        ui->checkBox_Ant4Sensor09Set->setChecked(iSensorSet[3][8]);
        ui->checkBox_Ant4Sensor10Set->setChecked(iSensorSet[3][9]);
        ui->checkBox_Ant4Sensor11Set->setChecked(iSensorSet[3][10]);
        ui->checkBox_Ant4Sensor12Set->setChecked(iSensorSet[3][11]);
    }

    line = in.readLine();//衰减
    if(!line.isNull())
    {
        iRFSetData[0][0]=line.mid(0,2).toInt();
        iRFSetData[0][1]=line.mid(2,2).toInt();
        iRFSetData[0][2]=line.mid(4,2).toInt();
        iRFSetData[0][3]=line.mid(6,2).toInt();
        iRFSetData[0][4]=line.mid(8,2).toInt();
        iRFSetData[0][5]=line.mid(10,2).toInt();
        iRFSetData[0][6]=line.mid(12,2).toInt();
        iRFSetData[0][7]=line.mid(14,2).toInt();
        iRFSetData[0][8]=line.mid(16,2).toInt();
        iRFSetData[0][9]=line.mid(18,2).toInt();
        iRFSetData[0][10]=line.mid(20,2).toInt();
        iRFSetData[0][11]=line.mid(22,2).toInt();
        iRFSetData[1][0]=line.mid(24,2).toInt();
        iRFSetData[1][1]=line.mid(26,2).toInt();
        iRFSetData[1][2]=line.mid(28,2).toInt();
        iRFSetData[1][3]=line.mid(30,2).toInt();
        iRFSetData[1][4]=line.mid(32,2).toInt();
        iRFSetData[1][5]=line.mid(34,2).toInt();
        iRFSetData[1][6]=line.mid(36,2).toInt();
        iRFSetData[1][7]=line.mid(38,2).toInt();
        iRFSetData[1][8]=line.mid(40,2).toInt();
        iRFSetData[1][9]=line.mid(42,2).toInt();
        iRFSetData[1][10]=line.mid(44,2).toInt();
        iRFSetData[1][11]=line.mid(46,2).toInt();
        iRFSetData[2][0]=line.mid(48,2).toInt();
        iRFSetData[2][1]=line.mid(50,2).toInt();
        iRFSetData[2][2]=line.mid(52,2).toInt();
        iRFSetData[2][3]=line.mid(54,2).toInt();
        iRFSetData[2][4]=line.mid(56,2).toInt();
        iRFSetData[2][5]=line.mid(58,2).toInt();
        iRFSetData[2][6]=line.mid(60,2).toInt();
        iRFSetData[2][7]=line.mid(62,2).toInt();
        iRFSetData[2][8]=line.mid(64,2).toInt();
        iRFSetData[2][9]=line.mid(66,2).toInt();
        iRFSetData[2][10]=line.mid(68,2).toInt();
        iRFSetData[2][11]=line.mid(70,2).toInt();
        iRFSetData[3][0]=line.mid(72,2).toInt();
        iRFSetData[3][1]=line.mid(74,2).toInt();
        iRFSetData[3][2]=line.mid(76,2).toInt();
        iRFSetData[3][3]=line.mid(78,2).toInt();
        iRFSetData[3][4]=line.mid(80,2).toInt();
        iRFSetData[3][5]=line.mid(82,2).toInt();
        iRFSetData[3][6]=line.mid(84,2).toInt();
        iRFSetData[3][7]=line.mid(86,2).toInt();
        iRFSetData[3][8]=line.mid(88,2).toInt();
        iRFSetData[3][9]=line.mid(90,2).toInt();
        iRFSetData[3][10]=line.mid(92,2).toInt();
        iRFSetData[3][11]=line.mid(94,2).toInt();
        ui->comboBox_Ant1Sensor01RF->setCurrentIndex(iRFSetData[0][0]);
        ui->comboBox_Ant1Sensor02RF->setCurrentIndex(iRFSetData[0][1]);
        ui->comboBox_Ant1Sensor03RF->setCurrentIndex(iRFSetData[0][2]);
        ui->comboBox_Ant1Sensor04RF->setCurrentIndex(iRFSetData[0][3]);
        ui->comboBox_Ant1Sensor05RF->setCurrentIndex(iRFSetData[0][4]);
        ui->comboBox_Ant1Sensor06RF->setCurrentIndex(iRFSetData[0][5]);
        ui->comboBox_Ant1Sensor07RF->setCurrentIndex(iRFSetData[0][6]);
        ui->comboBox_Ant1Sensor08RF->setCurrentIndex(iRFSetData[0][7]);
        ui->comboBox_Ant1Sensor09RF->setCurrentIndex(iRFSetData[0][8]);
        ui->comboBox_Ant1Sensor10RF->setCurrentIndex(iRFSetData[0][9]);
        ui->comboBox_Ant1Sensor11RF->setCurrentIndex(iRFSetData[0][10]);
        ui->comboBox_Ant1Sensor12RF->setCurrentIndex(iRFSetData[0][11]);
        ui->comboBox_Ant2Sensor01RF->setCurrentIndex(iRFSetData[1][0]);
        ui->comboBox_Ant2Sensor02RF->setCurrentIndex(iRFSetData[1][1]);
        ui->comboBox_Ant2Sensor03RF->setCurrentIndex(iRFSetData[1][2]);
        ui->comboBox_Ant2Sensor04RF->setCurrentIndex(iRFSetData[1][3]);
        ui->comboBox_Ant2Sensor05RF->setCurrentIndex(iRFSetData[1][4]);
        ui->comboBox_Ant2Sensor06RF->setCurrentIndex(iRFSetData[1][5]);
        ui->comboBox_Ant2Sensor07RF->setCurrentIndex(iRFSetData[1][6]);
        ui->comboBox_Ant2Sensor08RF->setCurrentIndex(iRFSetData[1][7]);
        ui->comboBox_Ant2Sensor09RF->setCurrentIndex(iRFSetData[1][8]);
        ui->comboBox_Ant2Sensor10RF->setCurrentIndex(iRFSetData[1][9]);
        ui->comboBox_Ant2Sensor11RF->setCurrentIndex(iRFSetData[1][10]);
        ui->comboBox_Ant2Sensor12RF->setCurrentIndex(iRFSetData[1][11]);
        ui->comboBox_Ant3Sensor01RF->setCurrentIndex(iRFSetData[2][0]);
        ui->comboBox_Ant3Sensor02RF->setCurrentIndex(iRFSetData[2][1]);
        ui->comboBox_Ant3Sensor03RF->setCurrentIndex(iRFSetData[2][2]);
        ui->comboBox_Ant3Sensor04RF->setCurrentIndex(iRFSetData[2][3]);
        ui->comboBox_Ant3Sensor05RF->setCurrentIndex(iRFSetData[2][4]);
        ui->comboBox_Ant3Sensor06RF->setCurrentIndex(iRFSetData[2][5]);
        ui->comboBox_Ant3Sensor07RF->setCurrentIndex(iRFSetData[2][6]);
        ui->comboBox_Ant3Sensor08RF->setCurrentIndex(iRFSetData[2][7]);
        ui->comboBox_Ant3Sensor09RF->setCurrentIndex(iRFSetData[2][8]);
        ui->comboBox_Ant3Sensor10RF->setCurrentIndex(iRFSetData[2][9]);
        ui->comboBox_Ant3Sensor11RF->setCurrentIndex(iRFSetData[2][10]);
        ui->comboBox_Ant3Sensor12RF->setCurrentIndex(iRFSetData[2][11]);
        ui->comboBox_Ant4Sensor01RF->setCurrentIndex(iRFSetData[3][0]);
        ui->comboBox_Ant4Sensor02RF->setCurrentIndex(iRFSetData[3][1]);
        ui->comboBox_Ant4Sensor03RF->setCurrentIndex(iRFSetData[3][2]);
        ui->comboBox_Ant4Sensor04RF->setCurrentIndex(iRFSetData[3][3]);
        ui->comboBox_Ant4Sensor05RF->setCurrentIndex(iRFSetData[3][4]);
        ui->comboBox_Ant4Sensor06RF->setCurrentIndex(iRFSetData[3][5]);
        ui->comboBox_Ant4Sensor07RF->setCurrentIndex(iRFSetData[3][6]);
        ui->comboBox_Ant4Sensor08RF->setCurrentIndex(iRFSetData[3][7]);
        ui->comboBox_Ant4Sensor09RF->setCurrentIndex(iRFSetData[3][8]);
        ui->comboBox_Ant4Sensor10RF->setCurrentIndex(iRFSetData[3][9]);
        ui->comboBox_Ant4Sensor11RF->setCurrentIndex(iRFSetData[3][10]);
        ui->comboBox_Ant4Sensor12RF->setCurrentIndex(iRFSetData[3][11]);
    }
    return true;
}

void WTSCommDialog::on_pushButton_ClearAll_clicked()
{
    InitMainDlgItem();
    iSendPackageCount=0;
    ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
    iRecvPackageCount=0;
    ui->label_RecvPackage->setText("发送包："+QString::number(iRecvPackageCount,10));
}

void WTSCommDialog::on_comboBox_ReaderID_currentIndexChanged(int index)
{
    InitMainDlgItem();
    iSendPackageCount=0;
    ui->label_SendPackage->setText("发送包："+QString::number(iSendPackageCount,10));
    iRecvPackageCount=0;
    ui->label_RecvPackage->setText("发送包："+QString::number(iRecvPackageCount,10));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<12;j++)
        {
            iSensorSet[i][j]=0;
            iSensorRead[i][j]=0;
            iRFReadData[i][j]=0;
            iRFSetData[i][j]=0;
        }
    }
    ui->checkBox_Ant1Sensor01Set->setChecked(false);
    ui->checkBox_Ant1Sensor02Set->setChecked(false);
    ui->checkBox_Ant1Sensor03Set->setChecked(false);
    ui->checkBox_Ant1Sensor04Set->setChecked(false);
    ui->checkBox_Ant1Sensor05Set->setChecked(false);
    ui->checkBox_Ant1Sensor06Set->setChecked(false);
    ui->checkBox_Ant1Sensor07Set->setChecked(false);
    ui->checkBox_Ant1Sensor08Set->setChecked(false);
    ui->checkBox_Ant1Sensor09Set->setChecked(false);
    ui->checkBox_Ant1Sensor10Set->setChecked(false);
    ui->checkBox_Ant1Sensor11Set->setChecked(false);
    ui->checkBox_Ant1Sensor12Set->setChecked(false);
    ui->comboBox_Ant1Sensor01RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor02RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor03RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor04RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor05RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor06RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor07RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor08RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor09RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor10RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor11RF->setCurrentIndex(0);
    ui->comboBox_Ant1Sensor12RF->setCurrentIndex(0);
    ui->checkBox_Ant2Sensor01Set->setChecked(false);
    ui->checkBox_Ant2Sensor02Set->setChecked(false);
    ui->checkBox_Ant2Sensor03Set->setChecked(false);
    ui->checkBox_Ant2Sensor04Set->setChecked(false);
    ui->checkBox_Ant2Sensor05Set->setChecked(false);
    ui->checkBox_Ant2Sensor06Set->setChecked(false);
    ui->checkBox_Ant2Sensor07Set->setChecked(false);
    ui->checkBox_Ant2Sensor08Set->setChecked(false);
    ui->checkBox_Ant2Sensor09Set->setChecked(false);
    ui->checkBox_Ant2Sensor10Set->setChecked(false);
    ui->checkBox_Ant2Sensor11Set->setChecked(false);
    ui->checkBox_Ant2Sensor12Set->setChecked(false);
    ui->comboBox_Ant2Sensor01RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor02RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor03RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor04RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor05RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor06RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor07RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor08RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor09RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor10RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor11RF->setCurrentIndex(0);
    ui->comboBox_Ant2Sensor12RF->setCurrentIndex(0);
    ui->checkBox_Ant3Sensor01Set->setChecked(false);
    ui->checkBox_Ant3Sensor02Set->setChecked(false);
    ui->checkBox_Ant3Sensor03Set->setChecked(false);
    ui->checkBox_Ant3Sensor04Set->setChecked(false);
    ui->checkBox_Ant3Sensor05Set->setChecked(false);
    ui->checkBox_Ant3Sensor06Set->setChecked(false);
    ui->checkBox_Ant3Sensor07Set->setChecked(false);
    ui->checkBox_Ant3Sensor08Set->setChecked(false);
    ui->checkBox_Ant3Sensor09Set->setChecked(false);
    ui->checkBox_Ant3Sensor10Set->setChecked(false);
    ui->checkBox_Ant3Sensor11Set->setChecked(false);
    ui->checkBox_Ant3Sensor12Set->setChecked(false);
    ui->comboBox_Ant3Sensor01RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor02RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor03RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor04RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor05RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor06RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor07RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor08RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor09RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor10RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor11RF->setCurrentIndex(0);
    ui->comboBox_Ant3Sensor12RF->setCurrentIndex(0);
    ui->checkBox_Ant4Sensor01Set->setChecked(false);
    ui->checkBox_Ant4Sensor02Set->setChecked(false);
    ui->checkBox_Ant4Sensor03Set->setChecked(false);
    ui->checkBox_Ant4Sensor04Set->setChecked(false);
    ui->checkBox_Ant4Sensor05Set->setChecked(false);
    ui->checkBox_Ant4Sensor06Set->setChecked(false);
    ui->checkBox_Ant4Sensor07Set->setChecked(false);
    ui->checkBox_Ant4Sensor08Set->setChecked(false);
    ui->checkBox_Ant4Sensor09Set->setChecked(false);
    ui->checkBox_Ant4Sensor10Set->setChecked(false);
    ui->checkBox_Ant4Sensor11Set->setChecked(false);
    ui->checkBox_Ant4Sensor12Set->setChecked(false);
    ui->comboBox_Ant4Sensor01RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor02RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor03RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor04RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor05RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor06RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor07RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor08RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor09RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor10RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor11RF->setCurrentIndex(0);
    ui->comboBox_Ant4Sensor12RF->setCurrentIndex(0);
    StatusSensor1_1="0";
    StatusSensor1_2="0";
    StatusSensor1_3="0";
    StatusSensor1_4="0";
    StatusSensor1_5="0";
    StatusSensor1_6="0";
    StatusSensor1_7="0";
    StatusSensor1_8="0";
    StatusSensor1_9="0";
    StatusSensor1_10="0";
    StatusSensor1_11="0";
    StatusSensor1_12="0";
    StatusSensor2_1="0";
    StatusSensor2_2="0";
    StatusSensor2_3="0";
    StatusSensor2_4="0";
    StatusSensor2_5="0";
    StatusSensor2_6="0";
    StatusSensor2_7="0";
    StatusSensor2_8="0";
    StatusSensor2_9="0";
    StatusSensor2_10="0";
    StatusSensor2_11="0";
    StatusSensor2_12="0";
    StatusSensor3_1="0";
    StatusSensor3_2="0";
    StatusSensor3_3="0";
    StatusSensor3_4="0";
    StatusSensor3_5="0";
    StatusSensor3_6="0";
    StatusSensor3_7="0";
    StatusSensor3_8="0";
    StatusSensor3_9="0";
    StatusSensor3_10="0";
    StatusSensor3_11="0";
    StatusSensor3_12="0";
    StatusSensor4_1="0";
    StatusSensor4_2="0";
    StatusSensor4_3="0";
    StatusSensor4_4="0";
    StatusSensor4_5="0";
    StatusSensor4_6="0";
    StatusSensor4_7="0";
    StatusSensor4_8="0";
    StatusSensor4_9="0";
    StatusSensor4_10="0";
    StatusSensor4_11="0";
    StatusSensor4_12="0";
}
