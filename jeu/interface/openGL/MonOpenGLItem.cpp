#include "MonOpenGLItem.h"
#include "MonRenderer.h"

QQuickFramebufferObject::Renderer *MonOpenGLItem::createRenderer() const
{
    return new MonRenderer();
}
