#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

class Counter :public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString& contents, QWidget* parent = 0);

signals:
    void tick_signal();

public slots:
    void add_one();
};

class Widget_Counter : public QWidget
{
    Q_OBJECT

public:
    Widget_Counter(QWidget *parent = nullptr);
    ~Widget_Counter();

protected:
    QTextCodec* codec;
    QLabel* label1, * label2;
    Counter* edit1, * edit2;
    QPushButton* calcbutton;
    QPushButton* exitbutton;
};
