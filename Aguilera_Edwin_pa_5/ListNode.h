#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// This class defines a node, which will always be dynamically allocated
class ListNode
{
	public:
		/*ListNode();*/
		ListNode (int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel);// constructor - "constructs" a ListNode; initializes the object
		/*, int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel*/

		 ListNode(string array[]);
		ListNode (ListNode &copy);  // copy constructor - implicitly invoked when a ListNode object is passed-by-value
		friend class List;
		~ListNode ();               // destructor - implicitly invoked when a ListNode object leaves scope

		ListNode & operator= (const ListNode &rhs);

		// getters
		int getRecordNum () const; 
		int getID () const;
		string getName () const;
		string getEmail () const;
		int getCredit() const;
		string getMajor () const;
		string getLevel () const;




		ListNode * getNextPtr () const;      // used to retrieve a copy of the node's next pointer

		// setters
		
		void setRecordNum (int newRecordNum);
		void setIDnum(int newID);
		void setName(string newName);
		void setEmial(string newEmail);
		void setCredit(int newCredit);
		void setMajor(string newMajor);
		void setLevel(string newLevel);

		
		
		
		
		void print_Record();
		bool ListNode:: edit_plan();

		
		// used to modify the data in the node
		void setNextPtr (ListNode * pNewNext); // used to modify the node's next pointer

	private:
		int mRecordNum; //record number
		int mId; //ID number
		string mName; // Name(last,first)
		string mEmail; // emial
		int mCredits; //nmber of credits for class or AU for audit
		string mMajor; // major of student
		string mLevel; // student acodemic status like freshman or sophomore


		ListNode *pNext;            // should be set to NULL in the constructor
};

#endif