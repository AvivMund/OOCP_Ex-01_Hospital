#ifndef PATIENT_H
#define PATIENT_H
#include "Visitation_Record.h"
//#include "Date.h"
#include "ConstantsAndGenFuncs.h"
//#include "Department.h"

class Department;

class Patient
{
private:
	char* name;
	eGender gender;
	char* ID;
	char*  yearOfBirth;
	VisitationRecord** visits;
	int logSizeOfVisits;
	int phySizeOfVisits;
	const Department** departmentsVisited;
	int logsizeOfDepartments;
	int phySizeOfDepartments;


public:
	// C'tor:
	Patient(const char* inName,const char*id, enum eGender inGender, char* inYearOBirth);
	// Copy C'tor:
	Patient(const Patient& other) = delete;
	// D'tor:
	~Patient();

	// Methods:
	bool addVistation(VisitationRecord& newVisit);
	void reallocVisitsArr();
	void reallocDepartmentsVisitedArr();
	bool addDepatrtmentToPatient(const Department& pDepartment);
	const char* getName()const;
	const char* getId()const;
	void showGender() const;
	const char * getYearOfBirth() const;
	void showVisits() const;
	void showDepatmentsVisited() const;

	bool hasVisitedDepartment(Department& pDepartment) const;
};

#endif
