#ifndef ZOO_HPP
#define ZOO_HPP
#include"Animal.hpp"
#include"Tiger.hpp"
#include"Penguin.hpp"
#include "Turtle.hpp"
#include<iostream>

using std::endl;
using std::cout;
using std::cin;

class Zoo
{
protected:
	int tigerCount;
	int turtleCount;
	int penguinCount;
	int tigerArraySize = 10;
	int turtleArraySize = 10;
	int penguinArraySize = 10;
	Animal **tigerArray;
	Animal **penguinArray;
	Animal **turtleArray;
	double bankAccount = 100000;
	double dailyPayoff;

public:
	void doubleArray(Animal &initialArray, Animal **animalArray, int &initialSize);
	void doRandomEvent();
	void addTiger(int age);
	void addPenguin(int age);
	void addTurtle(int age);
	void play();
	void doSingleDay();
	bool shouldKeepPlaying();
	void payoffAmount();
	};

#endif