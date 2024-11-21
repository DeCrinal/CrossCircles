#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include <QApplication>
#include <QObject>

class GameController;
class GameApplication : public QApplication
{
    Q_OBJECT
    GameController *mGameController {nullptr};

public:
    explicit GameApplication(int &argc, char **argv);
};

#endif // GAMEAPPLICATION_H
