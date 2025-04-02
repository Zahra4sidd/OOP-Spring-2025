#include <iostream>
#include <string>
using namespace std;

class Ghost
{
    protected:
    string name;
    int scareLevel;
    public:
    Ghost(string n,int scare):name(n),scareLevel(scare){}
    virtual void haunt() const = 0;
    virtual Ghost* operator+(const Ghost &obj)const;
    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os<<"Ghost Name: "<<g.name<<", Scare Level: "<<g.scareLevel;
        return os;
    }
    string getName() const{
        return name;
    }
    int getScareLevel() const{
        return scareLevel;
    }
    virtual ~Ghost(){}
};
class Poltergeist : public Ghost{
    public:
    Poltergeist(string n,int s):Ghost(n,s){}
    void haunt()const override{
        cout<<name<<" moves objects around\n";
    }
};
class Banshee : public Ghost{
    public:
    Banshee(string n,int s):Ghost(n,s){}
    void haunt()const override{
        cout<<name<<" screams loudly\n";
    }
};
class ShadowGhost : public Ghost{
    public:
    ShadowGhost(string n, int s):Ghost(n,s){}
    void haunt()const override{
        cout<<name<<" whispers creepily\n";
    }
};
Ghost* Ghost::operator+(const Ghost &obj)const{
    return new Poltergeist(name + " & " + obj.name,scareLevel + obj.scareLevel);
}
class Visitor{
    private:
    string name;
    int bravery;
    public:
    Visitor(string n,int b):name(n),bravery(b){}
    void react(const Ghost &g){
        cout<<name<<" encounters "<<g<<" and ";
        if(g.getScareLevel() < bravery)
        {
            cout<<"laughs at the ghost\n";
        }
        else if(g.getScareLevel() < bravery)
        {
            cout<<"screams and runs away\n";
        }
        else
        {
            cout<<"gets a shaky voice\n";
        }
    }
};
class HauntedHouse{
    private:
    string name;
    Ghost *ghosts[3];
    public:
    HauntedHouse(string n,Ghost *g1,Ghost *g2,Ghost *g3):name(n)
    {
        ghosts[0] = g1;
        ghosts[1] = g2;
        ghosts[2] = g3;
    }
    friend void visit(Visitor visitors[], int numVisitors, const HauntedHouse& house);
};
void visit(Visitor visitors[], int numVisitors, const HauntedHouse& house)
{
    cout<<"Visitors Entering "<<house.name<<endl;
        for(int i=0;i<numVisitors;i++)
        {
            for(int j=0;j<3;j++)
            {
                visitors[i].react(*house.ghosts[j]);
            }
        }
}
int main()
{
    Poltergeist p1("Poltergeist 1", 5);
    Banshee b1("Banshee 1", 7);
    ShadowGhost s1("ShadowGhost 1", 4);
    Poltergeist p2("Poltergeist 2", 6);
    Banshee b2("Banshee 2", 8);
    ShadowGhost s2("ShadowGhost 2", 5);
    Ghost* upgradedGhost1 = p1 + b1;
    Ghost* upgradedGhost2 = s1 + p2;
    HauntedHouse house1("Ghost Mansion", &p1, &b1, &s1);
    HauntedHouse house2("Dark Forest", &p2, &b2, &s2);
    HauntedHouse house3("Abandoned Theater", upgradedGhost1, upgradedGhost2, &s1);
    Visitor visitors[] = {
        Visitor("John", 3),  //cowardly
        Visitor("Sara", 6), //average
        Visitor("Mike", 9) //fearless
    };
    int numVisitors = sizeof(visitors) / sizeof(visitors[0]);
    visit(visitors, numVisitors, house1);
    visit(visitors, numVisitors, house2);
    visit(visitors, numVisitors, house3);
    delete upgradedGhost1;
    delete upgradedGhost2;
    return 0;
}
