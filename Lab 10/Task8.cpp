#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include <sstream>
using namespace std;

int main(){
    ofstream outfile("config.txt");
    if(!outfile){
        cerr<<"ERROR opening file\n";
        exit(0);
    }
    outfile<<"AAAAABBBBBCCCCC";
    outfile.close();
    
    fstream file("config.txt",ios::in | ios::out);
    if(!file){
        cerr<<"ERROR opening file\n";
        exit(0);
    }
    file.seekp(5);
    file<<"XXXXX";
    file.close();

    ifstream infile("config.txt");
    if(!infile){
        cerr<<"ERROR opening file\n";
        exit(0);
    }
    string line;
    while(getline(infile, line)){
        cout<<line<<endl;
    }
    infile.close();
    return 0;
}
