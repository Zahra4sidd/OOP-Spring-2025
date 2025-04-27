#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("vehicles.txt");
    if(!inFile){
        cerr<<"Error opening file\n";
        exit(0);
    }
    string line;
    while(getline(inFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }
        cout<<line<<endl;
    }
    inFile.close();
    return 0;
}
