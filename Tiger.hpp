#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal
{
private:

public:
	Tiger();
	double getFoodCost();
	void incrementAge();
};
#endif