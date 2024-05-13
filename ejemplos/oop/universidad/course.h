#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "student.h"
#include "teacher.h"
#include <memory>
#include <vector>

using namespace std;

class Student;
class Teacher;

class Course : public enable_shared_from_this<Course>
{
public:
  Course();
  Course(string const &name);
  string getName() const;
  void setName(string const &name);
  void addStudent(shared_ptr<Student> student);
  void setTeacher(shared_ptr<Teacher> teacher);
  vector<shared_ptr<Student>> getStudents() const;
  shared_ptr<Teacher> getTeacher() const;

private:
  string name;
  vector<shared_ptr<Student>> students;
  shared_ptr<Teacher> teacher;
};

ostream &operator<<(ostream &os, Course const &c);

#endif // COURSE_H