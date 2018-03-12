/*
MARC GIANNANDREA
AC21008
ListNode.h:Contains all method & variable prototypes for ListNode class
*/
#include <iostream>

#ifndef _LISTNODE_H
#define _LISTNODE_H

#include "Person.h"

using namespace std;

class ListNode{
	private:
		Person* data;//Person class for storing a person
		ListNode* next;//Next listnode in the list
	
	public:
		ListNode(Person* value);//Constructor of ListNode which takes in a person class
		~ListNode();//Destructor of ListNode
		ListNode* getNext();// Returns next node in the list
		void setNext(ListNode* n);//Sets the Nodes next node
		Person* getData();//Returns the person class in ListNode
		void setData(Person* p);//Set the person class in ListNode
};
#endif
