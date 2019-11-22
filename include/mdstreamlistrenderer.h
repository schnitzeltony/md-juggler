#ifndef MDSTREAMLISTRENDERER_H
#define MDSTREAMLISTRENDERER_H

#include "abstractstreamitemrenderer.h"

QT_BEGIN_NAMESPACE

class MdStreamListRendererPrivate;
class MdStreamListRenderer : public AbstractStreamItemRenderer
{
    Q_OBJECT
public:
    explicit MdStreamListRenderer(QObject *parent = nullptr);

protected:
    Q_DECLARE_PRIVATE(MdStreamListRenderer)
    Q_DISABLE_COPY(MdStreamListRenderer)
};

QT_END_NAMESPACE

#endif // MDSTREAMLISTRENDERER_H
