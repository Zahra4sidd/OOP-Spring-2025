#include<iostream>
#include<string>
using namespace std;

class Skill
{
    private:
    int skillID;
    string skillName;
    string description;

    public:
    Skill() : skillID(0), skillName(""), description("") {} //default constructor
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}
    void showSkillDetails()
    {
        cout<<"Skill ID: "<<skillID<<endl;
        cout<<"Skill name: "<<skillName<<endl;
        cout<<"Skill description: "<<description<<endl;
    }
    void updateSkillDescription(string newDescription)
    {
        description = newDescription;
        cout<<"Skill description updated\n";
    }
    int getSkillID()
    {
        return skillID;
    }
    string getSkillName()
    {
        return skillName;
    }
};

class Sport
{
    private:
    int sportID;
    string name;
    string description;
    Skill requiredSkills[5]; //max 5 skills per sports
    int skillCount;

    public:
    Sport() : sportID(0), name(""), description(""), skillCount(0) {}
    Sport(int id, string n, string desc) : sportID(id), name(n), description(desc), skillCount(0) {}
    void addSkill(Skill s)
    {
        if(skillCount<5)
        {
            requiredSkills[skillCount] = s;
            skillCount++;
            cout<<"Skill "<<s.getSkillName()<<" added to sport "<<name<<endl;
        }
        else
        {
            cout<<"Skill limit reached!!.Max 5 skills per sport\n";
        }
    }
    void removeSkill(int skillId)
    {
        for(int i=0;i<skillCount;i++)
        {
            if(requiredSkills[i].getSkillID()==skillId)
            {
                for(int j=i;j<skillCount-1;j++)
                {
                    requiredSkills[j] = requiredSkills[j+1];
                }
                skillCount--;
                cout<<"Skill removed from sport: "<<name<<endl;
                return;
            }
        }
        cout<<"Skill not found\n";
    }
    string getName()
    {
        return name;
    }
};

class Student;

class Mentor
{
    private:
    int mentorID;
    string name;
    Sport sportsExpertise[3]; //max 3 per mentor
    int maxLearners;
    Student *assignedLearners[3];
    int learnerCount;

    public:
    Mentor(int id, string n, int max) : mentorID(id), name(n), maxLearners(max),learnerCount(0) {}
    void assignLearner(Student *s);
    void removeLearner(Student *s);
    void viewLearners();
    void provideGuidance()
    {
        cout<<"Mentor "<<name<<" is providing guidance\n";
    }
    string getName()
    {
        return name;
    }
};
class Student
{
    int studentID;
    string name;
    int age;
    string sportsInterests[3];
    int interestCount;
    Mentor *mentorAssigned;

    public:
    Student(int id, string n, int a) : studentID(id), name(n), age(a), interestCount(0), mentorAssigned(nullptr) {}
    void registerForMentorship(Mentor *m)
    {
        mentorAssigned = m;
        cout<<"Student "<<name<<" assigned mentor "<<m->getName()<<endl;
    }
    void viewMentorDetails()
    {
        if(mentorAssigned)
        {
            cout<<"Mentor details\n";
            cout<<"Name: "<<mentorAssigned->getName()<<endl;
        }
        else
        {
            cout<<"No mentor assigned\n";
        }
    }
    void updateSportsInterest(Sport *s)
    {
        if (interestCount < 3)
        {
            sportsInterests[interestCount] = s->getName();
            interestCount++;
            cout << "Sports interest updated to " << s->getName() << endl;
        }
        else
        {
            cout << "Cannot add more sports interests. Maximum limit reached!\n";
        }
    }
    string getName()
    {
        return name;
    }
    int getStudentID()
    {
        return studentID;
    }
};
void Mentor :: assignLearner(Student *s)
{
    if(learnerCount<maxLearners)
    {
        assignedLearners[learnerCount] = s;
        learnerCount++;
        cout<<"Learner "<<s->getName()<<" assigned to mentor "<<name<<endl;
    }
    else
    {
        cout<<"Mentor "<<name<<" has reached maximum capacity\n";
    }
}
void Mentor :: removeLearner(Student *s)
{
    for(int i=0;i<learnerCount;i++)
    {
        if(assignedLearners[i]==s)
        {
            for(int j=i;j<learnerCount-1;j++)
            {
                assignedLearners[j] = assignedLearners[j+1];
            }
            learnerCount--;
            cout<<"Learner "<<s->getName()<<" removed from mentor "<<name<<endl;
            return;
        }
    }
    cout<<"Learner not found\n";
}
void Mentor :: viewLearners()
{
    cout<<"List of learners assigned to mentor "<<name<<endl;
    for(int i=0;i<learnerCount;i++)
    {
        cout<<"StudentID: "<<assignedLearners[i]->getStudentID()<<". Name: "<<assignedLearners[i]->getName()<<endl;
    }
}

int main()
{
    // Skill obj
    Skill skill1(1,"Forehand","Forehand stroke in tennis");
    Skill skill2(2,"Backhand","Backhand stroke in tennis");
    //Sport obj
    Sport sport1(1,"Tennis","Racket sport");
    sport1.addSkill(skill1);
    sport1.addSkill(skill2);
    //Mentor obj
    Mentor m1(101,"Ali",3);
    //Student obj
    Student s1(201,"Saad",18);
    Student s2(202,"Sara",19);
    //register for mentorship
    s1.registerForMentorship(&m1);
    s2.registerForMentorship(&m1);
    //view mentor details
    s1.viewMentorDetails();
    //assign students for mentorship
    m1.assignLearner(&s1);
    m1.assignLearner(&s2);
    //view students assigned to mentor
    m1.viewLearners();
    //update sports interests
    s1.updateSportsInterest(&sport1);
    //provide guidance
    m1.provideGuidance();
    //remove learner
    m1.removeLearner(&s1);
    m1.viewLearners();
  return 0;
}
