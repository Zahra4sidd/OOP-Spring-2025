#include "iostream"
#include "string"
using namespace std;

class Vehicle
{
    protected:
    string brand;
    int speed;
    public:
    Vehicle(string b,int s):brand(b),speed(s) {}
    void displayDetails()
    {
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};
class Car : public Vehicle
{
    public:
    int seats;
    Car(string b,int speed,int seats):Vehicle(b,speed),seats(seats) {}
    void displayDetails()
    {
        Vehicle::displayDetails();
        cout<<"Seats: "<<seats<<endl;
    }
};
class ElectricCar : public Car
{
    public:
    int batteryLife;
    ElectricCar(string b,int speed,int seats,int battery):
    Car(b,speed,seats),batteryLife(battery) {}
    void displayDetails()
    {
        Car::displayDetails();
        cout<<"Battery life: "<<batteryLife<<" hours"<<endl;
    }
};

int main()
{
    ElectricCar car("Tesla",350,6,20);
    car.displayDetails();
}
