#include <iostream>
#include <cstring>
using namespace std;

class Person{
    protected:
    string name;
    int id;
    string address;
    int phoneNumber;
    string email;
    public:
    Person(string n,int id,string a,int num,string e):
    name(n),id(id),address(a),phoneNumber(num),email(e){}
    virtual void displayInfo()
    {
        cout<<"Name: "<<name<<"\nID: "<<id<<"\nAddress: "<<address
        <<"\nPhone: "<<phoneNumber<<"\nEmail: "<<email<<endl;
    }
};
class Student : public Person{
    private:
    string coursesEnrolled[3];
    float gpa;
    int enrollYear;
    public:
    Student(string n,int id,string a,int num,string e,string courses[],float gpa,int year):
    Person(n,id,a,num,e),gpa(gpa),enrollYear(year){
        for(int i=0;i<3;i++){
            coursesEnrolled[i] = courses[i];
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout<<"GPA: "<<gpa<<"\nEnrollment Year: "<<enrollYear<<"\nCourses Enrolled: ";
        for(int i=0;i<3;i++){
            cout<<coursesEnrolled[i]<<(i<2 ? ", ": "\n");
        }
    }
};
class Professor : public Person{
    private:
    string dept;
    string courseTaught[2];
    float salary;
    public:
    Professor(string n,int id,string a,int num,string e,string dept,string courses[],float s):
    Person(n,id,a,num,e),dept(dept),salary(s){
        for(int i=0;i<2;i++)
        {
            courseTaught[i] = courses[i];
        }
    }
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Department: "<<dept<<"\nSalary: $"<<salary<<"\nCourses Taught: ";
        for(int i=0;i<2;i++){
            cout<<courseTaught[i]<<(i<1 ? ", ": "\n");
        }
    }
};
class Staff : public Person{
    private:
    string dept,position;
    float salary;
    public:
    Staff(string n,int id,string a,int num,string e,string dept,string p,float s):
    Person(n,id,a,num,e),dept(dept),position(p),salary(s){}
    void displayInfo() override{
        Person::displayInfo();
        cout<<"Department: "<<dept<<"\nPosition: "<<position<<"\nSalary: $"<<salary<<endl;
    }
};
class Course{
    private:
    int credits;
    string courseName, instructor, schedule,courseId;
    string studentsRegistered[5];
    public:
    Course(string id,string name,string instr,int cred,string sched):
    courseId(id),courseName(name),instructor(instr),credits(cred),schedule(sched){
        for(int i=0;i<5;i++){
            studentsRegistered[i] = "";
        }
    }
    void registerStudent(string sName)
    {
        for(int i=0;i<5;i++)
        {
            if(studentsRegistered[i] == ""){
                studentsRegistered[i] = sName;
                cout<<sName<<" has been registered in "<<courseName<<endl;
                return;
            }
        }
        cout<<"Course is full, cannot register "<<sName<<endl;
    }
    void displayCourse() {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nInstructor: " << instructor << "\nCredits: " << credits
             << "\nSchedule: " << schedule << "\nStudents Enrolled: ";
        for (int i = 0; i < 5; i++) {
            if (studentsRegistered[i] != "")
                cout << studentsRegistered[i] << (i < 4 ? ", " : "\n");
        }
    }
};
int main() {
    string stuCourses[] = {"Math", "Physics", "History"};
    Student s1("Alice", 1576, "123 Main St", 5556789, "alice@email.com", stuCourses, 3.8, 2022);

    string profCourses[] = {"Physics", "Quantum Mechanics"};
    Professor p1("Dr. Smith", 9834, "456 Elm St", 5551234, "smith@univ.edu", "Physics Dept", profCourses, 75000);

    Staff staff1("Mr. Brown",9387, "789 Oak St", 5559876, "brown@univ.edu", "Admin Dept", "HR Manager", 50000);

    Course c1("CS101", "Computer Science", "Dr. Smith", 4, "10:00-11:30");

    cout<<"Student Info\n";
    s1.displayInfo();
    cout <<"Professor Info\n";
    p1.displayInfo();
    cout<<"Staff Info\n";
    staff1.displayInfo();
    cout <<"Course Registration\n";
    c1.registerStudent("Alice");
    c1.registerStudent("Bob");
    c1.displayCourse();
    return 0;
}
