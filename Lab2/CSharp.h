#pragma once
#include <vector>

#include "Unit.h"
#include "Factory.h"

class CSharpClass : public ClassUnit
{
public:
	CSharpClass(std::string n);
	~CSharpClass() override = default;

	std::string compile() const override;
};

class CSharpMethod : public MethodUnit
{
public:
	CSharpMethod(MethodSignature s);
	~CSharpMethod() override = default;

	std::string compile() const override;
};

class CSharpPrintOperator : public PrintOperatorUnit
{
public:
	CSharpPrintOperator(std::string out);
	~CSharpPrintOperator() override;

	std::string compile() const override;
};

class CSharpFactory : public Factory
{
public:
	std::shared_ptr<ClassUnit> createClass(std::string name) const override;
	// TODO: make method signature
	std::shared_ptr<MethodUnit> createMethod(MethodUnit::MethodSignature signature) const override;
	std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string output) const override;
};
