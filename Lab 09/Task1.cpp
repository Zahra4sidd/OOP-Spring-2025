#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
    string model;
    double rate;
    public:
    Vehicle(string m,double r):model(m),rate(r){}
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
};
class Car : public Vehicle{
    public:
    Car(string m, double r):Vehicle(m,r){}
    double getDailyRate(){
        return rate;
    }
    void displayDetails(){
        cout<<"Car Deatils:\n";
        cout<<"Model: "<<model<<endl;
        cout<<"Rate:$"<<rate<<endl; 
    }
};
class Bike : public Vehicle{
    public:
    Bike(string m, double r):Vehicle(m,r){}
    double getDailyRate(){
        return rate;
    }
    void displayDetails(){
         cout<<"Bike Deatils:\n";
        cout<<"Model: "<<model<<endl;
        cout<<"Rate:$"<<rate<<endl; 
    }
};
int main(){
    Car c1("BMW i5",400);
    Bike b1("Yamaha YBR",35);
    c1.displayDetails();
    b1.displayDetails();
    cout<<"Daily rate for the BMW i5:$"<<c1.getDailyRate()<<endl;
    return 0;
}
