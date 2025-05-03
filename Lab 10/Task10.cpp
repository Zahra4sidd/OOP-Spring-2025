#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include <sstream>
using namespace std;

int main(){
    ifstream infile("data_records.txt");
    if(!infile){
        cerr<<"Error opening file\n";
        exit(0);
    }
    infile.seekg(20, ios::beg);
    string line;
    getline(infile,line);
    cout<<"Third record content: "<<line<<endl;
    infile.close();
    return 0;
}
