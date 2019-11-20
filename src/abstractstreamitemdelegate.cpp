#include "abstractstreamitemdelegate.h"
#include <QAbstractItemModel>

QT_BEGIN_NAMESPACE

AbstractStreamItemDelegate::AbstractStreamItemDelegate(QObject *parent) :
    QObject(parent)
{
}

AbstractStreamItemDelegate::~AbstractStreamItemDelegate()
{
}

QT_END_NAMESPACE
