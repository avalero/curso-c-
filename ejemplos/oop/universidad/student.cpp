#include "student.h"
#include <memory>

Student::Student()
{
}

Student::Student(string &name)
    : Person(name)
{
}

void Student::addCourse(shared_ptr<Course> course)
{

  // If the student is not already attending this course, add it to the student's courses
  for (auto studentCourse : courses)
  {
    if (course == studentCourse)
      return;
  }

  courses.push_back(course);
  course->addStudent(shared_from_this());
}

vector<shared_ptr<Course>> Student::getCourses() const
{
  return courses;
}

ostream &operator<<(ostream &os, Student const &s)
{
  os << s.getName() << endl;
  os << " attends:\n ";
  for (auto course : s.getCourses())
  {
    os << "\t- " << course->getName() << "\n";
  }
  return os;
}