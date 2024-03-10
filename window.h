#ifndef WINDOW_H
#define WINDOW_H
#include "area.h"

class Window:public QWidget{
protected:
    Area *area; //область отображения рисунка
    QPushButton *btn; //кнопка
public:
    Window();
};
#endif
