#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <bitset>

#include "Node.h"
#include "Edge.h"
#include "Gauss.h"

#include "mainwindow.h"

Phy::Phy(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("A Simulation for curuit"));
    resize(800, 800);
}

void Phy::paintEvent(QPaintEvent *)
{
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.setPen(hourColor);
    startPoint=QPoint(0,0);
    // draw nodes
    for (int i=0; i<Node::count(); ++i)
    {
        painter.drawEllipse(Node::select(i)->getX(),Node::select(i)->getY(),5,5);
    }
    // draw edges
    for (int i=0; i<Edge::count(); ++i)
    {
        painter.drawLine(
                    Node::select(Edge::select(i)->getEdge().first)->getX(),
                    Node::select(Edge::select(i)->getEdge().first)->getY(),
                    Node::select(Edge::select(i)->getEdge().second)->getX(),
                    Node::select(Edge::select(i)->getEdge().second)->getY());
    }
}

void Phy::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        Node *tmp = new Node(event->x(),event->y());
        Edge::select(id)->
    }
}
void Phy::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}
void Phy::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}
