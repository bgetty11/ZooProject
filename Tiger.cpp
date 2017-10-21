#include "Tiger.hpp"
#include "Animal.hpp"

Tiger::Tiger()
	:Animal()
{
	cost = 10000;
	babies = 1;
	payoff = cost * .2;
}

double Tiger::getFoodCost() 
{
	return (foodCost * 5);
}

void Tiger::incrementAge()
{
	age++;
}

