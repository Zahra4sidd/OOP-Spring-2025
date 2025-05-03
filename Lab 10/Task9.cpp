#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include <sstream>
using namespace std;

int main(){
    ifstream infile("large_log.txt");
    if(!infile){
        cerr<<"Error opening file\n";
        exit(0);
    }
    char buffer[11] = {0};
    infile.read(buffer,10);
    cout<<buffer<<endl;
    streampos pos1 = infile.tellg();
    cout<<"Position after first read:"<<pos1<<endl;
    infile.read(buffer,10);
    cout<<buffer<<endl;
    streampos pos2 = infile.tellg();
    cout<<"Position after second read:"<<pos2<<endl;
    infile.close();
    return 0;
}
