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

    static constexpr float _R_HEX = 1.f;
    static constexpr float _SQRT_3 = 1.7320508f;
    static constexpr float _LARGEUR_HEX  = 2.f * _R_HEX;
    static constexpr float _HAUTEUR_HEX  = _SQRT_3 * _R_HEX;

    static constexpr float _LARGEUR_CADRE = _R_HEX / 2.f;
    static constexpr float _HAUTEUR_CADRE = _R_HEX * _SQRT_3 / 4.f;

    static constexpr float _R_CERCLE =  _R_HEX / 4.f;
    static constexpr float _R_DEMI_CERCLE =  _R_HEX / 5.f;
    static constexpr int _NB_SEG_DEMI_CERCLE = 10;
    static constexpr int _NB_SEG_CERCLE = 20;

    static constexpr float _DEMIE_LARGEUR_GENIE = _R_HEX / 3.f;
    static constexpr float _DEMIE_HAUTEUR_GENIE = _HAUTEUR_CADRE / 2.f;

};
