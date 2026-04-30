#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QLocale>
#include <QTranslator>
#include <QQmlContext>
#include <QSurfaceFormat>

#include "langues/languagemanager.h"
#include "openGL/MonOpenGLItem.h"

int main(int argc, char *argv[])
{
    // version openGL
    QSurfaceFormat format;
    format.setVersion(2, 1);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    QSurfaceFormat::setDefaultFormat(format);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Basic");

    qputenv("QSG_RHI_BACKEND", "opengl");
    qmlRegisterType<MonOpenGLItem>("MonGL", 1, 0, "MonOpenGLItem");

    LanguageManager languageManager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("languageManager", &languageManager);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

    //engine.load(QUrl("qrc:/qt/qml/jeu/interface/pages/TestGL.qml"));
    const QUrl url("qrc:/qt/qml/jeu/interface/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
