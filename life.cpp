#include "life.h"
#include <math.h>
#include <QtGui/QColor>

Life::Life(int width, int height, QObject *parent)
    : QObject(parent), odd(width, height), even(width, height), m_step(0), w(width), h(height)
{
    reset();
}

int BI(bool v)
{
    return v ? 1 : 0;
}

int Life::neigbours(const torus<bool>& v, int x, int y)
{
    return BI(v.get(x - 1, y - 1)) + BI(v.get(x, y - 1)) + BI(v.get(x + 1, y - 1)) +
           BI(v.get(x - 1, y)) + BI(v.get(x + 1, y)) +
           BI(v.get(x - 1, y + 1)) + BI(v.get(x, y + 1)) + BI(v.get(x + 1, y + 1));
}

bool Life::isAlive(const torus<bool>& v, int x, int y)
{
        int count = neigbours(v, x, y);
        //cout << "(" << x << ", " << y << ") = " << count;// << endl;
        bool result = v.get(x, y) ? 2 <= count && count <= 3 : count == 3;
        //cout << " " << result << endl;
        return result;
}

int Life::transform(torus<bool>& now, torus<bool>& next)
{
    int activeCells = 0;
    for(int j = 0; j < now.height(); ++j)
    {
        for(int i = 0; i < now.width(); ++i)
        {
            bool isSet = isAlive(now, i, j);
            next.set(isSet, i, j);
            if(isSet)
                ++activeCells;
        }
    }
    return activeCells;
}

QImage Life::field() const
{
    QImage result(QSize(w, h), QImage::Format_Indexed8);
    result.setColor(0, QColor(Qt::black).rgb());
    result.setColor(1, QColor(Qt::red).rgb());

    for(int y = 0; y < h; ++y)
    {
        for(int x = 0; x < w; ++x)
        {
            //result.setPixel(x, y, (m_step & 1) > 0 ? even.get(x, y) : odd.get(x, y));
            bool cell = (m_step & 1) > 0 ? even.get(x, y) : odd.get(x, y);
            result.setPixel(x, y, cell ? 1 : 0);
            //QDebug() << "(" << x << "," << y << ") " << index << " / " << result.pixel(x, y);
            //Q_ASSERT(result.pixel(x, y) == result.color((x+y) % 2));
        }
    }
    result.save(QString("c:\\temp.bmp"), "BMP");
    return result;
}

int Life::step()
{
    m_aliveCells = ((m_step & 1) != 0) ? transform(even, odd) : transform(odd, even);
    return ++m_step;
}

void Life::reset()
{
    m_step = 0;
    m_aliveCells = 0;
    for(int y = 0; y < h; ++y)
    {
        for(int x = 0; x < w; ++x)
        {
            bool isSet = (rand() % 2) == 0;
            odd.set(isSet, x, y);
            if(isSet)
                ++m_aliveCells;
        }
    }
}
