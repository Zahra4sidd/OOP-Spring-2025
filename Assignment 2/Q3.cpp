#include <iostream>
#include<string>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    float speed, capacity, energyEfficiency;
    static int totalDeliveries;

public:
    Vehicle(float s, float c, float e) : vehicleID(++totalDeliveries), speed(s), capacity(c), energyEfficiency(e) {}

    virtual void optimalDeliveryRoute() = 0;
    virtual void estimateDeliveryTime() = 0;
    virtual void command(string cmd, int packageID) = 0;
    virtual void command(string cmd, int packageID, string urgency) = 0;

    friend bool operator==(const Vehicle &v1, const Vehicle &v2);
    friend void AIConflictResolution(Vehicle &v1, Vehicle &v2);

    int getID()
    {
        return vehicleID;
    }
};
bool operator==(const Vehicle &v1, const Vehicle &v2)
{
    return (v1.vehicleID == v2.vehicleID && v1.speed == v2.speed && v1.capacity == v2.capacity && v1.energyEfficiency == v2.energyEfficiency);
}

void AIConflictResolution(Vehicle &v1, Vehicle &v2)
{
    if (v1 == v2) // No need for (v1 == v2) == 1
    {
        cout << "The Same Vehicle has been assigned the order twice!" << endl;
    }
    else
    {
        int ve1 = 0, ve2 = 0;
        if (v1.speed > v2.speed)
        {
            cout << "In terms of speed, Vehicle " << v1.vehicleID << " is better!" << endl;
            ve1++;
        }
        else
        {
            cout << "In terms of speed, Vehicle " << v2.vehicleID << " is better!" << endl;
            ve2++;
        }
        if (v1.capacity > v2.capacity)
        {
            cout << "In terms of capacity, Vehicle " << v1.vehicleID << " is better!" << endl;
            ve1++;
        }
        else
        {
            cout << "In terms of capacity, Vehicle " << v2.vehicleID << " is better!" << endl;
            ve2++;
        }
        if (v1.energyEfficiency > v2.energyEfficiency)
        {
            cout << "In terms of Energy Efficiency, Vehicle " << v1.vehicleID << " is better!" << endl;
            ve1++;
        }
        else
        {
            cout << "In terms of Energy Efficiency, Vehicle " << v2.vehicleID << " is better!" << endl;
            ve2++;
        }

        if (ve1 > ve2)
        {
            cout << "According to AI Conflict Resolution System, Vehicle " << v1.vehicleID << " is more suitable for executing the task!" << endl;
        }
        else
        {
            cout << "According to AI Conflict Resolution System, Vehicle " << v2.vehicleID << " is more suitable for executing the task!" << endl;
        }
    }
}

int Vehicle::totalDeliveries = 0;

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(float s, float c, float e) : Vehicle(s, c, e) {}

    void optimalDeliveryRoute() override
    {
        cout << "Calculating Optimal Aerial Route..." << endl;
    }

    void estimateDeliveryTime() override
    {
        cout << "Determining Estimated Delivery Time when using Aerial Route..." << endl;
    }

    void command(string cmd, int packageID) override
    {
        cout << "Vehicle " << vehicleID << " executing " << cmd << " for package " << packageID << " using Drone Mode!" << endl;
    }

    void command(string cmd, int packageID, string urgency) override
    {
        cout << "Vehicle " << vehicleID << " executing " << cmd << " for package " << packageID << " with Urgency: " << urgency << " using Drone Mode!" << endl;
        cout << "High-Speed Mode Activated!" << endl;
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(float s, float c, float e) : Vehicle(s, c, e) {}

    void optimalDeliveryRoute() override
    {
        cout << "Calculating Optimal Time-Travel Route..." << endl;
    }

    void estimateDeliveryTime() override
    {
        cout << "Determining Estimated Delivery Time when using Time-Travel..." << endl;
    }

    void command(string cmd, int packageID) override
    {
        cout << "Vehicle " << vehicleID << " executing " << cmd << " for package " << packageID << " using Time-Travel Mode!" << endl;
    }

    void command(string cmd, int packageID, string urgency) override
    {
        cout << "Requiring Validation... for Vehicle " << vehicleID << " to execute " << cmd << " for package " << packageID << " with Urgency: " << urgency << " using Time-Travel Mode!" << endl;
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    RamzanHyperPod(float s, float c, float e) : Vehicle(s, c, e) {}

    void optimalDeliveryRoute() override
    {
        cout << "Calculating Optimal Underground Transport Route..." << endl;
    }

    void estimateDeliveryTime() override
    {
        cout << "Determining Estimated Delivery Time when using Underground Transport Route..." << endl;
    }

    void command(string cmd, int packageID) override
    {
        cout << "Vehicle " << vehicleID << " executing " << cmd << " for package " << packageID << " using Underground Transport Mode!" << endl;
    }

    void command(string cmd, int packageID, string urgency) override
    {
        cout << "Vehicle " << vehicleID << " executing " << cmd << " for package " << packageID << " with Urgency: " << urgency << " using Hyper Pod Mode!" << endl;
        cout << "Navigating through an underground tunnel network!" << endl;
    }
};

int main()
{
    RamzanDrone d1(90, 20, 80);
    RamzanTimeShip t1(70, 50, 60);
    RamzanHyperPod r1(40, 100, 85);

    Vehicle *vehiclesArray[3];
    vehiclesArray[0] = &d1;
    vehiclesArray[1] = &t1;
    vehiclesArray[2] = &r1;

    cout << "Vehicle ID: " << vehiclesArray[0]->getID() << endl;
    vehiclesArray[0]->estimateDeliveryTime();
    vehiclesArray[0]->optimalDeliveryRoute();
    vehiclesArray[0]->command("Deliver", 100, "Iftaar");

    for (int i = 1; i < 3; i++)
    {
        cout << "Vehicle ID: " << vehiclesArray[i]->getID() << endl;
        vehiclesArray[i]->estimateDeliveryTime();
        vehiclesArray[i]->optimalDeliveryRoute();
        vehiclesArray[i]->command("Deliver", i + 200);
    }
    // Test AI Conflict Resolution
    cout << "\nTesting AI Conflict Resolution:" << endl;
    AIConflictResolution(d1, t1);
}
