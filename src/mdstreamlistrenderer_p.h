#ifndef MDSTREAMLISTRENDERER_P_H
#define MDSTREAMLISTRENDERER_P_H

#include "mdstreamlistrenderer.h"
#include "abstractstreamitemrenderer_p.h"

class MdStreamListRendererPrivate : AbstractStreamItemRendererPrivate
{
    Q_DECLARE_PUBLIC(MdStreamListRenderer)
public:
    MdStreamListRendererPrivate(MdStreamListRenderer *pPublic);

};

#endif // MDSTREAMLISTRENDERER_P_H
