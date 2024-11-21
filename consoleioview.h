#ifndef CONSOLEIOVIEW_H
#define CONSOLEIOVIEW_H

#include <QThread>
#include "ioview.h"

class ConsoleInputHandler : public QThread {

    Q_OBJECT

public:
    ConsoleInputHandler(QObject *parent = nullptr) : QThread(parent) {}

protected:
    void run() override;

signals:
    void newInput(const QString &text);  // Сигнал для нового ввода

};

class ConsoleIOView : public IOView
{
    Q_OBJECT
    QVector<QVector<int>> *mField {nullptr};
    ConsoleInputHandler *mConsoleInputHandler {nullptr};
    QPair<int, int> mMove;
public:
    explicit ConsoleIOView(QObject *parent = nullptr);

    void updateField() override;
    void setField(QVector<QVector<int>> *field) override;
    QPair<int, int> getMove() const override;

private slots:
    void handleInput(const QString &text);
};

#endif // CONSOLEIOVIEW_H
