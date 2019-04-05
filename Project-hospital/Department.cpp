
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"

// C'tor:
Department::Department(const char* inName)
	: name(nullptr), docsArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
	nursesArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{
	name = new char [strlen(inName) + 1];
	strcpy(name, inName);
}

// D'tor:
Department::~Department()
{
	delete[]name;
}

//

bool Department::addPatient(Patient& patient)
{
	if (allocPatientsArr()) //to reallocte the array to the new size
	{
		patientsArr[logSizeOfPatients] = &patient;
		logSizeOfPatients++;
		return true;
	}
	else
		return false;
}

void Department::allocPatientsArr()
{
	if (phySizeOfPatients == 0) // If this is the 1st Patient
	{
		patientsArr = new Patient*;
		phySizeOfPatients++;
	}
	else if (logSizeOfPatients == phySizeOfPatients) //if there is no more room in the array
	{
		phySizeOfPatients *= 2;
		Patient** newArr = new Patient*[phySizeOfPatients];
		for (int i = 0; i < logSizeOfPatients; i++)
		{
			newArr[i] = patientsArr[i];
		}
		delete[] patientsArr;
		patientsArr = newArr;
	}
	else
		return;
}

bool Department::addDoctor(Doctor& doc)
{
	if (phySizeOfDocs == 0) //if the first researcher
	{
		docsArr = new Doctor*;
		phySizeOfDocs++;
	}
	else if (logSizeOfDocs == phySizeOfDocs) //if there is no place in the array
	{
		phySizeOfDocs *= 2;
		allocDocArr();  //to reallocte the array to the new size
	}

	if (logSizeOfDocs< phySizeOfDocs)
	{
		docsArr[logSizeOfDocs] = &doc;
		logSizeOfDocs++;
	}
	return true;
}

void Department::allocDocArr()
{
	if (phySizeOfDocs == 0) // If this is the 1st Department
	{
		docsArr = new Doctor*;
		phySizeOfDocs++;
	}
	else if (logSizeOfDocs == phySizeOfDocs) //if there is no place in the array
	{
		phySizeOfDocs *= 2;
		Doctor** newArr = new Doctor*[phySizeOfDocs];
		for (int i = 0; i < logSizeOfDocs; i++)
		{
			newArr[i] = docsArr[i];
		}
		delete[] docsArr;
		docsArr = newArr;
	}
	else
		return;
}

bool Department::addNurse(Nurse& nurse)
{
	if (phySizeOfNurses == 0) //if the first researcher
	{
		nursesArr = new Nurse*;
		phySizeOfNurses++;
	}
	else if (logSizeOfNurses == phySizeOfNurses) //if there is no place in the array
	{
		phySizeOfNurses *= 2;
		allocNursesArr();  //to reallocte the array to the new size
	}

	if (logSizeOfNurses < phySizeOfNurses)
	{
		nursesArr[logSizeOfNurses] = &nurse;
		logSizeOfNurses++;
	}
	return true;
}

void Department::allocNursesArr()
{
	if (phySizeOfNurses == 0) // If this is the 1st Department
	{
		nursesArr = new Nurse*;
		phySizeOfNurses++;
	}
	else if (logSizeOfNurses == phySizeOfNurses) //if there is no place in the array
	{
		phySizeOfNurses *= 2;
		Nurse** newArr = new Nurse*[phySizeOfNurses];
		for (int i = 0; i < logSizeOfNurses; i++)
		{
			newArr[i] = nursesArr[i];
		}
		delete[] nursesArr;
		nursesArr = newArr;
	}
	else
		return;
}

const char* Department:: getName() const
{
	return name;
}


void Department::showPatients() const
{
	if (logSizeOfPatients > 0)
	{
		cout << "The patients in " << name << (logSizeOfPatients > 1 ? "are" : "is") << endl;
		for (int i = 0; i < logSizeOfDocs; i++)
		{
			cout << "name: " << patientsArr[i]->getName() << endl;
			cout << "ID: " << patientsArr[i]->getId() << endl;
			cout << "Gender: ";
			patientsArr[i]->showGender();
			cout << endl;
			cout << "Year of birth: " << patientsArr[i]->getYearOfBirth() << endl;
			patientsArr[i]->showVisits();
		}
	}
	else
		cout << "There is no patients in this department" << endl;
}
