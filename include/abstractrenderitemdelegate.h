#ifndef QABSTRACTRENDERITEMDELEGATE_H
#define QABSTRACTRENDERITEMDELEGATE_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractRenderItemDelegatePrivate;
class MDJUGGLER_EXPORT AbstractRenderItemDelegate : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRenderItemDelegate(QObject *parent = nullptr);
    virtual ~AbstractRenderItemDelegate();

    // render to file by role
    virtual QByteArray render(const QModelIndex &index) const = 0;

    virtual void setModelData(QAbstractItemModel *model,
                              const QModelIndex &index) const;
public slots:

protected:
    const QScopedPointer<AbstractRenderItemDelegatePrivate> d_ptr;
    AbstractRenderItemDelegate(AbstractRenderItemDelegatePrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractRenderItemDelegate)
    Q_DISABLE_COPY(AbstractRenderItemDelegate)
};


QT_END_NAMESPACE

#endif // QABSTRACTRENDERITEMDELEGATE_H
