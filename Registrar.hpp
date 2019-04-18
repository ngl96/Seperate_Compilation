#ifndef REC07_REGISTRAR_H
#define REC07_REGISTRAR_H
#include "Course.hpp"
#include "Student.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace BrooklynPoly{
    class Registrar {
        friend std::ostream& operator<<(std::ostream& os, const Registrar& aRegistrar);
    public:
        Registrar(){}
        bool addCourse(const std::string& courseName);
        bool addStudent(const std::string& studentName);
        bool enrollStudentInCourse(const std::string& studentName,const std::string& courseName);
        bool cancelCourse(const std::string& courseName);
        void purge();
    private:
        size_t findStudent(const std::string& aName) {
            for (size_t i = 0; i < students.size(); ++i) {
                if (aName == students[i]->getName()) {
                    return i;
                }
            }
            return students.size() - 1;
        }
        size_t findCourse(const std::string& aName) {
            for ( size_t i = 0; i < courses.size(); ++i ){
                if ( aName == courses[i]->getName() ){
                    return i;
                }
            }
            return courses.size() - 1;
        }
        std::vector<Course*> courses;
        std::vector<Student*> students;
    };
}
#endif
