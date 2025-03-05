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
class SmartPhone : virtual public Device
{
    protected:
    float screenSize;
    public:
    SmartPhone(int id,bool status,float size):Device(id,status),screenSize(size){}
    void displayDetails()
    {
        Device::displayDetails();
        cout<<"Screen Size: "<<screenSize<<endl;
    }
};
class SmartWatch : virtual public Device 
{
    protected:
    bool heartRateMonitor;
    public:
    SmartWatch(int id,bool status,bool monitor):Device(id,status),heartRateMonitor(monitor){}
    void displayDetails()
    {
        Device::displayDetails();
        if(heartRateMonitor)
        {
            cout<<"Heart rate monitor: Available\n";
        }
        else
        {
            cout<<"Heart rate monitor: Not Available\n";
        }
    }
};
class SmartWearable : public SmartPhone,public SmartWatch
{
    private:
    int stepCounter;
    public:
    SmartWearable(int id,bool status,float size,bool monitor,int steps):
    Device(id,status),SmartPhone(id,status,size),SmartWatch(id,status,monitor),stepCounter(steps){}
    void displayDetails()
    {
        Device::displayDetails();
        cout<<"Screen size: "<<screenSize<<endl;
        if(heartRateMonitor)
        {
            cout<<"Heart rate monitor: Available\n";
        }
        else
        {
            cout<<"Heart rate monitor: Not Available\n";
        }
        cout<<"Step Counter: "<<stepCounter<<" steps\n";
    }
};
int main()
{
    SmartWearable s1(1234,true,6.2,true,1200);
    s1.displayDetails();
}
