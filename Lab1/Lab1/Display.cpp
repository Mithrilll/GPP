#include <iostream>

#include "Display.h"

Display Display::instance;

Display::Display(QObject *parent) : QObject(parent)
{
}

Display::~Display()
{
}

void Display::show(File file)
{
	std::cout << file.getFilePath().toStdString();

	std::cout << "  |  ";

	switch (file.getState())
	{
	case File::FileState::NOT_EXIST:
		std::cout << "Not Exist";
		break;
	case File::FileState::CREATED:
		std::cout << "Created";
		break;
	case File::FileState::EXIST:
		std::cout << "Exist";
		break;
	case File::FileState::SIZE_CHANGED:
		std::cout << "Size Changed";
		break;
	case File::FileState::DELETED:
		std::cout << "Deleted";
		break;
	default:
		break;
	}

	std::cout << std::endl;
	
}
