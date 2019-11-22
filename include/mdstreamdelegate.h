#ifndef MDSTREAMDELEGATE_H
#define MDSTREAMDELEGATE_H

#include "abstractstreamitemdelegate.h"

QT_BEGIN_NAMESPACE

class MdStreamDelegatePrivate;
class MDJUGGLER_EXPORT MdStreamDelegate : public AbstractStreamItemDelegate
{
    Q_OBJECT
public:
    explicit MdStreamDelegate(QObject *parent = nullptr);

    enum MDType {
        MDText,
        MDHeader,
        MDUnorderedList,
        MDOrderedList,
        MDTableHeader,
        MDTableHeaderAndColum,  // corner
        MDTableFirstRowSepearator,
        MDTableColumn,
        MDTableEntry
    };
    Q_ENUM(MDType)

    void setMdType(MDType type);
    MDType mdType();

    virtual QByteArray render(const QModelIndex &viewRootIndex, const QModelIndex &index) const override;
protected:
    Q_DECLARE_PRIVATE(MdStreamDelegate)
    Q_DISABLE_COPY(MdStreamDelegate)
};

QT_END_NAMESPACE

#endif // MDSTREAMDELEGATE_H
