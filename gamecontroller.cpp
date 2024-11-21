#include "gamecontroller.h"
#include "arbiter.h"
#include "iocontroller.h"
#include <QDebug>

GameController::GameController(QObject *parent)
    : QObject{parent}
{
    mField.resize(mFieldSize);
    for(size_t i = 0; i < mFieldSize; i++){
        mField[i].resize(mFieldSize);
        for(size_t j = 0; j < mFieldSize; j++){
            mField[i][j] = -1;
        }
    }

    mArbiter = new Arbiter;
    mIOController = new IOController;

    connect(mIOController, &IOController::newMoveDone, this,
            &GameController::newMoveDoneHandler);

    mIOController->setField(&mField);
}

void GameController::addMoveToField(const Move &move)
{
    if(move.x >= mField.size() || move.y >= mField.size()){
        return;
    }

    mField[move.x][move.y] = move.player;
}

void GameController::newMoveDoneHandler()
{
    //const Move lastMove = mIOController->getLastMove();
    const QPair<int, int> moveCoords = mIOController->getLastMove();
    Move lastMove;
    lastMove.x = moveCoords.first;
    lastMove.y = moveCoords.second;
    lastMove.player = mCurrentPlayerID;

    const bool isCorrect = mArbiter->isMoveCorrect(mField, lastMove);
    if(!isCorrect){
        //
        return;
    }
    addMoveToField(lastMove);
    mCurrentPlayerID = (mCurrentPlayerID + 1) % mPlayersNum;
    mIOController->setField(&mField);

    const bool isFinalMove = mArbiter->isMoveFinal(mField, lastMove, mNumInRowToWin);
    if(isFinalMove){
        //
        qDebug() << QString("Player: %1 wins").arg(lastMove.player);
    }
}
