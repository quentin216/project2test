/*
	Chen, Quentin (team leader)
	Espejo, Alexander
	Foroutan, Pantea

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Student.h"
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

void Student::setStudent(const Student& aStudent)
{
	studentID = aStudent.studentID;
	firstName = aStudent.firstName;
	lastName = aStudent.lastName;
	numberOfCourses = aStudent.numberOfCourses;
	tuitionWasPaid = aStudent.tuitionWasPaid;
	coursesCompleted = aStudent.coursesCompleted;
}

void Student::setStudentInfo(int newID, const string& newFirstName, 
	const string& newLastName, bool paid, 
	const multimap<Course, char>& courses)
{
	studentID = newID;
	firstName = newFirstName;
	lastName = newLastName;
	tuitionWasPaid = paid;
	coursesCompleted = courses;
	numberOfCourses = static_cast<int>(coursesCompleted.size());
}

int Student::getID() const
{
	return studentID;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

void Student::getName(string& newFirstName, string& newLastName)
{
	newFirstName = firstName;
	newLastName = lastName;
}

int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
	int unitsCompleted = 0;
	auto iter = coursesCompleted.begin();
	while (iter != coursesCompleted.end())
	{
		unitsCompleted += iter->first.getCourseUnits();
		iter++;
	}
	return unitsCompleted;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
	return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& prefix, 
	int courseNumber) const
{
	if (numberOfCourses == 0)
	{
		return false;
	}
	auto iter = coursesCompleted.begin();
	while (iter != coursesCompleted.end())
	{
		if (prefix == iter->first.getCoursePrefix() &&
			courseNumber == iter->first.getCourseNumber())
		{
			return true;
		}
		iter++;
	}
	return false;
}

double Student::calculateGPA() const
{
	double totalPoints = 0.0;
	double totalUnits = 0.0;
	auto iter = coursesCompleted.begin();
	while (iter != coursesCompleted.end())
	{
		double grade = 0.0;
		switch ((*iter).second)
		{
		case 'A': grade = 4.0;
			break;
		case 'B': grade = 3.0;
			break;
		case 'C': grade = 2.0;
			break;
		case 'D': grade = 1.0;
			break;
		case 'F': grade = 0.0;
			break;
		}

		totalPoints += grade * iter->first.getCourseUnits();
		totalUnits += iter->first.getCourseUnits();
		iter++;
	}
	return totalPoints / totalUnits;
}

double Student::billingAmount(double tuitionRate) const
{
	return tuitionRate * numberOfCourses;
}

void Student::printStudent() const
{
	cout << studentID << " - " << lastName << ", " << firstName 
		<< endl;
}

void Student::printStudentInfo(double tuitionRate)
{
	cout << "Student Name: " << lastName << ", " << firstName 
		<< endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << numberOfCourses 
		<< endl;
	cout << endl;
	cout << "CourseNo  Units  Grade" << endl;
	int totalCreditHours = 0;
	for (auto iter = coursesCompleted.begin();
		iter != coursesCompleted.end(); iter++)
	{
		cout << left << setw(5) << iter->first.getCoursePrefix()
			<< setw(7) << iter->first.getCourseNumber()
			<< setw(7) << iter->first.getCourseUnits()
			<< iter->second << endl;
	}
	cout << endl;
	cout << "Total number of credit hours: " << totalCreditHours 
		<< endl;
	cout << "Current Term GPA: " << this->calculateGPA() << endl;
	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" 
		<< endl;
}