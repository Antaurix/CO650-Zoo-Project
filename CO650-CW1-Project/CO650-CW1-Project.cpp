

#include <iostream>
using namespace std;
#include "Zoo.h"
#include "Animals.h"
#include "Zookeeper.h"
#include "Birds.h"
#include "Reptiles.h"
#include "Mammals.h"

// Initialize the static member of the animal class with 0;
int Animals::totalAnimals = 0;

int main()
{
	// Create a zoo object of the class Zoo
	// and display it
	Zoo zoo("Boris's Zoo","UK");	
	cout << "  ---  Zoo Details  ---  " << endl;
	cout <<" Name: " << zoo.ZooName << " " << " Location: " << zoo.Location << endl;
	cout << "--------------------------- " << endl;
	cout << " " << endl;

	// Create an animal object of each class.
	// Last 3 parameters are: feedable, pettable, healthy
	Birds parrot("Polly", 3, 1, "Squawk",true,true,false);
	Reptiles snake("Slytherin", 5, 2, "Hiss",true,false,true);
	Mammals lion("Simba", 4, 300, "Roar",true,false,true);

	// Add animals to the zoo
	zoo.addAnimal(&parrot);
	zoo.addAnimal(&snake);
	zoo.addAnimal(&lion);
	cout << "--------------------------- " << endl;

	// Get the total number of animals using the static member
	cout << "Total number of animals: " << Animals::getTotalAnimals() << std::endl;
	cout << "--------------------------- " << endl;
	cout << " " << endl;

	// Demonstrate specific behaviors
	parrot.fly();
	snake.crawl();
	lion.run();
	cout << "--------------------------- " << endl;
	cout << " " << endl;

	// Feed and pet the animals
	zoo.feedAnimals();
	zoo.petAnimals();
	cout << "--------------------------- " << endl;
	cout << " " << endl;

	// Function overloading
	// Check if the animals are feedable and pettable with certain parameters
	int feedingTime = 11;
	bool isDangerous = true;
	cout << "Is the snake feedable at " << feedingTime << ":00? " << (snake.isFeedable(feedingTime) ? "Yes" : "No") << endl;
	cout << "Is the snake pettable ?  " << (snake.isPettable(isDangerous) ? "Yes" : "No") << endl;
	cout << "--------------------------- " << endl;
	cout << " " << endl;

	// Create and add zookeepers
	Zookeeper zookeeper("John", "Doe", 25, 50000);
	Zookeeper zookeeper2("Vlad", "The impaler", 27, 777777);
	zoo.addZookeeper(&zookeeper);
	zoo.addZookeeper(&zookeeper2);
	cout << endl;

	// Demonstrate functional pointers using the zookeepers greetings  
	zookeeper.greetFunction(&Zookeeper::greetStandard);
	zookeeper2.greetFunction(&Zookeeper::greetSpecial);
	cout << "---------------------------  " << endl;
	cout << " " << endl;

	// Inspect an animal
	cout << " Zookeeper " << zookeeper.getKeeperFirstName() << " inspects the animals ! "<< endl;
	cout << endl;
	zookeeper.inspectAnimal(parrot);
	zookeeper.inspectAnimal(snake);
	zookeeper.inspectAnimal(lion);
	cout << "---------------------------  " << endl;
	cout << " " << endl;

	// Remove an animal and a zookeeper
	zoo.removeAnimal(&snake);
	cout << "  " << endl;
	zoo.removeZookeeper(&zookeeper);
	cout << "---------------------------  " << endl;
	cout << " " << endl;


	//Check the vectors after deletion
	cout << "--------------------------- " << endl;
	cout << " Current animals inside the zoo : " << endl;
	zoo.CheckVectorAnimal();
	cout << " " << endl;
	cout << "--------------------------- " << endl;
	cout << "Current Zookeepers inside the zoo: " << endl;
	zoo.CheckVectorZookeeper();
	
}

