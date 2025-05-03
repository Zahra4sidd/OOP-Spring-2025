#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include <sstream>
using namespace std;

int main(){
    ofstream outfile("sensor_log.txt");
    if(!outfile){
        cerr<<"Error while opening file\n";
        exit(0);
    }
    outfile<<"Sensor1:23.5°C\n";
    streampos pos1 = outfile.tellp();
    cout<<"Position after first write:"<<pos1<<endl;
    outfile<<"Sensor2:19.8°C\n";
    streampos pos2 = outfile.tellp();
    cout<<"Position after second write:"<<pos2<<endl;
    outfile<<"Sensor3:32.7°C\n";
    streampos pos3 = outfile.tellp();
    cout<<"Position after third write:"<<pos3<<endl;
    outfile.close();
    return 0;
}
