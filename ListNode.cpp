/*
MARC GIANNANDREA
AC21008
ListNode.cpp:Contains all method definitions for ListNode class
*/
//Not all methods are used in the creation and use of a hashtable however accessor and mutator methods
//were left in to provide extra functionality if later needed
#include <iostream>
#include "ListNode.h"

using namespace std;
//Inclusion of ListNode definition for ease of refrencing
/*
class ListNode{
	private:
		Person* data;
		ListNode* next;
	
	public:
		ListNode(Person* value);
		~ListNode();
		ListNode* getNext();
		void setNext(ListNode* n);
		Person* getData();
		void setData(Person* p);
};
*/

//Constructor of ListNode. Takes in a Person class.
ListNode::ListNode(Person* value){
	data  = value;
	next = NULL; 
}
//Destructor of ListNode.
ListNode::~ListNode(){
	data  = NULL;
	next = NULL; 
}
//Returns ListNode's next node
ListNode* ListNode::getNext(){
	return next;
}
//Returns the Person class stored in the node
Person* ListNode::getData(){
	return data;
}
//Used to set the Person class stored in the node
void ListNode::setData(Person* p){
	data = p;
}
//Sets the Nodes next node
void ListNode::setNext(ListNode* n){
	next = n;
}
