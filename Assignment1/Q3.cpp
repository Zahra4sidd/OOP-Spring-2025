#include<iostream>
#include<string>
using namespace std;

class User
{
    private:
    string name;
    int age;
    string licenseType;
    string contactInfo;
    int userID;

    public:
    User(string n, int a, string license, string contact, int userId)
    : name(n), age(a), licenseType(license), contactInfo(contact), userID(userId) {}
    
    void updateDetails(string newName, int newAge, string newLicenseType)
    {
        name = newName;
        age = newAge;
        licenseType = newLicenseType;
    }
    int getUserID()
    {
        return userID;
    }
    string getLicenseType()
    {
        return licenseType;
    }
};
class Vehicle
{
    private:
    string model;
    float rentalPrice;
    string eligibilityLicenseType;

    public:
    Vehicle(string model, float rentalPrice, string eligibilityLicenseType)
    : model(model), rentalPrice(rentalPrice), eligibilityLicenseType(eligibilityLicenseType) {}

    void displayDetails()
    {
        cout<<"Model: "<<model<<endl;
        cout<<"Rental Price (Per Day): "<<rentalPrice<<endl;
        cout<<"Eligibility License Type: "<<eligibilityLicenseType<<endl;
    }
    string getModel()
    {
        return model;
    }
    string getEligibility()
    {
        return eligibilityLicenseType;
    }
    float getPrice()
    {
        return rentalPrice;
    }
};
class RentalSystem
{
    private:
    User **users;
    Vehicle **vehicles;
    int userCount;
    int vehicleCount;
    int userCapacity;
    int vehicleCapacity;

    public:
    RentalSystem(int userCapacity, int vehicleCapacity) : userCapacity(userCapacity), vehicleCapacity(vehicleCapacity)
    {
        users = new User*[userCapacity];
        vehicles = new Vehicle*[vehicleCapacity];
        userCount = 0;
        vehicleCount = 0;
    }
    ~RentalSystem() //destructor
    { 
        for (int i=0;i<userCount;i++) 
        {
            delete users[i];
        }
        delete[] users;
        for (int i=0;i<vehicleCount;i++) 
        {
            delete vehicles[i];
        }
        delete[] vehicles;
    }
    void addUser(string name, int age, string licenseType,string contactInfo,int userID)
    {
        if(userCount<userCapacity)
        {
            users[userCount] = new User(name,age,licenseType,contactInfo,userID);
            userCount++;
            cout<<"User "<<userCount<<" registered successfully\n";
        }
        else
        {
            cout<<"Cannot register more users! capacity reached\n";
        }
    }
    void updateUser(int ID,string newName, int newAge, string newLicenseType)
    {
        for(int i=0;i<userCount;i++)
        {
            if(users[i]->getUserID() == ID)
            {
                users[i]->updateDetails(newName,newAge,newLicenseType);
                cout<<"User details updated successfully\n";
                return;
            }
        }
        cout<<"User not found\n";
    }
    void addVehicle(string model,float rentalPrice, string eligibilityLicenseType)
    {
        if(vehicleCount<vehicleCapacity)
        {
            vehicles[vehicleCount] = new Vehicle(model,rentalPrice,eligibilityLicenseType);
            vehicleCount++;
            cout<<"Vehicle "<<vehicleCount<<" added successfully\n";
        }
        else
        {
            cout<<"Cannot add more vehicles!capacity reached\n";
        }
    }
    void displayVehicles()
    {
        cout<<"Available vehicles\n";
        for(int i=0;i<vehicleCount;i++)
        {
            vehicles[i]->displayDetails();
        }
    }
    void rent(int id,string model)
    {
        User* user = nullptr;
        Vehicle* vehicle = nullptr;
        for(int i=0;i<userCount;i++)
        {
            if(id==users[i]->getUserID())
            {
                user = users[i];
                break;
            }
        }
        if(!user)
        {
            cout<<"User not found\n";
            return;
        }
        for(int i=0;i<vehicleCount;i++)
        {
            if(model==vehicles[i]->getModel())
            {
                vehicle = vehicles[i];
                break;
            }
        }
        if(!vehicle)
        {
            cout<<"Vehicle not found\n";
            return;
        }
        if(user->getLicenseType() == vehicle->getEligibility())
        {
            cout<<"Rental successful!\n";
            cout<<"User: "<<user->getUserID()<<" has rented the vehicle: "<<vehicle->getModel()<<endl;
            cout<<"Rental Price(Per Day): "<<vehicle->getPrice()<<endl;
        }
        else
        {
            cout<<"User is not eligible to rent this vehicle\n";
        }
    }
};

int main()
{
    RentalSystem rental(10, 10); //capacity of users and vehicles
    rental.addUser("Sarah",21,"Full","sarah@gmail.com",102);
    rental.addUser("John",18,"Learner","john@gmail.com",508);
    rental.addVehicle("Elantra",65.0,"Full");
    rental.addVehicle("Civic",68.0,"Intermediate");
    rental.displayVehicles();
    rental.rent(102,"Elantra"); //eligible
    rental.rent(508,"Civic"); //not eligible
    rental.updateUser(508,"John",19,"Intermediate");
    return 0;
}
