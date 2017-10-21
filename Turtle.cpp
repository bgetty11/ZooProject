#include "Turtle.hpp"
#include "Animal.hpp"

Turtle::Turtle()
	: Animal()
{
	cost = 100;
	babies = 10;
	payoff = cost * .05;

}

double Turtle::getFoodCost()
{
	return foodCost/2;
}

void Turtle::incrementAge()
{
	age++;
}
