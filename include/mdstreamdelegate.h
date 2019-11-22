#ifndef MDSTREAMDELEGATE_H
#define MDSTREAMDELEGATE_H

#include "abstractstreamitemdelegate.h"

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

#endif // MDSTREAMDELEGATE_H
