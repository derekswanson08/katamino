#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QVector>
#include <QColor>

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int level READ level)

public:
    explicit Board(QObject *parent = nullptr);

    QVector<QColor> items();

    bool setColors(QVector<QColor> x);
    int level() const { return m_colors.size() / 5; }

signals:
    void preSetColors();
    void postSetColors();
    void runSolver();
    void dataChanged(int size);

public slots:
    void solve();
    void onUpdateModel(QVector<QColor> colors);

private:
    QVector<QColor> m_colors;
};

#endif // BOARD_H
