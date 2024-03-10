#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <cmath>

class Figura{
protected:
    int x, y, halflen, dx, dy, r; //сторон
    virtual void draw(QPainter *Painter) = 0; //объявление чисто виртуальной функции, которая рисует фигуру
public:
    Figura(int X, int Y, int Halflen):x(X), y(Y), halflen(Halflen){} //конструктор
    void move(float Alpha, QPainter *Painter); //функция движения
};

class MyLine:public Figura{
protected:
    void draw(QPainter *Painter); //функция отрисовки
public:
    MyLine(int x, int y, int halflen):Figura(x, y, halflen){} //конструктор линии
};

class MyRect:public Figura{
protected:
    void draw(QPainter *Painter);//функция отрисовки
public:
    MyRect(int x, int y, int halflen):Figura(x, y, halflen){}//конструктор прямоугольника
};
#endif
