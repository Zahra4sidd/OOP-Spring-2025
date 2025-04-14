#include<iostream>
#include<string>
using namespace std;

class Activity{
    public:
    virtual void calcCaloriesBurned() = 0;
};
class Running : public Activity{
    private:
    double distance, time;
    public:
    Running(double d, double t):distance(d),time(t){}
    void calcCaloriesBurned(){
        double calories;
        calories = distance * 60; //60 calories per km
        cout<<"Calories burned running: "<<calories<<endl;
    }
};
class Cycling : public Activity{
    private:
    double speed, time;
    public:
    Cycling(double s, double t):speed(s),time(t){}
    void calcCaloriesBurned(){
        double calories;
        calories = speed * time * 5; //5 calories per km
        cout<<"Calories burned cycling: "<<calories<<endl;
    }
};
int main(){
    Running r(5,30);
    r.calcCaloriesBurned();
    Cycling c(20,1);
    c.calcCaloriesBurned();
    return 0;
}
