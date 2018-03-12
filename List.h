/*
MARC GIANNANDREA
AC21008
List.h:Contains all method & variable prototypes for List class
*/
#include <iostream>
#include "ListNode.h"


#ifndef _LIST_H
#define _LIST_H

class List{   // Declare PERSON struct type
	private:  
			ListNode* head;  // Declare member types  
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
#endif
