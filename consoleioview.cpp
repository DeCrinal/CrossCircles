#include "consoleioview.h"
#include <iostream>
#include <QDebug>
#include <cstdio>

ConsoleIOView::ConsoleIOView(QObject *parent)
    : IOView{parent}
{
    mConsoleInputHandler = new ConsoleInputHandler;
    connect(mConsoleInputHandler, &ConsoleInputHandler::newInput,
            this, &ConsoleIOView::handleInput);

    mConsoleInputHandler->start();
}

void ConsoleIOView::updateField()
{
    if(!mField){
        return;
    }

    for(int x = 0; x < mField->size(); x++){
        for(int y = 0; y < mField->size(); y++){
            QTextStream(stdout) << (*mField)[x][y] << "\t";
        }
        QTextStream(stdout) << "\n";
    }
}

void ConsoleIOView::setField(QVector<QVector<int> > *field)
{
    mField = field;
}

QPair<int, int> ConsoleIOView::getMove() const
{
    return mMove;
}

void ConsoleIOView::handleInput(const QString &text)
{
    const auto values = text.split(" ");
    if(values.size() != 2){
        return;
    }
    bool isOkX {false};
    bool isOkY {false};

    const int x = values[0].toInt(&isOkX);
    const int y = values[1].toInt(&isOkY);

    if(!isOkX || !isOkY){
        return;
    }

    mMove = {x, y};

    emit moveDone();
}

void ConsoleInputHandler::run()
{
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        emit newInput(QString::fromStdString(input));
    }
}
