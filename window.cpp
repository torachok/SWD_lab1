#include "window.h"
#include <QVBoxLayout>

Window::Window(){
    this->setWindowTitle("Обработка событий");//название окна
    area = new Area(this); //инициализация области фигуры
    btn = new QPushButton("Завершить",this); //кнопка выхода
    QVBoxLayout * layout = new QVBoxLayout(this); //класс макета для выстраивания виджетов вертикально
    layout->addWidget(area); //добавление виджета области фигуры
    layout->addWidget(btn); //добавление виджета для кнопки
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(close())); //выход при нажатии кнпки "завершить"
}
