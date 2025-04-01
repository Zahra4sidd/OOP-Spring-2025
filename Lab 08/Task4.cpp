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
    Currency wholesale(20),retail;
    retail = wholesale;
    cout<<"Wholesale price: "<<wholesale<<endl;
    cout<<"Retail price: "<<retail<<endl;
    Currency discount(4);
    retail -= discount;
    cout<<"Retail price after discount: "<<retail<<endl;
    wholesale = Currency(34);
    cout<<"New wholesale price: "<<wholesale<<endl;
    retail = wholesale + 10;
    cout<<"New retail price: "<<retail<<endl;
    Currency profit(retail - wholesale);
    cout<<"Profit: "<<profit<<endl;
    profit = -profit;
    cout<<"Profit after unary minus: "<<profit<<endl;
    return 0;
}
