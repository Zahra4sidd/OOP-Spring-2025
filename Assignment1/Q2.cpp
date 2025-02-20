#include<iostream>
#include<string>
#include<tuple>
using namespace std;

class Ball
{
    private:
    int x;
    int y;

    public:
    Ball(int x=0,int y=0) : x(x), y(y) {}
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void move(int dx,int dy)
    {
        x+=dx;
        y+=dy;
    }
    tuple<int, int>getPosition()
    {
        return make_tuple(x, y);
    }
};
class Goal
{
    private:
    int goalX;
    int goalY;

    public:
    Goal(int x=3, int y=3) : goalX(x), goalY(y) {}
    bool isGoalReached(int ballX, int ballY)
    {
        return (ballX==goalX && ballY==goalY);
    }
};
class Robot
{
    private:
    string name;
    int hits;

    public:
    Robot(string n = "") : name(n)
    {
        hits = 0;
    }
    void hitBall(int &ballX, int &ballY, const string &direction)
    {
        if(direction=="up")
        {
            ballY++;
        }
        else if(direction=="down")
        {
            ballY--;
        }
        else if(direction=="right")
        {
            ballX++;
        }
        else if(direction=="left")
        {
            ballX--;
        }
        else
        {
            cout<<"Invalid direction\n";
            return;
        }
        hits++;
    }
    int getHits()
    {
        return hits;
    }
    string getName()
    {
        return name;
    }
};
class Team
{
    private:
    string teamName;
    Robot *robot;

    public:
    Team(string name, Robot *r) : teamName(name), robot(r) {}
    string getTeamName()
    {
        return teamName;
    }
    Robot* getRobot()
    {
        return robot;
    }
};
class Game
{
    private:
    Team *teamOne, *teamTwo;
    Ball ball;
    Goal goal;

    public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2) {}
    void play(Team *team)
    {
        Robot *robot = team->getRobot();
        cout<<team->getTeamName()<<"'s turn:\n";
        while(!goal.isGoalReached(ball.getX(), ball.getY()))
        {
            string direction;
            cout<<"Enter direction (up,down,right,left): ";
            cin>>direction;
            int ballX = ball.getX();
            int ballY = ball.getY();
            robot->hitBall(ballX,ballY,direction);
            ball.move(ballX-ball.getX(), ballY-ball.getY());
            cout<<"Current Position:("<<ball.getX()<<","<<ball.getY()<<")\n";
        }
        cout<<"Goal reached by "<<team->getTeamName()<<" in "<<robot->getHits()<<" hits\n";
    }
    void startGame()
    {
        cout<<"Game start\n";
        play(teamOne);
        ball = Ball(0,0); //reset position
        play(teamTwo);
    }
    void declareWinner()
    {
        int hits1 = teamOne->getRobot()->getHits();
        int hits2 = teamTwo->getRobot()->getHits();
        cout<<"Game Results\n";
        cout<<teamOne->getTeamName()<<" hits: "<<hits1<<endl;
        cout<<teamTwo->getTeamName()<<" hits: "<<hits2<<endl;
        if(hits1<hits2)
        {
            cout<<teamOne->getTeamName()<<" wins!\n";
        }
        else if(hits2<hits1)
        {
            cout<<teamTwo->getTeamName()<<" wins!\n";
        }
        else
        {
            cout<<"Its a tie!\n";
        }
    }
};
int main()
{
    Robot r1("Robot 1");
    Robot r2("Robot 2");
    Team t1("Team A",&r1);
    Team t2("Team B",&r2);
    Game game(&t1, &t2);
    game.startGame();
    game.declareWinner();
    return 0;
}
