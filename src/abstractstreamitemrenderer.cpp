#include "abstractstreamitemrenderer.h"
#include "abstractstreamitemrenderer_p.h"
#include <QAbstractItemModel>

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
    if (d->model && d->model != qEmptyModel()) {
        // TODO cleanup before we change model
    }
    d->model = (model ? model : qEmptyModel());
    if (d->model != qEmptyModel()) {
        // TODO connections?
    }

}

QAbstractItemModel *AbstractStreamItemRenderer::model() const
{
    Q_D(const AbstractStreamItemRenderer);
    return (d->model == qEmptyModel() ? nullptr : d->model);
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

void AbstractStreamItemRenderer::setCurrentIndex(const QModelIndex &index)
{
    Q_D(AbstractStreamItemRenderer);
    /*if (d->selectionModel && (!index.isValid() || d->isIndexEnabled(index))) {
        QItemSelectionModel::SelectionFlags command = selectionCommand(index, 0);
        d->selectionModel->setCurrentIndex(index, command);
        d->currentIndexSet = true;
        if ((command & QItemSelectionModel::Current) == 0)
            d->currentSelectionStartIndex = index;
    }*/

}

QT_END_NAMESPACE
