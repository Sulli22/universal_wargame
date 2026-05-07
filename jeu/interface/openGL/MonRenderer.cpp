#include "MonRenderer.h"

#include "casemarine.hh"
#include "caseterrestre.hh"
#include "artillerie.hh"
#include "charassaut.hh"
#include "chasseur.hh"
#include "fregate.hh"
#include "genie.hh"
#include "sousmarin.hh"

#include <QOpenGLFramebufferObjectFormat>
#include <GL/gl.h>

MonRenderer::MonRenderer(ModelePourQML *modele):
    _modele(modele)
{
    initializeOpenGLFunctions();

    // lissage
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
}

couleur MonRenderer::getCouleur(uint16_t q, uint16_t r) const
{
    auto c = _modele->accesCasePlateau({q, r});

    if (dynamic_cast<CaseMarine *>(c))
        return { 0.2f, 0.2f, 1.f };

    auto ct = dynamic_cast<CaseTerrestre *>(c);
    switch (ct->getTerrain()) {
    case typeTerrain::plaine:   return { 0.f,  1.f,  0.f  };
    case typeTerrain::foret:    return { 0.f,  0.5f, 0.f  };
    case typeTerrain::montagne: return { 0.5f, 0.5f, 0.5f };
    case typeTerrain::riviere:  return { 0.4f, 0.4f, 1.f  };
    }

    throw std::runtime_error("Erreur : impossible de determiner la couleur");
}

void MonRenderer::dessinB()
{
    static constexpr float LARGEUR_2 = _LARGEUR_CADRE_2 / 4.f;
    static constexpr float HAUTEUR_2 = _HAUTEUR_CADRE_2 / 1.5f;

    glBegin(GL_LINE_LOOP);
    {
        // trait vertical
        glVertex2f(-LARGEUR_2, -HAUTEUR_2);
        glVertex2f(-LARGEUR_2,  HAUTEUR_2);

        // "boucles" du B
        glVertex2f( LARGEUR_2,  HAUTEUR_2 / 2.f);
        glVertex2f(-LARGEUR_2,  0.f            );
        glVertex2f( LARGEUR_2, -HAUTEUR_2 / 2.f);
    }
    glEnd();
}

void MonRenderer::dessinF()
{
    static constexpr float LARGEUR_2 = _LARGEUR_CADRE_2 / 4.f;
    static constexpr float HAUTEUR_2 = _HAUTEUR_CADRE_2 / 1.5f;

    //trait vertical et horizontal haut
    glBegin(GL_LINE_STRIP);
    {
        glVertex2f(-LARGEUR_2, -HAUTEUR_2);
        glVertex2f(-LARGEUR_2,  HAUTEUR_2);
        glVertex2f( LARGEUR_2,  HAUTEUR_2);
    }
    glEnd();

    // trait horizontal milieu
    glBegin(GL_LINES);
    {
        glVertex2f(-LARGEUR_2, 0.f);
        glVertex2f( LARGEUR_2, 0.f);
    }
    glEnd();
}

void MonRenderer::dessinCadre()
{
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(-_LARGEUR_CADRE_2, -_HAUTEUR_CADRE_2);
        glVertex2f(-_LARGEUR_CADRE_2,  _HAUTEUR_CADRE_2);
        glVertex2f( _LARGEUR_CADRE_2,  _HAUTEUR_CADRE_2);
        glVertex2f( _LARGEUR_CADRE_2, -_HAUTEUR_CADRE_2);
    }
    glEnd();
}

void MonRenderer::pointsArcCercleGauche()
{
    static constexpr int   NB_SEG = 10;

    for (uint16_t i = 0; i <= NB_SEG; ++i) {
        float theta = M_PI * (float)i/(float)NB_SEG + M_PI_2;

        float   x = _R_ARC_CERCLE * cos(theta),
                y = _R_ARC_CERCLE * sin(theta);

        glVertex2f(- _R_ARC_CERCLE + x, y);
    }
}

void MonRenderer::dessinAileGauche()
{
    glBegin(GL_POLYGON);
    {
        glVertex2f(0.f, 0.f);
        pointsArcCercleGauche();
        glVertex2f(0.f, 0.f);
    }
    glEnd();
}

void MonRenderer::dessinAiles()
{
    dessinAileGauche();

    // aile droite
    glPushMatrix();
    {
        glRotatef(180.f, 0.f, 0.f, 1.f);
        dessinAileGauche();
    }
    glPopMatrix();
}

void MonRenderer::dessinGenie()
{
    static constexpr float  LARGEUR_2 = _LARGEUR_CADRE_2 / 1.8f;
    static constexpr float  HAUTEUR_2 = _HAUTEUR_CADRE_2 / 2.f;

    glBegin(GL_LINES);
    {
        glVertex2f(-LARGEUR_2,  HAUTEUR_2);
        glVertex2f( LARGEUR_2,  HAUTEUR_2);

        glVertex2f(-LARGEUR_2,  HAUTEUR_2);
        glVertex2f(-LARGEUR_2, -HAUTEUR_2);

        glVertex2f( LARGEUR_2,  HAUTEUR_2);
        glVertex2f( LARGEUR_2, -HAUTEUR_2);

        glVertex2f(0.f       ,  HAUTEUR_2);
        glVertex2f(0.f       , -HAUTEUR_2);
    }
    glEnd();
}

