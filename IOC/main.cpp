#include <QtCore/QCoreApplication>
#include <iostream>

#include "IOC.h"
#include "Car.h"

static IoCContainer gIoCContainer;

void action() {
    auto car = Car{ gIoCContainer.getService<IEngine>() };
    int n = rand() % 10000;
    for (int i = 0; i < n; i++)
        car.getEngine()->work();
    std::cout << car.info() << "\n\n";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    gIoCContainer.registerService<IEngine, NullEngine>();
    action();

    gIoCContainer.registerService<IEngine, BMWEngine>(EngineType(EngineType::V), 1.6f);
    action();

    gIoCContainer.registerService<IEngine, MercedesEngine>(EngineType(EngineType::U), 2.0f);
    action();

    return a.exec();
}
