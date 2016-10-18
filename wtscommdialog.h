#ifndef WTSCOMMDIALOG_H
#define WTSCOMMDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <string.h>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <Qt>
#include <QDebug>
#include <QPainter>

namespace Ui {
class WTSCommDialog;
}

class WTSCommDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WTSCommDialog(QWidget *parent = 0);
    ~WTSCommDialog();

public:
    int iRecvPackageCount;//接收包技术
    int iSendPackageCount;//发送包计数

    int ReceiveDataCount;//
    int StatusForRecv;//数据接收状态机
    int DebugStopFlagStatus;//调试模式下记录是否接收到调试数据，状态机

    int iSensorSet[4][12];//
    int iRFSetData[4][12];//
    int iRFReadData[4][12];//
    QString  receiveMsg;//
    unsigned int Power_Data;
    unsigned int Freq_Data;
    float Temper_Data;

    int m_FreqData[4][12];//保存校准时的频点值
    int DataForDebug[4][12][3];//保存用于自动调试的各种数据，0为频点值，1为功率值，2为衰减值

    //BYTE rxdata[256]; //设置BYTE数组，存储接收数据
    unsigned char*  rxdata;
    bool CommOpenFlag;//true is open ,false is close

    bool SetReaderIDCheckStatusFlag;//true is checking,false is check over

    bool FlagForDebugButton;//true is pressed,false is released

    bool FlagForGetTempButton;//true is pressed,false is released

    bool singleShotFlag;//true is can be start ,false is stop timer

    QString StatusSensor1_1;
    QString StatusSensor1_2;
    QString StatusSensor1_3;
    QString StatusSensor1_4;
    QString StatusSensor1_5;
    QString StatusSensor1_6;
    QString StatusSensor1_7;
    QString StatusSensor1_8;
    QString StatusSensor1_9;
    QString StatusSensor1_10;
    QString StatusSensor1_11;
    QString StatusSensor1_12;
    QString StatusSensor2_1;
    QString StatusSensor2_2;
    QString StatusSensor2_3;
    QString StatusSensor2_4;
    QString StatusSensor2_5;
    QString StatusSensor2_6;
    QString StatusSensor2_7;
    QString StatusSensor2_8;
    QString StatusSensor2_9;
    QString StatusSensor2_10;
    QString StatusSensor2_11;
    QString StatusSensor2_12;
    QString StatusSensor3_1;
    QString StatusSensor3_2;
    QString StatusSensor3_3;
    QString StatusSensor3_4;
    QString StatusSensor3_5;
    QString StatusSensor3_6;
    QString StatusSensor3_7;
    QString StatusSensor3_8;
    QString StatusSensor3_9;
    QString StatusSensor3_10;
    QString StatusSensor3_11;
    QString StatusSensor3_12;
    QString StatusSensor4_1;
    QString StatusSensor4_2;
    QString StatusSensor4_3;
    QString StatusSensor4_4;
    QString StatusSensor4_5;
    QString StatusSensor4_6;
    QString StatusSensor4_7;
    QString StatusSensor4_8;
    QString StatusSensor4_9;
    QString StatusSensor4_10;
    QString StatusSensor4_11;
    QString StatusSensor4_12;
public:
    void InitSystemParm(void);//初始化一些系统参数和变量
    void SaveParmToFile(QString FileName);

    bool ReadParmFromFile(QString FileName);

    void Ant1DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData);
    void Ant2DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData);
    void Ant3DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData);
    void Ant4DataFix(unsigned char SensorID,float GetTemperData,int GetFreqData,int GetPowerData);

    int SensorDataFix(float GetTemperData,int GetFreqData,int GetPowerData,QLabel* StaticTemper,QLabel* StaticPower,QLabel* StaticFreq);

    void SetSensorStatus(char AntID, char Sensor1, char Sensor2, char Sensor3, char Sensor4, char Sensor5, char Sensor6, char Sensor7, char Sensor8, char Sensor9, char Sensor10, char Sensor11, char Sensor12);

    void ShowLossData(unsigned char AntID, int Data[4][12]);

    void SendCMDByReader(int nIndexReader,QString CMD);//适用于查询，开始测温，停止测温，复位指令

    void SendCMDByReaderAnt(int nIndexReader,QString CMD,QString sAnt);//适用于衰减，传感器使能读取命令

    void InitMainDlgItem();

    unsigned char LrcDataArray[500];

    unsigned char LRC_Calculate(unsigned char * auchMsg, unsigned short usDataLen);

    QString LRC_Calculate(QString auchMsg);

    bool LRC_Check(unsigned char RecLRCHigh,unsigned char RecLRCLow,unsigned char LRC_Calculate);

    QString ReaderID_Int2CString(int nIndex);

    unsigned char GetReaderID(unsigned char High, unsigned char Low);

    void ShowReaderStatus(unsigned char ucStatus);

    void sleep(unsigned int msec);

