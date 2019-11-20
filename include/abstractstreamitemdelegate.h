#ifndef QABSTRACTSTREAMITEMDELEGATE_H
#define QABSTRACTSTREAMITEMDELEGATE_H

#include "mdjuggler_export.h"
#include <QObject>

QT_BEGIN_NAMESPACE

class MDJUGGLER_EXPORT AbstractStreamItemDelegate : public QObject
{
    Q_OBJECT
public:
    explicit AbstractStreamItemDelegate(QObject *parent = nullptr);
    virtual ~AbstractStreamItemDelegate();

    virtual QByteArray render(QByteArray data) const = 0;
};

QT_END_NAMESPACE

#endif // QABSTRACTSTREAMITEMDELEGATE_H
