#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

class InventoryItem{
    private:
    int id;
    char itemName[20];
    public:
    InventoryItem(){}
    InventoryItem(int id, char* name):id(id){
        strcpy(itemName,name);
    }
    void display(){
        cout<<"Id:"<<id<<endl;
        cout<<"Name:"<<itemName<<endl;
    }
};
int main(){
    char name[20] = {'k','e','y','b','o','a','r','d'};
    InventoryItem item1(101,name);
    ofstream outfile("inventory.dat",ios::binary);
    if(!outfile){
        cerr<<"Error while opening file\n";
        exit(0);
    }
    outfile.write((char*)&item1,sizeof(item1));
    outfile.close();
    InventoryItem item2;
    ifstream infile("inventory.dat",ios::binary);
    if(!infile){
        cerr<<"Error while opening file\n";
        exit(0);
    }
    infile.read((char*)&item2,sizeof(item2));
    infile.close();
    item2.display();
    return 0;
}
