#include<iostream>
#include<string>
using namespace std;

class Professor
{
    private:
    string name;
    string department;
    
    public:
    Professor(string n = "", string dept = "") : name(n), department(dept) {}
    void display()
    {
        cout<<"Professor "<<name<<" from department "<<department<<endl;
    }
};

class University
{
    private:
    string name;
    int capacity;
    Professor *professors;
    int professorCount;

    public:
    University(string n, int c) : name(n), capacity(c)
    {
        professors = new Professor[capacity];
        professorCount = 0;
    }
    void addProfessor(string name,string department)
    {
        if(professorCount<capacity)
        {
            professors[professorCount] = Professor(name,department);
            professorCount++;
            cout<<"Professor "<< professorCount <<" added successfully\n";
        }
        else
        {
            cout<<"Cannot add more professors! Capacity reached\n";
            return;
        }
    }
    void display()
    {
        cout<<"University name: "<<name<<endl;
        cout<<"List of professors\n";
        for(int i=0;i<professorCount;i++)
        {
            professors[i].display();
        }
    }
};

int main()
{
    University fast("Fast University",5);
    fast.addProfessor("Dr.John","Computer Science");
    fast.addProfessor("Dr.Sarah","AI & DS");
    fast.addProfessor("Dr.James","Software Engineering");
    fast.display();

    return 0;
}
