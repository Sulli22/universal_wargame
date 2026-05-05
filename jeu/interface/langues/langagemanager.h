#pragma once
#include <QTranslator>
#include <QObject>
#include <QGuiApplication>

class LangageManager: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString chaineVide READ getChaineVide NOTIFY langueChange)

public:
    LangageManager();
    QString getChaineVide() const;

public slots:
    Q_INVOKABLE void majLangue(QString langue);

signals:
    void langueChange();

private:
    QTranslator _traduction;
};
