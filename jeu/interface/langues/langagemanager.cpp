#include "langagemanager.h"

LangageManager::LangageManager()
{}

QString LangageManager::getChaineVide() const
{
    return QString();
}

void LangageManager::majLangue(QString langue)
{
    if (langue == "en") {
        if(_traduction.load(QGuiApplication::applicationDirPath() + "/traduction_en_UK.qm"))
            qApp->installTranslator(&_traduction);
        else
            qDebug() << "Traduction en anglais impossible";
    }

    else
        qApp->removeTranslator(&_traduction);

    emit langueChange();
}
