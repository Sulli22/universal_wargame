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

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

couleur MonRenderer::getCouleur(uint16_t q, uint16_t r) const
{
    auto c = _modele->getPlateau().accesCase({q, r});

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

void MonRenderer::dessinCadre(float x, float y) const
{
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(x - _R/2.f, y - _R*sqrt(3)/4.f);
        glVertex2f(x - _R/2.f, y + _R*sqrt(3)/4.f);
        glVertex2f(x + _R/2.f, y + _R*sqrt(3)/4.f);
        glVertex2f(x + _R/2.f, y - _R*sqrt(3)/4.f);
    }
    glEnd();
}

void MonRenderer::dessinAiles(float x, float y) const
{
    glBegin(GL_POLYGON);
    {
        // aile gauche
        glVertex2f(x, y);
        for (uint16_t i = 0; i <= 5; ++i) {
            float theta = M_PI * (float)i/5.f + M_PI/2.f;
            float cx = _R/5.f * cos(theta), cy = _R/5.f * sin(theta);
            glVertex2f(x - _R/5.f + cx, y + cy);
        }

        // aile droite
        glVertex2f(x, y);
        for (uint16_t i = 0; i <= 5; ++i) {
            float theta = M_PI * (float)i/5.f - M_PI/2.f;
            float cx = _R/5.f * cos(theta), cy = _R/5.f * sin(theta);
            glVertex2f(x + _R/5.f + cx, y + cy);
        }
    }
    glEnd();
}

void MonRenderer::dessinGenie(float x, float y) const
{
    glBegin(GL_LINES);
    {
        glVertex2f(x - _R/3.f, y + _R*sqrt(3)/8.f);
        glVertex2f(x + _R/3.f, y + _R*sqrt(3)/8.f);

        glVertex2f(x - _R/3.f, y + _R*sqrt(3)/8.f);
        glVertex2f(x - _R/3.f, y - _R*sqrt(3)/8.f);

        glVertex2f(x + _R/3.f, y + _R*sqrt(3)/8.f);
        glVertex2f(x + _R/3.f, y - _R*sqrt(3)/8.f);

        glVertex2f(x, y + _R*sqrt(3)/8.f);
        glVertex2f(x, y - _R*sqrt(3)/8.f);
    }
    glEnd();
}

void MonRenderer::dessinInfanterie(float x, float y) const
{
    glBegin(GL_LINES);
    {
        glVertex2f(x - _R/2.f, y - _R*sqrt(3)/4.f);
        glVertex2f(x + _R/2.f, y + _R*sqrt(3)/4.f);
        glVertex2f(x - _R/2.f, y + _R*sqrt(3)/4.f);
        glVertex2f(x + _R/2.f, y - _R*sqrt(3)/4.f);
    }
    glEnd();
}

void MonRenderer::dessinArtillerie(float x, float y) const
{
    glBegin(GL_POLYGON);
    {
        for (uint16_t i = 0; i <= 20; ++i) {
            float theta = 2.f * M_PI * (float)i / 20.f;
            float cx = _R/4.f * cos(theta), cy = _R/4.f * sin(theta);
            glVertex2f(x + cx, y + cy);
        }
    }
    glEnd();
}

void MonRenderer::dessinCharAssaut(float x, float y) const
{
    glBegin(GL_LINE_LOOP);
    {
        for (uint16_t i = 0; i <= 5; ++i) {
            float theta = M_PI * (float)i/5.f - M_PI/2.f;
            float cx = _R/5.f * cos(theta), cy = _R/5.f * sin(theta);
            glVertex2f(x + _R/5.f + cx, y + cy);
        }

        for (uint16_t i = 0; i <= 5; ++i) {
            float theta = M_PI * (float)i/5.f + M_PI/2.f;
            float cx = _R/5.f * cos(theta), cy = _R/5.f * sin(theta);
            glVertex2f(x - _R/5.f + cx, y + cy);
        }
    }
    glEnd();
}

void MonRenderer::dessinFregate(float x, float y) const
{
    // dessin "FF"
    glBegin(GL_LINES);
    {
        // 1er F
        glVertex2f(x - _R/4.f, y + _R/4.f);
        glVertex2f(x - _R/4.f, y - _R/4.f);

        glVertex2f(x - _R/4.f, y + _R/4.f);
        glVertex2f(x - _R/10.f, y + _R/4.f);

        glVertex2f(x - _R/4.f, y);
        glVertex2f(x - _R/10.f, y);

        // 2eme F
        glVertex2f(x + _R/10.f, y + _R/4.f);
        glVertex2f(x + _R/10.f, y - _R/4.f);

        glVertex2f(x + _R/10.f, y + _R/4.f);
        glVertex2f(x + _R/4.f, y + _R/4.f);

        glVertex2f(x + _R/10.f, y);
        glVertex2f(x + _R/4.f, y);
    }
    glEnd();
}

void MonRenderer::dessinSousMarin(float x, float y) const
{
    glBegin(GL_POLYGON);
    {
        glVertex2f(x - _R/5.f, y + _R/5.f);
        glVertex2f(x + _R/5.f, y + _R/5.f);
        glVertex2f(x + _R/3.f, y);
        glVertex2f(x + _R/5.f, y - _R/5.f);
        glVertex2f(x - _R/5.f, y - _R/5.f);
        glVertex2f(x - _R/3.f, y);
    }
    glEnd();
}

