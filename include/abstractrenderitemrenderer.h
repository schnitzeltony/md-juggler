#ifndef QABSTRACTRENDERITEMRENDERER_H
#define QABSTRACTRENDERITEMRENDERER_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;
class QItemSelectionModel;
class QAbstractRenderItemDelegate;

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractRenderItemRendererPrivate;
class MDJUGGLER_EXPORT AbstractRenderItemRenderer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool alternatingRowColors READ alternatingRowColors WRITE setAlternatingRowColors)

    explicit AbstractRenderItemRenderer(QObject *parent = nullptr);
    ~AbstractRenderItemRenderer();

    virtual void setModel(QAbstractItemModel *model);
    QAbstractItemModel *model() const;

    QByteArray render() const;

    void setItemDelegate(QAbstractRenderItemDelegate *delegate);
    QAbstractRenderItemDelegate *itemDelegate() const;

    QModelIndex currentIndex() const;
    QModelIndex rootIndex() const;

    void setAlternatingRowColors(bool enable);
    bool alternatingRowColors() const;

    void setItemDelegateForRow(int row, QAbstractRenderItemDelegate *delegate);
    QAbstractRenderItemDelegate *itemDelegateForRow(int row) const;

    void setItemDelegateForColumn(int column, QAbstractRenderItemDelegate *delegate);
    QAbstractRenderItemDelegate *itemDelegateForColumn(int column) const;

    QAbstractRenderItemDelegate *itemDelegate(const QModelIndex &index) const;

public slots:
    virtual void setRootIndex(const QModelIndex &index);

    void setCurrentIndex(const QModelIndex &index);

protected:
    const QScopedPointer<AbstractRenderItemRendererPrivate> d_ptr;
    AbstractRenderItemRenderer(AbstractRenderItemRendererPrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractRenderItemRenderer)
    Q_DISABLE_COPY(AbstractRenderItemRenderer)
};

QT_END_NAMESPACE

#endif // QABSTRACTRENDERITEMRENDERER_H
