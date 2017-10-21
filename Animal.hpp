#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>
#include<string>

using std::endl;
using std::string;

class Animal
{
protected:
	int age;
	double cost;
	int babies;
	double foodCost = 10;
	double payoff;
	

public:
	Animal();
	int getAge();
	int getBabies();
	virtual double getFoodCost();
	virtual void incrementAge();
	double getPayOff();
	double animalCost();
	void setAge(int tempAge);
	bool isAdult();
	virtual string getName();

};
#endif // !ANIMAL_HPP
