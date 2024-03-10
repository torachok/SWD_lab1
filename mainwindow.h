#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QValidator>
#include <QMessageBox>
#include <QVBoxLayout>

class Win:public QWidget{ //класс окна
    Q_OBJECT //макрос Qt, обеспечивающий коррекное создание сигналов и слотов
protected:
    QFrame *frame;  //рамка
    QLabel *inputLabel;  //метка ввода
    QLineEdit *inputEdit;   //строчный редактор ввода
    QLabel *outputLabel; //метка вывода
    QLineEdit *outputEdit; //строчный редакор вывода
    QPushButton *nextButton;    //кнопка Следующее
    QPushButton *exitButton;    //кнопка Выход
public:
    Win(QWidget *parent = 0); // конструктор
public slots:
    void begin();//метод начальной настройки интерфейса
    void calc();//метод реализации вычислений
};

class StrValidator:public QValidator{//класс компонента проверки кода
public:
    StrValidator(QObject *parent):QValidator(parent){} //метод проверки
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable;//метод всегда принимает вводимую строку
    }
};
#endif
