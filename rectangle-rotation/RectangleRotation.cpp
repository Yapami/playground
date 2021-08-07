#include "RectangleRotation.h"

#include <QGraphicsRectItem>

#include <qmath.h>

void rot(qreal &x, qreal &y, qreal a)
{
    qreal rx = x * qCos(a) - y * qSin(a);
    qreal ry = x * qSin(a) + y * qCos(a);
    x = rx;
    y = ry;
}

bool inside(qreal px, qreal py, qreal x1, qreal y1, qreal x2, qreal y2)
{
    qreal d = (x2 - x1) * (py - y1) - (px - x1) * (y2 - y1);
    return d <= 0.0;
}

RectangleRotation::RectangleRotation(QWidget *parent)
    : QGraphicsView(parent)
{
    setScene(&m_scene);
    QPen gray_pen(QColor(160, 160, 160));
    for (size_t i = 0; i <= 10; ++i)
    {
        m_scene.addLine(i * 100, 0, i * 100, 1000, gray_pen);
        m_scene.addLine(0, i * 100, 1000, i * 100, gray_pen);
    }
    QPainterPath p;

    qreal c = 500;

    qreal w = 600;
    qreal h = 400;
    qreal sx = w / 2.0;
    qreal sy = h / 2.0;
    qreal d = qSqrt(sx * sx + sy * sy) + 100.0;
    d -= fmod(d, 100);

    qreal x[4] = {sx, sx, -sx, -sx};
    qreal y[4] = {sy, -sy, -sy, sy};
    for (size_t i = 0; i < 4; ++i)
    {
        rot(x[i], y[i], M_PI_4);
    }
    for (qreal ty = -d; ty <= d; ty += 100.0)
    {
        for (qreal tx = -d; tx <= d; tx += 100.0)
        {
            bool l[4] = {
                inside(tx, ty, x[0], y[0], x[1], y[1]), inside(tx, ty, x[1], y[1], x[2], y[2]),
                inside(tx, ty, x[2], y[2], x[3], y[3]), inside(tx, ty, x[3], y[3], x[0], y[0])};
            if (l[0] && l[1] && l[2] && l[3])
            {
                m_scene.addEllipse(c + tx - 2, c + ty - 2, 4, 4);
            }
        }
    }
    p.moveTo(c + x[0], c + y[0]);
    p.lineTo(c + x[1], c + y[1]);
    p.lineTo(c + x[2], c + y[2]);
    p.lineTo(c + x[3], c + y[3]);
    p.lineTo(c + x[0], c + y[0]);
    m_scene.addPath(p);
}
