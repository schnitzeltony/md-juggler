#ifndef QABSTRACTSTREAMITEMDELEGATE_P_H
#define QABSTRACTSTREAMITEMDELEGATE_P_H

#include "abstractstreamitemdelegate.h"
#include <QPersistentModelIndex>

QT_BEGIN_NAMESPACE

class AbstractStreamItemDelegatePrivate
{
    Q_DECLARE_PUBLIC(AbstractStreamItemDelegate)

public:
    AbstractStreamItemDelegatePrivate(AbstractStreamItemDelegate *pPublic);
    virtual ~AbstractStreamItemDelegatePrivate();

    int calcItemLevel(const QPersistentModelIndex &viewRootIndex, const QModelIndex &index);
protected:
    AbstractStreamItemDelegate *q_ptr;
};

QT_END_NAMESPACE

#endif //QABSTRACTSTREAMITEMDELEGATE_P_H
