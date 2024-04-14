#include<iostream>
#include<string>
using namespace std;

int key[20],c[20],n;
int i;

class CITY
{  
	public:
	int patient_id,age;
	string name,gen,plan,history;
	void declare();
	void HTable();
	void accept();
	void search();
	void deletE();
	void modify();
}h[20];

void CITY::declare()
{
	cout<<"\nEnter the Total No Of Patients: ";
	cin>>n;
	cout<<"\nEnter The Patient Id: ";
	for(i=0;i<n;i++)
	{
	cin>>key[i];
	}
	for(i=0;i<20;i++)
	{
	
		h[i].patient_id=-1;
		c[i]=0;
		
	}
}

void CITY::accept()
{
	int no,pos;
	for(i=0;i<n;i++)
	{
		no=key[i]%10;
		pos=no;
		
		do
		{
			if(h[no].patient_id==-1)
			{
			    h[no].patient_id=key[i];
			    cout<<"\n********Enter Music Patient Details********";
			    
				cout<<"\nEnter Patient Name: ";
				cin>>h[no].name;
				cout<<"\nEnter Age: ";
				cin>>h[no].age;
				cout<<"\nEnter gender: ";
				cin>>h[no].gen;
				cout<<"\nEnter History: ";
				cin>>h[no].history;
				cout<<"\nEnter Treatment Plan: ";
				cin>>h[no].plan;
				break;
				
			}
			else
			{
				no++;
				c[pos]=no;
				if(no>10)
				{
					no=0;
				}
			}
		}while(no<10);
	}
}

void CITY::HTable()
{
	
	for(i=0;i<20;i++)
	{
		cout<<"\n";
		cout<<"\n"<<h[i].patient_id<<"\t"<<h[i].name<<"\t"<<h[i].age<<"\t"<<h[i].gen<<"\t"<<h[i].plan<<"\t"<<h[i].history<<"\t"<<c[i];
	}
}

void CITY::search()
{
    int patient_key;
    int no,f=0;
    cout<<"\nEnter Patient Id to SEARCH: ";
    cin>>patient_key;
    for(i=0;i<n;i++)
    {
        no=patient_key%10;
        if(h[no].patient_id==patient_key)
        {
            f=1;
            cout<<"\nRecord is Found";
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

void CITY::deletE()
{
    int patient_key, no, next_pos,nnext_pos;
    bool record_found = false;
    
    cout << "\nEnter Patient Id to DELETE: ";
    cin >> patient_key;

    // Calculate initial index from the patient key
    no = patient_key % 10;

    // Check if the patient ID is at the initial position
    if (h[no].patient_id == patient_key) {
        // Found the record at the initial position, delete it
        h[no].patient_id = -1;
        h[no].name = "";
        h[no].age = 0;
        h[no].gen = "";
        h[no].history = "";
        h[no].plan = "";
        
        // Update chain length array if necessary
        if (c[no] != 0) {
            // Move the next position's data back to the current position
            next_pos = c[no];
            h[no].patient_id = h[next_pos].patient_id;
            h[no].name = h[next_pos].name;
            h[no].age = h[next_pos].age;
            h[no].gen = h[next_pos].gen;
            h[no].history = h[next_pos].history;
            h[no].plan = h[next_pos].plan;
            
            // Clear the next position and adjust the chain
            h[next_pos].patient_id = -1;
            h[next_pos].name = "";
            h[next_pos].age = 0;
            h[next_pos].gen = "";
            h[next_pos].history = "";
            h[next_pos].plan = "";
            c[no] = 0;
        }
        
        record_found = true;
        cout << "\nRecord deleted successfully at position " << no;
    }
    if (h[no].patient_id != patient_key) {
        // Patient ID not found at the initial position
        if (c[no] != 0) {
            // Follow the chain length array to the next position
            next_pos = c[no];
            
            // Check if the patient ID is at the next position
            if (h[next_pos].patient_id == patient_key) {
                // Found the record at the next position, delete it
                h[next_pos].patient_id = -1;
                h[next_pos].name = "";
                h[next_pos].age = 0;
                h[next_pos].gen = "";
                h[next_pos].history = "";
                h[next_pos].plan = "";
                
            if (c[next_pos] != 0) {
            // Move the next position's data back to the current position
            nnext_pos = c[next_pos];
            h[next_pos].patient_id = h[nnext_pos].patient_id;
            h[next_pos].name = h[nnext_pos].name;
            h[next_pos].age = h[nnext_pos].age;
            h[next_pos].gen = h[nnext_pos].gen;
            h[next_pos].history = h[nnext_pos].history;
            h[next_pos].plan = h[nnext_pos].plan;
            
            // Clear the next position and adjust the chain
            h[nnext_pos].patient_id = -1;
            h[nnext_pos].name = "";
            h[nnext_pos].age = 0;
            h[nnext_pos].gen = "";
            h[nnext_pos].history = "";
            h[nnext_pos].plan = "";
            c[next_pos] = c[nnext_pos];
        }
                
                record_found = true;
                cout << "\nRecord deleted successfully at chained position " << next_pos;
            }
        }
    }
    
    else {
        cout << "\nRecord not found";
    }
}

void CITY::modify()
{
    int patient_key;
    int no,f=0;
    cout<<"\nEnter Patient Id to MODIFY: ";
    cin>>patient_key;
    for(i=0;i<n;i++)
    {
        no=patient_key%10;
        if(h[no].patient_id==patient_key)
        {
            f=1;
            
            cout<<"\nEnter New NAME: ";
            cin>>h[no].name;
            cout<<"\nEnter AGE: ";
            cin>>h[no].age;
            cout<<"\nEnter GENDER: ";
            cin>>h[no].gen;
            cout<<"\nEnter HISTORY RECORD: ";
            cin>>h[no].history;
            cout<<"\nEnter New TREARMENT PLAN: ";
            cin>>h[no].plan;
            cout<<"\nRecord modified successfully";
            
            break;
        }
        else
        {
            f=0;
            cout<<"\nRecord is not Found";
            break;
        }
    }
}

int main()
{
	int ch;
	CITY c;

	do {
		cout << "\nEnter your Choice: ";
		cout << "\n1. INSERT Patient NO's";
		cout << "\n2. Insert Patient DATA";
		cout << "\n3. DISPLAY";
		cout << "\n4. SEARCH Patient";
		cout << "\n5. DELETE Patient";
		cout << "\n6. MODIFY Patient \n7. EXIT\n";

		cin >> ch;

		switch (ch)
		{
		case 1:
			c.declare();
			cout<<"\n| PATIENT ID |\t NAME |\t AGE |\t GENDER |\t HISTORY |\t PLAN |\tCHain\n";
			c.HTable();
			break;
		case 2:
			c.accept();
			break;
		case 3:
		    cout<<"\n| PATIENT ID |\t NAME |\t AGE |\t GENDER |\t HISTORY |\t PLAN |\tCHain\n";
			c.HTable();
			break;
		case 4:
			c.search();
			break;
		case 5:
			c.deletE();
			break;
		case 6:
			c.modify();
			break;
		case 7:
			exit(0);
			break;
		default:
			cout << "Invalid Choice!!";
			break;
		}
	} while (ch != 8);

	return 0;
}
