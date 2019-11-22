#ifndef MDSTREAMTABLERENDERER_P_H
#define MDSTREAMTABLERENDERER_P_H

#include "mdstreamtablerenderer.h"
#include "abstractstreamitemrenderer_p.h"

class MdStreamTableRendererPrivate : AbstractStreamItemRendererPrivate
{
    Q_DECLARE_PUBLIC(MdStreamTableRenderer)
public:
    MdStreamTableRendererPrivate(MdStreamTableRenderer *pPublic);

};

#endif // MDSTREAMTABLERENDERER_P_H
