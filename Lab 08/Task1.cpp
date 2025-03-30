#include<iostream>
using namespace std;

class Humidity;
class Temperature{
    private:
    float temp;
    public:
    Temperature(float t):temp(t){}
    friend float calcHeatIndex(const Temperature& , const Humidity&);
};
class Humidity{
    private:
    float humidity;
    public:
    Humidity(float h):humidity(h){}
    friend float calcHeatIndex(const Temperature& , const Humidity&);
};
float calcHeatIndex(const Temperature& t, const Humidity& h){
    float index = t.temp + (0.1 * h.humidity);
    return index;
}
int main(){
    Temperature t(32);
    Humidity h(70);
    cout<<"Heat Index: "<<calcHeatIndex(t,h)<<endl;
    return 0;
}
