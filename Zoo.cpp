#include"Zoo.hpp"
#include<ctime>

void Zoo::doubleArray(Animal &initialArray, Animal **animalArray, int &initialSize)
{

		int size = initialSize;
		int doubleSize = initialSize * 2;
		int halfSize = initialSize;

		cout << &initialArray << endl;
		Animal **tempArray;
		tempArray = new Animal*[doubleSize];
		cout << &tempArray << endl;

		for (int index = 0; index < size; index++)
		{
			tempArray[index] = animalArray[index];
		}
				
		delete[] &initialArray;
		initialArray = tempArray;
		initialSize = doubleSize; 
		cout << &initialArray << endl;
}

void Zoo::doRandomEvent()
{
	int random;
	srand(time(NULL));

	random = rand() % 4;

	if (random == 0)
	{
		int numAnimals;
		numAnimals = tigerCount + turtleCount + penguinCount;
		int targetRandom = rand() % numAnimals;

		if (numAnimals > 0)
		{
			if (targetRandom < tigerCount)
			{
				cout << "A tiger died" << endl;
				tigerCount--;
			}
			else if (targetRandom < penguinCount + tigerCount)
			{
				cout << "A penguin died" << endl;
				penguinCount--;
			}
			else
			{
				cout << "A turtle died" << endl;
				turtleCount--;
			}
		}
	}
	else if (random == 1 && tigerCount > 0) //added in the tiger count thing cause how can we get money with no tigers
	{
		int randomMoney;
		randomMoney = (rand() % 251) + 250;
		dailyPayoff += (randomMoney * tigerCount);
		cout << "tiger day! added $" << randomMoney << endl;
		//add in an outfile stream
	}
	else if (random == 2)
	{
		int randomMom;
		randomMom = rand() % 3;

		if (randomMom == 0)
		{
			bool isOldEnough = false;
			for (int count = 0; count < tigerCount; count++)
			{
				if (tigerArray[count]->isAdult())
				{
					isOldEnough = true;
				}
			}
			if (isOldEnough)
			{
				cout << "tiger born" << endl;
				addTiger(0);
			}
		}

		else if (randomMom == 1)
		{
			bool isOldEnough = false;
			for (int count = 0; count < penguinCount; count++)
			{
				if (penguinArray[count]->isAdult())
				{
					isOldEnough = true;
				}
			}
			if (isOldEnough)
			{
				cout << "penguin born" << endl;
				addPenguin(0);
			}
		}

		else
		{
			bool isOldEnough = false;
			for (int count = 0; count < turtleCount; count++)
			{
				if (turtleArray[count]->isAdult())
				{
					isOldEnough = true;
				}
			}
			if (isOldEnough)
			{
				cout << "turtle born" << endl;
				addTurtle(0);
			}

		}
	}
	else
		cout << "Nothing has happened today." << endl;
}

void Zoo::addTiger(int age)
{
	Tiger *t = new Tiger();
	int numBabies = t->getBabies();
	if (age == 1095)
	{
		if (tigerCount + 1 > tigerArraySize)
		{
			doubleArray(**tigerArray, *&tigerArray, tigerArraySize);
		}
		
			tigerArray[tigerCount] = new Tiger();
			tigerArray[tigerCount]->setAge(age);
			tigerCount++;
	}

	else
	{
		if(tigerCount + numBabies > tigerArraySize)
		{
		doubleArray(**tigerArray, *&tigerArray, tigerArraySize);
		}
	for (int count = 0; count < numBabies; count++)
		{
		tigerArray[tigerCount] = new Tiger();
		tigerArray[tigerCount]->setAge(age);
		tigerCount++;
		}
	}
	delete t;
}

