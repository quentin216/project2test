/*
	Chen, Quentin (team leader)
	Espejo, Alex
	Foroutan, Pantea

	Project: Grade Report
	CS A250
	Fall 2023
*/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include "Student.h"
// #include "AnyList.h"

class Node
{
public:
	Node() : studentData(), next(nullptr) {}
	Node(const Student& theData, Node* newNext)
		: studentData(theData), next(newNext) {}

	Node* getNext() const { return next; }
	Student getData() const { return studentData; }

	void setData(const Student& theData) { studentData = theData; }
	void setNext(Node* newNext)
	{
		next = newNext;
	}

	~Node() {}

private:
	Student studentData;
	Node* next;
};

class StudentList
{

public:
	StudentList() : first(nullptr), count(0) {}

	void addStudent(const Student& aStudent);

	int getNoOfStudents() const;

	void printStudentByID(int anID, double aTuitionRate) const;
	void printStudentByName(const std::string& aLastName) const;
	void printStudentByCourse(const std::string& aCoursePrefix, int aCourseNumber) const;
	void printAllStudents(double aTuitionRate) const;

	void clearStudentList();

	~StudentList();

private:
	Node* first;
	Node* last;
	int count;

};

#endif
