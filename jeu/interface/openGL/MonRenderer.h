#pragma once

#include "modelepourqml.h"
#include "HexConfig.h"

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class MonRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    MonRenderer(ModelePourQML *modele);

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    std::array<float, 3> getCouleur(stat q, stat r) const;
    std::pair<float, float> hexVersLogique(stat q, stat r) const;

// methode pour surligner
    void surlignesCasesConcernees();
    void surligneCase(Case *c);
    void surligneCaseCible();
    void surligneCaseSelectionnee();
    void surligneChemin();

// methode de dessins principales
    void dessinHex(stat q, stat r);
    void dessinUnite(stat q, stat r);
    void dessinCadre(Faction f);
    void dessinConstruction(stat q, stat r);

// methodes de dessin static
    static void pointsHex();                //   > sommets bruts
    static void pointsCadre();              //  /
    static void pointsArcCercleGauche();    // /

    static void dessinB();                  //     > dessins partiels
    static void dessinF();                  //    /
    static void dessinAileGauche();         //   /
    static void dessinAiles();              //  /
    static void dessinGauchePont();         // /

    static void dessinGenie();              //        > dessins unites
    static void dessinInfanterie();         //       /
    static void dessinArtillerie();         //      /
    static void dessinCharAssaut();         //     /
    static void dessinFregate();            //    /
    static void dessinSousMarin();          //   /
    static void dessinChasseur();           //  /
    static void dessinBombardier();         // /

    static void dessinDepotMunitions();     //    > dessins constructions
    static void dessinDepotProvisions();    //   /
    static void dessinInfirmerie();         //  /
    static void dessinPont();               // /

// valeurs redondantes fixes
    static constexpr float  _R_HEX              = HexConfig::R_HEX;
    static constexpr float  _LARGEUR_HEX        = HexConfig::LARGEUR_HEX;
    static constexpr float  _HAUTEUR_HEX        = HexConfig::HAUTEUR_HEX;

    static constexpr float  _R_HEX_2            = _R_HEX            / 2.f;
    static constexpr float  _R_HEX_4            = _R_HEX_2          / 4.f;
    static constexpr float  _HAUTEUR_HEX_2      = _HAUTEUR_HEX      / 2.f;
    static constexpr float  _LARGEUR_CADRE_2    = _R_HEX_2;
    static constexpr float  _HAUTEUR_CADRE_2    = _HAUTEUR_HEX_2    / 2.f;

    static constexpr float _R_ARC_CERCLE        = _R_HEX            / 5.f;
    static constexpr float _DY_LETTRE           = _HAUTEUR_CADRE_2  / 2.f;

// attribut
    ModelePourQML *_modele;
};
