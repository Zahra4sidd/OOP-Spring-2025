#include <iostream>
#include <string>
#include <exception>
#include <sstream>
using namespace std;

class FileException : public exception{
    public:
    virtual const char* what() const noexcept override{
        return "File exception occured";
    }
};
class FileNotFoundException : public FileException{
    public:
    const char* what() const noexcept override{
        return "FileNotFoundException File not found!";
    }
};
class PermissionDeniedException : public FileException{
    public:
    const char* what() const noexcept override{
        return "PermissionDeniedException Access denied!";
    }
};

void readFile(const string& filename){
    if(filename == "missing.txt"){
        throw FileNotFoundException();
    }
    else if(filename == "secret.txt"){
        throw PermissionDeniedException();
    }else{
        cout<<"Reading "<<filename<<" success!\n";
    }
}
int main(){
    string name;
    cout<<"Enter file name: ";
    cin>>name;
    try{
        readFile(name);
    }
    catch(const FileNotFoundException& e){
        cout<<"Reading "<<name<<": "<<e.what();
    }
    catch(const PermissionDeniedException& e){
        cout<<"Reading "<<name<<": "<<e.what();
    }

    return 0;
}
