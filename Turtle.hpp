#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal
{
private:
	

public:
	Turtle();
	double getFoodCost();
	void incrementAge();
};
#endif
