#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQmlContext>
#include <QDebug>

class MyObject :public QObject {
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr) : QObject(parent) {}

public slots:
    void handleQmlSignal(const QString &message) {
        qDebug() << "Received QML signal with message: " << message;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    MyObject myObject;
    QObject::connect(engine.rootObjects()[0], SIGNAL(qmlSignal(QString)), &myObject, SLOT(handleQmlSignal(QString)));

    return app.exec();
}

#include "main.moc"
