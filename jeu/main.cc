#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QSurfaceFormat>

#include "langagemanager.h"
#include "MonOpenGLItem.h"
#include "modelepourqml.h"

#include <QMediaDevices>
#include <QAudioDevice>

int main(int argc, char *argv[])
{
    // version openGL
    QSurfaceFormat format;
    format.setVersion(2, 1);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    QSurfaceFormat::setDefaultFormat(format);
    qputenv("QSG_RHI_BACKEND", "opengl");

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Basic"); // force style basic

    LangageManager langageManager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("langageManager", &langageManager);

    const QUrl musiqueUrl = QUrl::fromLocalFile(QGuiApplication::applicationDirPath() + "/warzone.mp3");
    engine.rootContext()->setContextProperty("musiqueUrl", musiqueUrl);

    ModelePourQML modeleQML;
    engine.rootContext()->setContextProperty("modeleQML", &modeleQML);
    qmlRegisterType<MonOpenGLItem>("MonGL", 1, 0, "MonOpenGLItem");

    const QUrl url("qrc:/qt/qml/jeu/interface/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
                     [url](QObject *obj, const QUrl &objUrl) {
                        if (!obj && url == objUrl)
                            QCoreApplication::exit(-1);
                     },
        Qt::QueuedConnection);
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
