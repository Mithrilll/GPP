#include "CPP.h"

CPPClass::CPPClass(std::string n)
{
	name = n;
}

std::string CPPClass::compile() const
{
	std::string program;
	
	program += "class " + name + "\n";
	program += "{\n";

	std::string public_zone		= "public:\n";
	std::string protected_zone	= "protected:\n";
	std::string private_zone	= "private:\n";

	
	for (int i = 0; i < units.size(); i++)
	{
		std::string code = units[i].first->compile();
		addTabs(code);

		switch (units[i].second)
		{
		case Public:
			public_zone += code + "\n";
			break;
		case Protected:
			protected_zone += code + "\n";
			break;
		case Private:
			private_zone += code + "\n";
			break;
		}
	}

	if(public_zone != std::string("public:\n"))
		program += public_zone;
	if (protected_zone != std::string("protected:\n"))
		program += protected_zone;
	if (private_zone != std::string("private:\n"))
		program += private_zone;

	program += "}\n";

	return program;
}

CPPMethod::CPPMethod(MethodSignature s)
{
	signature = s;
}

std::string CPPMethod::compile() const
{
	std::string program;

	if (signature.is_virtual)
		program += "virtual ";
	if (signature.is_static)
		program += "static ";

	switch (signature.return_type)
	{
	case Void:
		program += "void ";
		break;
	case Interger:
		program += "int ";
		break;
	case Float:
		program += "float ";
		break;
	case Double:
		program += "double ";
		break;
	case String:
		program += "char* ";
		break;
	case Char:
		program += "char ";
		break;
	case Boolean:
		program += "bool ";
		break;
	}

	program += signature.name + "(";

	for (int i = 0; i < signature.args.size(); i++)
	{
		switch (signature.args[i].first)
		{
		case Void:
			program += "void ";
			break;
		case Interger:
			program += "int ";
			break;
		case Float:
			program += "float ";
			break;
		case Double:
			program += "double ";
			break;
		case String:
			program += "char* ";
			break;
		case Char:
			program += "char ";
			break;
		case Boolean:
			program += "bool ";
			break;
		}

		program += signature.args[i].second;
		if (i < signature.args.size() - 1)
			program += ",";
	}
	program += ")";
	if (signature.is_const)
		program += " const";

	program += "\n";

	program += "{\n";

	for (int i = 0; i < units.size(); i++)
	{
		std::string code = units[i]->compile();
		addTabs(code);

		program += code;
		program += "\n";
	}

	program += "\t";

	switch (signature.return_type)
	{
	case Void:
		program += "";
		break;
	case Interger:
		program += "return 0;";
		break;
	case Float:
		program += "return 0.0f;";
		break;
	case Double:
		program += "return 0.0;";
		break;
	case String:
		program += "return \"\";";
		break;
	case Char:
		program += "return 0;";
		break;
	case Boolean:
		program += "return true;";
		break;
	}

	program += "\n";

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

std::shared_ptr<MethodUnit> CPPFactory::createMethod(MethodUnit::MethodSignature signature) const
{
	return std::make_shared<CPPMethod>(CPPMethod(signature));
}

std::shared_ptr<PrintOperatorUnit> CPPFactory::createPrintOperator(std::string output) const
{
	return std::make_shared<CPPPrintOperator>(CPPPrintOperator(output));
}
