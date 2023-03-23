#include <iostream>

#include "Display.h"

Display Display::instance;

Display::Display(QObject *parent) : QObject(parent)
{
}

Display::~Display()
{
}

void Display::update(QVector<File> files)
{
	system("cls");

	int max_size = 8;
	for (int i = 0; i < files.size(); i++)
		if (files[i].getFilePath().size() > max_size)
			max_size = files[i].getFilePath().size();

	max_size += 2;
	std::cout << "Filepath";
	for (int j = 0; j < max_size - 8; j++)
		std::cout << " ";

	std::cout << "|  State" << std::endl;

	for (int j = 0; j < max_size + 15; j++)
		std::cout << "-";
	std::cout << std::endl;

	for (int i = 0; i < files.size(); i++)
	{
		std::cout << files[i].getFilePath().toStdString();
		for (int j = 0; j < max_size - files[i].getFilePath().size(); j++)
			std::cout << " ";

		std::cout << "|  ";

		switch (files[i].getState())
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
}
