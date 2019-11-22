#ifndef QABSTRACTSTREAMITEMDELEGATE_H
#define QABSTRACTSTREAMITEMDELEGATE_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractStreamItemDelegatePrivate;
class MDJUGGLER_EXPORT AbstractStreamItemDelegate : public QObject
{
    Q_OBJECT
public:
    explicit AbstractStreamItemDelegate(QObject *parent = nullptr);
    virtual ~AbstractStreamItemDelegate();

    virtual QByteArray render(const QModelIndex &viewRootIndex, const QModelIndex &index) const = 0;
protected:
    const QScopedPointer<AbstractStreamItemDelegatePrivate> d_ptr;
    AbstractStreamItemDelegate(AbstractStreamItemDelegatePrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractStreamItemDelegate)
    Q_DISABLE_COPY(AbstractStreamItemDelegate)
};

QT_END_NAMESPACE

#endif // QABSTRACTSTREAMITEMDELEGATE_H
