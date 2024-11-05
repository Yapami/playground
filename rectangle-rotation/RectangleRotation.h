#pragma once

#include <QGraphicsView>

class RectangleRotation : public QGraphicsView
{
    Q_OBJECT
public:
    explicit RectangleRotation(QWidget *parent = nullptr);

private:
    QGraphicsScene m_scene;
};