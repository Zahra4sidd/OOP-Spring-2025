#include "iostream"
#include "string"
using namespace std;

class Account
{
    protected:
    int accountNum;
    float balance;
    public:
    Account(int accNum,float b):accountNum(accNum),balance(b) {}
    void displayDetails()
    {
        cout<<"Account number: "<<accountNum<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
class SavingsAccount : public Account
{
    protected:
    float interestRate;
    public:
    SavingsAccount(int accNum,float b,float interest):
    Account(accNum,b),interestRate(interest) {}
    void displayDetails()
    {
        Account::displayDetails();
        cout<<"Interest Rate: "<<interestRate<<endl;
    }
};
class CheckingAccount : public Account
{
    protected:
    float overdraftLimit;
    public:
    CheckingAccount(int accNum,float b,float limit):
    Account(accNum,b),overdraftLimit(limit) {}
    void displayDetails()
    {
        Account::displayDetails();
        cout<<"Overdraft Limit: "<<overdraftLimit<<endl;
    }
};
int main()
{
    SavingsAccount saving(1234,1500.0,5.0);
    cout<<"Details for Savings Account\n";
    saving.displayDetails();
    CheckingAccount checking(9876,2000.0,500);
    cout<<"Details for Checking Account\n";
    checking.displayDetails();
}
