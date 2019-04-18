#include "Student.hpp"
#include "Course.hpp"
using namespace std;
namespace BrooklynPoly{
    ostream& operator<<(ostream& os, const Student& aStudent){
        os << aStudent.name << endl;
        os << "Courses Enrolled In:" << endl;
        if (aStudent.courses.size() == 0 ){ os << "\t" << "NONE"<< endl; }
        else {
            for (int i = 0; i < aStudent.courses.size(); ++i) {
                os << "\t" << aStudent.courses[i]->getName() << endl;
            }
        }
        return os;
    }
    Student::Student(const string& name): name(name){}
    string Student::getName() const {return name;}
    void Student::addCourse(Course* aCourse) { courses.push_back(aCourse); }
    void Student::removeCourse(Course* aCourse) {
        for (size_t i = 0; i < courses.size(); i++ ){
            if (aCourse->getName() == courses[i]->getName()){
                courses[i] = courses[courses.size() - 1];
                courses.pop_back();
            }
        }
    }
}
