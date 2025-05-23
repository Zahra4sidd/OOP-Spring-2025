#include<iostream>
#include<string>
using namespace std;

class MarkerPen
{
    public:
    string brand;
    string color;
    int inkLevel;
    bool refillability;
    
    void write(int amt)
    {
        if (inkLevel>amt)
        {
            inkLevel-=amt;
            cout<<"Writing...Remaining ink level: "<<inkLevel<<endl;
        }
        else
        {
            cout<<"Not sufficient ink level to write.Refill required\n";
        }
    }
    void refill()
    {
        if(refillability)
        {
            inkLevel = 100; //max level
            cout<<"Ink refilled\n";
        }
        else
        {
            cout<<"Marker is not refillable\n";
        }
    }
    void checkStatus()
    {
        cout<<"Status\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Ink level: "<<inkLevel<<endl;
        if(refillability)
        {
            cout<<"Refillable:Yes\n";
        }
        else
        {
            cout<<"Refillable:No\n";
        }
    }
};

int main()
{
    MarkerPen m1 = {"Sharpie","Blue",60,1};
    cout<<"Marker 1\n";
    m1.write(40);
    m1.write(50);
    m1.refill();
    m1.checkStatus();

    MarkerPen m2 = {"Pilot","Red",50,0};
    cout<<"Marker 2\n";
    m2.write(30);
    m2.checkStatus();

    return 0;
}

