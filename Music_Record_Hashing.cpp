#include <iostream>
#include <string>
using namespace std;

int key[20], c[20], n;
int i;

class Album {
public:
    int track_no;
    string composer, singer, title;

    void declare();
    void accept();
    void HTable();
    void search();
    void modify();
};

Album h[20];

void Album::declare() {
    cout << "\nEnter the Total No Of Keys: ";
    cin >> n;
    cout << "\nEnter The Keys: ";
    for (i = 0; i < n; i++) {
        cin >> key[i];
    }
    for (i = 0; i < 20; i++) {
        h[i].track_no = -1;
        c[i] = 0;
    }
}

void Album::accept() {
    int no, pos;
    for (i = 0; i < n; i++) {
        no = key[i] % 10;
        pos = no;
        
        do {
            if (h[no].track_no == -1) {
                h[no].track_no = key[i];
                cout << "\n********Enter Music Album Details********";
                cout << "\nEnter Title: ";
                cin >> h[no].title;
                cout << "\nEnter Singer: ";
                cin >> h[no].singer;
               
                cout << "\nEnter Composer: ";
                cin >> h[no].composer;
                break;
            } else {
                no++;
                c[pos] = no;
                if (no >= 20) {
                    no = 0;
                }
            }
        } while (no < 20);
    }
}

void Album::HTable() {
    cout << "\nTrack No\tTitle\tSinger\tComposer\tCollisions";
    for (i = 0; i < 20; i++) {
        cout << "\n" << h[i].track_no << "\t" << h[i].title << "\t" << h[i].singer << "\t" << h[i].composer << "\t" << c[i];
    }
}

void Album::search() {
    int track_no;
    cout << "\nEnter the Track Number to search: ";
    cin >> track_no;

    int pos = track_no % 10;
    int count = 0;
    
    while (count < 20) {
        if (h[pos].track_no == track_no) {
            cout << "\nTrack found: ";
            cout << "\nTrack No: " << h[pos].track_no;
            cout << "\nTitle: " << h[pos].title;
            cout << "\nSinger: " << h[pos].singer;
            cout << "\nComposer: " << h[pos].composer;
            return;
        }
        pos = (pos + 1) % 20;
        count++;
    }
    cout << "\nTrack not found.";
}

void Album::modify() {
    int track_no;
    cout << "\nEnter the Track Number to modify: ";
    cin >> track_no;

    int pos = track_no % 10;
    int count = 0;
    
    while (count < 20) {
        if (h[pos].track_no == track_no) {
            cout << "\nModifying track number " << track_no;
            cout << "\nEnter new title: ";
            cin >> h[pos].title;
            cout << "\nEnter new singer: ";
            cin >> h[pos].singer;
            cout << "\nEnter new composer: ";
            cin >> h[pos].composer;
            cout << "\nTrack modified successfully!";
            return;
        }
        pos = (pos + 1) % 20;
        count++;
    }
    cout << "\nTrack not found.";
}

int main() {
    Album a;
    a.declare();
    a.accept();
    a.HTable();

    // Adding search and modify functionality for demonstration purposes
    a.search();  // Search for a track
    a.modify();  // Modify a track

    cout << "\nUpdated hash table:";
    a.HTable();  // Display the hash table after modification

    return 0;
}
