#include<iostream>
#include<string>
using namespace std;

class Book
{
    private:
    string title;
    float basePrice;
    int *stock;
    float discountPercentage;
    int bookID;
    static int nextBookID;
    
    public:
    //default constructor with initialiser list
    Book() : title("Unknown"), basePrice(0.0), stock(new int(30)), discountPercentage(0.0), bookID(nextBookID++) {}

    //parameterised constructor with initialiser list
    Book(string t, float p, int s, float discount = 0.0) : title(t), basePrice(p), stock(new int(s)), discountPercentage(discount), bookID(nextBookID++) {}
    
    //copy constructor with initialiser list
    Book(Book& obj) : title(obj.title), basePrice(obj.basePrice), stock(new int(*obj.stock)), discountPercentage(obj.discountPercentage), bookID(nextBookID++) {}
    
    ~Book()
    {
        delete this->stock;
        cout << "Destructor called for Book ID: " << bookID << ". Memory freed.\n";
    }
    void updateDetails(string title,float price,int stock)
    {
        this->title = title;
        this->basePrice = price;
        this->stock = new int(stock);
    }
    float applyDiscount(int quantity)
    {
        float discountedPrice = this->basePrice * (1-this->discountPercentage/100.0);
        if(quantity>40)
        {
            discountedPrice *= 0.8; //20% on bulk purchase
        }
        else if(quantity>10)
        {
            discountedPrice *= 0.9;
        }
        else if(quantity>5)
        {
            discountedPrice *=0.95;
        }
        return discountedPrice;
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
        if(quantity>(*this->stock))
        {
            cout<<"Not enough stock\n";
            return;
        }
        (*this->stock) -= quantity;
        float discountedPrice = applyDiscount(quantity);
        float totalPrice = discountedPrice*quantity;
        cout<<quantity<<" books successfully purchased\n";
        cout<<"Total price (after discount): "<<totalPrice<<endl;
        cout<<"Remaining stock: "<<*this->stock<<endl;
        if(*this->stock < 5)
        {
            cout<<"Warning!! Low stock\n";
        }
    }
    void displayBook()
    {
        cout<<"Book ID: "<<this->bookID<<endl;
        cout<<"Title: "<<this->title<<endl;
        cout<<"Price: "<<this->basePrice<<endl;
        cout<<"Stock: "<<*this->stock<<endl;
    }
};
// Initialize the static counter
int Book::nextBookID = 1;
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
    b1.purchaseBook();
    return 0;
}
