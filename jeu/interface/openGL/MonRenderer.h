#pragma once

#include "modelePourQML/modelepourqml.h"
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

    //couleur getCouleur(float q, float r) const;
    void drawHex(float x, float y) const;

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;

private:
    ModelePourQML *_modele;

    static const float _R;
};
