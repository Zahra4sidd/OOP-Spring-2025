#include <iostream>
#include <cmath>
using namespace std;

class Currency{
    protected:
    float amount;
    string code;
    string symbol;
    float exchangeRate;
    public:
    Currency(float amt,string c,string s,float rate):
    amount(amt),code(c),symbol(s),exchangeRate(rate){}
    virtual float convertToBase(){ // Assume base currency is USD
        return amount * exchangeRate;
    }
    virtual float convertTo(Currency &targetCurrency){
        float baseAmt = convertToBase();
        return baseAmt / targetCurrency.exchangeRate;
    }
    virtual void displayCurrency()=0;
};
class Dollar : public Currency{
    public:
    Dollar(float amt):Currency(amt,"USD","$",1.0){}
    void displayCurrency() override{
        cout<<"USD amount: "<<symbol<<amount<<endl;
    }
};
class Euro : public Currency{
    public:
    Euro(float amt):Currency(amt,"EUR","€",1.08){}
    void displayCurrency() override{
        cout<<"EUR amount: €"<<amount<<endl;
    }
};
class Rupee : public Currency{
    public:
    Rupee(float amt):Currency(amt,"PKR","Rs",0.0036){}
    void displayCurrency() override{
        cout<<"PKR amount: "<<symbol<<amount<<endl;
    }
};
int main(){
    Dollar usd(100);
    Euro eur(50);
    Rupee pkr(7000);
    usd.displayCurrency();
    eur.displayCurrency();
    pkr.displayCurrency();
    cout<<"50 EUR in USD: "<<eur.convertTo(usd)<<" USD"<<endl;
    cout<<"7000 PKR in USD: "<<pkr.convertTo(usd)<<" USD"<<endl;
    cout<<"100 USD in PKR: "<<usd.convertTo(pkr)<<" PKR"<<endl;
    cout<<"50 EUR in PKR: "<<eur.convertTo(pkr)<<" PKR"<<endl;
}
