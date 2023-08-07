#include <QTextCodec>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMessageBox>
#include "Widget_Square.h"

Widget_Square::Widget_Square(QWidget *parent)
    : QWidget(parent)
{
    codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel(codec->toUnicode("Введите число:"), this);
    inputEdit = new QLineEdit("", this);
    StrValidator* v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel(codec->toUnicode("Результат:"), this);
    outputEdit = new QLineEdit("", this);
    nextButton = new QPushButton(codec->toUnicode("Следующее"), this);
    exitButton = new QPushButton(codec->toUnicode("Выход"), this);
    
    QVBoxLayout* vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout* vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    
    begin();
    
    connect(exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(nextButton, SIGNAL(clicked(bool)), this, SLOT(begin()));
    connect(inputEdit, SIGNAL(returnPressed()), this, SLOT(calc()));
}

Widget_Square::~Widget_Square()
{}

void Widget_Square::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget_Square::calc()
{
    bool Ok = true; float r, a;
    QString str = inputEdit->text();
    a = str.toDouble(&Ok);
    if (Ok)
    {
        r = a * a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else if (!str.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information, codec->toUnicode("Возведение в квадрат."), codec->toUnicode("Введено неверное значение."), QMessageBox::Ok);
        msgBox.exec();
    }
}

StrValidator::StrValidator(QObject* parent) : QValidator(parent)
{
}

QValidator::State StrValidator::validate(QString& str, int& pos) const
{
    return Acceptable;
}
