//Library Management System....
#include<iostream>
#include<cstring>
using namespace std;
 
int MAX=100;
class Library{
    public:
     int book_id, price, copies;
     char *title, *author;
     
     void addBook();
     void deleteBook();
    
};

void Library::addBook(){
  
   title=new char;
   author=new char;
   cout<<"\nBook ID : ";
   cin>>book_id;
   cout<<"\nTitle : ";
   cin>>title;
   cout<<"\nAuthor : ";
   cin>>author;
   cout<<"\nPrice : ";
   cin>>price;
   cout<<"\nCopies : ";
   cin>>copies;
}



int main(){
    
    Library b[MAX];
    int choice,a=1,i;
    int search_id;
    int entries;
    int index, position;
    cout<<"Currently the library is empty\n";
    
    do{
    cout << "1. Add Books\n2. Display Books\n3. Search Book by ID\n4. Modify Book\n5. Delete Book\n6. Insert new record\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
         switch (choice) {
            case 1: {
                
                 cout<<"Enter the no of entries to make :";
                 cin>>entries;
                 for(i=0; i<entries; i++){
                     cout<<"\nRecord of "<<a<<" book :\n";
                     b[i].addBook();
		     a++;
                 }
                  break;
                }
            case 6:
            
            
                     cout<<"\nRecord of "<<a<<" book :\n";
                     b[entries].addBook();
		     entries++;
                 
                  break;
                
        
            case 2: {
    		cout<<"BOOK ID | TITLE   | AUTHOR  | PRICE | COPIES|\n";
		cout<<"---------------------------------------------\n";
		for(i=0; i<entries; i++){
			cout<<b[i].book_id<<"\t|"<<b[i].title<<"\t|"<<b[i].author<<"\t|"<<b[i].price<<"\t|"<<b[i].copies<<"\t|\n";
			cout<<"---------------------------------------------\n";
		}
               
                break;
            }
            
            case 3: {
		cout<<"Enter the Book ID to search :";
                cin>>search_id;
		for(i=0; i<entries; i++){
			if(search_id==b[i].book_id){
			cout<<"BOOK FOUND ! Book Info is as follow :\n";
			cout<<"Book ID :"<<b[i].book_id<<endl;
			cout<<"BOOK TITLE :"<<b[i].title<<endl;
			cout<<"Book AUTHOR :"<<b[i].author<<endl;
			cout<<"Book PRICE :"<<b[i].price<<endl;
			cout<<"Book COPIES :"<<b[i].copies<<endl;
			break;
			}	
		}
                break;
            }

            case 4: {
		cout<<"Enter the Book ID whose Info you want to update :";
                cin>>search_id;
                for(i=0; i<entries; i++){
		if(search_id==b[i].book_id){
			cout<<"BOOK FOUND ! Enter new Book Info :\n";
			cout<<"Book ID :";
			cin>>b[i].book_id;
			cout<<"BOOK TITLE :";
			cin>>b[i].title;
			cout<<"Book AUTHOR :";
			cin>>b[i].author;
			cout<<"Book PRICE :";
			cin>>b[i].price;
			cout<<"Book COPIES :";
			cin>>b[i].copies;
			break;
			}	
                }
                break;
            }

             
            case 5: {
            	  cout << "\nEnter the Book ID of book to be deleted: ";
    		  cin>>search_id;
    		  for(i=0; i<entries; i++){
		  if(search_id==b[i].book_id){
		  do{
		    b[i]=b[i+1];
		    i++;
		    }while(i<entries);
		    entries--;
		  
                  break;
                  
            }
            }
            }

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
    
