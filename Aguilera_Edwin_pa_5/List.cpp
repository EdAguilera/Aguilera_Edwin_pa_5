#include "List.h"




List::List ()                    // default constructor; will always set mpHead to NULL
{
	mpHead = NULL;
}

List::~List ()                   // destructor - implicitly invoked when a List object leaves scope
{
	destroyList ();
}


ListNode * List::getHeadPtr () const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr ( ListNode *pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

void List::insertAtFront (int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel)     // inserts newData at the beginning or front of the list
{
	ListNode* newNode = new ListNode(newRecordNum,newID,  newName, newEmail,newCredit,  newMajor,  newLevel);
		
	ListNode* curr = mpHead;

	
	//insert at head
	if(isEmpty())// calls the isempty function returns bool
	{
		mpHead = newNode;
		
		
	}

	else
	{
	newNode->pNext = mpHead;
	mpHead= newNode;
	
	}
	

}

bool List::isEmpty ()                            // determines if the list is empty  
{
	if(mpHead ==NULL)
	{

		return true;

	}
	else
	{

		return false;

	}
}

ListNode * List::makeNode ( int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel)    // will only call within insert functions
{

	ListNode* newNode = NULL;
		newNode = new ListNode(newRecordNum,newID, newName, newEmail,newCredit, newMajor, newLevel);

	newNode->setRecordNum(newRecordNum);
	return newNode;

}
		
void List::destroyList ()                        // deletes each node to free memory; will call in the destructor
{
	ListNode *pTemp =NULL;
	while(mpHead!= NULL)
	{
		pTemp = mpHead;
		mpHead= mpHead->pNext;
		delete pTemp;




	}


}

void List::printList()
{
	if(isEmpty())
	{
		cout<<"list is empty"<<endl;
		return;

	}
	else
	{
		ListNode* temp = mpHead;

	while(temp != 0)
	{
		cout<<temp->getRecordNum()<<endl;
		cout<<temp->getName()<<endl;
		cout<<temp->getEmail()<<endl;
		cout<<temp->getID()<<endl;
		cout<<temp->getCredit()<<endl;
		cout<<temp->getMajor()<<endl;
		cout<<temp->getLevel()<<endl;






		temp = temp->pNext;


	}

	}
}
 void List::Import_course_list(ListNode* phead)
{
	cout << "Enter a filename: ";
	string filename;
	cin >> filename;

	ifstream input;
	input.open (filename, std::ios::in);  // out for read mode
	
	//ifstream input2 (filename.c_str (), std::ios::in); // c like string for filename

	string str[100];
	char myArray[100];
	int i = 0, count= 0;
	int newrecord = 0;
	int ID = 0;
	string name = "";
	string email = "";
	int  credits = 0;
	string major = "";
	string level = "";


while (!input.eof ())
	{

	input.getline (myArray, 100, ','); // will read in a string up to the ','
		str[i] = myArray;
		count++;
		i++;

		if(count == 7)// time to make a new node and equeue with the 7 strings
		{

			// make another variable for the node number
		
			//possibly change the peramiters for other fucntions
			//dont forget about str[0] which contains the number of student
			newrecord = stoi(str[1]);

			 ID = stoi(str[2]);
			 name = str[3];
			 email = str[4];
			 credits = stoi(str[5]); // make sure to change peramiters to execpt credits as int
			 major = str[6];
			 level = str[7];


			
			 //int newRecordNum,int newID, string newName, string newEmail,string newCredit, string newMajor, string newLevel

			 //ListNode* newNode = new ListNode(newrecord,ID, name,email,credits,major,level);
			 insertAtFront(newrecord,ID, name,email,credits,major,level);
			 i = 0;
			



		}
	}

	}
		


void List::deleteNode()
{

	int searchkey=0;
	ListNode *temp=NULL;

	cout<<"please enter the number you would like to delete"<<endl;
	cin>>searchkey;
	temp = mpHead;
	while((temp != NULL) && (searchkey != temp->mRecordNum))
	{

		temp = temp->pNext;

	}

	if(temp != NULL)
	{
		mpHead = mpHead->pNext;
		delete temp;
	}
	
	return;

}
int List::get_option(void)
{
	int option = 0;

	scanf ("%d", &option);
	fflush (stdin); // clears out whats left in the keyboard stream

	return option;


}
void List::displayMenu()
{

	cout<<"Absence Tracker"<<endl;
	cout<<"******************"<<endl;
	cout << "1. import course list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences"<<endl;
	cout <<	"6. Generate report"<<endl;
	cout <<	"7. Exit"<<endl;


}

void List::run_app()
{

	int newdata = 5, new2 = 0, option = 0;
	ListNode* phead= NULL;
	bool status = true;

	int mRecordNum = 0;//record number
		int mId = 11409911;//ID number
		string mName="Edwin"; // Name(last,first)
		string mEmail="Ed-a@Live.com"; // emial
		int mCredits= 15; //nmber of credits for class or AU for audit
		string mMajor="computer sci"; // major of student
		string mLevel="freshman"; // student acodemic status like freshman or sophomore


	List E;
	do{
	 
		displayMenu();
	option = get_option();
	system("cls");
	


		switch(option)
		{

			//int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel);  
		case 1:	 
			cout<<"enter record"<<endl;
			cin>>mRecordNum;
			E.insertAtFront(mRecordNum,mId,  mName, mEmail,mCredits, mMajor,mLevel);// make sure to check if it prints off stings and other memebrs but now start working on reading from the file.
		break;

		case 2: E.printList();
			break;
		case 3:E.deleteNode();
			break;
		case 4:E.Import_course_list(phead);
			break;
		
		}
	}while (status != false);

	





}