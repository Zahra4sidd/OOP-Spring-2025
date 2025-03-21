#include <iostream>
#include <cstring>
using namespace std;

class Media{
	protected:
		string title,date,publisher;
	    int id;
	public:
		Media(string t,string d,int id,string p):
			title(t),date(d),id(id),publisher(p) {}
		virtual void displayInfo(){
			cout<<"ID: "<<id<<endl;
			cout<<"Title: "<<title<<endl;
			cout<<"Publication Date: "<<date<<endl;
			cout<<"Publisher: "<<publisher<<endl;
		}
		virtual void checkOut(){
			cout<<title<<" has been checked out\n";
		}
		virtual void returnItem(){
			cout<<title<<" has been returned\n";
	 }
};
class Book : public Media{
	private:
		string author,ISBN;
		int numPages;
	public:
		Book(string t,string d,int id,string p,string a,string ISBN,int num):
		Media(t,d,id,p),author(a),ISBN(ISBN),numPages(num) {}
		void displayInfo() override
		{
			Media::displayInfo();
			cout<<"Author: "<<author<<endl;
			cout<<"ISBN: "<<ISBN<<endl;
			cout<<"Number of pages: "<<numPages<<endl;		
		}		
};
class DVD : public Media{
	private:
		string director,rating;
		int duration;
	public:
		DVD(string t,string d,int id,string p,string dir,int dur,string r):
		Media(t,d,id,p),director(dir),duration(dur),rating(r){}
		void displayInfo() override
		{
			Media::displayInfo();
			cout<<"Director: "<<director<<endl;
			cout<<"Duration: "<<duration<<" hrs\n";
			cout<<"Rating: "<<rating<<endl;
		}		
};
class CD : public Media{
	private:
		string artist,genre;
		int numTracks;
	public:
		CD(string t,string d,int id,string p,string a,int num,string g):
		Media(t,d,id,p),artist(a),numTracks(num),genre(g){}
		void displayInfo() override
		{
			Media::displayInfo();
			cout<<"Artist: "<<artist<<endl;
			cout<<"Number of tracks: "<<numTracks<<endl;
			cout<<"Genre: "<<genre<<endl;
		}
};
int main()
{
	Book book("The Great Gatsby", "1925-04-10", 9876, "Charles Scribner's Sons", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd("Inception", "2010-07-16", 2564, "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD cd("Thriller", "1982-11-30", 6754, "Epic Records", "Michael Jackson", 9, "Pop");
    cout<<"Book Details\n";
    book.displayInfo();
    cout<<"DVD details\n";
	dvd.displayInfo();
	cout<<"CD details\n";
	cd.displayInfo();
}
