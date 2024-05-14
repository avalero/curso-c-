#include <gtest/gtest.h>
#include "../teacher.h"
#include "../course.h"

class Course;
class Teacher;

class TeacherTest : public ::testing::Test
{
protected:
  shared_ptr<Teacher> teacher;

  void SetUp() override
  {
    teacher = make_shared<Teacher>(Teacher{"Jane Smith"});
  }
};

TEST_F(TeacherTest, CheckName)
{
  EXPECT_EQ("Jane Smith", teacher->getName());
}

TEST_F(TeacherTest, AddCourse)
{
  auto course = make_shared<Course>(Course{"Physics"});
  teacher->addCourse(course);
  EXPECT_EQ(1, teacher->getCourses().size());
  EXPECT_EQ("Physics", teacher->getCourses()[0]->getName());
}
