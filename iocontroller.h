#ifndef IOCONTROLLER_H
#define IOCONTROLLER_H

#include <QObject>
#include "global.h"

class IOView;
class IOController : public QObject
{
    Q_OBJECT
    IOView *mIOView {nullptr};
    Move mLastMove;

public:
    explicit IOController(QObject *parent = nullptr);
    QPair<int, int> getLastMove() const;
    void setField(QVector<QVector<int>> *field);

signals:
    void newMoveDone();

private slots:
    void moveDoneHandler();
};

#endif // IOCONTROLLER_H
