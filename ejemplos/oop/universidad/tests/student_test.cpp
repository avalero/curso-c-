#include <gtest/gtest.h>
#include "../student.h"
#include "../course.h"

class Course;
class Student;

class StudentTest : public ::testing::Test
{
protected:
  shared_ptr<Student> student;

  void SetUp() override
  {
    student = make_shared<Student>(Student{"John Doe"});
  }
};

TEST_F(StudentTest, CheckName)
{
  EXPECT_EQ("John Doe", student->getName());
}

TEST_F(StudentTest, AddCourse)
{
  auto course = make_shared<Course>(Course{"Mathematics"});
  student->addCourse(course);
  EXPECT_EQ(1, student->getCourses().size());
  EXPECT_EQ("Mathematics", student->getCourses()[0]->getName());
}
