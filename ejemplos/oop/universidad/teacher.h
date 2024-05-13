#ifndef TEACHER_H
#define TEACHER_H

#include <memory>
#include "person.h"
#include "course.h"

using namespace std;

class Course;

class Teacher : public Person, public enable_shared_from_this<Teacher>
{
public:
  Teacher();
  Teacher(string const &name);
  void addCourse(shared_ptr<Course> course);
  vector<shared_ptr<Course>> getCourses() const;

private:
  vector<shared_ptr<Course>> courses;
};

ostream &operator<<(ostream &os, Teacher const &t);

#endif // TEACHER_H
