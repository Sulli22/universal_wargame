#pragma once

#include "modelepourqml.h"
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

struct couleur {
    float r;
    float v;
    float b;
};

class MonRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    MonRenderer(ModelePourQML *modele);

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    couleur getCouleur(uint16_t q, uint16_t r) const;

    void dessinCadre(float x, float y) const;
    void dessinAiles(float x, float y) const;

    void dessinGenie(float x, float y) const;
    void dessinInfanterie(float x, float y) const;
    void dessinArtillerie(float x, float y) const;
    void dessinCharAssaut(float x, float y) const;
    void dessinFregate(float x, float y) const;
    void dessinSousMarin(float x, float y) const;
    void dessinChasseur(float x, float y) const;
    void dessinBombardier(float x, float y) const;

    void dessinUnite(uint16_t q, uint16_t r, float x, float y) const;
    void dessinHex(float x, float y) const;

// attributs
    ModelePourQML *_modele;

    static const float _R;
};
