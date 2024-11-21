#ifndef IOVIEW_H
#define IOVIEW_H

#include <QObject>

class IOView : public QObject
{
    Q_OBJECT
public:
    explicit IOView(QObject *parent = nullptr);
    virtual void updateField() = 0;
    virtual void setField(QVector<QVector<int>> *field) = 0;
    virtual QPair<int, int> getMove() const = 0;
signals:
    void moveDone();
};

#endif // IOVIEW_H
