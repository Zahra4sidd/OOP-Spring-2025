#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100

class GroceryStore
{
    private:
    struct Item
    {
        int id;
        string name;
        float price;
        int quantity;
    };
    Item item[MAX];
    int count = 0;
    
    public:
    void addItem()
    {
        if(count>=MAX)
        {
            cout<<"Inventory full!!\n";
            return;
        }
        cout<<"Item ID: ";
        cin>>item[count].id;
        cin.ignore();
        cout<<"Item name: ";
        getline(cin,item[count].name);
        cout<<"Item price: ";
        cin>>item[count].price;
        cout<<"Item quantity: ";
        cin>>item[count].quantity;
        cout<<"Item added successfully\n";
        count++;
    }
    void updateItem()
    {
        int Id;
        int found=0;
        cout<<"To update price, enter item Id:";
        cin>>Id;
        for(int i=0;i<count;i++)
        {
            if(item[i].id==Id)
            {
                found=1;
                cout<<"Enter updated price: ";
                cin>>item[i].price;
                cout<<"Enter updated quantity: ";
                cin>>item[i].quantity;
                cout<<"Item updated successfully\n";
            }
        }
        if(!found)
        {
            cout<<"Item with Id: "<<Id<<" not found\n";
        }
    }
    void generateReciept()
    {
        float total = 0,sum = 0;
        for(int i=0;i<count;i++)
        {
            cout<<"Item "<<i+1<<endl;
            cout<<"ID: "<<item[i].id<<endl;
            cout<<"Name: "<<item[i].name<<endl;
            cout<<"Price: "<<item[i].price<<endl;
            cout<<"Quantity: "<<item[i].quantity<<endl;
            sum = item[i].price * item[i].quantity;
            cout<<"Item total Price: "<<sum<<endl;
            total+=sum;
        }
        cout<<"Total Price of inventory: "<<total<<endl;
    }
};
int main()
{
    GroceryStore store;
    int choice;
    cout<<"Welcome to the grocery store\n";
    do
    {
        cout<<"Press\n";
        cout<<"1.Add item\n";
        cout<<"2.Update item\n";
        cout<<"3.Generate reciept\n";
        cout<<"4.Exit\n";
        cout<<"Enter youre choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            store.addItem();
            break;
            case 2:
            store.updateItem();
            break;
            case 3:
            store.generateReciept();
            break;
            case 4:
            cout<<"Exiting....\n";
        }
    } while (choice!=4);

    return 0;
}