private slots:
    void SetRF();

    void SetAnt1ForSensorSelect();

    void SetAnt2ForSensorSelect();

    void SetAnt3ForSensorSelect();

    void SetAnt4ForSensorSelect();

    void ScanAnt1ForSensor();

    void ScanAnt2ForSensor();

    void ScanAnt3ForSensor();

    void ScanAnt4ForSensor();

    void ScanAnt1ForRF();

    void ScanAnt2ForRF();

    void ScanAnt3ForRF();

    void ScanAnt4ForRF();

    void SendCheckReaderStatus();//发送查询读取器状态指令槽函数

    void SendCheckReaderStatusTimeOut();

    void WTS_ReadUart();//串口接收数据槽函数

    void on_pushButton_OpenComm_clicked();

    void on_pushButton_CloseComm_clicked();

    void on_pushButton_Ant1SelectAllSensor_clicked();

    void on_pushButton_Ant2SelectAllSensor_clicked();

    void on_pushButton_Ant3SelectAllSensor_clicked();

    void on_pushButton_Ant4SelectAllSensor_clicked();

    void on_pushButton_Ant1SelectNoSensor_clicked();

    void on_pushButton_Ant2SelectNoSensor_clicked();

    void on_pushButton_Ant3SelectNoSensor_clicked();

    void on_pushButton_Ant4SelectNoSensor_clicked();

    void on_checkBox_Ant1Sensor01Set_clicked();

    void on_checkBox_Ant1Sensor02Set_clicked();

    void on_checkBox_Ant1Sensor03Set_clicked();

    void on_checkBox_Ant1Sensor04Set_clicked();

    void on_checkBox_Ant1Sensor05Set_clicked();

    void on_checkBox_Ant1Sensor06Set_clicked();

    void on_checkBox_Ant1Sensor07Set_clicked();

    void on_checkBox_Ant1Sensor08Set_clicked();

    void on_checkBox_Ant1Sensor09Set_clicked();

    void on_checkBox_Ant1Sensor10Set_clicked();

    void on_checkBox_Ant1Sensor11Set_clicked();

    void on_checkBox_Ant1Sensor12Set_clicked();

    void on_checkBox_Ant2Sensor01Set_clicked();

    void on_checkBox_Ant2Sensor02Set_clicked();

    void on_checkBox_Ant2Sensor03Set_clicked();

    void on_checkBox_Ant2Sensor04Set_clicked();

    void on_checkBox_Ant2Sensor05Set_clicked();

    void on_checkBox_Ant2Sensor06Set_clicked();

    void on_checkBox_Ant2Sensor07Set_clicked();

    void on_checkBox_Ant2Sensor08Set_clicked();

    void on_checkBox_Ant2Sensor09Set_clicked();

    void on_checkBox_Ant2Sensor10Set_clicked();

    void on_checkBox_Ant2Sensor11Set_clicked();

    void on_checkBox_Ant2Sensor12Set_clicked();

    void on_checkBox_Ant3Sensor01Set_clicked();

    void on_checkBox_Ant3Sensor02Set_clicked();

    void on_checkBox_Ant3Sensor03Set_clicked();

    void on_checkBox_Ant3Sensor04Set_clicked();

    void on_checkBox_Ant3Sensor05Set_clicked();

    void on_checkBox_Ant3Sensor06Set_clicked();

    void on_checkBox_Ant3Sensor07Set_clicked();

    void on_checkBox_Ant3Sensor08Set_clicked();

    void on_checkBox_Ant3Sensor09Set_clicked();

    void on_checkBox_Ant3Sensor10Set_clicked();

    void on_checkBox_Ant3Sensor11Set_clicked();

    void on_checkBox_Ant3Sensor12Set_clicked();

    void on_checkBox_Ant4Sensor01Set_clicked();

    void on_checkBox_Ant4Sensor02Set_clicked();

    void on_checkBox_Ant4Sensor03Set_clicked();

    void on_checkBox_Ant4Sensor04Set_clicked();

    void on_checkBox_Ant4Sensor05Set_clicked();

    void on_checkBox_Ant4Sensor06Set_clicked();

    void on_checkBox_Ant4Sensor07Set_clicked();

    void on_checkBox_Ant4Sensor08Set_clicked();

    void on_checkBox_Ant4Sensor09Set_clicked();

    void on_checkBox_Ant4Sensor10Set_clicked();

    void on_checkBox_Ant4Sensor11Set_clicked();

    void on_checkBox_Ant4Sensor12Set_clicked();

    void on_pushButton_DebugCMD_clicked();

    void on_pushButton_StartGetTemp_clicked();

    void on_pushButton_CheckReaderCommunicate_clicked();

    void on_pushButton_SetTargetReaderID_clicked();

    void on_pushButton_CalTemp_clicked();

    void on_pushButton_ImportParmFile_clicked();

private:
    Ui::WTSCommDialog *ui;

private:
    QSerialPort *WTS_SerialPort;

protected:
    bool eventFilter(QObject *obj, QEvent *e);
};

#endif // WTSCOMMDIALOG_H
