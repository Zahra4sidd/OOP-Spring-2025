#include <iostream>
#include <string>
#include <fstream>
#include <exception>
using namespace std;

class InsufficientFundsException : public exception{
    double deficit;
    public:
    InsufficientFundsException(double d):deficit(d){}
    const char* what() const noexcept override{
        return "Insufficient Funds!";
    }
};

template <typename T>
class BankAccount{
    private:
    T balance;
    public:
    BankAccount(T b):balance(b){}
    void withdraw(T amount){
        if(amount > balance){
            double deficit = static_cast<double>(amount - balance);
            throw InsufficientFundsException(deficit);
        }
        balance -= amount;
        cout<<"Withdrawal of $"<<amount<<"successful | ";
        cout<<"Remaining balance: $"<<balance<<endl;
    }
    T getBalance(){
        return balance;
    }
};
int main(){
    BankAccount<double> act(5000.0);
    cout<<"Balance: "<<act.getBalance()<<endl;
    try{
        act.withdraw(6000.0);
    }catch(const InsufficientFundsException& e){
        cout<<"Withdraw $6000 | "<<e.what();
    }
    return 0;
}
