#include "abstractrenderitemdelegate.h"
#include "abstractrenderitemdelegate_p.h"
#include <QAbstractItemModel>

QT_BEGIN_NAMESPACE

AbstractRenderItemDelegate::AbstractRenderItemDelegate(QObject *parent) :
    QObject(parent)
{
}

AbstractRenderItemDelegate::AbstractRenderItemDelegate(AbstractRenderItemDelegatePrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{
}

AbstractRenderItemDelegate::~AbstractRenderItemDelegate()
{
}

void AbstractRenderItemDelegate::setModelData(QAbstractItemModel *, const QModelIndex &) const
{
}

QT_END_NAMESPACE
