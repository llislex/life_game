#include "field.h"
#include <QtGui/QPainter>

LifeField::LifeField(QWidget *parent) :
    QWidget(parent), m_life(0)
{
}

void LifeField::paintEvent(QPaintEvent*)
{
    if(m_life)
    {
        QPainter painter(this);
        QImage img = m_life->field();
        painter.drawImage(rect(), img, img.rect());
    }
}
