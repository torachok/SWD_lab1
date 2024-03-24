#include "figura.h"

void Figura::move(float Alpha, QPainter *Painter){//рисование фигуры
    dx = halflen*cos(Alpha); //по х
    dy = halflen*sin(Alpha); //по у
    draw(Painter); //функция отрисовки
}

void MyLine::draw(QPainter *Painter){
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); //рисование линии
}

void MyRect::draw(QPainter *Painter){ //рисование прямоугольника
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
