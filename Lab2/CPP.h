#pragma once
#include <vector>

#include "Utils.h"
#include "Unit.h"
#include "Factory.h"

class CPPClass : public ClassUnit
{
public:
	CPPClass(std::string n);
	~CPPClass() override = default;

	std::string compile() const override;
};

class CPPMethod : public MethodUnit
{
public:
	CPPMethod(MethodSignature s);
	~CPPMethod() override = default;

	std::string compile() const override;
};

class CPPPrintOperator : public PrintOperatorUnit
{
public:
	CPPPrintOperator(std::string out);
	~CPPPrintOperator() override;

	std::string compile() const override;
};

class CPPFactory : public Factory
{
public:
	std::shared_ptr<ClassUnit> createClass(std::string name) const override;
	std::shared_ptr<MethodUnit> createMethod(MethodUnit::MethodSignature signature) const override;
	std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string output) const override;
};
