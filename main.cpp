#include "wtscommdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WTSCommDialog w;
    w.setWindowTitle("无源无线温度监控系统调试软件V1.2        PowerByLXL");
    w.show();

    return a.exec();
}
