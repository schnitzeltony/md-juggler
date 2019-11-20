#ifndef QABSTRACTSTREAMITEMDELEGATE_H
#define QABSTRACTSTREAMITEMDELEGATE_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class QAbstractItemModel;

// clang: be quiet
QT_WARNING_DISABLE_CLANG("-Wshadow-field")

class AbstractStreamItemDelegatePrivate;
class MDJUGGLER_EXPORT AbstractStreamItemDelegate : public QObject
{
    Q_OBJECT
public:
    explicit AbstractStreamItemDelegate(QObject *parent = nullptr);
    virtual ~AbstractStreamItemDelegate();

    virtual QString render(const QModelIndex &index, const QString outFile = QString()) const = 0;

    virtual void setModelData(QAbstractItemModel *model,
                              const QModelIndex &index) const;

    //virtual QVector<int> paintingRoles() const;     // TODO rename renderingRoles??

public slots:

protected:
    const QScopedPointer<AbstractStreamItemDelegatePrivate> d_ptr;
    AbstractStreamItemDelegate(AbstractStreamItemDelegatePrivate &, QObject *parent = nullptr);
private:
    Q_DECLARE_PRIVATE(AbstractStreamItemDelegate)
    Q_DISABLE_COPY(AbstractStreamItemDelegate)
};


QT_END_NAMESPACE

#endif // QABSTRACTSTREAMITEMDELEGATE_H
