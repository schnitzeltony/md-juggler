#ifndef QABSTRACTRENDERITEMDELEGATE_P_H
#define QABSTRACTRENDERITEMDELEGATE_P_H

#include "abstractrenderitemdelegate.h"

QT_BEGIN_NAMESPACE

class AbstractRenderItemDelegatePrivate
{
    Q_DECLARE_PUBLIC(AbstractRenderItemDelegate)

public:
    AbstractRenderItemDelegatePrivate(AbstractRenderItemDelegate *pPublic);
    virtual ~AbstractRenderItemDelegatePrivate();


protected:
    AbstractRenderItemDelegate *q_ptr;

};

QT_END_NAMESPACE

#endif //QABSTRACTRENDERITEMDELEGATE_P_H
