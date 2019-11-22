#include "mdstreamdelegate.h"
#include "mdstreamdelegate_p.h"
#include <QBrush>


MdStreamDelegatePrivate::MdStreamDelegatePrivate(MdStreamDelegate *pPublic) :
    AbstractStreamItemDelegatePrivate(pPublic),
    mdType(MdStreamDelegate::MDText)
{
}

MdStreamDelegatePrivate::~MdStreamDelegatePrivate()
{
}

MdStreamDelegate::MdStreamDelegate(QObject *parent) :
    AbstractStreamItemDelegate(*new MdStreamDelegatePrivate(this), parent)
{
}

void MdStreamDelegate::setMdType(MdStreamDelegate::MDType type)
{
    Q_D(MdStreamDelegate);
    d->mdType = type;
}

MdStreamDelegate::MDType MdStreamDelegate::mdType()
{
    Q_D(MdStreamDelegate);
    return d->mdType;
}

QByteArray MdStreamDelegate::render(const QModelIndex &viewRootIndex, const QModelIndex &index) const
{
    Q_D(const MdStreamDelegate);
    QByteArray renderedData;
    int level = d->calcItemLevel(viewRootIndex, index);
    if(level >= 0) {
        QByteArray displayData = index.data().toString().toUtf8();
        // text color
        QVariant extraRoledata = index.data(Qt::ForegroundRole);
        if(!extraRoledata.isValid() && extraRoledata.canConvert<QBrush>()) {
            QBrush brush = extraRoledata.value<QBrush>();
            if(brush.color().isValid()) {
                QString colorName = brush.color().name();
                QString strTagOpen = QString("<font color=\"%1\">").arg(colorName);
                displayData.prepend(strTagOpen.toUtf8());
                displayData.append(QByteArrayLiteral("</font>"));
            }
        }
        // background color
        extraRoledata = index.data(Qt::BackgroundRole);
        if(!extraRoledata.isValid() && extraRoledata.canConvert<QBrush>()) {
            QBrush brush = extraRoledata.value<QBrush>();
            if(brush.color().isValid()) {
                QString colorName = brush.color().name();
                QString strTagOpen = QString("<foo style=\"background-color:%1;\">").arg(colorName);
                displayData.prepend(strTagOpen.toUtf8());
                displayData.append(QByteArrayLiteral("</foo>"));
            }
        }
        QByteArray prefix;
        switch(d->mdType) {
            case MDText:
                renderedData = displayData;
                break;
            case MDHeader:
                prefix.fill('#', level+1);
                prefix.append(' ');
                renderedData = prefix + displayData;
                break;
            case MDUnorderedList:
                prefix.fill('*', level+1);
                prefix.append(' ');
                renderedData = prefix + displayData;
                break;
            case MDOrderedList:
                prefix.fill(' ', level);
                prefix.append("1. ");
                renderedData = prefix + displayData;
                break;
            case MDTableHeader:
                // cmark-gfm set headers bold automatically
                renderedData = displayData;
                if(index.column() > 0) {
                    renderedData.prepend(" | ");
                }
                break;
            case MDTableHeaderAndColum:
                renderedData = QByteArrayLiteral("<hidden></hidden>");
                break;
            case MDTableFirstRowSepearator:
                renderedData = QByteArrayLiteral("----");
                if(index.column() > 0) {
                    renderedData.prepend(" | ");
                }
                break;
            case MDTableColumn:
                renderedData = QByteArrayLiteral("<b>") + displayData + QByteArrayLiteral("</b>");
                if(index.column() > 0) {
                    renderedData.prepend(" | ");
                }
                break;
            case MDTableEntry:
                renderedData = displayData;
                if(index.column() > 0) {
                    renderedData.prepend(" | ");
                }
                break;
        }
    }
    return renderedData;
}
