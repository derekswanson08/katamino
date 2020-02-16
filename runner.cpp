#include <vector>
#include <QColor>
#include <QMap>
#include <QVector>
#include <QDebug>
#include "runner.h"
#include "pent.h"

using namespace std;

Runner::Runner(QObject *)
{
    m_timer.start();
}

void Runner::onRunSolver()
{
    qDebug() << __FUNCTION__;
    vector<Pent> k;
    k.emplace_back(4,2);
    k.back().setString(
        "0."
        "0."
        "0."
        "00");

    k.emplace_back(4,2);
    k.back().setString(
        ".1"
        ".1"
        "11"
        "1.");

    k.emplace_back(3,2);
    k.back().setString(
        "22"
        "22"
        "2.");

    k.emplace_back(3,3);
    k.back().setString(
        "33."
        ".3."
        ".33");

    k.emplace_back(3,3);
    k.back().setString(
        "444"
        ".4."
        ".4.");

//    k.emplace_back(4,2);
//    k.back().setString(
//        ".5"
//        "55"
//        ".5"
//        ".5");

    k.emplace_back(3,3);
    k.back().setString(
        "..6"
        "..6"
        "666");

    k.emplace_back(2,3);
    k.back().setString(
        "7.7"
        "777");

    k.emplace_back(3,3);
    k.back().setString(
        ".88"
        "88."
        ".8.");

//    k.emplace_back(3,3);
//    k.back().setString(
//        "..9"
//        ".99"
//        "99.");
//
//    k.emplace_back(3,3);
//    k.back().setString(
//        ".a."
//        "aaa"
//        ".a.");
//    k.emplace_back(1,5);
//    k.back().setString(
//        "bbbbb");

    Pent board(5, (int) k.size());
    auto solution = Pent::solve(k, board, this);

    printf("=========================\n");
    printf("=========================\n");
    printf("=== solved it!!! ========\n");
    solution->print();
    printf("=========================\n");
    printf("=========================\n");
    
    update(*solution, true);
}

void Runner::update(const Pent& board, bool force)
{
    if((m_timer.elapsed() < 150) && !force)
    {
        return;
    }

    static QMap<char, QColor> lut;
    if(lut.size() == 0)
    {
        lut['0'] = QColor("black");
        lut['1'] = QColor("cyan");
        lut['2'] = QColor("darkCyan");
        lut['3'] = QColor("magenta");
        lut['4'] = QColor("darkMagenta");
        lut['5'] = QColor("green");
        lut['6'] = QColor("darkGreen");
        lut['7'] = QColor("yellow");
        lut['8'] = QColor("red");
        lut['9'] = QColor("blue");
        lut['a'] = QColor("darkBlue");
        lut['b'] = QColor("gray");
        lut['.'] = QColor("white");
        lut['$'] = QColor("red");
    }

    QVector<QColor> colors;
    for(int y = 0; y < board.height(); y++)
    {
        for(int x = 0; x < board.width(); x++)
        {
            colors.append(lut.value(board.at(x,y)));
        }
    }
    qDebug() << "emit updateModel(colors)";
    emit updateModel(colors);

    m_timer.start();
}

