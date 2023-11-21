#ifndef CLINIC_H
#define CLINIC_H

using namespace std;
#include <iostream>
#include "Animals.h"



class Clinic
{
public:

	// Function that will diagnose the animal health
	void DiagnoseAnimal(Animals& animal) {
	
		if (animal.getHealth()) {
			cout << animal.getName() << " is healthy " << endl;
		}

		else {

			cout << animal.getName() << " is not healthy " << endl;
		}
	};

};

#endif 