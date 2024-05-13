#include "course.h"

Course::Course()
{
}

Course::Course(string const &name)
    : name(name)
{
}

string Course::getName() const
{
  return name;
}

void Course::addStudent(shared_ptr<Student> student)
{
  // if the course does not have yet the student
  for (auto studentCourse : students)
  {
    if (student == studentCourse)
      return;
  }

  students.push_back(student);
  student->addCourse(shared_from_this());
}

void Course::setTeacher(shared_ptr<Teacher> teacher)
{
  this->teacher = teacher;
  teacher->addCourse(shared_from_this());
}

vector<shared_ptr<Student>> Course::getStudents() const
{
  return students;
}

shared_ptr<Teacher> Course::getTeacher() const
{
  return teacher;
}

ostream &operator<<(ostream &os, Course const &c)
{
  os << c.getName() << endl;
  os << "Students:" << endl;
  for (auto student : c.getStudents())
  {
    os << "\t- " << student->getName() << "\n";
  }
  os << "Teacher:" << endl;
  if (auto teacher = c.getTeacher())
  {
    os << "\t- " << teacher->getName() << "\n";
  }
  return os;
}