#include <QVector>
#include <QColor>
#include "board.h"

Board::Board(QObject *parent) : QObject(parent)
{
    m_colors = QVector<QColor>(45, "red");
}

QVector<QColor> Board::items()
{
    return m_colors;
}

bool Board::setColors(QVector<QColor> x)
{
    if(m_colors == x)
    {
        return false;
    }
    m_colors = x;
    return true;
}

void Board::solve()
{
    emit runSolver();
}

void Board::onUpdateModel(QVector<QColor> colors)
{
    if(setColors(colors))
    {
        emit dataChanged(m_colors.size());
    }
}
