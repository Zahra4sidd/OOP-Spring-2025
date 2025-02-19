#include<iostream>
#include<string>
using namespace std;

class Product
{
    private:
    int ID;
    string name;
    float price;

    public:
    Product(int id,string n,float p) : ID(id),name(n),price(p) {}
    void displayProduct()
    {
        cout<<"Product ID: "<<ID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Price:$"<<price<<endl;
    }
    float getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
};
class Inventory
{
    private:
    Product **products;
    int capacity;
    int productCount;

    public:
    Inventory(int c)
    {
        capacity = c;
        products = new Product*[capacity];
        productCount = 0;
    }
    void addProduct(int id,string name,float price)
    {
        if(productCount<capacity)
        {
            products[productCount] = new Product(id,name,price);
            productCount++;
            cout<<"Product added successfully\n";
        }
        else
        {
            cout<<"Capacity reached! Cannot add more products\n";
        }
    }
    void sortProductByPrice()
    {
        for(int i=0;i<productCount-1;i++)
        {
            for(int j=0;j<productCount-1-i;j++)
            {
                if(products[j]->getPrice() > products[j+1]->getPrice())
                {
                    Product* temp = products[j];
                    products[j] = products[j+1];
                    products[j+1] = temp;
                }
            }
        }
        cout<<"Inventory has been sorted by price\n";
    }
    void searchProductByName(string name)
    {
        int found = 0;
        for(int i=0;i<productCount;i++)
        {
            if(products[i]->getName() == name)
            {
                found =1;
                cout<<"Product "<<name<<" found!\n";
                products[i]->displayProduct();
                break;
            }
        }
        if(!found)
        {
            cout<<"Product not found!\n";
        }
    }
    void displayInventory()
    {
        cout<<"Inventory:\n";
        for(int i=0;i<productCount;i++)
        {
            products[i]->displayProduct();
        }
    }
};

int main()
{
    Inventory inventory(5);
    inventory.addProduct(101,"Laptop",599.9);
    inventory.addProduct(105,"Mangoes",19.9);
    inventory.addProduct(102,"Jeans",50.0);
    inventory.addProduct(104,"Headphones",75.0);
    inventory.searchProductByName("Jeans");
    inventory.sortProductByPrice();
    inventory.displayInventory();

    return 0;
}
