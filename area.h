#ifndef AREA_H
#define AREA_H
#include "figura.h"
#include <QWidget>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QShowEvent>
#include <QHideEvent>
#include <QSize>
#include <QPushButton>

class Area:public QWidget{
    int myTimer;//идентификатор таймера
    float alpha;//угол поворота
public:
    Area(QWidget *parent = 0); //конструктор
    ~Area();
    MyLine *myline; //инициализация линии
    MyRect *myrect; //инициализация прямоугольника
protected:
    //обработчики событий
    void paintEvent(QPaintEvent *event); //событие отрисовки
    void timerEvent(QTimerEvent *event); //событие таймера
    void showEvent(QShowEvent *event); //событие показа окна
    void hideEvent(QHideEvent *event); //событие сворачивания окна
};
#endif
