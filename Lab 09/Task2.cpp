#include<iostream>
#include<string>
using namespace std;

class SmartDevice{
    public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool getStatus() = 0;

};
class LightBulb : public SmartDevice{
    private:
    bool isOn;
    int brightness;
    public:
    LightBulb(int b):isOn(false),brightness(b){}
    void turnOn(){
        cout<<"Turning lightbulb on...\n";
        cout<<"Brightness level: "<<brightness<<"%"<<endl;
        isOn = true;
    }
    void turnOff(){
        cout<<"Turning lightbulb off...\n";
        isOn = false;
    }
    bool getStatus(){
        if(isOn){
            return true;
        }
        else{
            return false;
        }
    }
};
class Thermostat : public SmartDevice{
    private:
    bool isOn;
    double temperature;
    public:
    Thermostat(double t):isOn(false),temperature(t){}
    void turnOn(){
        cout<<"Turning Thermostat on...\n";
        cout<<"Temperature level: "<<temperature<<endl;
        isOn = true;
    }
    void turnOff(){
        cout<<"Turning thermostat off...\n";
        isOn = false;
    }
    void controlTemp(double t){
        if(isOn){
            temperature = t;
            cout<<"Temperature changed to: "<<temperature<<endl;
        }
        else{
            cout<<"Thermostat is off\n";
        }
    }
    bool getStatus(){
        if(isOn){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    LightBulb bulb(50);
    bulb.turnOn();
    if(bulb.getStatus()){
        cout<<"Lightbulb is on\n";
    }
    else{
        cout<<"Lightbulb is off\n";
    }
    bulb.turnOff();
    Thermostat stat(35.6);
    stat.turnOn();
    stat.controlTemp(32.6);
    stat.turnOff();
    if(stat.getStatus()){
        cout<<"Thermostat is on\n";
    }
    else{
        cout<<"Thermostat is off\n";
    }
    return 0;
}
