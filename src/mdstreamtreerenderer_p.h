#ifndef MDSTREAMTREERENDERER_P_H
#define MDSTREAMTREERENDERER_P_H

#include "mdstreamtreerenderer.h"
#include "abstractstreamitemrenderer_p.h"

class MdStreamTreeRendererPrivate : AbstractStreamItemRendererPrivate
{
    Q_DECLARE_PUBLIC(MdStreamTreeRenderer)
public:
    MdStreamTreeRendererPrivate(MdStreamTreeRenderer *pPublic);

};

#endif // MDSTREAMTREERENDERER_P_H
