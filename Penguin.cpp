#include "Penguin.hpp"
#include "Animal.hpp"

Penguin::Penguin()
	: Animal()
{
	cost = 1000;
	babies = 5;
	payoff = cost * .1;

}
void Penguin::incrementAge()
{
	age++;
}
