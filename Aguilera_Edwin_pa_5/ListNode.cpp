#include "ListNode.h"



ListNode::ListNode (int newRecordNum,int newID, string newName, string newEmail,int newCredit, string newMajor, string newLevel)
{

	mRecordNum = newRecordNum;
	mId = newID;
	mEmail = newEmail;
	mCredits = newCredit; // make string, advice from andy
	mName = newName;
	mLevel = newLevel;
	mMajor = newMajor;
	this->pNext = NULL;


}
ListNode ::ListNode(string array[])
{
	

}


ListNode::ListNode (ListNode &copy)
{
	
	pNext = copy.getNextPtr();
	mRecordNum = copy.getRecordNum();
	mMajor = copy.getMajor();
	mId = copy.getID();
	mEmail = copy.getEmail();
	mCredits = copy.getCredit();
	mLevel = copy.getLevel();
	mName = copy.getName();

	



}

ListNode::~ListNode ()
{
	cout<<mRecordNum<<endl;
	cout<<mName<<endl;
	cout<<mCredits<<endl;
	cout<<mEmail<<endl;
	cout<<mLevel<<endl;
	cout<<mMajor<<endl;
	cout<<mName<<endl;
	cout<<mId<<endl;

	delete(this);

}


ListNode & ListNode::operator= (const ListNode &rhs)
{
	if(this != &rhs)
	{

		this->mRecordNum = rhs.mRecordNum;
		this->mMajor= rhs.mMajor;
		this->mEmail=  rhs.mEmail;
		this->mId= rhs.mId;
		this->mLevel= rhs.mLevel;
		this->mCredits= rhs.mCredits;
		this->mName= rhs.mName;
		



		this->pNext= rhs.pNext;
		
		

	}
	return *this;

}
int ListNode::getRecordNum () const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return mRecordNum;
	
	

}
int ListNode::getID () const
{
	return mId;


}
string ListNode:: getName () const
{
	return mName;
}

string ListNode:: getEmail () const
{


	return mEmail;
}
		
int ListNode::getCredit() const
{
	return mCredits;

}
string ListNode::getMajor () const
{
	return mMajor;

}
string ListNode::getLevel () const
{
	return mLevel;

}


ListNode * ListNode::getNextPtr () const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return pNext;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// fill in other getters

void ListNode::setRecordNum (const int newRecordNum) // the const in this context ensures newData can't be modified
{
	mRecordNum = newRecordNum;
}

void ListNode::setIDnum(int newID)
{
	mId = newID;

}

void ListNode:: setName(string newName)
{
	mName = newName;
}

void ListNode::setEmial(string newEmail)
{
	mEmail = newEmail;

}

void ListNode::setCredit(int newCredit)
{

	mCredits = newCredit;
}

void ListNode:: setMajor(string newMajor)
{
	mMajor=newMajor;
}

void ListNode::setLevel(string newLevel)
{
	mLevel = newLevel;

}


void ListNode::setNextPtr ( ListNode *pNewNext) // the const in this context ensures pNewNext can't be modified
{
	pNext = pNewNext; 
}