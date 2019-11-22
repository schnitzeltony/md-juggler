#ifndef MDSTREAMDELEGATE_P_H
#define MDSTREAMDELEGATE_P_H

#include "mdstreamdelegate.h"
#include "abstractstreamitemdelegate_p.h"

class MdStreamDelegatePrivate : AbstractStreamItemDelegatePrivate
{
    Q_DECLARE_PUBLIC(MdStreamDelegate)
public:
    MdStreamDelegatePrivate(MdStreamDelegate *pPublic);
    ~MdStreamDelegatePrivate();

    MdStreamDelegate::MDType mdType;
};

#endif // MDSTREAMDELEGATE_P_H