void MonRenderer::dessinChasseur(float x, float y) const
{
    dessinAiles(x, y);

    // dessin "F"
    glBegin(GL_LINES);
    {
        glVertex2f(x, y + _R/6.f);
        glVertex2f(x, y + _R/3.f);

        glVertex2f(x, y + _R/3.f);
        glVertex2f(x + _R/8.f, y + _R/3.f);

        glVertex2f(x, y + _R/4.f);
        glVertex2f(x + _R/8.f, y + _R/4.f);
    }
    glEnd();
}

void MonRenderer::dessinBombardier(float x, float y) const
{
    dessinAiles(x, y);

    // dessin "B"
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(x, y + _R/6.f);
        glVertex2f(x, y + _R/3.f);

        glVertex2f(x + _R/10.f, y + _R/3.5f);
        glVertex2f(x, y + _R/4.f);
        glVertex2f(x + _R/10.f, y + _R/4.5f);
    }
    glEnd();
}

void MonRenderer::dessinUnite(uint16_t q, uint16_t r, float x, float y) const
{
    auto c = _modele->getPlateau().accesCase({q, r});

    if (c->nbUnites() > 0) {
        // cadre
        if (c->getFaction() == Faction::bleue)
            glColor3f(0.f, 0.f, 1.f);
        else
            glColor3f(1.f, 0.f, 0.f);
        dessinCadre(x, y);

        // on affiche la premiere unite
        glColor3f(0.f, 0.f, 0.f);
        auto u = c->getUnite(0);
        if (dynamic_cast<Genie *>(u))
            dessinGenie(x, y);

        else if (dynamic_cast<Infanterie *>(u))
            dessinInfanterie(x, y);

        else if (dynamic_cast<Artillerie *>(u))
            dessinArtillerie(x, y);

        else if (dynamic_cast<CharAssaut *>(u))
            dessinCharAssaut(x, y);

        else if (dynamic_cast<Fregate *>(u))
            dessinFregate(x, y);

        else if (dynamic_cast<SousMarin *>(u))
            dessinSousMarin(x, y);

        else if (dynamic_cast<Chasseur *>(u))
            dessinChasseur(x, y);

        else    // Bombardier
            dessinBombardier(x, y);
    }

    // sinon on affiche rien
}

void MonRenderer::dessinHex(float x, float y) const
{
    // applat de couleur
    glBegin(GL_POLYGON);
    {
        glVertex2f(x + _R, y);
        glVertex2f(x + _R/2.f, y + _R*sqrt(3)/2);
        glVertex2f(x - _R/2.f, y + _R*sqrt(3)/2);
        glVertex2f(x - _R, y);
        glVertex2f(x - _R/2.f, y - _R*sqrt(3)/2);
        glVertex2f(x + _R/2.f, y - _R*sqrt(3)/2);
    }
    glEnd();

    // contours
    glColor3f(0.f, 0.f, 0.f);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(x + _R, y);
        glVertex2f(x + _R/2.f, y + _R*sqrt(3)/2);
        glVertex2f(x - _R/2.f, y + _R*sqrt(3)/2);
        glVertex2f(x - _R, y);
        glVertex2f(x - _R/2.f, y - _R*sqrt(3)/2);
        glVertex2f(x + _R/2.f, y - _R*sqrt(3)/2);
    }
    glEnd();
}

void MonRenderer::render()
{
    glViewport(0, 0, framebufferObject()->width(), framebufferObject()->height());

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    const Carte& plateau = _modele->getPlateau();
    const auto hauteur = plateau.getHauteur(), largeur = plateau.getLargeur();

    // Dimensions d'un hexagone et de la grille
    const float HEX_W  = 2.f * _R;               // largeur  (pointe à pointe)
    const float HEX_H  = sqrt(3.f) * _R;    // hauteur  (plat à plat)
    const float GRID_W = HEX_W * (1.f + (largeur - 1) * 0.75f);
    const float GRID_H = HEX_H * hauteur;

    // on etend l'espace logique pour qu'il ait le même ratio que la fenêtre
    const float WIN_W   = static_cast<float>(framebufferObject()->width());
    const float WIN_H   = static_cast<float>(framebufferObject()->height());
    const float ASPECT  = WIN_W / WIN_H;

    // on garde la hauteur logique fixe et on elargit si besoin
    float orthoW = GRID_H * ASPECT, orthoH = GRID_H;

    if (orthoW < GRID_W) {
        orthoW = GRID_W;
        orthoH = GRID_W / ASPECT;
    }

    // centrage de la grille dans l'espace logique
    const float CX = GRID_W / 2.f, CY = GRID_H / 2.f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(CX - orthoW / 2.f, CX + orthoW / 2.f,
            CY - orthoH / 2.f - _R, CY + orthoH / 2.f,
            -1.f, 1.f);

    // MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // display
    for (std::size_t r = 0; r < hauteur; ++r) {
        for (std::size_t q = 0; q < largeur; ++q) {
            const float x = q * (HEX_W * 0.75f);
            const float y = (hauteur - 1 - r) * HEX_H + (q % 2) * HEX_H / 2.f;

            const couleur c = getCouleur(q, r);
            glColor3f(c.r, c.v, c.b);

            dessinHex(x, y);
            dessinUnite(q, r, x, y);
        }
    }

    update();
}

QOpenGLFramebufferObject *MonRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::Depth);
    format.setSamples(8);
    return new QOpenGLFramebufferObject(size, format);
}

const float MonRenderer::_R(5.f);
