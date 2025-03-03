#include "iostream"
#include "string"
using namespace std;

class Device
{
    protected:
    int deviceID;
    bool status;
    public:
    Device(int id,bool status):deviceID(id),status(status) {}
    void displayDetails()
    {
        cout<<"Device ID: "<<deviceID<<endl;
        if(status)
        {
            cout<<"Status:ON\n";
        }
        else
        {
            cout<<"Status:OFF\n";
        }
    }
};
class SmartPhone : public Device
{
    protected:
    float screenSize;
    public:
    SmartPhone(int id,bool status,float size) : 
    Device(id,status),screenSize(size){}
    void displayDetails()
    {
        Device::displayDetails();
        cout<<"Screen size(inches): "<<screenSize<<endl;
    }
};
class SmartWatch : public SmartPhone
{
    protected:
    bool heartRateMonitor;
    public:
    SmartWatch(int id,bool status,float size,bool heartRate):
    SmartPhone(id,status,size),heartRateMonitor(heartRate) {}
    void displayDetails()
    {
        SmartPhone::displayDetails();
        if(heartRateMonitor)
        {
            cout<<"Heart Rate Monitor:YES\n";
        }
        else
        {
            cout<<"Heart Rate Monitor:NO\n";
        }        
    }
};
class SmartWearable : public SmartWatch
{
    protected:
    int stepCounter;
    public:
    SmartWearable(int id,bool status,float size,bool heartRate,int steps):
    SmartWatch(id,status,size,heartRate),stepCounter(steps){}
    void displayDetails()
    {
        SmartWatch::displayDetails();
        cout<<"Step counter: "<<stepCounter<<" steps\n";
    }
};
int main()
{
    SmartWearable wearable(6543,false,6.2,true,1200);
    wearable.displayDetails();
}
