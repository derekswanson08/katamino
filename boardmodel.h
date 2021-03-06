#ifndef BOARDMODEL2_H
#define BOARDMODEL2_H

#include <QAbstractItemModel>
#include <QColor>
#include <QVector>

class Board;

class BoardModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Board* board READ board WRITE setBoard)

public:
    explicit BoardModel(QObject *parent = nullptr);

    enum {
        ColorRole = Qt::UserRole,
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Board* board() const { return m_board; }
    void setBoard(Board* board);


private:
    Board* m_board = nullptr;
};

#endif // BOARDMODEL2_H
