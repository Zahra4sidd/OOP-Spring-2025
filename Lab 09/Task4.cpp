#include<iostream>
#include<string>
using namespace std;

class PaymentMethod{
    public:
    virtual void processPayment(double amount)=0;
};
class CreditCard : public PaymentMethod{
    private:
    string cardNumber;
    public:
    CreditCard(string n):cardNumber(n){}
    void processPayment(double amount){
        string cNum;
        cout<<"Payment process for Credit Card\n";
        cout<<"Enter card number:";
        cin>>cNum;
        if(cNum == cardNumber){
            cout<<"Processing payment of $"<<amount<<endl;
        }
        else{
            cout<<"Invalid card number\n";
        }
    }
};
class DigitalWallet : public PaymentMethod{
    private:
    double balance;
    public:
    DigitalWallet(double b):balance(b){}
    void processPayment(double amount){
        cout<<"Payment process for Digital Wallet\n";
        if(balance > amount){
            balance -= amount;
            cout<<"Payment processed. Current balance:$"<<balance<<endl;
        }
        else{
            cout<<"Insufficient funds\n";
        }
    }
};
int main(){
    CreditCard c1("123-456-789");
    c1.processPayment(8500);
    DigitalWallet w1(45000);
    w1.processPayment(3200);
    return 0;
}
