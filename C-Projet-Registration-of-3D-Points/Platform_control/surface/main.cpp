#include "platform_control.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//自适应高分辨率
#if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);
    Platform_control w;
    w.show();

    return a.exec();
}
