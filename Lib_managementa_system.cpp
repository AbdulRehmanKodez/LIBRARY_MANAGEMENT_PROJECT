#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book{
    int id;
    string title;
    string author;
    bool isAvaliable;
    string Borrowedby;
};
vector<Book>library;
//-------------------ADD BOOK FUNCTION---------------
 void add_book(){
   cout << "\n╔══════════════════════════════╗\n";
cout << "║          ADD BOOK            ║\n";
cout << "╚══════════════════════════════╝\n";

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

   cout << "\n╔══════════════════════════════╗\n";
cout << "║         REMOVE BOOK          ║\n";
cout << "╚══════════════════════════════╝\n";
     int id;
      cout<<"Enter the id of book you want to remove"<<endl;
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
      cout << "\n╔══════════════════════════════╗\n";
cout << "║          ALL BOOKS          ║\n";
cout << "╚══════════════════════════════╝\n";
         int num=0;
        if (library.empty()) {
           cout<<"There is no Books to show";
           return;
        }

        for (const Book& book : library) {
         num++;
         cout<<"--------------------Book no "<<num<<" ---------------"<<endl;
          cout<<"ID "<< book.id<<endl;
          cout<<"Title "<< book.title<<endl;
          cout<<"Author "<< book.author<<endl;
          cout<<"Borrowed "<< (book.isAvaliable==1?"No":"Yes")<<endl;
          if (book.isAvaliable==0) {
            cout<<"Borrower name is: "<< book.Borrowedby<<endl;
          }
        }

     }

     //------------------UPDATE BOOK-----------------------

     void update_book(){

     cout << "\n╔══════════════════════════════╗\n";
cout << "║         UPDATE BOOK          ║\n";
cout << "╚══════════════════════════════╝\n";
     int id;
      cout<<"Enter the id of book you want to update"<<endl;
      cin>>id;
      cin.ignore();
      for (Book& book : library) {
           
           if (id==book.id) {
             cout << "Enter new title: ";
            getline(cin, book.title);

            cout << "Enter new author: ";
            getline(cin, book.author);

            cout << "Book updated successfully.\n";
            return;
           }

      }
       
         cout<<"Book with id : "<<id<<" not found\n";
     }
     
     //---------------SEARCH A SINGLE BOOK--------------

     void search_book(){

   cout << "\n╔══════════════════════════════╗\n";
cout << "║         SEARCH BOOK          ║\n";
cout << "╚══════════════════════════════╝\n";
     int id;
      cout<<"Enter the id of book you want to search"<<endl;
      cin>>id;
      cin.ignore();
      for ( Book& book : library) {
           
           if (id==book.id) {
              cout<<"ID "<< book.id<<endl;
          cout<<"Title "<< book.title<<endl;
          cout<<"Author "<< book.author<<endl;
          cout<<"Borrowed "<< (book.isAvaliable==1?"No":"Yes")<<endl;
          if (book.isAvaliable==0) {
            cout<<"Borrower name is: "<< book.Borrowedby<<endl;
          }
          else if(book.isAvaliable==1){
            
             char choice;
            cout<<"Want to Borrow?\nY/y if yes -- "<<endl;
            cin>>choice;
            cin.ignore();
            switch (choice) {
            case 'y':
                case 'Y':
             cout<<"Enter Borrower name\n";
             getline(cin,book.Borrowedby);
             book.isAvaliable=false;
             cout << "Book borrowed successfully.\n";
             break;
             default:
             break;
            }
            
          }

            
            return;
           }

      }
       
         cout<<"Book with id : "<<id<<" not found\n";
     }
 
int main(){

    for ( ;;) {
      cout << "\n╔═══════════════════════════════╗\n";
cout << "║  LIBRARY MANAGEMENT SYSTEM   ║\n";
cout << "╚═══════════════════════════════╝\n";
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
    case 3:
    update_book();
    break;
    case 4:
    search_book();
    break;
    case 5:
    display_all_books();
    break;
    case 0:
    return 0;
    }
    }
    
    
    


}