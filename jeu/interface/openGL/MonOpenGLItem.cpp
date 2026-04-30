#include "MonOpenGLItem.h"
#include "MonRenderer.h"

MonOpenGLItem::MonOpenGLItem(QQuickItem *parent):
    QQuickFramebufferObject(parent)
{
    setMirrorVertically(true);
}

ModelePourQML *MonOpenGLItem::getModele() const
{
    return _modele;
}

void MonOpenGLItem::setModele(ModelePourQML *nvModele)
{
    _modele = nvModele;
}

QQuickFramebufferObject::Renderer *MonOpenGLItem::createRenderer() const
{
    return new MonRenderer(_modele);
}
