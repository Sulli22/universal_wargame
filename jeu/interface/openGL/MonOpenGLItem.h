#pragma once

#include <QQuickFramebufferObject>

class MonRenderer;

class MonOpenGLItem : public QQuickFramebufferObject {
    Q_OBJECT

public:
    Renderer *createRenderer() const override;
};
