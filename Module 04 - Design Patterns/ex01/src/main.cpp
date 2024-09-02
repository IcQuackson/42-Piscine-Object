#include "singletons.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include "Course.hpp"
#include "room/Room.hpp"
#include "person/staff/Staff.hpp"
#include "person/Student.hpp"


void printGreen(const char *message)
{
    std::cout << "\033[1;32m" << message << "\033[0m" << std::endl;
}

void testGetInstance()
{
    std::cout << "testGetInstance" << std::endl;
    ListSingleton<int> *list = ListSingleton<int>::getInstance();
    assert(list != nullptr);
    printGreen("Passed");
}

void testGetItem()
{
    std::cout << "testGetItem" << std::endl;
    ListSingleton<int> *list = ListSingleton<int>::getInstance();
    int *item = new int(1);
    list->add(item);
    assert(list->get(item) == item);

    printGreen("Passed");
}

void testRemove()
{
    std::cout << "testRemove" << std::endl;
    ListSingleton<int> *list = ListSingleton<int>::getInstance();
    int *item = new int(1);
    list->add(item);
    assert(list->remove(item) == true);

    printGreen("Passed");
}

void testClear()
{
    std::cout << "testClear" << std::endl;
    ListSingleton<int> *list = ListSingleton<int>::getInstance();
    int *item = new int(1);
    list->add(item);
    list->clear();
    assert(list->remove(item) == false);

    printGreen("Passed");
}

void testPrint()
{
    std::cout << "testPrint" << std::endl;

    ListSingleton<int> *list = ListSingleton<int>::getInstance();
    int *item = new int(1);
    list->add(item);
    list->print();

    printGreen("Passed");
}

void testCreateObjects()
{
    std::cout << "testCreateObjects" << std::endl;

    ListSingleton<Student> *studentList = ListSingleton<Student>::getInstance();
    ListSingleton<Staff> *staffList = ListSingleton<Staff>::getInstance();
    ListSingleton<Course> *courseList = ListSingleton<Course>::getInstance();
    ListSingleton<Room> *roomList = ListSingleton<Room>::getInstance();
    assert(studentList != nullptr);
    assert(staffList != nullptr);
    assert(courseList != nullptr);
    assert(roomList != nullptr);
    printGreen("Passed");
}

void testAddObjects() {
    std::cout << "testAddObjects" << std::endl;
    ListSingleton<Student> *studentList = ListSingleton<Student>::getInstance();
    ListSingleton<Staff> *staffList = ListSingleton<Staff>::getInstance();
    ListSingleton<Course> *courseList = ListSingleton<Course>::getInstance();
    ListSingleton<Room> *roomList = ListSingleton<Room>::getInstance();

    Student *student1 = new Student("student1");
    Staff *staff1 = new Staff("staff1");
    Course *course1 = new Course("course1");
    Room *room1 = new Room(1);

    studentList->add(student1);
    staffList->add(staff1);
    courseList->add(course1);
    roomList->add(room1);

    assert(studentList->remove(student1) == true);
    assert(staffList->remove(staff1) == true);
    assert(courseList->remove(course1) == true);
    assert(roomList->remove(room1) == true);

    printGreen("Passed");
}

int main()
{
    testGetInstance();
    testGetItem();
    testRemove();
    testClear();
    testPrint();
    testCreateObjects();
    testAddObjects();
    return 0;
}