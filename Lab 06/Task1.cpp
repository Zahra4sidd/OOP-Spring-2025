#include "iostream"
#include "string"
using namespace std;

class Employee
{
    protected:
    string name;
    float salary;

    public:
    Employee(string n,float s) : name(n),salary(s) {}
    void displayDetails()
    {
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee salary: "<<salary<<endl;
    }
};
class Manager : public Employee
{
    protected:
    float bonus;

    public:
    Manager(string n,float s,float b) : Employee(n,s),bonus(b) {}
    void displayDetails()
    {
        Employee::displayDetails();
        cout<<"Bonus: "<<bonus<<endl;
    }
};
int main()
{
    Manager HR("John Bernard",250000,10000);
    HR.displayDetails();
}
