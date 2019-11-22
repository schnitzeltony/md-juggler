#ifndef MDSTREAMTREERENDERER_H
#define MDSTREAMTREERENDERER_H

#include "abstractstreamitemrenderer.h"

QT_BEGIN_NAMESPACE

class MdStreamTreeRendererPrivate;
class MdStreamTreeRenderer : public AbstractStreamItemRenderer
{
    Q_OBJECT
public:
    explicit MdStreamTreeRenderer(QObject *parent = nullptr);

protected:
    Q_DECLARE_PRIVATE(MdStreamTreeRenderer)
    Q_DISABLE_COPY(MdStreamTreeRenderer)
};

QT_END_NAMESPACE

#endif // MDSTREAMTREERENDERER_H
