#include<iostream>
#include<string>
using namespace std;

class Book
{
    private:
    string title;
    float price;
    int *stock;
    
    public:
    Book() //default constructor
    {
        title = "Unknown";
        price = 0.0;
        stock = new int(30);
    }
    Book(string t,float p,int s) //parameterized constructor
    {
        title = t;
        price = p;
        stock = new int(s);
    }
    Book(Book& obj) //copy constructor
    {
        title = obj.title;
        price = obj.price;
        stock = new int(*obj.stock);
    }
    ~Book()
    {
        delete stock;
        cout<<"Destructor called.Memory freed\n";
    }
    void updateDetails(string t,float p,int s)
    {
        title = t;
        price= p;
        stock = new int(s);
    }
    float applyDiscount(int quantity)
    {
        if(quantity>10)
        {
            return price * 0.9;
        }
        else if(quantity>5)
        {
            return price * 0.95;
        }
        else
        {
            return price;
        }
    }
    void purchaseBook()
    {
        string name;
        cout<<"Enter the book title to purchase: ";
        getline(cin,name);
        int quantity;
        if(name!=title)
        {
            cout<<"Book not found!\n";
            return;
        }
        cout<<"Book found!\n";
        cout<<"Enter quantity of books you want to purchase: ";
        cin>>quantity;
        cin.ignore();
        if(quantity>(*stock))
        {
            cout<<"Not enough stock\n";
            return;
        }
        (*stock) -= quantity;
        float discountedPrice = applyDiscount(quantity);
        float totalPrice = discountedPrice*quantity;
        cout<<quantity<<" books successfully purchased\n";
        cout<<"Total price (after discount): "<<totalPrice<<endl;
        cout<<"Remaining stock: "<<*stock<<endl;
        if(*stock < 5)
        {
            cout<<"Warning!! Low stock\n";
        }
    }
    void displayBook()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<*stock<<endl;
    }
};

int main()
{
    Book b1("Silent Patient",500,40);
    cout<<"Welcome to the bookstore\n";
    cout<<"Original book details(b1)\n";
    b1.displayBook();
    Book b2(b1);
    cout<<"Book 2 created.(Copy of book 1)\n";
    b1.updateDetails("Silent Patient",550,60);
    cout<<"Updated book 1 details\n";
    b1.displayBook();
    cout<<"Copied book details(b2)\n";
    b2.displayBook();
    return 0;
}
