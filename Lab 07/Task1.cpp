#include<iostream>
using namespace std;

class Account
{
    protected:
    int accNum;
    string name;
    float balance;
    string type;
    public:
    Account(int n,string name,float b,string t):
    accNum(n),name(name),balance(b),type(t){}
    virtual void deposit(float amt)
    {
        balance += amt;
        cout<<"Deposited:"<<amt<<" | Balance:"<<balance<<endl;
    }
    virtual void withdraw(float amt)
    {
        if(amt < balance)
        {
            balance -= amt;
            cout<<"Withdrawed:"<<amt<<" | Balance:"<<balance<<endl;
        }
        else
        {
            cout<<"Insufficient funds\n";
        }
    }
    virtual float calcInterest()
    {
        return 0.0;
    }
    virtual void printStatement()
    {
        cout<<"Account Statement\n";
        cout<<"Balance: "<<balance<<endl;
    }
    virtual void displayAccount()
    {
        cout<<"Account number: "<<accNum<<endl;
        cout<<"Holder name: "<<name<<endl;
        cout<<"Account type: "<<type<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
class Savings : public Account
{
    private:
    float interestRate;
    float minBal;
    public:
    Savings(int n,string name,float b,string t,float rate,float minBal):
    Account(n,name,b,t),interestRate(rate),minBal(minBal){}
    float calcInterest()override
    {
        return (balance*interestRate/100);
    }
    void withdraw(float amt)override
    {
        if(balance-amt >= minBal)
        {
            Account::withdraw(amt);
        }
        else
        {
            cout<<"Withdrawal denied\n"; 
        }
    }
    void printStatement()override
    {
        Account::printStatement();
        cout<<"Interest Rate: "<<interestRate<<"%\n";
        cout<<"Minimum Balance: "<<minBal<<endl;
    }
};
class FixedDepositAccount : public Account
{
    private:
    string maturityDate;
    float fixedInterestRate;
    public:
    FixedDepositAccount(int n,string name,float b,string t,string date,float rate):
    Account(n,name,b,t),maturityDate(date),fixedInterestRate(rate){}
    float calcInterest()override
    {
        return (balance*fixedInterestRate/100);
    }
    void withdraw(float amt)override
    {
        cout<<"Withdrawal denied due to maturity date\n";
    }
    void printStatement()override
    {
        Account::printStatement();
        cout<<"Fixed Interest Rate: "<<fixedInterestRate<<"%\n";
        cout<<"Maturity Date: "<<maturityDate<<endl;
    }
};

int main() 
{
    Savings savings(12345,"John Doe",1000,"Savings", 2.5, 500);
    FixedDepositAccount fixedDeposit(67890,"Jane Doe",5000,"Fixed Deposit","2025-12-31", 5.0);

    savings.deposit(500);
    savings.withdraw(200);
    float interest = savings.calcInterest();
    cout<<"Interest: "<<interest<<endl;
    savings.printStatement();

    fixedDeposit.deposit(1000);
    fixedDeposit.withdraw(500);
    fixedDeposit.printStatement();

    return 0;
}
