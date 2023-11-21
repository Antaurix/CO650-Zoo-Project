#ifndef ZOOKEEPER_H// Header file guards to prevent multiple inclusions
#define ZOOKEEPER_H

#include <string>
using namespace std;
#include <iostream>
#include "Clinic.h"


class Zookeeper {

	// Set the variables
private:
	string FirstName;
	string LastName;
	int age;
	int salary;

	// Referencing
	// Define the Zookeper constructors with references to the variable 
public:
	 Zookeeper(string FirstName, string LastName, int age, int salary): FirstName(FirstName),LastName(LastName),age(age),salary(salary) {}

	  // Get the zookeeper first name
	 string getKeeperFirstName() {
		return FirstName;
	}
	// Get the zookeeper last name
	 string getKeeperLastName() {
		return LastName;
	}
	// get the zookeeper age
	 int getKeeperAge() {
		return age;
	}
	// get its salary
	 int getKeeperSalary() {
		return salary;
	}

	 // Define a standard greeting function
	   void greetStandard()  {
        cout << "Hello, I'm the zookeeper " << FirstName << "!" << endl;
    }

	 // Define a special greeting function
    void greetSpecial()  {
        cout << "Greetings from the special zookeeper " << FirstName << "!" << endl;
    }

	// Define a function that will set the greeting of each zookeeper using the above functions
	// Zookeeper:: is the scope resolution (meaning something from withing the Zookeeper class)
	// void(...*greeting)() is a void greeting pointer function (a blueprint function) that points towards greetSpecial() or greetStandard()
	void greetFunction(void(Zookeeper::* greeting)() ) {
		(this->*greeting)(); // this = the current instance of the zookeeper class | refers to the specific Zookeeper object like zookeeper1 from the main program
	}

	// Define a function to inspect an animal object
	void inspectAnimal(Animals& animal) {
		Clinic clinic;
		clinic.DiagnoseAnimal(animal);
	}



	// Destructor, used when deleting objects created with pointers and references.
	 virtual ~Zookeeper() {}


}; //Encapsulation
#endif