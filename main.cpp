#include "gameapplication.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    qDebug() << "adsf";
    GameApplication gameApp(argc, argv);
    return gameApp.exec();
}
