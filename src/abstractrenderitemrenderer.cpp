#include "abstractrenderitemrenderer.h"
#include "abstractrenderitemrenderer_p.h"
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


AbstractRenderItemRendererPrivate::AbstractRenderItemRendererPrivate(AbstractRenderItemRenderer *pPublic) :
    model(qEmptyModel()),
    alternatingColors(false),
    q_ptr(pPublic)
{
}

AbstractRenderItemRendererPrivate::~AbstractRenderItemRendererPrivate()
{
}



AbstractRenderItemRenderer::AbstractRenderItemRenderer(QObject *parent) :
    QObject(parent)
{
}

AbstractRenderItemRenderer::AbstractRenderItemRenderer(AbstractRenderItemRendererPrivate &dd, QObject *parent) :
    QObject(parent), d_ptr(&dd)
{

}

AbstractRenderItemRenderer::~AbstractRenderItemRenderer()
{
}

void AbstractRenderItemRenderer::setModel(QAbstractItemModel *model)
{
    Q_D(AbstractRenderItemRenderer);
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

QAbstractItemModel *AbstractRenderItemRenderer::model() const
{
    Q_D(const AbstractRenderItemRenderer);
    return (d->model == qEmptyModel() ? nullptr : d->model);
}

void AbstractRenderItemRenderer::setAlternatingRowColors(bool enable)
{
    Q_D(AbstractRenderItemRenderer);
    d->alternatingColors = enable;
}

bool AbstractRenderItemRenderer::alternatingRowColors() const
{
    Q_D(const AbstractRenderItemRenderer);
    return d->alternatingColors;
}

void AbstractRenderItemRenderer::setRootIndex(const QModelIndex &index)
{
    Q_D(AbstractRenderItemRenderer);
    if (Q_UNLIKELY(index.isValid() && index.model() != d->model)) {
        qWarning("QAbstractItemView::setRootIndex failed : index must be from the currently set model");
        return;
    }
    d->root = index;
}

QModelIndex AbstractRenderItemRenderer::rootIndex() const
{
    Q_D(const AbstractRenderItemRenderer);
    return QModelIndex(d->root);
}

void AbstractRenderItemRenderer::setCurrentIndex(const QModelIndex &index)
{
    Q_D(AbstractRenderItemRenderer);
    /*if (d->selectionModel && (!index.isValid() || d->isIndexEnabled(index))) {
        QItemSelectionModel::SelectionFlags command = selectionCommand(index, 0);
        d->selectionModel->setCurrentIndex(index, command);
        d->currentIndexSet = true;
        if ((command & QItemSelectionModel::Current) == 0)
            d->currentSelectionStartIndex = index;
    }*/

}

QT_END_NAMESPACE
