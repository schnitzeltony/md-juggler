#include "mdstreamtablerenderer.h"
#include "mdstreamtablerenderer_p.h"

MdStreamTableRendererPrivate::MdStreamTableRendererPrivate(MdStreamTableRenderer *pPublic) :
    AbstractStreamItemRendererPrivate(pPublic)
{

}

MdStreamTableRenderer::MdStreamTableRenderer(QObject *parent) :
    AbstractStreamItemRenderer(*new MdStreamTableRendererPrivate(this), parent)
{

}

