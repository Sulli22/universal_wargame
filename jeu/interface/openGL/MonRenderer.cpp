#include "MonRenderer.h"

#include <QOpenGLFramebufferObjectFormat>
#include <GL/gl.h>

MonRenderer::MonRenderer(ModelePourQML *modele):
    _modele(modele)
{
    initializeOpenGLFunctions();
}

void MonRenderer::drawHex(float x, float y) const
{
    glBegin(GL_POLYGON);
    {
        glVertex2f(x + _R, y);
        glVertex2f(x + _R/2, y + _R*sqrt(3)/2);
        glVertex2f(x - _R/2, y + _R*sqrt(3)/2);
        glVertex2f(x - _R, y);
        glVertex2f(x - _R/2, y - _R*sqrt(3)/2);
        glVertex2f(x + _R/2, y - _R*sqrt(3)/2);
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
    glColor3f(0.f, 1.f, 0.f);
    for (std::size_t r = 0; r < hauteur; ++r) {
        for (std::size_t q = 0; q < largeur; ++q) {
            const float x = q * (HEX_W * 0.75f);
            const float y = r * HEX_H + (q % 2) * HEX_H / 2.f;
            drawHex(x, y);
        }
    }

    update();
}

QOpenGLFramebufferObject *MonRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::Depth);
    return new QOpenGLFramebufferObject(size, format);
}

const float MonRenderer::_R(1.);
