#include "iostream"
#include "string"
using namespace std;

class Person
{
    protected:
    string name;
    int age;
    public:
    Person(string name,int age) : name(name),age(age) {}
    void displayDetails()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class Teacher : public Person
{
    protected:
    string subject;
    public:
    Teacher(string name,int age,string subject):
    Person(name,age),subject(subject) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout<<"Subject: "<<subject<<endl;
    }
};
class Researcher : public Teacher
{
    protected:
    string researchArea;
    public:
    Researcher(string name,int age,string subject,string area):
    Teacher(name,age,subject),researchArea(area) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout<<"Research Area: "<<researchArea<<endl;
    }
};
class Professor : public Researcher
{
    protected:
    int publications;
    public:
    Professor(string name,int age,string subject,string area,int p):
    Researcher(name,age,subject,area),publications(p) {}
    void displayDetails()
    {
        Researcher::displayDetails();
        cout<<"Publications: "<<publications<<endl;
    }
};
int main()
{
    Professor Uni("James",35,"Calculus 2","Mathematics",8);
    Uni.displayDetails();
}
