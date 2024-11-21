#include "arbiter.h"

Arbiter::Arbiter(QObject *parent)
    : QObject{parent}
{

}

bool Arbiter::isMoveCorrect(const QVector<QVector<int>> &field, const Move &move)
{
    if(move.x >= field.size() || move.y >= field.size()){
        return false;
    }

    if(field[move.x][move.y] != -1){
        return false;
    }

    return true;
}

bool Arbiter::isMoveFinal(const QVector<QVector<int> > &field, const Move &move, int numInRowToWin)
{
    const bool isFinal = isFinalInRow(field, move, numInRowToWin) ||
                         isFinalInColumn(field, move, numInRowToWin) ||
                         isFinalInCross(field, move, numInRowToWin);

    return isFinal;
}

bool Arbiter::isFinalInRow(const QVector<QVector<int> > &field, const Move &move, int numInRowToWin)
{
    int lefterThanThis {0};
    int righterThanThis {0};

    for(int x = move.x + 1; x < field.size(); x++){
        if(field[x][move.y] != move.player){
            break;
        }
        righterThanThis++;
    }

    for(int x = move.x - 1; x < field.size() && x >= 0; x--){
        if(field[x][move.y] != move.player){
            break;
        }
        lefterThanThis++;
    }

    return lefterThanThis + righterThanThis + 1 >= numInRowToWin;
}

bool Arbiter::isFinalInColumn(const QVector<QVector<int> > &field, const Move &move, int numInRowToWin)
{
    int belowThanThis {0};
    int higherThanThis {0};

    for(int y = move.y + 1; y < field.size(); y++){
        if(field[move.x][y] != move.player){
            break;
        }
        higherThanThis++;
    }

    for(int y = move.x - 1; y < field.size() && y >= 0; y--){
        if(field[move.x][y] != move.player){
            break;
        }
        belowThanThis++;
    }

    return belowThanThis + higherThanThis + 1 >= numInRowToWin;
}

bool Arbiter::isFinalInCross(const QVector<QVector<int> > &field, const Move &move, int numInRowToWin)
{
    //TODO: realise
    return false;
}

