/*
	Chen, Quentin (team leader)
	Espejo, Alex
	Foroutan, Pantea 

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include <iostream>
#include "Student.h"
#include "Course.h"
#include "StudentList.h"

using namespace std;

int main()
{
	cout << "Course Class Test: " << endl << endl;
	Course java;
	java.setCourseInfo("CS", 170, 4);
	Course python;
	python.setCourseInfo("CS", 160, 4);
	Course calc2;
	calc2.setCourseInfo("Math", 185, 4);
	cout << java.getCoursePrefix() << java.getCourseNumber() 
			<< " Java Programming I" << endl;
	cout << "Units: " << java.getCourseUnits() << endl;
	cout << endl << endl;

	//Student Class
	multimap<Course, char> courses{ {java, 'A'}, {python, 'A'}, 
		{calc2, 'A'} };

	cout << "Student Class Test: " << endl << endl;
	Student pantea(42069, "Alex", "Espejo", false, courses);

	//testing setters
	Student quentin;
	quentin.setStudentInfo(60942, "Quentin", "Chen", false, courses);

	Student alex;
	alex.setStudent(pantea);

	string fName, lName;
	alex.getName(fName, lName);
	cout << "Full Name: " << fName << " " << lName << endl;

	//Testing individual getters	
	cout << alex.getFirstName() << "'s information" << endl;
	cout << "ID: " << alex.getID() << endl;
	cout << "Units Completed: " << alex.getUnitsCompleted() << endl;
	cout << "Courses Completed: " << endl;
	for (auto course : alex.getCoursesCompleted()) 
	{
		cout << course.first.getCoursePrefix() 
			<< course.first.getCourseNumber() << endl;
	}
	cout << "GPA: " << alex.calculateGPA() << endl;

	cout << (alex.isTuitionPaid() ? 
		"You've paid your fees" : "Pay your fees!") << endl;
	cout << "Outstanding Balance: " << alex.billingAmount(1231) 
		<< endl;

	//Printing Student 
	cout << endl;
	alex.printStudent();
	quentin.printStudentInfo(1231);
	cout << endl << endl;

	cout << "StudentList Class Test" << endl << endl;
	StudentList projectGroup;
	projectGroup.addStudent(alex);
	projectGroup.addStudent(quentin);

	pantea.setStudentInfo(96024, "Bob", "Espejo", true, 
		{ {java, 'A'}, {python, 'A'} });
	projectGroup.addStudent(pantea);


	cout << "Students taking MATHA180: " << endl;
	projectGroup.printStudentByCourse("MATHA", 185);

	cout << "Students taking CSA150: " << endl;
	projectGroup.printStudentByCourse("CSA", 150);
	cout << endl;

	cout << "Students with last name Tran: ";
	projectGroup.printStudentByName("Tran");

	cout << "Students with last name Espejo: " << endl;
	projectGroup.printStudentByName("Espejo");
	cout << endl;

	cout << "Students with ID# 96024: " << endl;
	projectGroup.printStudentByID(96024, 1234);
	projectGroup.printStudentByID(80085, 1234);
	cout << endl;

	//print all students
	projectGroup.printAllStudents(123);

	//clear students
	projectGroup.clearStudentList();
	projectGroup.printAllStudents(1234);

	cout << endl;
	system("Pause");
	return 0;
}