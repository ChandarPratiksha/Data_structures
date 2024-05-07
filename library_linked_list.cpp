#include<iostream>
#include<string>
using namespace std;

class sll {
public:
    int bid, price;
    string title, author, isbn;
    bool status;
    sll* next;
    void insertion();
    void display();
    void display1();
    void searchByTitle(string title);
    void insertNewBook();
    void insertAtStart();
    void insertAtPosition(int position);
    void deleteFirst(); // Delete first record
    void deleteByTitle(string title); // Delete book by title
    void deleteLast(); // Delete last record
}* start;

void sll::insertion() {
    sll* newnode;
    newnode = new sll();
    cout << "\n Book ID :";
    cin >> newnode->bid;
    cout << "Book Title :";
    cin.ignore();
    getline(cin, newnode->title);
    cout << "Book Author :";
    getline(cin, newnode->author);
    cout << "Book ISBN :";
    getline(cin, newnode->isbn);
    cout << "Book Price :";
    cin >> newnode->price;
    cout << "Book Status [Available(1) Unavailable(0)]:";
    cin >> newnode->status;
    cout << endl;

    if (start == NULL) {
        start = newnode;
        start->next = NULL;
        return;
    }

    sll* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void sll::display() {
    sll* temp = start;
    if (start == NULL) {
        cout << "List is empty";
        return;
    }

    while (temp != NULL) {
        cout << "\n Book ID : " << temp->bid;
        cout << "\n Book Title : " << temp->title;
        cout << "\n Book Author : " << temp->author;
        cout << "\n Book ISBN : " << temp->isbn;
        cout << "\n Book Price : " << temp->price;
        cout << "\n Book Status : " << temp->status;
        cout << endl;
        temp = temp->next;
    }
}

void sll::display1() {
    sll* temp;
    temp = start;
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Book ID | Title   | Author | ISBN         | Price | Availability Status\n";
    while (temp != NULL) {
        cout << "---------------------------------------------------------------------------------------------\n";
        cout << temp->bid << "\t| " << temp->title << " | " << temp->author << " | " << temp->isbn << " | " << temp->price << " | " << (temp->status ? "Available" : "Unavailable") << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------------------------------------------\n";
}

void sll::searchByTitle(string title) {
    sll* temp = start;
    bool found = false;
    while (temp != NULL) {
        if (temp->title == title) {
            cout << "\n Book ID : " << temp->bid;
            cout << "\n Book Title : " << temp->title;
            cout << "\n Book Author : " << temp->author;
            cout << "\n Book ISBN : " << temp->isbn;
            cout << "\n Book Price : " << temp->price;
            cout << "\n Book Status : " << temp->status;
            cout << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
        cout << "Book with title \"" << title << "\" not found.\n";
}

void sll::insertNewBook() {
    insertion();
}

void sll::insertAtStart() {
    sll* newnode;
    newnode = new sll();
    cout << "\n Book ID :";
    cin >> newnode->bid;
    cout << "Book Title :";
    cin.ignore();
    getline(cin, newnode->title);
    cout << "Book Author :";
    getline(cin, newnode->author);
    cout << "Book ISBN :";
    getline(cin, newnode->isbn);
    cout << "Book Price :";
    cin >> newnode->price;
    cout << "Book Status [Available(1) Unavailable(0)]:";
    cin >> newnode->status;
    cout << endl;

    newnode->next = start;
    start = newnode;
}

void sll::insertAtPosition(int position) {
    if (position <= 0) {
        cout << "Invalid position.\n";
        return;
    }

    sll* newnode = new sll();
    cout << "\n Book ID :";
    cin >> newnode->bid;
    cout << "Book Title :";
    cin.ignore();
    getline(cin, newnode->title);
    cout << "Book Author :";
    getline(cin, newnode->author);
    cout << "Book ISBN :";
    getline(cin, newnode->isbn);
    cout << "Book Price :";
    cin >> newnode->price;
    cout << "Book Status [Available(1) Unavailable(0)]:";
    cin >> newnode->status;
    cout << endl;

    if (position == 1) {
        newnode->next = start;
        start = newnode;
        return;
    }

    sll* temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void sll::deleteFirst() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    sll* temp = start;
    start = start->next;
    delete temp;
    cout << "First record deleted successfully.\n";
}

void sll::deleteByTitle(string title) {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (start->title == title) {
        sll* temp = start;
        start = start->next;
        delete temp;
        cout << "Record with title \"" << title << "\" deleted successfully.\n";
        return;
    }
    sll* prev = start;
    sll* curr = start->next;
    while (curr != NULL) {
        if (curr->title == title) {
            prev->next = curr->next;
            delete curr;
            cout << "Record with title \"" << title << "\" deleted successfully.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Book with title \"" << title << "\" not found.\n";
}

void sll::deleteLast() {
    if (start == NULL) {
        cout << "List is empty.\n";
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
        cout << "Last record deleted successfully.\n";
        return;
    }
    sll* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Last record deleted successfully.\n";
}

int main() {
    sll s;
    int no, i;
    cout << "Enter the number of book records to insert in the list: ";
    cin >> no;
    cout << endl;
    for (i = 0; i < no; i++) {
        cout << "Enter the info of book " << i + 1 << " : ";
        s.insertion();
    }

    s.display();
    s.display1();

    string search_title;
    cout << "\nEnter the title to search: ";
    cin.ignore();
    getline(cin, search_title);
    s.searchByTitle(search_title);
    
    cout << "\nInsert a new book record:\n";
    s.insertNewBook();
    cout << "\nUpdated list of books:\n";
    s.display1();

    cout << "\nInsert a new book record at the start:\n";
    s.insertAtStart();
    cout << "\nUpdated list of books:\n";
    s.display1();

    s.deleteFirst();
    cout << "\nUpdated list of books:\n";
    s.display1();

    string delete_title;
    cout << "\nEnter the title to delete: ";
    cin.ignore();
    getline(cin, delete_title);
    s.deleteByTitle(delete_title);
    cout << "\nUpdated list of books:\n";
    s.display1();

    cout << "\nDeleting the last record...\n";
    s.deleteLast();
    cout << "\nUpdated list of books:\n";
    s.display1();

    return 0;
}
