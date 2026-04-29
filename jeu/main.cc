#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQuickStyle>
#include <QLocale>
#include <QTranslator>

#include <QQmlContext>

#include "langues/languagemanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Fusion");

    LanguageManager languageManager;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("languageManager", &languageManager);

    const QUrl url("qrc:/jeu/interface/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
