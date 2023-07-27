#include "Java.h"

JavaClass::JavaClass(std::string n)
{
	name = n;
}

std::string JavaClass::compile() const
{
	std::string program;

	program += "class " + name + "\n";
	program += "{\n";

	for (int i = 0; i < units.size(); i++)
	{
		// TODO:: add tabs logic
		switch (units[i].second)
		{
		case Public:
			program += "public " + units[i].first->compile() + "\n";
			break;
		case Protected:
			program += "protected " + units[i].first->compile() + "\n";
			break;
		case Private:
			program += "private " + units[i].first->compile() + "\n";
			break;
		}
	}

	program += "}\n";

	return program;
}

JavaMethod::JavaMethod(MethodSignature s)
{
	signature = s;
}

std::string JavaMethod::compile() const
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
		program += "String ";
		break;
	case Char:
		program += "char ";
		break;
	case Boolean:
		program += "boolean ";
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
			program += "String ";
			break;
		case Char:
			program += "char ";
			break;
		case Boolean:
			program += "boolean ";
			break;
		}

		program += signature.args[i].second;
		if (i < signature.args.size() - 1)
			program += ",";
	}
	program += ") ";
	if (signature.is_const)
		program += ""; // no this functiol in Java

	program += "\n";

	program += "{\n";

	for (int i = 0; i < units.size(); i++)
	{
		std::string code = units[i]->compile();

		// TODO:: add tabs logic

		program += code;
		program += "\n";
	}

	program += "";

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

JavaPrintOperator::JavaPrintOperator(std::string out)
{
	output = out;
}

JavaPrintOperator::~JavaPrintOperator()
{
}

std::string JavaPrintOperator::compile() const
{
	std::string program = "System.out.println(\"" + output + "\");\n";

	return program;
}

std::shared_ptr<ClassUnit> JavaFactory::createClass(std::string name) const
{
	return std::make_shared<JavaClass>(JavaClass(name));
}

std::shared_ptr<MethodUnit> JavaFactory::createMethod(MethodUnit::MethodSignature signature) const
{
	return std::make_shared<JavaMethod>(JavaMethod(signature));
}

std::shared_ptr<PrintOperatorUnit> JavaFactory::createPrintOperator(std::string output) const
{
	return std::make_shared<JavaPrintOperator>(JavaPrintOperator(output));
}
