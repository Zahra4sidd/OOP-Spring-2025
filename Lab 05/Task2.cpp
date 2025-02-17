#include <iostream>
#include <string>
using namespace std;

class Patient
{
    private:
    int ID;
    string name;
    int *testResults;

    public:
    Patient(int id,string n,int *results)
    {
        ID = id;
        name = n;
        testResults = new int(5);
        for(int i=0;i<5;i++)
        {
            testResults[i] = results[i];
        }
    }
    Patient(Patient &obj) //deep copy
    {
        ID = obj.ID;
        name = obj.name;
        testResults = new int (5);
        for(int i=0;i<5;i++)
        {
            testResults[i] = obj.testResults[i];
        }
    }
    void displayDetails()
    {
        cout<<"Patient ID: "<<ID<<endl;
        cout<<"Patient name: "<<name<<endl;
        cout<<"Test results\n";
        for(int i=0;i<5;i++)
        {
            cout<<i+1<<":" <<testResults[i]<<endl;
        }
    }
};

int main()
{
    int results[] = {50,46,87,23,65};
    Patient p1(1234,"Sara",results);
    Patient p2(p1);
    cout<<"Original details\n";
    p1.displayDetails();
    cout<<"Copied details (for analysis)\n";
    p2.displayDetails();
    
    return 0;
}
