#ifndef REC07_COURSE_H
#define REC07_COURSE_H
#include "Student.hpp"
#include <string>
#include <vector>

namespace BrooklynPoly {
    class Student;
    class Course {
        friend std::ostream &operator<<(std::ostream &os, const Course &aCourse);
        
    public:
        Course(const std::string &courseName);
        
        std::string getName() const;
        
        void addStudent(Student *aStudent);
        
        void purge();
        
    private:
        std::string name;
        std::vector<Student *> students;
    };
}
#endif
