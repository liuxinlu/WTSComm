#ifndef WTSCOMMDIALOG_H
#define WTSCOMMDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class WTSCommDialog;
}

class WTSCommDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WTSCommDialog(QWidget *parent = 0);
    ~WTSCommDialog();

private:
    Ui::WTSCommDialog *ui;
};

#endif // WTSCOMMDIALOG_H
