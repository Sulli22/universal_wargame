#include "MonOpenGLItem.h"
#include "MonRenderer.h"

MonOpenGLItem::MonOpenGLItem(QQuickItem *parent):
    QQuickFramebufferObject(parent)
{
    setMirrorVertically(true);
}

ModelePourQML *MonOpenGLItem::getModele() const
{
    return _modele;
}

void MonOpenGLItem::setModele(ModelePourQML *nvModele)
{
    _modele = nvModele;
}

QPointF MonOpenGLItem::pixelVersLogique(float mouseX, float mouseY) const
{
    float largeurFen = static_cast<float>(width());
    float hauteurFen = static_cast<float>(height());

    const auto  hauteur = _modele->getHauteurPlateau(),
                largeur = _modele->getLargeurPlateau();

    const float LARGEUR_GRILLE = _LARGEUR_HEX * (1.f + (largeur - 1) * 0.75f);
    const float HAUTEUR_GRILLE = _HAUTEUR_HEX * hauteur;

    const float ASPECT = largeurFen / hauteurFen;
    float largeurOrtho = HAUTEUR_GRILLE * ASPECT;
    float hauteurOrtho = HAUTEUR_GRILLE;

    if (largeurOrtho < LARGEUR_GRILLE) {
        largeurOrtho = LARGEUR_GRILLE;
        hauteurOrtho = LARGEUR_GRILLE / ASPECT;
    }

    const float CX = LARGEUR_GRILLE / 2.f;
    const float CY = HAUTEUR_GRILLE / 2.f;

    // bornes de la projection (identiques à glOrtho dans render())
    const float gauche   = CX - largeurOrtho / 2.f;
    const float droite  = CX + largeurOrtho / 2.f;
    const float basse = CY - hauteurOrtho / 2.f - _HAUTEUR_HEX / 2.f;
    const float haute    = CY + hauteurOrtho / 2.f;

    // normalise en [0,1] et flip Y
    float nx =  mouseX / largeurFen;
    float ny =  1.f - mouseY / hauteurFen;   // flip

    // Dénormalise dans l'espace logique
    float lx = gauche + nx * (droite  - gauche);
    float ly = basse + ny * (haute - basse);

    return {lx, ly};
}

Position MonOpenGLItem::logiqueVersHex(float lx, float ly) const
{
    const std::size_t hauteur = _modele->getHauteurPlateau();

    // chaque colonne est espacee de LARGEUR_HEX * 0.75
    int q = static_cast<int>(std::round(lx / (_LARGEUR_HEX * 0.75f)));
    q = std::max(0, q);

    // depend du décalage de colonne
    float yDec = (q % 2) * _HAUTEUR_HEX / 2.f;

    int r = static_cast<int>(std::round(
        static_cast<float>(hauteur - 1) - (ly - yDec) / _HAUTEUR_HEX)
        );

    return {q, r};
}

void MonOpenGLItem::gererClic(float mouseX, float mouseY)
{
    const auto [lx, ly] = pixelVersLogique(mouseX, mouseY);
    const auto pos      = logiqueVersHex(lx, ly);

    if (_modele->positionValidePlateau(pos)) {
        _modele->selectionnerCase(pos);
        update();
    }
}

void MonOpenGLItem::rafraichir()
{
    update();
}

QQuickFramebufferObject::Renderer *MonOpenGLItem::createRenderer() const
{
    return new MonRenderer(_modele);
}
