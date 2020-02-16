#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include "boardmodel.h"
#include "runner.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qRegisterMetaType<QVector<QColor>>();

    // add global c++ object to the QML context as a property
    BoardModel myBoard;
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
    worker.quit();

    return status;
}