void Zoo::addPenguin(int age)
{
	// This work around for getting numBabies wouldn't be necessary if babies 
	// was not required by the project to be a member of animal, but instead a static 
	// constant of Penguin.
	Penguin *p = new Penguin();
	int numBabies = p->getBabies();
	if (age == 1095)
	{
		if (penguinCount + 1 > penguinArraySize)
		{
			doubleArray(**penguinArray, *&penguinArray, penguinArraySize);
		}
			penguinArray[penguinCount] = new Penguin();
			penguinArray[penguinCount]->setAge(age);
			penguinCount++;
		
	}

	else
	{
		if (penguinCount + numBabies > penguinArraySize)
		{
			doubleArray(**penguinArray, *&penguinArray, penguinArraySize);
		}
		for (int count = 0; count < numBabies; count++)
		{
			penguinArray[penguinCount] = new Penguin();
			penguinArray[penguinCount]->setAge(age);
			penguinCount++;
		}
	}
	delete p;
}

void Zoo::addTurtle(int age)
{
	Turtle *turt = new Turtle();
	int numBabies = turt->getBabies();
	if (age == 1095)
	{
		if (turtleCount + 1 > turtleArraySize)
		{
			doubleArray(**turtleArray, *&turtleArray, turtleArraySize);
		}
		
			turtleArray[turtleCount] = new Turtle();
			turtleArray[turtleCount]->setAge(age);
			turtleCount++;
		
	}

	else
	{
		if (turtleCount + numBabies > turtleArraySize)
		{
			doubleArray(**turtleArray, *&turtleArray, turtleArraySize);
		}

		cout << "number of turtle babies" << numBabies << endl;
		cout << "the turtle count is " << turtleCount << endl;
		for (int count = 0; count < numBabies; count++)
		{
			turtleArray[turtleCount] = new Turtle();
			turtleArray[turtleCount]->setAge(age);
			cout << "Added turtle " << turtleCount << " with age " << turtleArray[turtleCount]->getAge() << endl;
			turtleCount++;
			
		}

		
		cout<< "the turtle count is " << turtleCount << endl;
		cout << "the turtle array count is" << turtleArraySize << endl;
	}
	delete turt;
}

int main() {
	Zoo *zoo = new Zoo();
	zoo-> play();
	delete zoo;
	
}

void Zoo::play()
{
	int answer;	
	tigerArray = new Animal*[10];
	penguinArray = new Animal*[10];
	turtleArray = new Animal*[10];

	cout << "Welcome to Zoo Tycoon!" << endl;
	cout << "You start with $" << bankAccount << " in your bank account." << endl;
	cout << endl;
	cout << "How many tigers would you like to buy, 1 or 2?" << endl;
	while (!(cin >> answer) || (answer != 1 && answer != 2) )
	{
		cout << "Please enter 1 or 2: " << endl;
		cin.clear();
		cin.ignore(10, '\n');
	}
	cout << endl;

	for (int count = 0; count < answer; count++)
	{
		tigerArray[count] = new Tiger();
		tigerArray[count]->setAge(365);
		bankAccount -= tigerArray[count]->animalCost();
		tigerCount++;
	}

	cout << "How many penguins would you like to buy, 1 or 2?" << endl;
	while (!(cin >> answer) || (answer != 1 && answer != 2))
	{
		cout << "Please enter 1 or 2: " << endl;
		cin.clear();
		cin.ignore(10, '\n');
	}
	cout << endl;

	for (int count = 0; count < answer; count++)
	{
		penguinArray[count] = new Penguin();
		penguinArray[count]->setAge(365);
		bankAccount -= penguinArray[count]->animalCost();
		penguinCount++;
	}

	cout << "How many turtles would you like to buy, 1 or 2?" << endl;
	while (!(cin >> answer) || (answer != 1 && answer != 2))
	{
		cout << "Please enter 1 or 2: " << endl;
		cin.clear();
		cin.ignore(10, '\n');
	}
	cout << endl;

	for (int count = 0; count < answer; count++)
	{
		turtleArray[count] = new Turtle();
		turtleArray[count]->setAge(365);
		bankAccount -= turtleArray[count]->animalCost();
		turtleCount++;
	}

	doSingleDay();
	while (shouldKeepPlaying())
	{
		doSingleDay();
	}

}

