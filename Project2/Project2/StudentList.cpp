/*
    Chen, Quentin (team leader)
    Espejo, Alex
    Foroutan, Pantea

    Project: Grade Report
    CS A250
    Fall 2023
*/

#include <iostream>
#include "StudentList.h"

using namespace std;

void StudentList::addStudent(const Student& aStudent)
{
    if (first == nullptr)
    {
        first = new Node(aStudent, nullptr);
        last = first;
    }
    else
    {
        last->setNext(new Node(aStudent, nullptr));
        last = last->getNext();
    }
    ++count;
}

int StudentList::getNoOfStudents() const
{
    return count;
}

void StudentList::printStudentByID(int anID, 
    double aTuitionRate) const
{
    Node* current = first;
    bool flag = false;

    while (current != nullptr && !flag)
    {
        flag = (current->getStudent().getID() == anID);
        if (!flag)
            current = current->getNext();
    }

    if (flag)
        current->getStudent().printStudentInfo(aTuitionRate);
    else
        cout << "NO students with ID " << anID 
        << " found in the list." << endl;
}

void StudentList::printStudentByName(const string& aLastName) const
{
    Node* current = first;
    bool flag = false;

    while (current != nullptr)
    {
        if (current->getStudent().getLastName() == aLastName) {
            current->getStudent().printStudent();
            flag = true;
        }
        current = current->getNext();
    }

    if (!flag)
        cout << "No students with ID last name " << aLastName
        << " is on the list." << endl;
}
void StudentList::printStudentByCourse(const string& aCoursePrefix, 
    int aCourseNumber) const
{
    Node* current = first;
    bool flag = false;
    while (current != nullptr) {
        if (current->getStudent().isCourseCompleted(aCoursePrefix, 
            aCourseNumber)) 
        {
            current->getStudent().printStudent();
            flag = true;
        }
        current = current->getNext();
    }

    if (!flag)
    {
        cout << "No students enrolled in " << aCoursePrefix
            << aCourseNumber << endl;
    }
}
void StudentList::printAllStudents(double aTuitionRate) const
{
    Node* current = first;
    while (current != nullptr) 
    {
        current->getStudent().printStudentInfo(aTuitionRate);
        current = current->getNext();
    }
}

void StudentList::clearStudentList()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;
    count = 0;
}

StudentList::~StudentList()
{
    if (first != nullptr)
        clearStudentList();
}