#include<iostream>
#include<string>
using namespace std;

class Teacher;
class Student{
    private:
    string name;
    float grades[3];
    public:
    Student(string n,float g1,float g2,float g3):name(n){
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }
    friend class Teacher;
    friend float calcAvgGrade(const Student&);
};
class Teacher{
    public:
    void displayGrade(Student& s){
        cout<<"Student name: "<<s.name<<endl;
        cout<<"Grades:\n";
        for(int i=0;i<3;i++){
            cout<<s.grades[i]<<" ";
        }
        cout<<endl;
    }
    void updateGrade(Student& s,int index,float newGrade){
        if(index>=0 && index<3){
            s.grades[index] = newGrade;
            cout<<"Grade at index "<<index<<" updated to "<<newGrade<<endl;
        }
        else{
            cout<<"Invalid grade index\n";
        }
    }
};
float calcAvgGrade(const Student& s){
    float total = 0;
    for(int i=0;i<3;i++){
        total += s.grades[i];
    }
    return total/3;
}
int main(){
    Student s1("Alex",75,82,87);
    Teacher teacher;
    teacher.displayGrade(s1);
    teacher.updateGrade(s1,1,85);
    cout<<"New average grade: "<<calcAvgGrade(s1);
    return 0;
}
