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
    Book()
    {
        title = "Unknown";
        price = 0.0;
        stock = new int(30);
    }
    void updateDetails(string t,float p)
    {
        title = t;
        price = p;
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
        cout<<quantity<<" books successfully purchased\n";
        cout<<"Total price: "<<price*quantity<<endl;
        cout<<"Remaining stock: "<<*stock<<endl;
        if(*stock < 5)
        {
            cout<<"Warning!! Low stock\n";
        }
    }
};

int main()
{
    Book b1;
    cout<<"Welcome to the bookstore\n";
    cout<<"Book 1\n";
    b1.updateDetails("Silent Patient",500.0);
    b1.purchaseBook();
}
