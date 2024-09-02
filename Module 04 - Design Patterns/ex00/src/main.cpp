#include "enums/Event.hpp"
#include "enums/FormType.hpp"
#include "room/Room.hpp"
#include "room/ClassRoom.hpp"
#include "room/StaffRestRoom.hpp"
#include "room/SecretarialOffice.hpp"
#include "person/Person.hpp"
#include "person/staff/Headmaster.hpp"
#include "person/staff/Professor.hpp"
#include "person/Student.hpp"
#include "form/Form.hpp"
#include "Course.hpp"
#include <iostream>
#include <vector>
#include <assert.h>

#define PRINT_GREEN(x) std::cout << "\033[1;32m" << x << "\033[0m" << std::endl;

void testRoomCreation()
{
    Room *classRoom = new ClassRoom(50);
    Room *staffRestRoom = new StaffRestRoom(20);
    Room *secretarialOffice = new SecretarialOffice(20);

    assert(classRoom->getMaxOccupants() == 50);
    assert(staffRestRoom->getMaxOccupants() == 20);
    assert(secretarialOffice->getMaxOccupants() == 20);

    delete classRoom;
    delete staffRestRoom;
    delete secretarialOffice;

    std::cout << "Rooms creation test passed" << std::endl;
}

void testPersonCreation()
{
    Person *headmaster = new Headmaster("Dumbledore");
    Person *professor = new Professor("McGonagall");
    Person *student = new Student("Harry Potter");

    assert(headmaster->getName() == "Dumbledore");
    assert(professor->getName() == "McGonagall");
    assert(student->getName() == "Harry Potter");

    delete headmaster;
    delete professor;
    delete student;

    std::cout << "Person creation test passed" << std::endl;
}

void testCourseCreation()
{
    Course *course = new Course("Transfiguration");

    assert(course->getName() == "Transfiguration");

    delete course;

    PRINT_GREEN("Course creation test passed");
}

void testStudentAttendingClass()
{
    ClassRoom *classRoom = new ClassRoom(50);
    Course *course = new Course("Transfiguration");
    Professor *professor = new Professor("McGonagall");
    Student *student = new Student("Harry Potter");

    classRoom->assignCourse(course);
    professor->assignCourse(course);
    student->subscribe(course);
    student->attendClass(classRoom);

    assert(student->getSubscribedCourses().size() == 1);
    assert(student->getSubscribedCourses()[0] == course);

    delete classRoom;
    delete course;
    delete professor;
    delete student;

    PRINT_GREEN("Student attending class test passed");
}

void testStudentGraduating()
{
    Course *course = new Course("Transfiguration");
    Student *student = new Student("Harry Potter");

    student->subscribe(course);
    student->graduate(course);

    assert(student->getSubscribedCourses().size() == 0);

    delete course;
    delete student;

    PRINT_GREEN("Student graduating test passed");
}

void testFormCreation()
{
    Form *form = new Form(FormType::NeedMoreClassRoom);

    assert(form->getFormType() == FormType::NeedMoreClassRoom);

    delete form;

    PRINT_GREEN("Form creation test passed");
}



int main()
{
    testRoomCreation();
    testPersonCreation();
    testCourseCreation();
    testStudentAttendingClass();
    testStudentGraduating();
}