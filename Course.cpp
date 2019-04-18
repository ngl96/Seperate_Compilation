#include "Course.hpp"
#include "Student.hpp"
using namespace std;

namespace BrooklynPoly {
    ostream &operator<<(ostream &os, const Course &aCourse) {
        os << aCourse.name << endl;
        os << "Students Enrolled:" << endl;
        if (aCourse.students.size() == 0) { os << "\t" << "NONE" << endl; }
        else {
            for (size_t i = 0; i < aCourse.students.size(); ++i) {
                os << aCourse.students[i]->getName() << endl;
            }
        }
        return os;
    }
    
    Course::Course(const string &courseName) : name(courseName) {}
    
    string Course::getName() const { return name; }
    
    void Course::addStudent(Student *aStudent) { students.push_back(aStudent); }
    
    void Course::purge() {
        for (size_t i = 0; i < students.size(); i++) {
            students[i]->removeCourse(this);
        }
        students.clear();
    }
}
