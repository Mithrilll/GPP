#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QValidator>

class Widget_Square : public QWidget
{
    Q_OBJECT

public:
    Widget_Square(QWidget *parent = nullptr);
    ~Widget_Square();

public slots:
    void begin();
    void calc();

protected:
    QTextCodec* codec;
    QFrame* frame;
    QLabel* inputLabel;
    QLineEdit* inputEdit;
    QLabel* outputLabel;
    QLineEdit* outputEdit;
    QPushButton* nextButton;
    QPushButton* exitButton;
};

class StrValidator : public QValidator
{
public:
    StrValidator(QObject* parent);
    State validate(QString& str, int& pos) const override;
};