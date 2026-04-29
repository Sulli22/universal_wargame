#pragma once

#include <QQuickFramebufferObject>
#include <QOpenGLFunctions>

class MonRenderer : public QQuickFramebufferObject::Renderer, protected QOpenGLFunctions {
public:
    MonRenderer();

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
};
