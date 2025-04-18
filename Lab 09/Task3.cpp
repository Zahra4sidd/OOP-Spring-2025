#include"iostream"
#include"Book.h"
using namespace std;


Book::Book(string t, string a, string isbn) : title(t), author(a), isbn(isbn) {}

string Book :: getTitle() const { return title; }
string Book ::  getAuthor() const { return author; }
string Book ::  getISBN() const { return isbn; }

void Library :: AddBooks(Book b)
{  if(bookCount<MAX_BOOK)
   {  book[bookCount++] = b;
   }else{
     cout<<"Book can't be added!\n";
   }
}

void Library ::  Remove(string isbn)
{ int j=0, flag = 0;
  for(int i=0; i<bookCount; i++)
  {  if(isbn == book[i].getISBN())
     {  flag = 1;
        cout<< book[i].getTitle()<<" with ISBN: "<<book[i].getISBN()<<" has been removed!\n";
     }else{
       book[j++] = book[i];
     }
  }
  

  if(flag == 0){
     cout<<"Book with ISBN: "<<isbn<<" is not found!\n";
  }else{
    bookCount--;
  }
}

void Library ::  Search(string isbn, string title)
{ bool flag = 0;
  for(int i=0; i<bookCount; i++)
  {  if(isbn == book[i].getISBN() && title == book[i].getTitle())
     {   flag = 1;
         cout<<"Details of the book you searched for:"<<endl;
         cout<<"Title: "<<book[i].getTitle()<<endl;
         cout<<"Author: "<<book[i].getAuthor()<<endl;
         cout<<"ISBN: "<<book[i].getISBN()<<endl;
     }
  }

  if(flag == 0){
     cout<<"Book with ISBN: "<<isbn<<" is not found!\n";
  }
}

int main()
{
    Book b("Rock Paper Scissor","Alie","123409");
    cout<<"Title: "<<b.getTitle()<<endl;
    cout<<"Author: "<<b.getAuthor()<<endl;
    cout<<"ISBN: "<<b.getISBN()<<endl;

    Book b1("Rock Paper Scissor","Alie","123409"), 
    b2("Harry Potter","JK Rowling","090807"), 
    b3("Kite Runner","Khaled","080604");

    Library l;
    l.AddBooks(b1);  l.AddBooks(b2);  l.AddBooks(b3);
    l.Search("090807","Harry Potter");
    l.Remove("090807");
    l.Search("090807","Harry Potter");
    return 0;
}
