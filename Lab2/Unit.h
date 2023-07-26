#pragma once
#include <string>
#include <memory>

enum AccessModifier
{
	Public = 0,
	Protected,
	Private,
};

class Unit
{
public:
	virtual ~Unit() = default;
	virtual std::string compile() const = 0;
};

class ClassUnit : public Unit
{
public:
	~ClassUnit() override
	{
		units.clear();
	}

	void addMethod(std::shared_ptr<Unit> unit, AccessModifier mod)
	{
		modifiers.push_back(mod);
		units.push_back(unit);
	}

protected:
	std::string name;
	std::vector<AccessModifier> modifiers;
	std::vector<std::shared_ptr<Unit>> units;
};

class MethodUnit : public Unit
{
public:
	~MethodUnit() override
	{
		units.clear();
	}

	void addOperator(std::shared_ptr<Unit> unit)
	{
		units.push_back(unit);
	}

protected:
	std::string name;
	std::vector<std::shared_ptr<Unit>> units;
};

class PrintOperatorUnit : public Unit
{
public:
	~PrintOperatorUnit() override = default;

protected:
	std::string output;
};