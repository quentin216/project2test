/*
	Chen, Quentin (team leader)
	Espejo, Alex
	Foroutan, Pantea

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <map>
#include "Course.h"

class Student
{
public:
	Student() : studentID(0), firstName("N/A"), lastName("N/A"), 
		numberOfCourses(0), tuitionWasPaid(false) {}
	Student(int newID, const std::string& newFirstName,
		const std::string& newLastName, bool paid, const std::multimap<Course, char>& courses) : studentID(newID), firstName(newFirstName), lastName(newLastName),
		numberOfCourses(static_cast<int>(courses.size())), tuitionWasPaid(paid), coursesCompleted(courses) {}
	
	void setStudent(const Student& newStudent);
	void setStudentInfo(int newID, const std::string& newFirstName, const std::string& newLastName, bool paid, const std::multimap<Course, char>& courses);
	
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	void getName(std::string& newFirstName, std::string& newLastName);
	int getNumberOfCourses() const;
	int getUnitsCompleted() const;
	std::multimap<Course, char> getCoursesCompleted() const;

	bool isTuitionPaid() const;
	bool isCourseCompleted(const std::string& coursePrefix, int courseNumber) const;

	double calculateGPA() const;
	double billingAmount(double tuitionRate) const;
	
	void printStudent() const;
	void printStudentInfo(double tuitionRate);

	~Student() {}

private:
	int studentID;
	std::string firstName;
	std::string lastName;
	int numberOfCourses;
	bool tuitionWasPaid;
	std::multimap<Course, char> coursesCompleted;

};
#endif