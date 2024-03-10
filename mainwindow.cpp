#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget (parent){
    setWindowTitle("Возведение в квадрат"); //название нового окна
    frame = new QFrame(this); //инициализация нового фрейма
    frame->setFrameShadow(QFrame::Raised); //тень фрейма
    frame->setFrameShape(QFrame::Panel); //форма фрейма
    inputLabel = new QLabel("Введите число: ", this); //отображение текста
    inputEdit = new QLineEdit("", this); //редактор однострочного текста (ввод значений)
    StrValidator *v = new StrValidator(inputEdit); //валидатор для проверки корректности вводимых значений
    inputEdit->setValidator(v); //проверка введенных значений
    outputLabel = new QLabel("Результат: ", this); //отображение текста
    outputEdit = new QLineEdit("", this); //редактор однострочного текста (для вывода результата)
    nextButton = new QPushButton("Следующее", this); //инициализация кнопки
    exitButton = new QPushButton("Выход", this); //инициализация кнопки

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //класс макета для выстраивания виджетов вертикально
    vLayout1->addWidget(inputLabel); //добавление виджета отображения текста
    vLayout1->addWidget(inputEdit); //добавление виджета для ввода
    vLayout1->addWidget(outputLabel); //добавление виджета отображения текста
    vLayout1->addWidget(outputEdit); //добавление виджета для вывода результата
    vLayout1->addStretch(); //создание пустой нерастяжимой ячейки

    QVBoxLayout *vLayout2 = new QVBoxLayout(); //класс макета для выстраивания виджетов вертикально
    vLayout2->addWidget(nextButton); //добавление кнопки
    vLayout2->addWidget(exitButton); //добавление кнопки
    vLayout2->addStretch(); //создание пустой нерастяжимой ячейки

    QHBoxLayout *hLayout = new QHBoxLayout(this); //класс макета для выстраивания виджетов горизонтально
    hLayout->addWidget(frame); //добавление фрейма
    hLayout->addLayout(vLayout2); //добавление ячейки, содержащей другой QLayout в ряд и установки его растяжения

    begin(); //запуск программы

    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close())); //закрытие при нажатии на кнопку "выход"
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin())); //перезапуск программы при нажатии на кнопку "следующее"
    connect(inputEdit, SIGNAL(returnPressed()), this, SLOT(calc())); //расчет по введенному после нажатия на enter
}

void Win::begin(){ //функция начала программы
    inputEdit->clear(); //очистка inputedit - места, куда вводить значения
    nextButton->setEnabled(false); //блокировка кнопки "следующее"
    nextButton->setDefault(false); //кнопка "следующее" не среагирует на enter
    inputEdit->setEnabled(true); //доступ к введению значений в ячейку открыт
    outputLabel->setVisible(false); //не показывать надпись
    outputEdit->setVisible(false); //не показывать ячейку с выводом результата
    outputEdit->setEnabled(false); //недоступность к редактированию значения в ячейке результата
    inputEdit->setFocus(); //фокус клавиатуры на ячейку ввода
}

void Win::calc(){ //функция расчета
    bool Ok = true; //начальное значение
    float r,a; //инициализация переменных
    QString str = inputEdit->text(); //ввод значений в соответствующую ячейку
    a = str.toDouble(&Ok); //преобразование в число, если ввели число, то ok = true
    if(Ok){ //если введенное значение - число, то цикл запускается
        r = a*a;  //квадрат
        str.setNum(r); //строку в число переводит
        outputEdit->setText(str); //вывод результата
        inputEdit->setEnabled(false); //недоступна ячейка ввода
        outputLabel->setVisible(true); //показать надпись
        outputEdit->setVisible(true); //показать ячейку с результатом
        nextButton->setDefault(true); //кнопка "следующее" среагирует на enter
        nextButton->setEnabled(true); //кнопка "следующее" стала доступна
        nextButton->setFocus(); //фокус клавиатуры на кнопку "следующее"
    }
    else //если введенное не число, то ошибка
        if(!str.isEmpty()) //если непустая ячейка ввода
        {
            QMessageBox msgBox(QMessageBox::Information, //окно ошибки
                               "Возведение в квадрат.",
                               "Введено неверное значение.",
                               QMessageBox::Ok);
            msgBox.exec(); //закрытие окна ошибки
        }
}
