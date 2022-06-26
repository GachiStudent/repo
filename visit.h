#pragma once
#include<iostream>
#include<vector>

class fish;
class shellfish;
class seaweed;

namespace Marine_Organisms {
	int Counter_Individual{ 0 };
}

//Посетитель
class Visitor
{
public:
	virtual void VisitFish(const fish* elem) const = 0;
	virtual void VisitShellFish(const shellfish* elem) const = 0;
	virtual void VisitSeaweed(const seaweed* elem) const = 0;
};

//Аквариум
class marine_organisms
{
public:
	virtual	~marine_organisms() {}
	virtual void Accept(Visitor* visitor) const = 0;
};

//Класс рыб
class fish : public marine_organisms
{
public:
	void Accept(Visitor* visitor) const override
	{
		visitor->VisitFish(this);
	}

	virtual std::string Name() const = 0;

	std::string MyDepartment() const {
		return "Fish";
	}
};

//Класс моллюсков
class shellfish : public marine_organisms
{
public:
	void Accept(Visitor* visitor) const override
	{
		visitor->VisitShellFish(this);
	}

	virtual std::string Name() const = 0;

	std::string MyDepartment() const {
		return "SHellfish";
	}
};

//Класс водорослей
class seaweed : public marine_organisms
{
public:
	void Accept(Visitor* visitor) const override {
		visitor->VisitSeaweed(this);
	}

	virtual std::string Name() const = 0;

	std::string MyDepartment() const {
		return "Seaweed";
	}
};

//Конкретные рыбы
class Barbus : public fish
{
public:
	std::string Name() const override {
		return "I'm Seaweed";
	}
};

class Barbus_new : public fish
{
public:
	std::string Name() const override {
		return "I'm Seaweed";
	}
};

class Barbus_new_new : public fish
{
public:
	std::string Name() const override {
		return "I'm Seaweed";
	}
};

class Eurasian_carp : public fish
{
public:
	std::string Name() const override {
		return "I'm Eurasian carp";
	}
};

class Wels_catfish : public fish
{
public:
	std::string Name() const override {
		return "I'm Wels catfish";
	}
};

//Конкретные моллюски
class Gaint_Snail : public shellfish
{
public:
	std::string Name() const override {
		return "I'm Gaint Snail";
	}
};

class Tiny_Snail : public shellfish
{
public:
	std::string Name() const override {
		return "I'm Tiny Snail";
	}
};

//Конкретные водоросли
class Pandorina : public seaweed
{
public:
	std::string Name() const override {
		return "I'm Pandorina";
	}
};

class Rhodymenia : public seaweed
{
public:
	std::string Name() const override {
		return "I'm Rhodymenia";
	}
};

//Конкретные посетители
class Name_Visitor : public Visitor
{
public:
	void VisitFish(const fish* elem) const override {
		std::cout << elem->Name() << std::endl;
	}
	void VisitShellFish(const shellfish* elem) const override {
		std::cout << elem->Name() << std::endl;
	}
	void VisitSeaweed(const seaweed* elem) const override {
		std::cout << elem->Name() << std::endl;
	}
};

class Counter_Individuals_Visitor : public Visitor
{
public:
	void VisitFish(const fish* elem) const override {
		Marine_Organisms::Counter_Individual += 1;
	}
	void VisitShellFish(const shellfish* elem) const override {
		Marine_Organisms::Counter_Individual += 1;
	}
	void VisitSeaweed(const seaweed* elem) const override {
		Marine_Organisms::Counter_Individual += 0;
	}
};

//Конкретный визитор к конкретному аквариуму
void Code(std::vector<const marine_organisms*> organisms, Visitor* visitor)
{
	for (const marine_organisms* organism : organisms) {
		organism->Accept(visitor);
	}
	if (typeid(*visitor) == typeid(Counter_Individuals_Visitor)) {
		std::cout << Marine_Organisms::Counter_Individual;
		Marine_Organisms::Counter_Individual = 0;
	}
}