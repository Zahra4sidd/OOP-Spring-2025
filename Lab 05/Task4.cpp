#include<iostream>
#include<string>
using namespace std;

class Battery
{
    private:
    int capacity;

    public:
    Battery(int c) : capacity(c){}
    void display()
    {
        cout<<"Battery Capacity: "<<capacity<<" mAh"<<endl;
    }
};
class Smartphone
{
    private:
    string model;
    Battery battery;

    public:
    Smartphone(string m, int batteryCapacity) : model(m), battery(batteryCapacity){}
    void display()
    {
        cout<<"Smartphone Model: "<<model<<endl;
        battery.display();
    }
};

int main()
{
    Smartphone s1("Model X",4000);
    Smartphone s2("Model Y",5000);
    s1.display();
    s2.display();

    return 0;
}
