#include "abstractstreamitemdelegate.h"
#include "abstractstreamitemdelegate_p.h"
#include <QAbstractItemModel>

QT_BEGIN_NAMESPACE

AbstractStreamItemDelegatePrivate::AbstractStreamItemDelegatePrivate(AbstractStreamItemDelegate *pPublic) :
    q_ptr(pPublic)
{
}

AbstractStreamItemDelegatePrivate::~AbstractStreamItemDelegatePrivate()
{
}

int AbstractStreamItemDelegatePrivate::calcItemLevel(const QPersistentModelIndex &viewRootIndex, const QModelIndex &index) const
{
    int level = 0;
    if(index.isValid() && index.model() == viewRootIndex.model()) {
        QModelIndex modelIndexTemp = index;
        while(modelIndexTemp.parent() != viewRootIndex) {
            modelIndexTemp = modelIndexTemp.parent();
            ++level;
        }
    }
    else {
        level = -1;
    }
    return level;
}

AbstractStreamItemDelegate::AbstractStreamItemDelegate(QObject *parent) :
    QObject(parent)
{
}

AbstractStreamItemDelegate::AbstractStreamItemDelegate(AbstractStreamItemDelegatePrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{
}

AbstractStreamItemDelegate::~AbstractStreamItemDelegate()
{
}

QT_END_NAMESPACE
