#pragma once

#include "modelePourQML/modelepourqml.h"
#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class MonRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    MonRenderer(ModelePourQML *modele);

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    ModelePourQML *_modele;
};
