#include "CPP.h"

CPPClass::CPPClass(std::string n)
{
	name = n;
}

std::string CPPClass::compile() const
{
	std::string program = "class " + name + "\n";
	program += "{\n";

	std::string public_zone		= "public:\n";
	std::string protected_zone	= "protected:\n";
	std::string private_zone	= "private:\n";

	
	for (int i = 0; i < units.size(); i++)
	{
		switch (modifiers[i])
		{
		case Public:
			public_zone += units[i]->compile();
			public_zone += "\n";
			break;
		case Protected:
			protected_zone += units[i]->compile();
			protected_zone += "\n";
			break;
		case Private:
			private_zone += units[i]->compile();
			private_zone += "\n";
			break;
		}
	}

	program += public_zone;
	program += protected_zone;
	program += private_zone;

	program += "}\n";

	return program;
}

CPPMethod::CPPMethod(std::string n)
{
	name = n;
}

std::string CPPMethod::compile() const
{
	std::string program = "void " + name + "()\n";
	program += "{\n";

	for (int i = 0; i < units.size(); i++)
	{
		program += units[i]->compile();
		program += "\n";
	}

	program += "}\n";

	return program;
}

CPPPrintOperator::CPPPrintOperator(std::string out)
{
	output = out;
}

CPPPrintOperator::~CPPPrintOperator()
{
}

std::string CPPPrintOperator::compile() const
{
	std::string program = "std::cout << \"" + output + "\" << std::endl;\n";

	return program;
}

std::shared_ptr<ClassUnit> CPPFactory::createClass(std::string name) const
{
	return std::make_shared<CPPClass>(CPPClass(name));
}

std::shared_ptr<MethodUnit> CPPFactory::createMethod(std::string name) const
{
	return std::make_shared<CPPMethod>(CPPMethod(name));
}

std::shared_ptr<PrintOperatorUnit> CPPFactory::createPrintOperator(std::string output) const
{
	return std::make_shared<CPPPrintOperator>(CPPPrintOperator(output));
}
