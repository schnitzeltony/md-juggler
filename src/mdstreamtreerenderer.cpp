#include "mdstreamtreerenderer.h"
#include "mdstreamtreerenderer_p.h"

MdStreamTreeRendererPrivate::MdStreamTreeRendererPrivate(MdStreamTreeRenderer *pPublic) :
    AbstractStreamItemRendererPrivate(pPublic)
{

}

MdStreamTreeRenderer::MdStreamTreeRenderer(QObject *parent) :
    AbstractStreamItemRenderer(*new MdStreamTreeRendererPrivate(this), parent)
{

}

