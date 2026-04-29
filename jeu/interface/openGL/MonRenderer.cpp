#include "MonRenderer.h"

#include <QOpenGLFramebufferObjectFormat>
#include <GL/gl.h>

MonRenderer::MonRenderer()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH);
}

void MonRenderer::render()
{
    glViewport(0, 0, framebufferObject()->width(), framebufferObject()->height());

    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    {
        glColor3f(1, 0, 0); glVertex2f(0.0f, 0.6f);
        glColor3f(0, 1, 0); glVertex2f(-0.6f, -0.6f);
        glColor3f(0, 0, 1); glVertex2f(0.6f, -0.6f);
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
