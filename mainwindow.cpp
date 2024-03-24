#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget(parent){
    this->setWindowTitle("Счетчик"); //название окна
    label1 = new QLabel("Счет по 1", this); //отображение текста
    label2 = new QLabel("Счет по 5", this); //отображение текста
    edit1 = new Counter("0", this); //редактор однострочного текста для отображения сколько 1-иц
    //edit1 = new Counter("2147483646", this); //редактор однострочного текста для проверки переполнения типа данных
    edit2 = new Counter("0", this); //редактор однострочного текстадля отображения, сколько 5-ок
    calcbutton = new QPushButton("+1", this); //кнопка +1
    exitbutton = new QPushButton("Выход", this); //кнопка выхода

    QHBoxLayout *layout1 = new QHBoxLayout(); //класс макета для выстраивания виджетов горизонтально
    QHBoxLayout *layout2 = new QHBoxLayout(); //класс макета для выстраивания виджетов горизонтально
    QHBoxLayout *layout3 = new QHBoxLayout(); //класс макета для выстраивания виджетов горизонтально
    QVBoxLayout *layout4 = new QVBoxLayout(this); //класс макета для выстраивания виджетов вертикально

    if(label1 && label2 && edit1 && edit2 &&calcbutton && exitbutton && layout1 && layout2 && layout2 && layout3 && layout4){
    //проверка выделения памяти
    edit1->setReadOnly(true); //недоступность к изменению редактора однострочного текста (только чтение)
    edit2->setReadOnly(true); //недоступность к изменению редактора однострочного текста (только чтение)

    layout1->addWidget(label1); //добавление виджета отображения текста
    layout1->addWidget(label2); //добавление виджета отображения текста


    layout2->addWidget(edit1); //добавление виджета для вывода результата счетчика
    layout2->addWidget(edit2); //добавление виджета для вывода результата счетчика


    layout3->addWidget(calcbutton); //добавление виджета кнопки добавления +1 к счетчику
    layout3->addWidget(exitbutton); //добавление виджета кнопки выхода


    layout4->addLayout(layout1); //добавление ячейки, содержащей другой QLayout в ряд и установки его растяжения
    layout4->addLayout(layout2); //добавление ячейки, содержащей другой QLayout в ряд и установки его растяжения
    layout4->addLayout(layout3); //добавление ячейки, содержащей другой QLayout в ряд и установки его растяжения


    connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one); //связи нажатия кнопки и добавление +1 к счетчику
    connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one); //увеличение второго счётчика, если в первом случился tick_signal
    connect(exitbutton, &QPushButton::clicked, this, &Win::close); //связь для нажатия кнопки и слота закрытия окна

    }
}
