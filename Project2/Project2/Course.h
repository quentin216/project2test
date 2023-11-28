/*
	Chen, Quentin (team leader)
	Espejo, Alex
	Foroutan, Pantea

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
	Course() : coursePrefix("N/A"), courseNumber(0), 
		courseUnits(0) {}
	/* Course(const std::string& prefix, int courseNum, 
	int numOfUnits) : coursePrefix(prefix), 
	courseNumber(courseNum), courseUnits(numOfUnits) {} */

	void setCourseInfo(const std::string& newCoursePrefix, int newCourseNumber, int newCourseUnits);
	
	std::string getCoursePrefix() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	bool operator<(const Course& other) const;

	~Course() {}

private:
	std::string coursePrefix;
	int courseNumber;
	int courseUnits;

};
#endif