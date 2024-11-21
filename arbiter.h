#ifndef ARBITER_H
#define ARBITER_H

#include <QObject>
#include "global.h"

class Arbiter : public QObject
{
    Q_OBJECT
public:
    explicit Arbiter(QObject *parent = nullptr);
    bool isMoveCorrect(const QVector<QVector<int>> &field, const Move &move);
    bool isMoveFinal(const QVector<QVector<int>> &field, const Move &move, int numInRowToWin);
signals:

private:
    bool isFinalInRow(const QVector<QVector<int>> &field, const Move &move, int numInRowToWin);
    bool isFinalInColumn(const QVector<QVector<int>> &field, const Move &move, int numInRowToWin);
    bool isFinalInCross(const QVector<QVector<int>> &field, const Move &move, int numInRowToWin);
};

#endif // ARBITER_H
