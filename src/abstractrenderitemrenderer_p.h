#ifndef QABSTRACTRENDERITEMRENDERER_P_H
#define QABSTRACTRENDERITEMRENDERER_P_H

#include "abstractrenderitemrenderer.h"
#include "abstractrenderitemdelegate.h"
#include <QPointer>
#include <QMap>
#include <QPersistentModelIndex>

QT_BEGIN_NAMESPACE

class AbstractRenderItemRendererPrivate
{
    Q_DECLARE_PUBLIC(AbstractRenderItemRenderer)

public:
    AbstractRenderItemRendererPrivate(AbstractRenderItemRenderer *pPublic);
    virtual ~AbstractRenderItemRendererPrivate();

    QAbstractItemModel *model;
    QPointer<AbstractRenderItemDelegate> itemDelegate;
    QMap<int, QPointer<AbstractRenderItemDelegate> > rowDelegates;
    QMap<int, QPointer<AbstractRenderItemDelegate> > columnDelegates;

    QPersistentModelIndex root;

    bool alternatingColors;
protected:
    AbstractRenderItemRenderer *q_ptr;

};

QT_END_NAMESPACE

#endif //QABSTRACTRENDERITEMRENDERER_P_H
