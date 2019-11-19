#ifndef MD_JUGGLER_H
#define MD_JUGGLER_H

#include "mdjuggler_export.h"
#include <QObject>

class MDJUGGLER_EXPORT MdJuggler : public QObject
{
  Q_OBJECT
public:
    explicit MdJuggler(QObject *parent = nullptr);

signals:

public slots:

private:
};


#endif // MD_JUGGLER_H
