#pragma once

#include "position.hh"
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

    QPointF pixelVersLogique(float mouseX, float mouseY,
                             float largeurFen, float hauteurFen) const;
    Position logiqueVersHex(float lx, float ly) const;
    Q_INVOKABLE void gererClic(float mouseX, float mouseY);

private:
    ModelePourQML *_modele;
};
