#pragma once

#include <QQuickFramebufferObject>

class ModelePourQML;
class MonRenderer;

class MonOpenGLItem: public QQuickFramebufferObject {
    Q_OBJECT
    Q_PROPERTY(ModelePourQML* modele READ getModele WRITE setModele)

public:
    explicit MonOpenGLItem(QQuickItem *parent = nullptr);

    Renderer *createRenderer() const override;

    ModelePourQML* getModele() const;
    void setModele(ModelePourQML* nvModele);

private:
    ModelePourQML *_modele;
};
