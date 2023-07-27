#include "CSharp.h"

CSharpClass::CSharpClass(std::string n)
{
	name = n;
}

std::string CSharpClass::compile() const
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

CSharpMethod::CSharpMethod(MethodSignature s)
{
	signature = s;
}

std::string CSharpMethod::compile() const
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
		program += "string ";
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
			program += "string ";
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
	program += ") ";
	if (signature.is_const)
		program += ""; // no this functiol in C#

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

CSharpPrintOperator::CSharpPrintOperator(std::string out)
{
	output = out;
}

CSharpPrintOperator::~CSharpPrintOperator()
{
}

std::string CSharpPrintOperator::compile() const
{
	std::string program = "System.Console.WriteLine(\"" + output + "\");\n";

	return program;
}

std::shared_ptr<ClassUnit> CSharpFactory::createClass(std::string name) const
{
	return std::make_shared<CSharpClass>(CSharpClass(name));
}

std::shared_ptr<MethodUnit> CSharpFactory::createMethod(MethodUnit::MethodSignature signature) const
{
	return std::make_shared<CSharpMethod>(CSharpMethod(signature));
}

std::shared_ptr<PrintOperatorUnit> CSharpFactory::createPrintOperator(std::string output) const
{
	return std::make_shared<CSharpPrintOperator>(CSharpPrintOperator(output));
}
