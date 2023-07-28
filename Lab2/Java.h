#pragma once
#include <vector>

#include "Utils.h"
#include "Unit.h"
#include "Factory.h"

class JavaClass : public ClassUnit
{
public:
	JavaClass(std::string n);
	~JavaClass() override = default;

	std::string compile() const override;
};

class JavaMethod : public MethodUnit
{
public:
	JavaMethod(MethodSignature s);
	~JavaMethod() override = default;

	std::string compile() const override;
};

class JavaPrintOperator : public PrintOperatorUnit
{
public:
	JavaPrintOperator(std::string out);
	~JavaPrintOperator() override;

	std::string compile() const override;
};

class JavaFactory : public Factory
{
public:
	std::shared_ptr<ClassUnit> createClass(std::string name) const override;
	std::shared_ptr<MethodUnit> createMethod(MethodUnit::MethodSignature signature) const override;
	std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string output) const override;
};
