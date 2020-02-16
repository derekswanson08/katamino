#pragma once
#include <QObject>
#include <QElapsedTimer>
#include <QVector>
#include <QColor>

class Pent;

class Runner : public QObject
{
    Q_OBJECT

public:
    explicit Runner(QObject *parent = nullptr);
    void update(const Pent& p, bool force);

signals:
    void updateModel(QVector<QColor>);

public slots:
    void onRunSolver();

private:
    bool m_uiBusy = false;
    QElapsedTimer m_timer;
};
