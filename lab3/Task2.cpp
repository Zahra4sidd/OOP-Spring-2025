#include<iostream>
#include<string>
using namespace std;

class TeaMug
{
    private:
    string brand;
    string color;
    int capacity;
    int currentFillLevel;

    public:
    void setAttributes(string b,string c, int cap,int l)
    {
        brand = b;
        color = c;
        capacity = cap;
        currentFillLevel = l;
    }
    void sipTea(int amt)
    {
        if(currentFillLevel>amt)
        {
            currentFillLevel-=amt;
            cout<<"Sipping...Current fill level:"<<currentFillLevel<<"ml"<<endl;
        }
        else
        {
            cout<<"Not enough tea!Refill reqiured\n";
            currentFillLevel = 0;
        }
    }
    void refillTea()
    {
        currentFillLevel = capacity;
        cout<<"Mug refilled!Current fill level:"<<currentFillLevel<<"ml"<<endl;
    }
    void checkStatus()
    {
        cout<<"Brand:"<<brand<<endl;
        cout<<"Color:"<<color<<endl;
        cout<<"Capacity:"<<capacity<<endl;
        cout<<"Current fill level:"<<currentFillLevel<<"ml"<<endl;
        if(currentFillLevel==0)
        {
            cout<<"Mug is empty\n";
        }
        else
        {
            cout<<"Mug is not empty\n";
        }
    }
}; 

int main()
{
    TeaMug mug;
    mug.setAttributes("Yeti","Black",250,0);
    
    mug.checkStatus();
    mug.refillTea();
    mug.sipTea(90);
    mug.sipTea(80);
    mug.sipTea(100);
    mug.checkStatus();

    // OR
   /* int choice;
    do
    {
        cout<<"1.Check status\n";
        cout<<"2.Sip tea\n";
        cout<<"3.Refill tea\n";
        cout<<"4.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;
        switch (choice)
        {
            case 1:
            mug.checkStatus();
            break;
            case 2:
            int amt;
            cout<<"Enter sipping amount(ml):";
            cin>>amt;
            mug.sipTea(amt);
            break;
            case 3:
            mug.refillTea();
            break;
            case 4:
            cout<<"Exiting...\n";
            break;
        }
    } while (choice!=4);
    */
    return 0;
}

