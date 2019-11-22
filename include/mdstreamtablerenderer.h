#ifndef MDSTREAMTABLERENDERER_H
#define MDSTREAMTABLERENDERER_H

#include "abstractstreamitemrenderer.h"

QT_BEGIN_NAMESPACE

class MdStreamTableRendererPrivate;
class MdStreamTableRenderer : public AbstractStreamItemRenderer
{
    Q_OBJECT
public:
    explicit MdStreamTableRenderer(QObject *parent = nullptr);

protected:
    Q_DECLARE_PRIVATE(MdStreamTableRenderer)
    Q_DISABLE_COPY(MdStreamTableRenderer)
};

QT_END_NAMESPACE

#endif // MDSTREAMTABLERENDERER_H
