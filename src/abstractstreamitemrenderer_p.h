#ifndef QABSTRACTSTREAMITEMRENDERER_P_H
#define QABSTRACTSTREAMITEMRENDERER_P_H

#include "abstractstreamitemrenderer.h"
#include "abstractstreamitemdelegate.h"
#include <QPointer>
#include <QMap>
#include <QPersistentModelIndex>

QT_BEGIN_NAMESPACE

class AbstractStreamItemRendererPrivate
{
    Q_DECLARE_PUBLIC(AbstractStreamItemRenderer)

public:
    AbstractStreamItemRendererPrivate(AbstractStreamItemRenderer *pPublic);
    virtual ~AbstractStreamItemRendererPrivate();

    QAbstractItemModel *model;
    QPointer<AbstractStreamItemDelegate> itemDelegate;
    QMap<int, QPointer<AbstractStreamItemDelegate> > rowDelegates;
    QMap<int, QPointer<AbstractStreamItemDelegate> > columnDelegates;

    QPersistentModelIndex root;

    bool alternatingColors;
protected:
    AbstractStreamItemRenderer *q_ptr;

};

QT_END_NAMESPACE

#endif //QABSTRACTSTREAMITEMRENDERER_P_H
