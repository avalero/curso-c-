#ifndef STUDENT_H
#define STUDENT_H

#include <memory>
#include <vector>
#include "person.h"
#include "course.h"

using namespace std;

class Course;

class Student : public Person, public enable_shared_from_this<Student>
{
public:
  Student();
  Student(string const &name);

  void addCourse(shared_ptr<Course> course);
  vector<shared_ptr<Course>> getCourses() const;

private:
  vector<shared_ptr<Course>> courses;
};

ostream &operator<<(ostream &os, Student const &s);

#endif // STUDENT_H