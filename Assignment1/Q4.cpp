#include<iostream>
#include<string>
using namespace std;

class Student
{
    public:
    int studentID;
    string name;
    double balance;
    bool isActive;
    
    Student(int id, string n,double b) : studentID(id),name(n),balance(b),isActive(false){}

    void registerStudent()
    {
        cout<<"Student "<<name<<" (ID:"<<studentID<<") registered successfully\n";
    }
    void payFees(double fees)
    {
        if(balance >= fees)
        {
            balance -= fees;
            isActive = true;
            cout<<"Fees paid. Transport card activated for "<<name<<endl;
        }
        else
        {
            cout<<"Insufficient balance. Card not activated!\n";
        }
    }
    void displayStudent()
    {
        cout<<"Student ID: "<<studentID<<endl;
        cout<<"Student name: "<<name<<endl;
        if(isActive)
        {
            cout<<"Card status:Active\n";
        }
        else
        {
            cout<<"Card status:Inactive\n";
        }
    }
    bool getCardStatus()
    {
        return isActive;
    }
    string getName()
    {
        return name;
    }
};
class Route
{
    public:
    string routeName;
    string stops[10];
    int numStops;

    Route(string n) : routeName(n),numStops(0) {}
    void addStop(string stop)
    {
        if(numStops<10)
        {
            stops[numStops] = stop;
            numStops++;
            cout<<"Added stop:"<<stop<<endl;
        }
        else
        {
            cout<<"Cannot add more stops\n";
        }
    }
    void displayRoute()
    {
        cout<<"Route name:"<<routeName<<endl;
        cout<<"Stops:\n";
        for(int i=0;i<numStops;i++)
        {
            cout<<stops[i]<<" ";
        }
        cout<<endl;
    }
    string getRouteName()
    {
        return routeName;
    }
};
class Bus
{
    public:
    int busID;
    Route *route;
    Student *attendance[10];
    int numStudents;

    Bus(int id,Route *r) : busID(id),route(r),numStudents(0) {}
    void recordAttendance(Student *student)
    {
        if(student->getCardStatus())
        {
            attendance[numStudents] = student;
            numStudents++;
            cout<<student->getName()<<" has tapped in.Attendance recorded!\n";
        }
        else
        {
            cout<<student->getName()<<"'s card is inactive.Unpaid fees!\n";
        }
    }
    void displayAttendance()
    {
        cout<<"Bus ID:"<<busID<<" Attendance\n";
        for(int i=0;i<numStudents;i++)
        {
            attendance[i]->displayStudent();
        }
    }
    int getBusId()
    {
        return busID;
    }
};
class TransportSystem
{
    private:
    Student *students[50];
    Route *routes[5];
    Bus *buses[10];
    int studentCount;
    int routeCount;
    int busCount;

    public:
    TransportSystem() : studentCount(0),routeCount(0), busCount(0) {}

    void registerStudent(Student *student)
    {
        if(studentCount<50)
        {
            students[studentCount] = student;
            studentCount++;
            cout<<student->getName()<<" has been registered\n";
        }
        else
        {
            cout<<"Student capacity reached!\n";
        }
    }
    void addRoute(Route *route)
    {
        if(routeCount<5)
        {
            routes[routeCount] = route;
            routeCount++;
            cout<<route->getRouteName()<<" added\n";
        }
        else
        {
            cout<<"Route capacity reached\n";
        }
    }
    void addBus(Bus *bus)
    {
        if(busCount<10)
        {
            buses[busCount] = bus;
            busCount++;
            cout<<"Bus "<<bus->getBusId()<<" assigned to route:"<<bus->route->getRouteName()<<endl;
        }
        else
        {
            cout<<"Bus capacity reached\n";
        }
    }
    void processPayment(int studentId,float fees)
    {
        for(int i=0;i<studentCount;i++)
        {
            if(students[i]->studentID == studentId)
            {
                students[i]->payFees(fees);
                return;
            }
        }
        cout<<"Student not found!\n";
    }
    void displayAttendance(int busId)
    {
        for(int i=0;i<busCount;i++)
        {
            if(buses[i]->getBusId() == busId)
            {
                buses[i]->displayAttendance();
                return;
            }
        }
        cout<<"Bus not found\n";
    }
};

int main()
{
    TransportSystem system;
    Student s1(1,"John",1000.0); //id,name,balance
    Student s2(2,"Sara",4500.0);
    system.registerStudent(&s1);
    system.registerStudent(&s2);
    system.processPayment(1,500.0); //fees cost
    system.processPayment(2,500.0);
    Route r1("Route 1");
    r1.addStop("Stop A");
    r1.addStop("Stop B");
    Bus b1(1001,&r1);
    system.addBus(&b1);
    b1.recordAttendance(&s1);
    b1.recordAttendance(&s2);
    system.displayAttendance(1001);

    return 0;
}
