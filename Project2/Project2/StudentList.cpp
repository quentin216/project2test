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

void StudentList::addStudent(const Student& aStudent) {
    if (first == nullptr) {
        first = new Node(aStudent, nullptr);
        last = first;
    }
    else {
        last->setNext(new Node(aStudent, nullptr));
        last = last->getNext();
    }
    ++count;
}

int StudentList::getNoOfStudents() const {
    return count;
}

void StudentList::printStudentByID(int anID, double aTuitionRate) const {
    Node* current = first;
    bool flag = false;
    while (current != nullptr && !flag) {
        flag = (current->getData().getID() == anID);
        //  Student me = current->getData();
        //  cout << me.getFirstName() << " " << me.getID() << " " << flag << endl;
        if (!flag) {
            current = current->getNext();
        }

    }
    if (flag) {
        current->getData().printStudentInfo(aTuitionRate);
    }
    else {
        cout << "NO students with ID " << anID << " found in the list." << endl;
    }
}

void StudentList::printStudentByName(const std::string& aLastName) const {
    Node* current = first;
    bool flag = false;
    while (current != nullptr && !flag) {
        flag = (current->getData().getLastName() == aLastName);
        if (!flag)
            current = current->getNext();
    }
    if (flag) {
        current->getData().printStudent();
    }
    else {
        cout << "No students with ID last name " << aLastName << " is on the list." << endl;
    }
}
void StudentList::printStudentByCourse(const std::string& aCoursePrefix, int aCourseNumber) const {
    Node* current = first;
    while (current != nullptr) {
        if (current->getData().isCourseCompleted(aCoursePrefix, aCourseNumber)) {
            current->getData().printStudent();
        }
        current = current->getNext();
    }

}
void StudentList::printAllStudents(double aTuitionRate) const {
    Node* current = first;
    while (current != nullptr) {
        current->getData().printStudentInfo(aTuitionRate);
        current = current->getNext();
    }
}

void StudentList::clearStudentList() {
    Node* temp = first;
    while (first != nullptr) {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;
    count = 0;
}

StudentList::~StudentList() {
    if (first != nullptr)
        clearStudentList();
}