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

QPointF MonOpenGLItem::pixelVersLogique(float mouseX, float mouseY,
                                        float largeurFen, float hauteurFen) const
{
    // TODO
    return {0, 0};
}

Position MonOpenGLItem::logiqueVersHex(float lx, float ly) const
{
    // TODO
    return {0, 0};
}

void MonOpenGLItem::gererClic(float mouseX, float mouseY)
{
    float largeurFen = static_cast<float>(width());
    float hauteurFen = static_cast<float>(height());

    // TODO
}

QQuickFramebufferObject::Renderer *MonOpenGLItem::createRenderer() const
{
    return new MonRenderer(_modele);
}
