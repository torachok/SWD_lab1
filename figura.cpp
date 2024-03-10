#include "figura.h"

void Figura::move(float Alpha, QPainter *Painter){
    dx = halflen*cos(Alpha);
    dy = halflen*sin(Alpha);
    draw(Painter);
}

void MyLine::draw(QPainter *Painter){
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);
}

void MyRect::draw(QPainter *Painter){
    Painter->drawLine(x+dx,y+dy,x+dx,y-dy);
    Painter->drawLine(x+dx,y-dy,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dx,y+dy);
    Painter->drawLine(x-dx,y+dy,x+dx,y+dy);
}
