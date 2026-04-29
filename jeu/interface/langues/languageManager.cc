#include "languagemanager.h"

LanguageManager::LanguageManager()
{}

QString LanguageManager::getChaineVide() const
{
    return QString();
}

void LanguageManager::majLangue(QString langue)
{
    if (langue == "en") {
        if(_traduction.load(QGuiApplication::applicationDirPath() + "/traduction_en_US.qm"))
            qApp->installTranslator(&_traduction);
        else
            qDebug() << "Pas anglais";
    }

    else
        qApp->removeTranslator(&_traduction);

    emit langueChange();
}
