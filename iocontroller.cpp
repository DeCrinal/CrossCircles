#include "iocontroller.h"
#include "ioview.h"
#include "consoleioview.h"

IOController::IOController(QObject *parent)
    : QObject{parent}
{
    //mIOView = new IOView;
    mIOView = new ConsoleIOView;
    connect(mIOView, &IOView::moveDone,
            this, &IOController::moveDoneHandler);
}

QPair<int, int> IOController::getLastMove() const
{
    return mIOView->getMove();
}

void IOController::setField(QVector<QVector<int> > *field)
{
    mIOView->setField(field);
    mIOView->updateField();
}

void IOController::moveDoneHandler()
{
    emit newMoveDone();
}