void MonRenderer::dessinInfanterie()
{
    glBegin(GL_LINES);
    {
        glVertex2f(-_LARGEUR_CADRE_2, -_HAUTEUR_CADRE_2);
        glVertex2f( _LARGEUR_CADRE_2,  _HAUTEUR_CADRE_2);
        glVertex2f(-_LARGEUR_CADRE_2,  _HAUTEUR_CADRE_2);
        glVertex2f( _LARGEUR_CADRE_2, -_HAUTEUR_CADRE_2);
    }
    glEnd();
}

void MonRenderer::dessinArtillerie()
{
    static constexpr float R_CERCLE = _R_HEX / 4.f;
    static constexpr int   NB_SEG = 20;

    glBegin(GL_POLYGON);
    {
        for (uint16_t i = 0; i <= NB_SEG; ++i) {
            float theta = 2.f * M_PI * (float)i/(float)NB_SEG;

            float   x = R_CERCLE * cos(theta),
                    y = R_CERCLE * sin(theta);

            glVertex2f(x, y);
        }
    }
    glEnd();
}

void MonRenderer::dessinCharAssaut()
{
    glBegin(GL_LINE_STRIP);
    {
        pointsArcCercleGauche();
        glVertex2f( _R_ARC_CERCLE, -_R_ARC_CERCLE);
    }
    glEnd();

    // dessin symétrique
    glPushMatrix();
    {
        glRotatef(180.f, 0.f, 0.f, 1.f);
        glBegin(GL_LINE_STRIP);
        {
            pointsArcCercleGauche();
            glVertex2f( _R_ARC_CERCLE, -_R_ARC_CERCLE);
        }
        glEnd();
    }
    glPopMatrix();
}

void MonRenderer::dessinFregate()
{
    static constexpr float DX = _LARGEUR_CADRE_2 / 3.f;

    // dessin F droit
    glPushMatrix();
    {
        glTranslatef(-DX, 0.f, 0.f);
        dessinF();
    }
    glPopMatrix();

    // dessin F gauche
    glPushMatrix();
    {
        glTranslatef( DX, 0.f, 0.f);
        dessinF();
    }
    glPopMatrix();
}

void MonRenderer::dessinSousMarin()
{
    glBegin(GL_POLYGON);
    {
        glVertex2f(-_R_ARC_CERCLE      ,  _R_ARC_CERCLE);
        glVertex2f( _R_ARC_CERCLE      ,  _R_ARC_CERCLE);
        glVertex2f( 2.f * _R_ARC_CERCLE,  0.f          );
        glVertex2f( _R_ARC_CERCLE      , -_R_ARC_CERCLE);
        glVertex2f(-_R_ARC_CERCLE      , -_R_ARC_CERCLE);
        glVertex2f(-2.f * _R_ARC_CERCLE,  0.f          );
    }
    glEnd();
}

void MonRenderer::dessinChasseur()
{
    dessinAiles();

    // dessin F
    glPushMatrix();
    {
        glTranslatef(0.f, _DY_LETTRE, 0.f);
        glScalef(0.4f, 0.4f, 0.f);
        dessinF();
    }
    glPopMatrix();
}

void MonRenderer::dessinBombardier()
{
    dessinAiles();

    // dessin "B"
    glPushMatrix();
    {
        glTranslatef(0.f, _DY_LETTRE, 0.f);
        glScalef(0.4f, 0.4f, 0.f);
        dessinB();
    }
    glPopMatrix();
}

void MonRenderer::dessinUnite(uint16_t q, uint16_t r)
{
    auto c = _modele->accesCasePlateau({q, r});

    if (c->nbUnites() > 0) {
        // cadre
        if (c->getFaction() == Faction::bleue)
            glColor3f(0.f, 0.f, 1.f);
        else
            glColor3f(1.f, 0.f, 0.f);
        dessinCadre();

        // on affiche la premiere unite ou l'unite selectionee
        auto u =  (c != _modele->getCaseSelectionnee()) ?
                     c->getUnite(0) : _modele->getUniteSelectionee();

        glColor3f(0.f, 0.f, 0.f);
        if (dynamic_cast<Genie *>(u))
            dessinGenie();

        else if (dynamic_cast<Infanterie *>(u))
            dessinInfanterie();

        else if (dynamic_cast<Artillerie *>(u))
            dessinArtillerie();

        else if (dynamic_cast<CharAssaut *>(u))
            dessinCharAssaut();

        else if (dynamic_cast<Fregate *>(u))
            dessinFregate();

        else if (dynamic_cast<SousMarin *>(u))
            dessinSousMarin();

        else if (dynamic_cast<Chasseur *>(u))
            dessinChasseur();

        else    // Bombardier
            dessinBombardier();
    }

    // sinon on affiche rien
}

