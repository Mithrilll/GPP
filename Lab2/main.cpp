#include <QtCore/QCoreApplication>
#include <iostream>

#include "CPP.h"
#include "CSharp.h"
#include "Java.h"

std::shared_ptr<Unit> generateProgram(const Factory& factory)
{
    auto main_class = factory.createClass("Programm");

    MethodUnit::MethodSignature init_signature;
    init_signature.is_virtual = true;
    init_signature.is_static = true;
    init_signature.return_type = Boolean;
    init_signature.name = "Init";
    init_signature.args = {std::make_pair(Interger, "type")};
    init_signature.is_const = false;

    auto method_init = factory.createMethod(init_signature);

    MethodUnit::MethodSignature update_signature;
    update_signature.is_virtual = false;
    update_signature.is_static = false;
    update_signature.return_type = Float;
    update_signature.name = "Update";
    update_signature.args = { std::make_pair(String, "time"), std::make_pair(Boolean, "needUpdate")};
    update_signature.is_const = true;

    auto method_update = factory.createMethod(update_signature);

    MethodUnit::MethodSignature shutdown_signature;
    shutdown_signature.is_virtual = false;
    shutdown_signature.is_static = false;
    shutdown_signature.return_type = Boolean;
    shutdown_signature.name = "Shutdown";
    shutdown_signature.args = {};
    shutdown_signature.is_const = false;

    auto method_shutdown = factory.createMethod(shutdown_signature);

    auto sub_class = factory.createClass("Subclass");
    sub_class->addUnit(method_shutdown, Public);

    main_class->addUnit(method_init, Public);
    main_class->addUnit(method_update, Protected);
    main_class->addUnit(sub_class, Private);

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

    auto cppProgram = generateProgram(CPPFactory());
    auto csharpProgram = generateProgram(CSharpFactory());
    auto javaProgram = generateProgram(JavaFactory());

    std::cout << "==================C++ code==================\n";
    std::cout << cppProgram->compile() << "\n\n\n";
    std::cout << "==================C# code==================\n";
    std::cout << csharpProgram->compile() << "\n\n\n";
    std::cout << "==================Java code==================\n";
    std::cout << javaProgram->compile() << "\n\n\n";


    return a.exec();
}