void Zoo::doSingleDay()
{
	for (int count = 0; count < tigerCount; count++)
	{
		tigerArray[count]->incrementAge();
		bankAccount -= tigerArray[count]->getFoodCost();
		cout << "feeding tiger costs $" << tigerArray[count]->getFoodCost()  << endl;
	}

	for (int count = 0; count < penguinCount; count++)
	{
		penguinArray[count]->incrementAge();
		bankAccount -= penguinArray[count]->getFoodCost();
		cout << "feeding penguin costs $" << penguinArray[count]->getFoodCost() << endl;
	}
	
	for (int count = 0; count < turtleCount; count++)
	{
		turtleArray[count]->incrementAge();
		bankAccount -= turtleArray[count]->getFoodCost();
		cout << "feeding turtle costs $" << turtleArray[count]->getFoodCost() << endl;
	}
	cout << endl;

	doRandomEvent();
	cout << endl;

	payoffAmount();

	cout << "Your daily payoff amount is $" << dailyPayoff << endl;

	bankAccount += dailyPayoff;

	cout << "You currently have $" << bankAccount << " in your account after the daily payoff." << endl;
	cout << endl;

	int answer;
	cout << "Which of the following would you like to do:" << endl;
	cout << "1. End Day without purchasing an animal." << endl;
	cout << "2. Buy an adult tiger." << endl;
	cout << "3. Buy an adult penguin." << endl;
	cout << "4. Buy an adult turtle." << endl;
	while (!(cin >> answer) || (answer < 1) || (answer > 4))
	{
		cout << "Please enter 1, 2, 3, or 4: " << endl;
		cin.clear();
		cin.ignore(10, '\n');
	}
	cout << endl;

	if (answer == 2 && bankAccount >= 10000)
	{
		addTiger(1095);
		bankAccount -= 10000;
		//tigerCount++;

	}
	else if (answer == 3 && bankAccount >= 1000)
	{
		addPenguin(1095);
		bankAccount -= 1000;
		//penguinCount++;
	}
	else if (answer == 4 && bankAccount >= 100)
	{
		addTurtle(1095); 
		bankAccount -= 100;
		//turtleCount++;
	}
	else if (answer >= 2 && answer <= 4) 
	{
		cout << "You did not have enough money in your account." << endl;
	}


	cout << "You currently have $" << bankAccount << " in your account." << endl;
	cout << endl;

	dailyPayoff = 0;

	
}

bool Zoo::shouldKeepPlaying()
{
	int answer;

	//I added this in to end the game if you have no money
	if (bankAccount <= 0)
	{
		cout << "Unfortunately you have no money left. The game is over." << endl;
		return false;
	}

		cout << "Would you like to keep playing or end the game?" << endl;
		cout << "Press 1 to continue or 2 to quit." << endl;
		while (!(cin >> answer) || (answer != 1 && answer != 2))
		{
			cout << "Please enter 1 or 2: " << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}
		cout << endl;

		if (answer == 1)
			return true;
		else //(answer == 2)
			return false;
	

		

}

//I added this to add in the daily payoff 
void Zoo::payoffAmount()
{

	Tiger *tig = new Tiger(); 
	double tigerPayoff;

	tigerPayoff = tig->getPayOff() * tigerCount;
	dailyPayoff+= tigerPayoff;
	
	Penguin *peng = new Penguin();
	double penguinPayoff;

	penguinPayoff = peng->getPayOff() * penguinCount;
	dailyPayoff += penguinPayoff;

	Turtle *turt = new Turtle();
	double turtlePayoff; 

	turtlePayoff = turt->getPayOff() * turtleCount;
	dailyPayoff += turtlePayoff;

	delete tig;
	delete peng; 
	delete turt;
}

