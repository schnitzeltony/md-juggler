#ifndef QABSTRACTSTREAMITEMDELEGATE_P_H
#define QABSTRACTSTREAMITEMDELEGATE_P_H

#include "abstractstreamitemdelegate.h"

QT_BEGIN_NAMESPACE

class AbstractStreamItemDelegatePrivate
{
    Q_DECLARE_PUBLIC(AbstractStreamItemDelegate)

public:
    AbstractStreamItemDelegatePrivate(AbstractStreamItemDelegate *pPublic);
    virtual ~AbstractStreamItemDelegatePrivate();


protected:
    AbstractStreamItemDelegate *q_ptr;

};

QT_END_NAMESPACE

#endif //QABSTRACTSTREAMITEMDELEGATE_P_H
