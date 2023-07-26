#include <QtCore/QCoreApplication>
#include <iostream>

#include "CPP.h"

std::shared_ptr<Unit> generateProgram(const Factory& factory)
{
    auto main_class = factory.createClass("Programm");

    auto method_init = factory.createMethod("Init");
    auto method_update = factory.createMethod("Update");
    auto method_shutdown = factory.createMethod("Shutdown");

    main_class->addMethod(method_init, Public);
    main_class->addMethod(method_update, Public);
    main_class->addMethod(method_shutdown, Public);

    auto print_init = factory.createPrintOperator("Init");
    auto print_update = factory.createPrintOperator("Update");
    auto print_shutdown = factory.createPrintOperator("Shutdown");

    method_init->addOperator(print_init);
    method_update->addOperator(print_update);
    method_shutdown->addOperator(print_shutdown);

    return main_class;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto program = generateProgram(CPPFactory());

    std::cout << program->compile() << std::endl;

    return a.exec();
}
