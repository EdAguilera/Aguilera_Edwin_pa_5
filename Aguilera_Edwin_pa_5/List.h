#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
#include <fstream>
#include <string>
#include <cstring> 

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;

// This class defines a container for a list; it's a singly linked list
class List
{
	public:
		List ();                    // default constructor; will always set mpHead to NULL
		List (List &copyList);      // copy constructor - implicitly invoked when a List object is passed-by-value
		~List ();                   // destructor - implicitly invoked when a List object leaves scope

		List & operator= (const List &rhs); // overloaded assignment operator - must perform a deep copy

		friend ListNode;
		// getter
		ListNode * getHeadPtr () const;     // returns a copy of the address stored in mpHead

		// setter
		void setHeadPtr (ListNode *pNewHead); // modifies mpHead
		
	   void insertAtFront (int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel);     // inserts newData at the beginning or front of the list
		    // inserts newData at the end of the list

		bool isEmpty ();                            // determines if the list is empty  

		int deleteAtFront ();                       // deletes the node at the front of the list
		void deleteNode ();    // deletes the node with data == searchValue
		                      // deletes the node at the end of the list

		void printList ();                          // visits each node, print the node's data - we could also overload the stream insertion << operator to print the list
		void Import_course_list(ListNode* mpHead);

		void displayMenu();
		int get_option(void);

		int getMenuOption() const;
		void run_app();
	
	private:
		ListNode *mpHead;

		// yes, we can make member functions private as well
		ListNode * makeNode (int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel);    // will only call within insert functions
		void destroyList ();                        // deletes each node to free memory; will call in the destructor
};

#endif