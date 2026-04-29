#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QTranslator>

#include <QQmlContext>

#include "interface/langues/languagemanager.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    LanguageManager languageManager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("languageManager", &languageManager);
    engine.rootContext()->setContextProperty("applicationDirPath", QGuiApplication::applicationDirPath());

    const QUrl url(u"qrc:/jeu/interface/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
