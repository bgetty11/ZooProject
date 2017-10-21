#include"Animal.hpp"

Animal::Animal()
{
	age = 0;
	//age;
}

int Animal::getAge()
{
	return age;
}

int Animal::getBabies()
{
	return babies;
}

double Animal::getFoodCost()
{
	return foodCost;
}

void Animal::incrementAge()
{
	age++;
}

double Animal::getPayOff()
{
	return payoff;
}

double Animal::animalCost()
{
	return cost;
}

bool Animal::isAdult()
{
	bool adult = true; 
	if (age < 1095)
	{
		adult = false;
	}
	return adult;
}

void Animal::setAge(int tempAge)
{
	age = tempAge;
}

string Animal::getName()
{
	return "animal";
}