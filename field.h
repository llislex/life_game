#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include "life.h"

class LifeField : public QWidget
{
    Q_OBJECT
    const Life* m_life;
public:
    explicit LifeField(QWidget *parent = 0);
    void set(const Life* life){m_life = life;}
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:

};

#endif // FIELD_H
