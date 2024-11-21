#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QVector>

#include "global.h"
class Arbiter;
class IOController;


class GameController : public QObject
{
    Q_OBJECT
    size_t mFieldSize {3};
    size_t mPlayersNum {2};
    size_t mNumInRowToWin {3};
    QVector<QVector<int>> mField;
    Arbiter *mArbiter {nullptr};
    IOController *mIOController;

    int mCurrentPlayerID {0};

public:
    explicit GameController(QObject *parent = nullptr);

    Move getLastMove() const;
signals:
    //void moveDone();

private:
    void addMoveToField(const Move &move);
private slots:
    void newMoveDoneHandler();
};

#endif // GAMECONTROLLER_H
