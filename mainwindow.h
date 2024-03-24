#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <limits>

class Counter:public QLineEdit{
    Q_OBJECT //макрос Qt, обеспечивающий коррекное создание сигналов и слотов
public:
    Counter(const QString & contents, QWidget *parent = 0):QLineEdit(contents,parent){} //счетчик и его конструктор
signals:
    void tick_signal(); //событие, которое говорит, что счётчик дошёл до 5
public slots:
    void add_one(){ //добавление +1 к значению
        QString str = text(); //инициализация строки
        int r = str.toInt(); //преобразование строки в число
        r++; //прибвление к счетчику 1

        if(r == std::numeric_limits<int>::max()){ //проверка на переполение типа данных
            auto msg = QMessageBox(
                QMessageBox::Information,
                "Счетчики",
                "Число переполнило тип данных, будет сброшено в 0",
                QMessageBox::Ok
                );
            msg.exec();
            r=0;
        }

        if(r!=0 && (r+1)%5 == 0) emit tick_signal(); //если число != 0 и делится на 5 без остатка, запускаем имитацию сигнала

        str.setNum(r); //преобразование строки в число
        setText(str); //установка в поле увелиения числа
    }
};

class Win: public QWidget{
    Q_OBJECT //макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QLabel *label1, *label2; //инициализация отображения текста
    Counter *edit1, *edit2; //инициализация редактируемых строк
    QPushButton *calcbutton; //инициализация кнопки добавления значения
    QPushButton *exitbutton; //инициализация кнопки выхода
public:
    Win(QWidget *parent = 0); //конструктор окна
};
#endif
