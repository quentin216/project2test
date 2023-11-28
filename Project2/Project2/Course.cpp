/*
	Chen, Quentin (team leader)
	Espejo, Alex
	Foroutan, Pantea

	Project: Grade Report
	CS A250
	Fall 2023
*/

#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

void Course::setCourseInfo(const string& newCoursePrefix, 
	int newCourseNumber, int newCourseUnits)
{
	coursePrefix = newCoursePrefix;
	courseNumber = newCourseNumber;
	courseUnits = newCourseUnits;
}

string Course::getCoursePrefix() const
{
	return coursePrefix;
}

int Course::getCourseNumber() const
{
	return courseNumber;
}

int Course::getCourseUnits() const
{
	return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const 
{
	return courseUnits < otherCourse.courseUnits;
}
