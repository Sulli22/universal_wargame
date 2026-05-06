#pragma once

#include "position.hh"
#include "HexConfig.h"

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

    QPointF pixelVersLogique(float mouseX, float mouseY) const;
    Position logiqueVersHex(float lx, float ly) const;

    Q_INVOKABLE void gererClic(float mouseX, float mouseY);
    Q_INVOKABLE void rafraichir();

private:
// valeurs redondantes fixes
    static constexpr float  _R_HEX              = HexCondig::R_HEX;
    static constexpr float  _LARGEUR_HEX        = HexCondig::LARGEUR_HEX;
    static constexpr float  _HAUTEUR_HEX        = HexCondig::HAUTEUR_HEX;

// atribut
    ModelePourQML *_modele;
};
