#pragma once
#include <string>
#include <memory>

enum AccessModifier
{
	Public = 0,
	Protected,
	Private,
};

enum Type
{
	Void = 0,
	Interger,
	Float,
	Double,
	String,
	Char,
	Boolean,
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

	void addUnit(std::shared_ptr<Unit> unit, AccessModifier mod)
	{
		units.push_back(std::make_pair(unit, mod));
	}

protected:
	std::string name;
	std::vector<std::pair<std::shared_ptr<Unit>, AccessModifier>> units;
};

class MethodUnit : public Unit
{
public:
	struct MethodSignature
	{
		bool is_virtual = false;
		bool is_static = false;
		Type return_type = Void;
		std::string name = "func";
		std::vector<std::pair<Type, std::string>> args = std::vector<std::pair<Type, std::string>>(0);
		bool is_const = false;
	};

	~MethodUnit() override
	{
		units.clear();
	}

	void addOperator(std::shared_ptr<Unit> unit)
	{
		units.push_back(unit);
	}

protected:
	MethodSignature signature;
	std::vector<std::shared_ptr<Unit>> units;
};

class PrintOperatorUnit : public Unit
{
public:
	~PrintOperatorUnit() override = default;

protected:
	std::string output;
};