#include <QDebug>
#include "boardmodel.h"
#include "board.h"

BoardModel::BoardModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !m_board)
    {
        return 0;
    }

    return m_board->items().size();
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    QVariant retval;
    if (index.isValid() && m_board)
    {
        switch(role)
        {
            case ColorRole: retval = QVariant(m_board->items().at(index.row())); break;
        }
    }

    return retval;
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[ColorRole] = "color";
    return names;
}



void BoardModel::setBoard(Board* board)
{
    beginResetModel();
    if(m_board)
    {
        m_board->disconnect(this);
    }
    m_board = board;

    if(m_board)
    {
        connect(m_board, &Board::dataChanged, this, [this](int size){
                emit dataChanged(QAbstractItemModel::createIndex(0,0),
                        createIndex(size, 0));
                });
    }
    endResetModel();
}

