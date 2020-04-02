#ifndef LIFE_H
#define LIFE_H

#include <QObject>
#include <QImage>
#include "torus.h"
#include "qmath.h"

class Life : public QObject
{
    Q_OBJECT
    torus<bool> odd;
    torus<bool> even;
    static int neigbours(const torus<bool>& v, int x, int y);
    static bool isAlive(const torus<bool>& v, int x, int y);
    static int transform(torus<bool>& now, torus<bool>& next);
    int m_step;
    int m_aliveCells;
    int w;
    int h;
public:
    explicit Life(int width = 160, int height = 80, QObject *parent = 0);
    int alive() const {return m_aliveCells;}
    qreal aliveRatio() const {return ((qreal) m_aliveCells) / (w * h);}
    QImage field() const;
signals:

public slots:
    int step();
    void reset();
};

#endif // LIFE_H
