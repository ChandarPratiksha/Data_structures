#include<iostream>
using namespace std;

class lms {
public:
    int bid, price;
    string title, author, ISBN;
    bool availabilityStatus;
    lms *next, *temp;
    void create1();
    void create();
    void display();
    void insertNode();
    void deleteNode();
    void insertAtBeginning();
    void insertAtEnd();
    void insertAtMiddle();
    void deleteAtBeginning();
    void deleteAtEnd();
    void deleteByBookID(int bookID);
    void searchByBookID(int bookID);
}*start;

void lms::create1() {
    int numBooks;
    cout << "Enter the number of books you want to create: ";
    cin >> numBooks;

    for (int i = 0; i < numBooks; ++i) {
        temp = new lms;
        cout << "Enter the details for book " << i + 1 << ":\n";
        cout << "Book ID, Title, Author, ISBN, Price, Availability Status (1 for available, 0 for unavailable): ";
        cin >> temp->bid >> temp->title >> temp->author >> temp->ISBN >> temp->price >> temp->availabilityStatus;
        temp->next = NULL;
        temp->next = start;
        start = temp;
    }
}

void lms::create() {
    temp = new lms;
    cout << "Enter the book ID, Title, Author, ISBN, Price, Availability Status (1 for available, 0 for unavailable) : \n";
    cin >> temp->bid >> temp->title >> temp->author >> temp->ISBN >> temp->price >> temp->availabilityStatus;
    temp->next = NULL;
    if (start == NULL)
        start = temp;
    else {
        temp->next = start;
        start = temp;
    }
}

void lms::display() {
    temp = start;
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Book ID | Title   | Author | ISBN         | Price | Availability Status\n";
    while (temp != NULL) {
        cout << "---------------------------------------------------------------------------------------------\n";
        cout << temp->bid << "\t| " << temp->title << " | " << temp->author << " | " << temp->ISBN << " | " << temp->price << " | " << (temp->availabilityStatus ? "Available" : "Unavailable") << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------------------------------------------\n";
}

void lms::insertNode() {
    int insertChoice;
    cout << "Where would you like to insert the new node?\n";
    cout << "1. At the Beginning\n";
    cout << "2. At the End\n";
    cout << "3. In the Middle\n";
    cin >> insertChoice;

    switch (insertChoice) {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtMiddle();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void lms::deleteNode() {
    int deleteChoice;
    cout << "Where would you like to delete the node from?\n";
    cout << "1. At the Beginning\n";
    cout << "2. At the End\n";
    cout << "3. By Book ID\n";
    cin >> deleteChoice;

    switch (deleteChoice) {
        case 1:
            deleteAtBeginning();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            int bookID;
            cout << "Enter the Book ID to delete: ";
            cin >> bookID;
            deleteByBookID(bookID);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

void lms::insertAtBeginning() {
    create();
}

void lms::insertAtEnd() {
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    create();
    temp->next = start;
}

void lms::insertAtMiddle() {
    int pos, i;
    cout << "Enter the position where you want to insert: ";
    cin >> pos;
    if (pos == 1)
        insertAtBeginning();
    else {
        temp = start;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL)
            cout << "Position out of range\n";
        else {
            create();
            temp->next = start;
        }
    }
}

void lms::deleteAtBeginning() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    start = start->next;
    delete temp;
}

void lms::deleteAtEnd() {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void lms::deleteByBookID(int bookID) {
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    lms *prev = NULL;
    while (temp != NULL && temp->bid != bookID) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Book ID not found\n";
        return;
    }
    if (prev == NULL)
        start = start->next;
    else
        prev->next = temp->next;
    delete temp;
}

void lms::searchByBookID(int bookID) {
    temp = start;
    while (temp != NULL) {
        if (temp->bid == bookID) {
            cout << "Book found:\n";
            cout << "Book ID: " << temp->bid << endl;
            cout << "Title: " << temp->title << endl;
            cout << "Author: " << temp->author << endl;
            cout << "ISBN: " << temp->ISBN << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Availability Status: " << (temp->availabilityStatus ? "Available" : "Unavailable") << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Book with ID " << bookID << " not found\n";
}

int main() {
    int ch;
    lms b;
    do {
        cout << "Enter your choice: \n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT NEW NODE\n";
        cout << "4. DELETE A NODE\n";
        cout << "5. SEARCH BY BOOK ID\n";
        cout << "6. EXIT\n";
        cin >> ch;
        switch (ch) {
            case 1:
                b.create1();
                break;
            case 2:
                b.display();
                break;
            case 3:
                b.insertNode();
                break;
            case 4:
                b.deleteNode();
                break;
            case 5:
                int bookID;
                cout << "Enter the Book ID to search: ";
                cin >> bookID;
                b.searchByBookID(bookID);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 6);

    return 0;
}
