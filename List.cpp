/*
MARC GIANNANDREA
AC21008
List.cpp:Contains all method definitions for List class
*/
#include <iostream>
#include <string>
#include "List.h"

using namespace std;
//Inclusion of definition of List class to easily reference
/*
class List{  
	private:  
			ListNode* head;  
			ListNode* tail;  
			int size;
	public:
		List();
		~List();
		int getSize();
		ListNode* getHead();
		ListNode* getTail();
		ListNode* addNode(Person* p);
		bool delNode(Person* p);
		ListNode* searchNode(string name);
};
*/
//Constructor of List. Set default values
List::List(){
	head = NULL;
	tail = NULL;
	size = 0;
}

//Destructor of List. Delete every node in the list and null values
List::~List(){
	ListNode* cur = head;
	while(cur != NULL){
		head = head->getNext();
		delete cur;	
		size--;
		cur = head;
	}
	cur = NULL;
	head = NULL;
	tail = NULL;
	size = 0;
}

//Returns size of list
int List::getSize(){
	return size;
}
//Returns head of list
ListNode* List::getHead(){
	return head;
}
//Returns tail of list
ListNode* List::getTail(){
	return tail;
}
//Adds a node to the list from a person parameter
ListNode* List::addNode(Person* p){
	ListNode* newNode = new ListNode(p);

	//Check if the node is the first to be added 
	if(size == 0){
		head = newNode;
		tail = newNode;
	}else{
		tail->setNext(newNode);
		tail = newNode;
	}
	size++;
	return newNode;
}
//Delete node from the list based on a person class.
bool List::delNode(Person* p){
	//Check if the list size is 0
	if(size == 0){
		return false;
	}

	ListNode* cur = head;
	ListNode* prev = NULL;
	while(cur != NULL){
		//Determine what changes need to be made the other listnodes upon deletion of the stated
		if(cur->getData() == p){
			if(cur == head){
				head = cur->getNext();
			}
			if(cur == tail){
				tail = prev;
			}
			if(prev != NULL){
				prev->setNext(cur->getNext());
			}
			delete(cur);
			size--;
			return true;
		}
		prev = cur;
		cur = cur->getNext();
	}
	return false;
}
//Searches for a node in the list
ListNode* List::searchNode(string name){
	if(size == 0){
		return NULL;
	}

	//Loop through the list and check if the passed name is in the list
	ListNode* cur = head;
	while(cur != NULL){
		if(cur->getData()->getName() == name){
			return cur;
		}
		cur = cur->getNext();
	}
	return NULL;
}
