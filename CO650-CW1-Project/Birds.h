#ifndef BIRDS_H // Header file guards to prevent multiple inclusions
#define BIRDS_H


using namespace std;
#include <iostream>
#include <string>
#include "Animals.h"


//Define the birds class
class Birds : public Animals{

public:
	Birds(string name, int age, int weight, string sound, bool isAnimalFeedable, bool isAnimalPettable, bool healthy):
		Animals(name, age, weight, sound,isAnimalFeedable,isAnimalPettable, healthy) {}

	void fly() {  //Define a specific behaviour of birds
		cout << getName() << " is flying !" << endl;
	}

}; // Encapsulation


#endif 