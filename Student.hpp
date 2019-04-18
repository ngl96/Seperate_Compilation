#ifndef REC07_STUDENT_H
#define REC07_STUDENT_H
#include "Course.hpp"
#include <string>
#include <iostream>
#include <vector>

namespace BrooklynPoly{
    class Course;
    class Student {
        friend std::ostream& operator<<(std::ostream& os, const Student& aStudent);
    public:
        Student(const std::string& name);
        std::string getName() const;
        void addCourse(Course* aCourse);
        void removeCourse(Course* aCourse);
    private:
        std::string name;
        std::vector<Course*> courses;
    };
}
#endif
