#pragma once
#include <QTranslator>
#include <QObject>
#include <QGuiApplication>


class LanguageManager: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString chaineVide READ getChaineVide NOTIFY langueChange)
public:
    LanguageManager();
    QString getChaineVide() const;

public slots:
    Q_INVOKABLE void majLangue(QString langue);

signals:
    void langueChange();

private:
    QTranslator _traduction;
};
