#include <gtest/gtest.h>
#include "../course.h"
#include "../student.h"
#include "../teacher.h"

class Teacher;
class Student;
class Course;

class CourseTest : public ::testing::Test
{
protected:
  shared_ptr<Course> course;

  void SetUp() override
  {
    course = make_shared<Course>(Course{"Biology"});
  }
};

TEST_F(CourseTest, CheckName)
{
  EXPECT_EQ("Biology", course->getName());
}

TEST_F(CourseTest, AddStudent)
{
  auto student = make_shared<Student>(Student{"Alice Johnson"});
  course->addStudent(student);
  EXPECT_EQ(1, course->getStudents().size());
  EXPECT_EQ("Alice Johnson", course->getStudents()[0]->getName());
}

TEST_F(CourseTest, SetTeacher)
{
  auto teacher = make_shared<Teacher>("Robert Lang");
  course->setTeacher(teacher);
  EXPECT_EQ("Robert Lang", course->getTeacher()->getName());
}

// Additional tests can be added as necessary.
