#include "Course.hpp"
#include "Student.hpp"
#include "Registrar.hpp"
using namespace std;

namespace BrooklynPoly{
    ostream& operator<<(ostream& os, const Registrar& aRegistrar){
        if (aRegistrar.students.size() == 0 && aRegistrar.courses.size() == 0){
            os << "Registrar is empty." << endl;
        }
        else {
            if (aRegistrar.courses.size() == 0) {
                os << "Course: " << endl;
                os << "\t" << "There are no courses." << endl;
            }
            else {
                for (Course *aCourse : aRegistrar.courses) {
                    os << "Course: " << endl;
                    os << "\t" << *aCourse << endl;
                }
            }
            if (aRegistrar.students.size() == 0){
                os << "Student: " << endl;
                os << "\t" << "There are no students" << endl;
            }
            else {
                for (Student *aStudent : aRegistrar.students) {
                    os << "Student: " << endl;
                    os << "\t" << *aStudent << endl;
                }
            }
        }
        return os;
    }
    bool Registrar::addCourse(const string& courseName){
        size_t courseIndex = findCourse(courseName);
        if (courses.size() == 0 || courses[courseIndex]->getName() != courseName ){
            Course* aCourse = new Course(courseName);
            courses.push_back(aCourse);
            return true;
        }
        return false;
    }
    bool Registrar::addStudent(const string& studentName){
        size_t studentIndex = findStudent(studentName);
        if (students.size() == 0 || students[studentIndex]->getName() != studentName ){
            Student* aStudent = new Student(studentName);
            students.push_back(aStudent);
            return true;
        }
        return false;
    }
    bool Registrar::enrollStudentInCourse(const string& studentName,const string& courseName) {
        size_t studentIndex = findStudent(studentName);
        size_t courseIndex = findCourse(courseName);
        if ( students[studentIndex]->getName() == studentName ){
            if ( courses[courseIndex]->getName() == courseName ){
                students[studentIndex]->addCourse(courses[courseIndex]);
                courses[courseIndex]->addStudent(students[studentIndex]);
                return true;
            }
        }
        return false;
    }
    bool Registrar::cancelCourse(const string& courseName){
        size_t courseIndex = findCourse(courseName);
        if (courses[courseIndex]->getName() == courseName){
            courses[courseIndex]->purge();
            delete courses[courseIndex];
            courses[courses.size() - 1] = courses[courseIndex];
            courses.pop_back();
            return true;
        }
        return false;
    }
    void Registrar::purge(){
        for (size_t i = 0; i < courses.size(); i++){
            courses[i]->purge();
            delete courses[i];
        }
        courses.clear();
        for (size_t i = 0; i < students.size(); i++){
            delete students[i];
        }
        students.clear();
    }
    
}
