#include <QTextCodec>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include "Widget_Counter.h"

Counter::Counter(const QString& contents, QWidget* parent)
	: QLineEdit(contents, parent)
{
}

void Counter::add_one()
{
	QString str = text();
	int r = str.toInt();
	if (r != 0 && r % 5 == 0) emit tick_signal();
	r++;
	str.setNum(r);
	setText(str);
}

Widget_Counter::Widget_Counter(QWidget* parent)
	: QWidget(parent)
{
	codec = QTextCodec::codecForName("Windows-1251");
	this->setWindowTitle(codec->toUnicode("Counter"));
	label1 = new QLabel(codec->toUnicode("Count by 1"), this);
	label2 = new QLabel(codec->toUnicode("Count by 5"), this);
	edit1 = new Counter("0", this);
	edit2 = new Counter("0", this);
	calcbutton = new QPushButton("+1", this);
	exitbutton = new QPushButton(codec->toUnicode("Quit"), this);
	QHBoxLayout* layout1 = new QHBoxLayout();
	layout1->addWidget(label1);
	layout1->addWidget(label2);
	QHBoxLayout* layout2 = new QHBoxLayout();
	layout2->addWidget(edit1);
	layout2->addWidget(edit2);
	QHBoxLayout* layout3 = new QHBoxLayout();
	layout3->addWidget(calcbutton);
	layout3->addWidget(exitbutton);
	QVBoxLayout* layout4 = new QVBoxLayout(this);
	layout4->addLayout(layout1);
	layout4->addLayout(layout2);
	layout4->addLayout(layout3);
	
	connect(calcbutton, SIGNAL(clicked(bool)), edit1, SLOT(add_one()));
	connect(edit1, SIGNAL(tick_signal()), edit2, SLOT(add_one()));
	connect(exitbutton, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Widget_Counter::~Widget_Counter()
{}