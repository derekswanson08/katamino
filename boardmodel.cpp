#include <QDebug>
#include "boardmodel.h"


BoardModel::BoardModel(QObject *parent) : QObject(parent)
{

}

void BoardModel::solve()
{
    qDebug() << "emit runSolver";
    emit runSolver();
}

void BoardModel::onUpdateModel(QVector<QColor> colors)
{
    for(int index = 0; index < colors.size(); index++)
    {
        QColor color = colors.at(index);
        switch(index)
        {
            default:
            case 0 : setColor0 (color); break;
            case 1 : setColor1 (color); break;
            case 2 : setColor2 (color); break;
            case 3 : setColor3 (color); break;
            case 4 : setColor4 (color); break;
            case 5 : setColor5 (color); break;
            case 6 : setColor6 (color); break;
            case 7 : setColor7 (color); break;
            case 8 : setColor8 (color); break;
            case 9 : setColor9 (color); break;
            case 10: setColor10(color); break;
            case 11: setColor11(color); break;
            case 12: setColor12(color); break;
            case 13: setColor13(color); break;
            case 14: setColor14(color); break;
            case 15: setColor15(color); break;
            case 16: setColor16(color); break;
            case 17: setColor17(color); break;
            case 18: setColor18(color); break;
            case 19: setColor19(color); break;
            case 20: setColor20(color); break;
            case 21: setColor21(color); break;
            case 22: setColor22(color); break;
            case 23: setColor23(color); break;
            case 24: setColor24(color); break;
            case 25: setColor25(color); break;
            case 26: setColor26(color); break;
            case 27: setColor27(color); break;
            case 28: setColor28(color); break;
            case 29: setColor29(color); break;
            case 30: setColor30(color); break;
            case 31: setColor31(color); break;
            case 32: setColor32(color); break;
            case 33: setColor33(color); break;
            case 34: setColor34(color); break;
            case 35: setColor35(color); break;
            case 36: setColor36(color); break;
            case 37: setColor37(color); break;
            case 38: setColor38(color); break;
            case 39: setColor39(color); break;
        }
    } 
}
