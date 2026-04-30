#include "MonRenderer.h"

#include <QOpenGLFramebufferObjectFormat>
#include <GL/gl.h>

MonRenderer::MonRenderer(ModelePourQML *modele):
    _modele(modele)
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH);
}

void MonRenderer::render()
{
    glViewport(0, 0, framebufferObject()->width(), framebufferObject()->height());

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // PROJECTION
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    const Carte &plateau = _modele->getPlateau();
    auto hauteur = plateau.getHauteur();
    auto largeur = plateau.getLargeur();
    glOrtho(0.0,  largeur-1,
            0.0,  hauteur-1,
            -1.0, 1.0);

    // MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Display
    glPointSize(10.f);
    glBegin(GL_POINTS);
    {
        glColor3f(1.f, 0.f, 0.f); glVertex2f(0., 0.);   // origine

        glColor3f(0.f, 1.f, 0.f);
        for (std::size_t r = 0; r < hauteur; ++r) {
            for (std::size_t q = 0; q < largeur; ++q) {
                glVertex2f(q, r);
            }
        }
    }
    glEnd();

    update(); // redraw continu
}

QOpenGLFramebufferObject *MonRenderer::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::Depth);

    return new QOpenGLFramebufferObject(size, format);
}
