#include "area.h"

Area::Area(QWidget * parent):QWidget(parent){
    setFixedSize(QSize(300,200)); //определение масштаба окна
    myline = new MyLine(80,100,50); //масштаб линии
    myrect = new MyRect(200,100,50); //масштаб прямоугольника
    alpha = 0; //угол
}

void Area::showEvent(QShowEvent *){
    myTimer = startTimer(50);//создать таймер
}

void Area::paintEvent(QPaintEvent *){
    QPainter painter(this); //создание специального объекта (кисточка или рисователем)
    painter.setPen(Qt::red); //цвет фигур
    myline->move(alpha, &painter); //движение согласно заданному углу
    myrect->move(alpha*(-0.5), &painter); //движение согласно заданному углу
}

void Area::timerEvent(QTimerEvent *event){
    if(event->timerId() == myTimer) //если наш таймер
    {
        alpha = alpha+0.2;//смена угла
        update(); //обновить внешний вид
    }
    else
        QWidget::timerEvent(event);//иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *){
    killTimer(myTimer);//уничтожить таймер
}

Area::~Area(){//деструктор
    delete myline;
    delete myrect;
}
