#include<iostream>
#include<string>
using namespace std;

class Movie
{
    private:
    string title;
    string director;
    float duration;
    
    public:
    Movie(string t, string director, float duration)
    : title(t), director(director), duration(duration) {}
    void displayMovies()
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Director: "<<director<<endl;
        cout<<"Duration: "<<duration<<" hours"<<endl;
    }
};

class CinemaHall
{
    private:
    string name;
    Movie **movies;
    int capacity;
    int movieCount;
    
    public:
    CinemaHall(string name, int c) : name(name),capacity(c)
    {
        movies = new Movie*[capacity];
        movieCount = 0;
    }
    void addMovie(string title,string director,float duration)
    {
        if(movieCount<capacity)
        {
            movies[movieCount] = new Movie(title,director,duration);
            movieCount++;
            cout<<"Movie "<<movieCount<<" added successfully\n";
        }
        else
        {
            cout<<"Cannot add more movies! Capacity reached\n";
        }
    }
    void display()
    {
        cout<<"Cinema: "<<name<<endl;
        cout<<"List of available movies:\n";
        for(int i=0;i<movieCount;i++)
        {
            movies[i]->displayMovies();
        }
    }
};

int main()
{
    CinemaHall cinema("Nuplex",5); //hall name and capacity
    cinema.addMovie("Inception","Christopher Nolan",2.5);
    cinema.addMovie("Avatar","James Cameron",3.5);
    cinema.addMovie("The Matrix","Wachowskis",3.75);
    cinema.display();

    return 0;
}
