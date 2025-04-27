#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    ifstream inFile("vehicles.txt");
    if(!inFile){
        cerr<<"Error opening file\n";
        exit(0);
    }
    cout<<"Reading data from file...\n";
    string line;
    while(getline(inFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        istringstream ss(line);
        string type,id,name,year,extraData,cert;
        getline(ss,type,',');
        getline(ss,id,',');
        getline(ss,name,',');
        getline(ss,year,',');
        getline(ss,extraData,',');
        getline(ss,cert,',');

        cout<<"Type:"<<type<<endl;
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Year:"<<year<<endl;
        cout<<"Extra Data:"<<extraData<<endl;
        cout<<"Certification:"<<cert<<endl;
        cout<<"---------------------\n";
    }
    inFile.close();
    return 0;
}
