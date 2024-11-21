#include "gameapplication.h"
#include "gamecontroller.h"
#include "mainwindow.h"

GameApplication::GameApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
    mGameController = new GameController;
}
