#pragma once
#include "Unit.h"

class Factory
{
public:
	virtual std::shared_ptr<ClassUnit> createClass(std::string name) const = 0;
	// TODO: make method signature
	virtual std::shared_ptr<MethodUnit> createMethod(MethodUnit::MethodSignature signature) const = 0;
	virtual std::shared_ptr<PrintOperatorUnit> createPrintOperator(std::string output) const = 0;
};