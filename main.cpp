#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include "boardmodel.h"
#include "board.h"
#include "runner.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qRegisterMetaType<QVector<QColor>>();

    qmlRegisterType<BoardModel>("com.swans.BoardModel",1,0,"BoardModel");
    qmlRegisterUncreatableType<Board>("com.swans.BoardModel",1,0,"Board","Board should not be created in QML");

    // add global c++ object to the QML context as a property
    Board myBoard;
    engine.rootContext()->setContextProperty("myBoard", &myBoard);

    QThread worker;
    Runner runner;
    runner.moveToThread(&worker);
    worker.start();

    QObject::connect(&myBoard, SIGNAL(runSolver()), &runner, SLOT(onRunSolver()), Qt::QueuedConnection);
    QObject::connect(&runner, SIGNAL(updateModel(QVector<QColor>)), &myBoard, SLOT(onUpdateModel(QVector<QColor>)), Qt::QueuedConnection);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    int status = app.exec();
    runner.quit = true;
    worker.quit();
    worker.wait(1000);

    return status;
}
