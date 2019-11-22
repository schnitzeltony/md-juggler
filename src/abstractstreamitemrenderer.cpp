#include "abstractstreamitemrenderer.h"
#include "abstractstreamitemrenderer_p.h"
#include "abstractstreamitemdelegate.h"
#include <QAbstractItemModel>
#include <QItemSelectionModel>
#include <QMap>

QT_BEGIN_NAMESPACE

// clang: be quiet - there is one instance only
QT_WARNING_DISABLE_CLANG("-Wweak-vtables")

// QAbstractItemModel does not export qEmptyModel. So we have to steal the
// code to avoid including privat API
class QEmptyItemModel : public QAbstractItemModel
{
public:
    explicit QEmptyItemModel(QObject *parent = nullptr) : QAbstractItemModel(parent) {}
    QModelIndex index(int, int, const QModelIndex &) const override { return QModelIndex(); }
    QModelIndex parent(const QModelIndex &) const override { return QModelIndex(); }
    int rowCount(const QModelIndex &) const override { return 0; }
    int columnCount(const QModelIndex &) const override { return 0; }
    bool hasChildren(const QModelIndex &) const override { return false; }
    QVariant data(const QModelIndex &, int) const override { return QVariant(); }
};

Q_GLOBAL_STATIC(QEmptyItemModel, qEmptyModel)


AbstractStreamItemRendererPrivate::AbstractStreamItemRendererPrivate(AbstractStreamItemRenderer *pPublic) :
    model(qEmptyModel()),
    alternatingColors(false),
    q_ptr(pPublic)
{
}

AbstractStreamItemRendererPrivate::~AbstractStreamItemRendererPrivate()
{
}

AbstractStreamItemRenderer::AbstractStreamItemRenderer(QObject *parent) :
    QObject(parent)
{
}

AbstractStreamItemRenderer::AbstractStreamItemRenderer(AbstractStreamItemRendererPrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{

}

AbstractStreamItemRenderer::~AbstractStreamItemRenderer()
{
}

void AbstractStreamItemRenderer::setModel(QAbstractItemModel *model)
{
    Q_D(AbstractStreamItemRenderer);
    if (model == d->model)
        return;

}

QAbstractItemModel *AbstractStreamItemRenderer::model() const
{
    Q_D(const AbstractStreamItemRenderer);
    return (d->model == qEmptyModel() ? nullptr : d->model);
}

void AbstractStreamItemRenderer::setSelectionModel(QItemSelectionModel *selectionModel)
{
    // ### if the given model is null, we should use the original selection model
    Q_ASSERT(selectionModel);
    Q_D(AbstractStreamItemRenderer);

    if (Q_UNLIKELY(selectionModel->model() != d->model)) {
        qWarning("AbstractStreamItemRenderer::setSelectionModel() failed: "
                 "Trying to set a selection model, which works on "
                 "a different model than the view.");
        return;
    }

    d->selectionModel = selectionModel;
}

QItemSelectionModel *AbstractStreamItemRenderer::selectionModel() const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->selectionModel;
}

void AbstractStreamItemRenderer::setItemDelegate(AbstractStreamItemDelegate *delegate)
{
    Q_D(AbstractStreamItemRenderer);
    if (delegate == d->itemDelegate)
        return;
    d->itemDelegate = delegate;
}

AbstractStreamItemDelegate *AbstractStreamItemRenderer::itemDelegate() const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->itemDelegate;
}

void AbstractStreamItemRenderer::setSelectionMode(AbstractStreamItemRenderer::SelectionMode mode)
{
    Q_D(AbstractStreamItemRenderer);
    d->selectionMode = mode;
}

AbstractStreamItemRenderer::SelectionMode AbstractStreamItemRenderer::selectionMode() const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->selectionMode;
}

void AbstractStreamItemRenderer::setAlternatingRowColors(bool enable)
{
    Q_D(AbstractStreamItemRenderer);
    d->alternatingColors = enable;
}

bool AbstractStreamItemRenderer::alternatingRowColors() const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->alternatingColors;
}

void AbstractStreamItemRenderer::setRootIndex(const QModelIndex &index)
{
    Q_D(AbstractStreamItemRenderer);
    if (Q_UNLIKELY(index.isValid() && index.model() != d->model)) {
        qWarning("QAbstractItemView::setRootIndex failed : index must be from the currently set model");
        return;
    }
    d->root = index;
}

QModelIndex AbstractStreamItemRenderer::rootIndex() const
{
    Q_D(const AbstractStreamItemRenderer);
    return QModelIndex(d->root);
}

void AbstractStreamItemRenderer::setItemDelegateForRow(int row, AbstractStreamItemDelegate *delegate)
{
    Q_D(AbstractStreamItemRenderer);
    // no signal/slot -> just replace
    d->rowDelegates[row] = delegate;
}

AbstractStreamItemDelegate *AbstractStreamItemRenderer::itemDelegateForRow(int row) const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->rowDelegates.value(row, nullptr);
}

void AbstractStreamItemRenderer::setItemDelegateForColumn(int column, AbstractStreamItemDelegate *delegate)
{
    Q_D(AbstractStreamItemRenderer);
    // no signal/slot -> just replace
    d->columnDelegates[column] = delegate;
}

AbstractStreamItemDelegate *AbstractStreamItemRenderer::itemDelegateForColumn(int column) const
{
    Q_D(const AbstractStreamItemRenderer);
    return d->columnDelegates.value(column, nullptr);
}

QT_END_NAMESPACE
