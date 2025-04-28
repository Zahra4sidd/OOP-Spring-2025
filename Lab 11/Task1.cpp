#include <iostream>
#include <string>
#include <exception>
using namespace std;

class InvalideValueException : public exception{
    public:
    const char* what() const noexcept override{
        return "Age cannot be negative or exceed 120";
    }
};
void validateAge(int age){
    if(age<0 || age>120){
        throw InvalideValueException();
    }
    cout<<"Valid age:"<<age<<endl;
}
int main(){
    int age;
    cout<<"Enter age:";
    cin>>age;
    try{
        validateAge(age);
    }
    catch (const InvalideValueException& e){
        cout<<"Error:Invalid value exception! "<<e.what();
    }
}
