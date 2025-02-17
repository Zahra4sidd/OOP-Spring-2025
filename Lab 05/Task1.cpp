#include <iostream>
#include <string>
using namespace std;

class Car
{
    private:
    int registrationNum;
    string model;
    string ownerName;

    public:
    Car(int r,string m,string o)
    {
        registrationNum = r;
        model = m;
        ownerName = o;
    }
    Car(const Car &obj,string newOwner) //shallow copy
    {
        registrationNum = obj.registrationNum;
        model = obj.model;
        ownerName = newOwner;
    }
    void displayDetails()
    {
        cout<<"Registration number: "<<registrationNum<<endl;
        cout<<"Car model: "<<model<<endl;
        cout<<"Car owner: "<<ownerName<<endl;
    }
};

int main()
{
    Car c1(1234,"i8","Sara");
    cout<<"Original Car details\n";
    c1.displayDetails();
    Car c2(c1,"John");
    cout<<"New Car details after rental\n";
    c2.displayDetails();
}
