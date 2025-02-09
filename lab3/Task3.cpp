#include<iostream>
#include<string>
using namespace std;

class Planner
{
    public:
    string task[12][30]; //assuming each month has 30 days;
    
    void initializeArray()
    {
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<30;j++)
            {
                task[i][j] = "";
            }
        }
    }

    void addTask()
    {
        string inputTask;
        int month,date;
        cout<<"Enter the month and date to add task to (eg: 1 10): "; //Jan 10th
        cin>>month>>date;
        cin.ignore();
        if(task[month-1][date-1] == "")
        {
            cout<<"Enter the task: ";
            getline(cin,inputTask);
            task[month-1][date-1]=inputTask;
            cout<<"Task added successfully\n";
        }
        else
        {
            cout<<"Task already present for this day\n";
            return;
        }
    }

    void removeTask()
    {
        int month,date;
        cout<<"Enter the month and date to remove a task (eg:1 10): "; //Jan 10th
        cin>>month>>date;
        if(task[month-1][date-1]== "")
        {
            cout<<"No task found to remove\n";
            return;
        }
        task[month-1][date-1]= "";
        cout<<"Task removed successfully\n";
    }

    void updateTask()
    {
        int month,date;
        string inputTask;
        cout<<"Enter month and date to update task (eg:1 10): "; //Jan 10th
        cin>>month>>date;
        cin.ignore();
        cout<<"Enter updated task: ";
        getline(cin,inputTask);
        task[month-1][date-1] = inputTask;
        cout<<"Task updated successfully\n";
    }

    void displayTask()
    {
        int month;
        cout<<"Enter the month to display tasks (1-12): ";
        cin>>month;
        cout<<"Tasks for month:"<<month<<endl;
        for(int i=0;i<30;i++)
        {
            if(task[month-1][i]!= "")
            {
                cout<<"Day "<<i+1<<" : "<<task[month-1][i]<<endl;
            }
        }
    }
};

int main()
{
    Planner plan;
    plan.initializeArray();
    int choice;
    cout<<"\nWelcome to the event planning tracker\n";
    do
    {
        cout<<"1.Add Task\n";
        cout<<"2.Remove Task\n";
        cout<<"3.Update Task\n";
        cout<<"4.Display Task\n";
        cout<<"5.Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        plan.addTask();
        break;
        case 2:
        plan.removeTask();
        break;
        case 3:
        plan.updateTask();
        break;
        case 4:
        plan.displayTask();
        break;
        case 5:
        cout<<"Exiting...\n";
        break;
        }
    } while (choice!=5);
    return 0; 
}
