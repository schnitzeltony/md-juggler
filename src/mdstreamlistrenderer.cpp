#include "mdstreamlistrenderer.h"
#include "mdstreamlistrenderer_p.h"

MdStreamListRendererPrivate::MdStreamListRendererPrivate(MdStreamListRenderer *pPublic) :
    AbstractStreamItemRendererPrivate(pPublic)
{
}

MdStreamListRenderer::MdStreamListRenderer(QObject *parent) :
    AbstractStreamItemRenderer(*new MdStreamListRendererPrivate(this), parent)
{
}