void MonRenderer::dessinContoursCasesConcernee()
{
    auto cases = _modele->getCasesConcernees();

    for (const auto &c: cases) {
        auto pos = c->getPos();
        auto [x, y] = hexVersLogique(pos.getQ(), pos.getR());

        glPushMatrix();
        {
            glTranslatef(x, y, 0.f);
            glLineWidth(3.f); // augmente epaisseur
            glColor3f(0.5f, 0.3f, 0.3f);
            glBegin(GL_LINE_LOOP);
            {
                pointsHex();
            }
            glEnd();
            glLineWidth(1.f); // reset epaisseur
        }
        glPopMatrix();
    }
}

void MonRenderer::surligneCaseSelectionnee()
{
    auto c = _modele->getCaseSelectionnee();
    if (c) {
        auto pos = c->getPos();
        auto [x, y] = hexVersLogique(pos.getQ(), pos.getR());

        glPushMatrix();
        {
            glTranslatef(x, y, 0.f);
            glColor4f(0.4f, 0.1, 0.1f, 0.3);
            glBegin(GL_POLYGON);
            {
                pointsHex();
            }
            glEnd();
        }
        glPopMatrix();
    }
}

std::pair<float, float> MonRenderer::hexVersLogique(uint16_t q, uint16_t r) const
{
    auto hauteur = _modele->getHauteurPlateau();

    float x = q * (_LARGEUR_HEX * 0.75f);
    float y = (hauteur - 1 - r) * _HAUTEUR_HEX + (q % 2) * _HAUTEUR_HEX / 2.f;

    return {x, y};
}

void MonRenderer::pointsHex()
{
    glVertex2f( _R_HEX  ,   0.f           );
    glVertex2f( _R_HEX_2,   _HAUTEUR_HEX_2);
    glVertex2f(-_R_HEX_2,   _HAUTEUR_HEX_2);
    glVertex2f(-_R_HEX  ,   0.f           );
    glVertex2f(-_R_HEX_2,  -_HAUTEUR_HEX_2);
    glVertex2f( _R_HEX_2,  -_HAUTEUR_HEX_2);
}

void MonRenderer::dessinHex()
{
    // applat de couleur
    glBegin(GL_POLYGON);
    {
        pointsHex();
    }
    glEnd();

    // contours
    glColor3f(0.f, 0.f, 0.f);
    glBegin(GL_LINE_LOOP);
    {
        pointsHex();
    }
    glEnd();
}

void MonRenderer::render()
{
    glViewport(0, 0, framebufferObject()->width(), framebufferObject()->height());

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    const auto  hauteur = _modele->getHauteurPlateau(),
                largeur = _modele->getLargeurPlateau();

    // Dimensions d'un hexagone et de la grille
    const float LARGEUR_GRILLE = _LARGEUR_HEX * (1.f + (largeur - 1) * 0.75f);
    const float HAUTEUR_GRILLE = _HAUTEUR_HEX * hauteur;

    // on etend l'espace logique pour qu'il ait le même ratio que la fenêtre
    const float LARGEUR_FEN   = static_cast<float>(framebufferObject()->width());
    const float HAUTEUR_FEN   = static_cast<float>(framebufferObject()->height());
    const float ASPECT  = LARGEUR_FEN / HAUTEUR_FEN;

    // on garde la hauteur logique fixe et on elargit si besoin
    float largeurOrtho = HAUTEUR_GRILLE * ASPECT, hauteurOrtho = HAUTEUR_GRILLE;

    if (largeurOrtho < LARGEUR_GRILLE) {
        largeurOrtho = LARGEUR_GRILLE;
        hauteurOrtho = LARGEUR_GRILLE / ASPECT;
    }

    // centrage de la grille dans l'espace logique
    const float CX = LARGEUR_GRILLE / 2.f, CY = HAUTEUR_GRILLE / 2.f;

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(CX - largeurOrtho / 2.f, CX + largeurOrtho / 2.f,
            CY - hauteurOrtho / 2.f - _HAUTEUR_HEX / 2.f, CY + hauteurOrtho / 2.f,
            -1.f, 1.f);

    // modelview
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // display
    for (std::size_t r = 0; r < hauteur; ++r) {
        for (std::size_t q = 0; q < largeur; ++q) {
            const auto [x, y] = hexVersLogique(q, r);

            const couleur c = getCouleur(q, r);
            glColor3f(c.r, c.v, c.b);

            glPushMatrix();
            {
                glTranslatef(x, y, 0.f);
                dessinHex();
                dessinUnite(q, r);
            }
            glPopMatrix();
        }
    }

    dessinContoursCasesConcernee();
    surligneCaseSelectionnee();
}

QOpenGLFramebufferObject *MonRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::Depth);
    format.setSamples(8);
    return new QOpenGLFramebufferObject(size, format);
}
