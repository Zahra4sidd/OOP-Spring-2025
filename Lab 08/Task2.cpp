#include<iostream>
#include<string>
using namespace std;

class Librarian;
class Book{
    private:
    string title;
    float price;
    public:
    Book(string t, float p):title(t),price(p){}
    friend class Librarian;
};
class Librarian{
    public:
    void displayBook(Book& b){
        cout<<"Book title: "<<b.title<<endl;
        cout<<"Book price: "<<b.price<<endl;
    }
    void applyDiscount(Book& b, float percentage){
        b.price = b.price * (100 - percentage)/100;
    }
};
int main(){
    Book b1("Harry Potter",550.0);
    Librarian librarian;
    cout<<"Before discount\n";
    librarian.displayBook(b1);
    librarian.applyDiscount(b1,20);
    cout<<"After discount\n";
    librarian.displayBook(b1);
    return 0;
}
