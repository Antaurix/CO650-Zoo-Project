#ifndef ANIMALS_H // Header file guards to prevent multiple inclusions
#define ANIMALS_H
using namespace std;
#include <iostream>
#include <string>




// Define the Animals class that inherits from the Zoo class
class Animals  {	

private:
	static int totalAnimals; // Static member to count the total number of animals;
	bool isHealthy; // Private variable that explain the current health status of an animal. Used to prove friendship.

	// Declar friend classes so that they can access the private variables 
	friend class Zookeeper; 
	friend class Clinic; 
	friend class Mammals;
	friend class Reptiles;
	friend class Birds;

public:
	string name;
	int age;
	int weight;
	string sound;
	bool isAnimalPettable;
	bool isAnimalFeedable;

public:

	// Define a constructor with parameters pointing to the variables defined in the class
	Animals(string name, int age, int weight, string sound, bool isAnimalFeedable, bool isAnimalPettable, bool healthy) :
		name(name), age(age), weight(weight), sound(sound),isAnimalFeedable(isAnimalFeedable), isAnimalPettable(isAnimalPettable), isHealthy(healthy) {
	
		totalAnimals++;
	}


	// Getting the name of the animal
	string getName() {
	return name;
	}
	// Getting the age of the animal
	 int getAge() {				
		return age;
	}
	//Getting the weight of an animal
	 int getWeight() {			
		return weight;
	}
	//The sound that the animal is doing
	 string makeSound() {			
		return sound;
	}
	//Sets if the animal is feedable or not
	 bool isFeedable() {			
		 return isAnimalFeedable;
	}
	//Sets if the animal is pettable or not
	 bool isPettable() {			
		 return isAnimalPettable;
	}

	 // Function overloading 
	 bool isFeedable(int feedTime) {
		 return feedTime > 12; // Set the feeding time to 12:00 pm
	 }

	 // Function overloading
	 bool isPettable(bool isDangerous) { // Check if an animal is dangerous before trying to pet it.
		 return !isDangerous;
	 }

	 // Get the total number of animals from the zoo
	 static int getTotalAnimals() {
		 return totalAnimals;
	 }

	 bool getHealth() {
		 return isHealthy;
	 }

	 virtual ~Animals() {} // Destructor used to destroy objects created using the constructor functon of a class.

}; //Encapsulation

#endif