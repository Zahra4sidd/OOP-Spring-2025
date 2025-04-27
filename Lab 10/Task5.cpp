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

        if(type == "AutonomousCar"){
            size_t pos = extraData.find(':');
            if(pos != string::npos){
                string str = extraData.substr(pos + 1);
                float softwareVersion = stof(str);
                cout<<"Vehicle ID:"<<id<<", ";
                cout<<"Software Version:"<<softwareVersion<<endl;
            }else{
                cout<<"Software Version not found!\n";
            }
        }
        else if(type == "ElectricVehicle"){
            size_t pos = extraData.find(':');
            if(pos != string::npos){
                string str = extraData.substr(pos+1);
                int battery = stoi(str);
                cout<<"Vehicle ID:"<<id<<", ";
                cout<<"Battery Capacity:"<<battery<<endl;
            }
        }
        else if(type == "HybridTruck"){
            size_t cargoPos = extraData.find("Cargo:");
            size_t pipePos = extraData.find('|');
            size_t batteryPos = extraData.find("Battery:");
            if(cargoPos!=string::npos && pipePos!=string::npos && batteryPos!=string::npos){
                string cargoStr = extraData.substr(cargoPos+6, pipePos-(cargoPos+6));
                int cargoVal = stoi(cargoStr);
                string batteryStr = extraData.substr(batteryPos+8);
                int batteryVal = stoi(batteryStr);
                cout<<"Vehcile ID:"<<id<<", Cargo:"<<cargoVal
                <<", Battery Capacity:"<<batteryVal<<endl;
            }else{
                cout<<"Cargo or battery values not found!\n";
            }
        }
        else{
            cout<<"Unkown vehicle type!\n";
        }
    }
    inFile.close();
    return 0;
}
