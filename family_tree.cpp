#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class FT {
public:
    string name, gen, dob, spouseName;
    int age;
    FT *lc, *rc;

    void create();
    void insert(FT *root, FT *next);
    void display(FT *root, int level);
    void CntR();
    int height(FT *root);
    void displayCurrentGeneration(FT *root, int level);
}*root;

void FT::create() {
    int ch;
    FT *next;
    root = new FT;
    cout << "ENTER the family member INFORMATION: \n";
    cout << "Enter NAME: ";
    cin >> root->name;
    cout << "Enter DOB: ";
    cin >> root->dob;
    cout << "Enter GENDER: ";
    cin >> root->gen;
    cout << "Enter AGE: ";
    cin >> root->age;
    if (root->gen == "male") {
                cout << "Enter SPOUSE NAME: ";
                cin >> root->spouseName;
            } else {
                root->spouseName = "null";
            }
    root->lc = root->rc = NULL;

    do {
        cout << "Do you want to add a new family member? (0/1) no/yes: ";
        cin >> ch;
        if (ch == 1) {
            next = new FT;
            cout << "ENTER the family member INFORMATION: \n";

            cout << "Enter NAME: ";
            cin >> next->name;
            cout << "Enter DOB: ";
            cin >> next->dob;
            cout << "Enter GENDER: ";
            cin >> next->gen;
            cout << "Enter AGE: ";
            cin >> next->age;
            if (next->gen == "male") {
                cout << "Enter SPOUSE NAME: ";
                cin >> next->spouseName;
            } else {
                next->spouseName = "null";
            }
            next->lc = next->rc = NULL;
            insert(root, next);
        }

    } while (ch == 1);

}

void FT::insert(FT *root, FT *next) {
    char chr;
    FT *temp;
    cout << "Enter where to insert, Left(l) OR Right(r): ";
    cin >> chr;
    if (chr == 'l' || chr == 'L') {
        if (root->lc == NULL) {
            root->lc = next;
        } else {
            insert(root->lc, next);
        }

    }
    if (chr == 'r' || chr == 'R') {
        if (root->rc == NULL) {
            root->rc = next;
        } else {
            insert(root->rc, next);
        }
    }
}

void FT::display(FT *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << "==========================================================================================" << endl;
        cout << "Name\t\tDOB\t\tGender\t\tAge\t\tSpouse Name" << endl;
        cout << "==========================================================================================" << endl;
        cout << root->name << "\t\t" << root->dob << "\t\t" << root->gen << "\t\t" << root->age << "\t\t" << root->spouseName << endl;
    } else if (level > 1) {
        display(root->lc, level - 1);
        display(root->rc, level - 1);
    }
}

void FT::CntR() {
    cout << "Total family members are: " << endl;
}

int FT::height(FT *root) {
    if (root == NULL) return 0;
    return max(height(root->lc), height(root->rc)) + 1;
}

void FT::displayCurrentGeneration(FT *root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->name << "\t\t" << root->dob << "\t\t" << root->gen << "\t\t" << root->age << "\t\t" << root->spouseName << endl;
    } else if (level > 1) {
        displayCurrentGeneration(root->lc, level - 1);
        displayCurrentGeneration(root->rc, level - 1);
    }
}

int main() {
    int ch;
    FT t;

    do {
        cout << "\nEnter your Choice: ";
        cout << "\n1. CREATE";
        cout << "\n2. DISPLAY";
        cout << "\n3. COUNT of Members";
        cout << "\n4. Height of Tree";
        cout << "\n5. Display Current Generation";
        cout << "\n6. EXIT\n";

        cin >> ch;

        switch (ch) {
            case 1:
                t.create();
                break;
            case 2:
                int levels;
                cout << "Enter the number of generations to display: ";
                cin >> levels;
                for (int i = 1; i <= levels; ++i) {
                    t.display(root, i);
                }
                break;
            case 3:
                t.CntR();
                break;
            case 4:
                cout << "Height of the tree: " << t.height(root) << endl;
                break;
            case 5:
                cout << "Enter the generation to display: ";
                int genLevel;
                cin >> genLevel;
                cout << "Current generation info:" << endl;
                t.displayCurrentGeneration(root, genLevel);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid Choice!!";
                break;
        }
    } while (ch != 6);

    return 0;
}
