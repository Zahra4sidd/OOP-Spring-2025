#include<iostream>
#include<string>
using namespace std;

class Laptop
{
    private:
    string brand;
    string model;
    string processor;
    int ram;
    int storage;

    public:
    void inputDetails()
    {
        cout<<"Laptop brand: ";
        getline(cin,brand);
        cout<<"Laptop model: ";
        getline(cin,model);
        cout<<"Processor type: ";
        getline(cin,processor);
        cout<<"RAM (GB): ";
        cin>>ram;
        cout<<"Storage (GB): ";
        cin>>storage;
        cin.ignore();
    }
    void turnOn()
    {
        cout<<"Turning ON...Laptop is now ON\n";
    }
    void turnOff()
    {
        cout<<"Turning OFF...Laptop is now OFF\n";
    }
    void runProgram(string program)
    {
        cout<<"Running program:"<<program<<endl;
    }
    void displaySpecs(string name)
    {
        cout << "\nLaptop Specifications for "<<name<<endl;
        cout << "Brand: "<<brand<<endl;
        cout << "Model: "<<model<<endl;
        cout << "Processor: "<<processor<<endl;
        cout << "RAM: " <<ram<<"GB"<<endl;
        cout << "Storage: "<<storage<<"GB"<<endl;
    }
};

int main()
{
    Laptop laptopAyesha,laptopBilal;
    cout<<"Enter details for Ayesha's laptop\n";
    laptopAyesha.inputDetails();
    laptopAyesha.turnOn();
    laptopAyesha.runProgram("Google Chrome");
    laptopAyesha.turnOff();
    cout<<"Enter details for Bilal's laptop\n";
    laptopBilal.inputDetails();
    laptopBilal.turnOn();
    laptopBilal.runProgram("Microsoft Word");
    laptopBilal.turnOff();

    laptopAyesha.displaySpecs("Ayesha");
    laptopBilal.displaySpecs("Bilal");
}
