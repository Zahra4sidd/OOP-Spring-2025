#include<iostream>
#include<string>
using namespace std;

class Currency{
    private:
    float value;
    public:
    Currency(float v = 0.0):value(v){}
    Currency operator-()const{
        return Currency(-value);
    }
    Currency operator+(const Currency& obj)const{
        return Currency(value + obj.value);
    }
    Currency operator-(const Currency& obj)const{
        return Currency(value - obj.value);
    }
    Currency& operator+=(const Currency& obj){
        value += obj.value;
        return *this;
    }
    Currency& operator-=(const Currency& obj){
        value -= obj.value;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Currency& obj);
};
ostream& operator<<(ostream& os, const Currency& obj){
    os<<obj.value;
    return os;
}
int main(){
    Currency c1(25.5), c2(76.8), c3;
    c3 = c1 + c2;
    cout<<"Addition: "<<c1<<" + "<<c2<<" = "<<c3<<endl;
    c3 = c1 - c2;
    cout<<"Subtraction: "<<c1<<" - "<<c2<<" = "<<c3<<endl;
    cout<<"Negation: "<<c1<<" = "<<-c1<<endl;
    c1 += c2;
    cout<<"After c1 += c2: "<<c1<<endl;
    c1 -= c2;
    cout<<"After c1 -= c2: "<<c1<<endl;
    return 0;
}
