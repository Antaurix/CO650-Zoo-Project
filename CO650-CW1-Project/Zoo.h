
#ifndef ZOO_H // Header file guards to prevent multiple inclusions
#define ZOO_H

using namespace std;
#include "Animals.h"
#include "Zookeeper.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>





class Zoo {


public:
	string ZooName; // Define the name of the zoo
	string Location; // Define the location of the zoo
	int TotalAnimals; // Define a variable that will store the total number of animals
	vector<Animals*> animals; // Array that stores pointers to animals
	vector<Zookeeper*> zookeepers;// Array that stores pointers to zookeepers

public:

	Zoo(string name, string location) {
	
		ZooName = name;
		Location = location;
	}


	//Adding an animal
	// animal is the object of the Animals class, that's why I used *
	void addAnimal(Animals* animal) {
		animals.push_back(animal); // Adds the animal at the end of the list
		TotalAnimals++; // Increment the total number of animals
		cout << " Added " << animal->getName() << " to the zoo. " << endl; // Accesing the getName() function through a pointer (animal) using "->"
	}

	//Remove an animal
	void removeAnimal(Animals* animal) {
		auto iter = find(animals.begin(), animals.end(), animal); // define an iterator that goes from the begining to the end of the vector and searches for the animal object.
		// the auto declaration makes sure to get the right variable type. For example instead of int X =10; you can use auto X=10;
		if (iter != animals.end()) { // Condition to check if the iterator is not equal with the lenght of the vector.
			animals.erase(iter); // Remove the iterator 
			 // Delete the animal object
			TotalAnimals--; // Decrease the total animal count
			cout << " Removed animal " << animal->getName() << " from the list " << endl;
		}
		else {
			cout << "Animal not found !";
		}

	}

	//Add a zookeper
	// zookeeper is the object of the Zookeeper class. That's why I used the *
	void addZookeeper(Zookeeper* zookeeper) {
		zookeepers.push_back(zookeeper); // Adds the zookeeper object at the end of the vector list.
		cout << "Hired Zookeeper: " << zookeeper->getKeeperFirstName() << " " << zookeeper->getKeeperLastName() << endl;
	}


	//Remove a zookeeper
	void removeZookeeper(Zookeeper* zookeeper) {
		auto iter = find(zookeepers.begin(), zookeepers.end(), zookeeper); // Iterator that goes from the begining to the end of the vector and searches for the zookeeper object
		if (iter != zookeepers.end()) { // Checks if the iterator lenght is not equal to the vector lenght
			zookeepers.erase(iter); // Remove the iterator if false
			 // Delete the zookeeper object
			cout << " Zookeeper " << zookeeper->getKeeperFirstName() << " " << zookeeper->getKeeperLastName() << " has been fired ! " << endl;
		}
		else {
			cout << " Zookeeper not found ! " << endl;
		}
	}
	//Feed an animal
	void feedAnimals() {
		// For loop for animal reference in the animals vector
		// & used to refer to the animal object so that I con modify it withing the code without the need to create new instances.
		for (auto& animal : animals) {
			if (animal->isFeedable()) { // Check if the animal is feedable
				cout << "Feeding " << animal->getName() << endl;
			}
			else {
				cout << animal->getName() << " is not feedable !" << endl;
			}
		}
	}
	//Pet an animal
	void petAnimals() {
		// For loop for animal reference in the animals vector
		// & used to refer to the animal object so that I con modify it within the code without the need to create new instances.
		for (auto& animal : animals) {
			if (animal->isPettable()) { //Checks if the animal is pettable
				cout << "Petting " << animal->getName() << " ! " << endl;
			}
			else {
				cout << animal->getName() << " is not pettable ! " << endl;
			}
		}
	}



	// Display the Animals vector after deletion
	void CheckVectorAnimal() {
		for(auto iter = animals.begin(); iter != animals.end(); iter++) {
			cout << (*iter)->getName() << endl;
		}
	}
	
	// Display the Zookeepers vector after deletion
	void CheckVectorZookeeper() {
		for (auto iter = zookeepers.begin(); iter != zookeepers.end(); iter++) {
			cout << (*iter)->getKeeperFirstName() << " " <<(*iter)->getKeeperLastName() << endl;
		}
	}

}; // Encapsulation

#endif // Guards end