#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book{
    int id;
    string title;
    string author;
    bool isAvaliable;
};
vector<Book>library;
//-------------------ADD BOOK FUNCTION---------------
 void add_book(){
    Book book;
   cout<<"Enter book id\n";
   cin>>book.id;
   cin.ignore();

for (const Book& b : library) {
    if (b.id == book.id) {
       cout<<"Book id already exist";
       return;
    }
}

   cout<<"Enter book title\n";
   getline(cin,book.title);

   cout<<"Enter book author\n";
   getline(cin,book.author);

  book.isAvaliable= true;

  library.push_back(book);
 }


 //------------------------REMOVE BOOK--------------
 void remove_book(){

    
     int id;
      cout<<"Enter the id of book you want to remove";
      cin>>id;
     for (int i=0; i<library.size(); i++) {
     if (library[i].id==id) {
              
        library.erase(library.begin()+i);
        cout<<"Book removed sucessfully";
        return;
     }
     }
       
         cout<<"Book with id : "<<id<<" not found\n";
     }
      

     //------------------- DISPLAY ALL BOOKS-------------
     void display_all_books(){

        if (library.empty()) {
           cout<<"There is no Books to show";
           return;
        }

        for (const Book& book : library) {
          cout<<"ID "<< book.id<<endl;
          cout<<"Title "<< book.title<<endl;
          cout<<"Author "<< book.author<<endl;
          cout<<"Borrowed "<< (book.isAvaliable==1?"No":"Yes")<<endl;
        }

     }
     
 
int main(){

    for ( ;;) {
    cout<<"1 for Add a Book"<<endl;
    cout<<"2 for Removing a Book"<<endl;
    cout<<"3 for Updating a Book"<<endl;
    cout<<"4 for Searching a Book"<<endl;
    cout<<"5 for Displaying all Books"<<endl;
    cout<<"0 To exit"<<endl;
    int num;
    cin>>num;

    switch (num) {
    case 1:
    add_book();
    break;
    case 2:
    remove_book();
    break;
    case 5:
    display_all_books();
    break;
    case 0:
    return 0;
    }
    }
    
    
    


}