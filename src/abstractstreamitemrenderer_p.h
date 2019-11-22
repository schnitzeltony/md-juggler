#ifndef QABSTRACTSTREAMITEMRENDERER_P_H
#define QABSTRACTSTREAMITEMRENDERER_P_H

#include "abstractstreamitemrenderer.h"
#include "abstractstreamitemdelegate.h"
#include <QPersistentModelIndex>
#include <QPointer>

QT_BEGIN_NAMESPACE

class AbstractStreamItemRendererPrivate
{
    Q_DECLARE_PUBLIC(AbstractStreamItemRenderer)

public:
    AbstractStreamItemRendererPrivate(AbstractStreamItemRenderer *pPublic);
    virtual ~AbstractStreamItemRendererPrivate();

    QAbstractItemModel *model;
    QPointer<AbstractStreamItemDelegate> itemDelegate;
    QMap<int, QPointer<AbstractStreamItemDelegate>> rowDelegates;
    QMap<int, QPointer<AbstractStreamItemDelegate>> columnDelegates;
    QPointer<QItemSelectionModel> selectionModel;
    AbstractStreamItemRenderer::SelectionMode selectionMode;

    QPersistentModelIndex root;

    bool alternatingColors; // TODO remove???
protected:
    AbstractStreamItemRenderer *q_ptr;
};

QT_END_NAMESPACE

#endif //QABSTRACTSTREAMITEMRENDERER_P_H
