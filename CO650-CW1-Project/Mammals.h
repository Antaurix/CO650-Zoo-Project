#ifndef MAMMALS_H
#define MAMMALS_H



using namespace std;
#include <iostream>
#include "Animals.h"



// Define the Mammals class
class Mammals: public Animals {

public:
	Mammals(string name, int age, int weight, string sound, bool isAnimalFeedable, bool isAnimalPettable, bool healthy) :
		Animals(name, age, weight, sound, isAnimalFeedable, isAnimalPettable,healthy) {}

	void run() { // Define a specific behaviour of mammals
		cout << getName() << " is running !" << endl;
	}

};//Encapsulation

#endif 