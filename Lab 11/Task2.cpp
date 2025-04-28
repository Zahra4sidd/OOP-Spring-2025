#include <iostream>
#include <string>
#include <exception>
using namespace std;

class StackOverflowException : public exception{
    public:
    const char* what() const noexcept override{
        return "Stack is full\n";
    }
};
class StackUnderflowException : public exception{
    public:
    const char* what() const noexcept override{
        return "Stack is empty\n";
    }
};
template<typename T>
class Stack{
    private:
    int capacity = 5;
    int data[10];
    int index;
    public:
    Stack():index(0){}
    void push(T val){
        if(index > capacity-1){
            throw StackOverflowException();
        }
        data[index++] = val;
    }
    T pop(){
        if(index == 0){
            throw StackUnderflowException();
        }
        return data[--index];
    }
};
int main(){
    Stack<int> s;
    try{
        cout<<"Pushing elements into stack...\n";
        for(int i=1;i<=6;i++){
            cout<<"Pushing "<<i<<endl;
            s.push(i);
        }
    }
    catch (const StackOverflowException& e){
    cout<<"Error: "<<e.what();
    }
    try{
        cout<<"Popping from stack...\n";
        for(int i=1;i<=6;i++){
            cout<<"Popped: "<<s.pop()<<endl;
        }
    }
    catch (const StackUnderflowException& e){
    cout<<"Error: "<<e.what();
    }
}
