#include <iostream>
#include <string>
using namespace std;

class User {
public:
    int userID;
    string name;
    double balance;
    bool isActive;

    User(int id, string n, double b) : userID(id), name(n), balance(b), isActive(false) {}

    virtual void payFees(double amount) = 0;

    void activateCard() {
        isActive = true;
        cout<<name<<"'s transport card activated.\n";
    }

    void displayInfo() {
        cout<<"ID: "<<userID<<" | Name: "<<name<<" | Status: " <<
        (isActive ? "Active" : "Inactive")<<endl;
    }
    bool getCardStatus() { return isActive; }
    string getName() { return name; }
};

class Student : public User {
public:
    Student(int id, string n, double b) : User(id, n, b) {}

    void payFees(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            activateCard();
        }
        else {
            cout<<"Insufficient balance for "<<name<<".\n";
        }
    }
};

class Teacher : public User {
public:
    Teacher(int id, string n, double b) : User(id, n, b) {}

    void payFees(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            activateCard();
        } 
        else {
            cout << "Insufficient balance for " << name << ".\n";
        }
    }
};

class Route {
public:
    string routeName;
    string stops[10];
    int numStops;

    Route(string n) : routeName(n), numStops(0) {}

    void addStop(string stop) {
        if (numStops < 10) {
            stops[numStops++] = stop;
            cout << "Added stop: " << stop << endl;
        } 
        else {
            cout << "Cannot add more stops!\n";
        }
    }
    void displayRoute() {
        cout << "Route: " << routeName << " | Stops: ";
        for (int i = 0; i < numStops; i++) {
            cout << stops[i] << " ";
        }
        cout << endl;
    }
    bool operator==(const Route& other) {
        if (routeName != other.routeName || numStops != other.numStops) return false;
        for (int i = 0; i < numStops; i++) {
            if (stops[i] != other.stops[i]) return false;
        }
        return true;
    }
};

class Bus {
public:
    int busID;
    Route* route;
    User* passengers[10];
    int numPassengers;

    Bus(int id, Route* r) : busID(id), route(r), numPassengers(0) {}

    void boardUser(User* user) {
        if (user->getCardStatus()) {
            passengers[numPassengers++] = user;
            cout<<user->getName()<<" has boarded bus "<<busID<<".\n";
        } 
        else {
            cout<<user->getName()<<"'s card is inactive. Cannot board!\n";
        }
    }
    void displayPassengers() {
        cout<<"Bus ID: "<<busID<<" | Passengers:\n";
        for (int i = 0; i < numPassengers; i++) {
            passengers[i]->displayInfo();
        }
    }
};

class TransportSystem {
private:
    User* users[50];
    Route* routes[5];
    Bus* buses[10];
    int userCount, routeCount, busCount;

public:
    TransportSystem() : userCount(0), routeCount(0), busCount(0) {}

    void registerUser(User* user) {
        if (userCount < 50) {
            users[userCount++] = user;
            cout<<user->getName()<<" registered.\n";
        } 
        else {
            cout<<"User limit reached!\n";
        }
    }
    void addRoute(Route* route) {
        if (routeCount < 5) {
            routes[routeCount++] = route;
            cout<<"Route added: "<<route->routeName<<endl;
        } 
        else {
            cout<<"Route limit reached!\n";
        }
    }
    void addBus(Bus* bus) {
        if (busCount < 10) {
            buses[busCount++] = bus;
            cout<<"Bus "<<bus->busID<<" assigned to "<<bus->route->routeName<<endl;
        } 
        else {
            cout<<"Bus limit reached!\n";
        }
    }
    void processPayment(int id, double amount) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->userID == id) {
                users[i]->payFees(amount);
                return;
            }
        }
        cout<<"User not found!\n";
    }
    void displayPassengers(int busID) {
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->busID == busID) {
                buses[i]->displayPassengers();
                return;
            }
        }
        cout<<"Bus not found!\n";
    }
};

int main() {
    TransportSystem system;
    Student s1(1, "John", 1000);
    Student s2(2, "Sara", 500);
    Teacher t1(3, "Mr. Smith", 2000);
    
    system.registerUser(&s1);
    system.registerUser(&s2);
    system.registerUser(&t1);
    system.processPayment(1, 500); 
    system.processPayment(3, 200);  

    Route r1("Route 1");
    r1.addStop("Stop A");
    r1.addStop("Stop B");

    Route r2("Route 2");
    r2.addStop("Stop X");
    r2.addStop("Stop Y");

    system.addRoute(&r1);
    system.addRoute(&r2);

    if (r1 == r2){
        cout<<"Routes are identical!\n";
    }
    else{
        cout<<"Routes are different!\n";
    }

    Bus b1(1001, &r1);
    system.addBus(&b1);
    b1.boardUser(&s1);
    b1.boardUser(&s2);
    b1.boardUser(&t1);
    system.displayPassengers(1001);
    return 0;
}
