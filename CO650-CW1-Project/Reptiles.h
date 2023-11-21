#ifndef REPTILES_H // Header file guards to prevent multiple inclusions
#define REPTILES_H



using namespace std;
#include "Animals.h"

// Define the reptile class
class Reptiles: public Animals{

public:

	Reptiles(string name, int age, int weight, string sound, bool isAnimalFeedable, bool isAnimalPettable, bool healthy) :
		Animals(name, age, weight, sound, isAnimalFeedable, isAnimalPettable, healthy) {};

	void crawl(){ /// Define a specific behaviour of reptiles
		cout << getName() << " is crawling !" << endl;
	}

};//Encapsulation

#endif 