#include "abstractstreamitemdelegate.h"
#include "abstractstreamitemdelegate_p.h"
#include <QAbstractItemModel>

QT_BEGIN_NAMESPACE

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

void AbstractStreamItemDelegate::setModelData(QAbstractItemModel *, const QModelIndex &) const
{
}

QT_END_NAMESPACE
