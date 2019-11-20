#ifndef QABSTRACTSTREAMITEMRENDERER_H
#define QABSTRACTSTREAMITEMRENDERER_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;
class QItemSelectionModel;
class QAbstractStreamItemDelegate;

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractStreamItemRendererPrivate;
class MDJUGGLER_EXPORT AbstractStreamItemRenderer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool alternatingRowColors READ alternatingRowColors WRITE setAlternatingRowColors)

    explicit AbstractStreamItemRenderer(QObject *parent = nullptr);
    ~AbstractStreamItemRenderer();

    virtual void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;

    QByteArray render() const;

    void setItemDelegate(QAbstractStreamItemDelegate *delegate);
    QAbstractStreamItemDelegate *itemDelegate() const;

    QModelIndex currentIndex() const;
    QModelIndex rootIndex() const;

    void setAlternatingRowColors(bool enable);
    bool alternatingRowColors() const;

    void setItemDelegateForRow(int row, QAbstractStreamItemDelegate *delegate);
    QAbstractStreamItemDelegate *itemDelegateForRow(int row) const;

    void setItemDelegateForColumn(int column, QAbstractStreamItemDelegate *delegate);
    QAbstractStreamItemDelegate *itemDelegateForColumn(int column) const;

    QAbstractStreamItemDelegate *itemDelegate(const QModelIndex &index) const;

public slots:
    virtual void setRootIndex(const QModelIndex &index);

    void setCurrentIndex(const QModelIndex &index);

protected:
    const QScopedPointer<AbstractStreamItemRendererPrivate> d_ptr;
    AbstractStreamItemRenderer(AbstractStreamItemRendererPrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractStreamItemRenderer)
    Q_DISABLE_COPY(AbstractStreamItemRenderer)
};

QT_END_NAMESPACE

#endif // QABSTRACTSTREAMITEMRENDERER_H
