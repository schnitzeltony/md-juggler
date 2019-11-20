#ifndef QABSTRACTSTREAMITEMRENDERER_H
#define QABSTRACTSTREAMITEMRENDERER_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;
class QItemSelectionModel;
class AbstractStreamItemDelegate;

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractStreamItemRendererPrivate;
class MDJUGGLER_EXPORT AbstractStreamItemRenderer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool alternatingRowColors READ alternatingRowColors WRITE setAlternatingRowColors)
    Q_PROPERTY(SelectionMode selectionMode READ selectionMode WRITE setSelectionMode)

public:
    // Just how to render
    enum SelectionMode {
        NoSelection,
        SingleSelection,
        MultiSelection
    };
    Q_ENUM(SelectionMode)

    explicit AbstractStreamItemRenderer(QObject *parent = nullptr);
    ~AbstractStreamItemRenderer();

    virtual void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;

    // we cannot select but can render based upon other view's selection
    virtual void setSelectionModel(QItemSelectionModel *selectionModel);
    QItemSelectionModel *selectionModel() const;

    void setSelectionMode(AbstractStreamItemRenderer::SelectionMode mode);
    AbstractStreamItemRenderer::SelectionMode selectionMode() const;

    // do the job
    virtual int render() const = 0;
    QByteArray getRenderedData() const;

    void setItemDelegate(AbstractStreamItemDelegate *delegate);
    AbstractStreamItemDelegate *itemDelegate() const;
    AbstractStreamItemDelegate *itemDelegate(const QModelIndex &index) const;

    QModelIndex rootIndex() const;

    void setItemDelegateForRow(int row, AbstractStreamItemDelegate *delegate);
    AbstractStreamItemDelegate *itemDelegateForRow(int row) const;

    void setItemDelegateForColumn(int column, AbstractStreamItemDelegate *delegate);
    AbstractStreamItemDelegate *itemDelegateForColumn(int column) const;

    // TODO remove ???
    void setAlternatingRowColors(bool enable);
    bool alternatingRowColors() const;

public slots:
    virtual void setRootIndex(const QModelIndex &index);

protected:
    const QScopedPointer<AbstractStreamItemRendererPrivate> d_ptr;
    AbstractStreamItemRenderer(AbstractStreamItemRendererPrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractStreamItemRenderer)
    Q_DISABLE_COPY(AbstractStreamItemRenderer)
};

QT_END_NAMESPACE

#endif // QABSTRACTSTREAMITEMRENDERER_H
