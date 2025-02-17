#include<iostream>
#include<string>
using namespace std;

class TourGuide
{
    private:
    string name;
    int yearsOfExperience;
    string specialization;

    public:
    TourGuide(string n = "", int years = 0, string s ="") : name(n), yearsOfExperience(years), specialization(s){}
    void display()
    {
        cout<<"Guide name: "<<name<<endl;
        cout<<"Years of experience: "<<yearsOfExperience<<endl;
        cout<<"Specialization: "<<specialization<<endl;
    }
};

class TravelAgency
{
    private:
    string name;
    TourGuide *guide;
    int capacity;
    int guideCount;

    public:
    TravelAgency(string n,int c = 5) : name(n), capacity(c)
    {
        guide = new TourGuide[capacity];
        guideCount = 0;
    }
    void addGuide(TourGuide g)
    {
        if(guideCount<capacity)
        {
            guide[guideCount] = g;
            guideCount++;
            cout<<"Tour guide "<<guideCount<<" added successfully\n";
        }
        else
        {
            cout<<"Cannot add more guides! capacity reached\n";
        }
    }
    void displayDetails()
    {
        cout<<"Travel Agency: "<<name<<endl;
        cout<<"List of tour guides assigned\n";
        for(int i=0;i<guideCount;i++)
        {
            guide[i].display();
        }
    }
};

int main()
{
    TravelAgency agency("Express Travels");
    TourGuide g1("John",8,"Adventure Tours");
    TourGuide g2("Sarah",5,"Cultural Tours");
    agency.addGuide(g1);
    agency.addGuide(g2);
    agency.displayDetails();

    return 0;
}
