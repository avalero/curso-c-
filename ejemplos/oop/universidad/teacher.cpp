#include "teacher.h"

Teacher::Teacher() : Person()
{
}

Teacher::Teacher(string &name)
    : Person(name)
{
}

void Teacher::addCourse(shared_ptr<Course> course)
{
  // If the teacher is not already teaching this course, add it to the teacher's courses
  for (auto teacherCourse : courses)
  {
    if (course == teacherCourse)
      return;
  }
  courses.push_back(course);

  // If the course is not already taught by this teacher, set the teacher of the course to this teacher
  if (course->getTeacher() != shared_from_this())
    course->setTeacher(shared_from_this());
}

vector<shared_ptr<Course>> Teacher::getCourses() const
{
  return courses;
}

ostream &operator<<(ostream &os, Teacher const &t)
{
  os << t.getName() << endl;
  os << " teaches: ";
  for (auto course : t.getCourses())
  {
    os << "\t- " << course->getName() << "\n";
  }
  return os;
}