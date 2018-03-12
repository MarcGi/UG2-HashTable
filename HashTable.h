/*
MARC GIANNANDREA
AC21008
150014251
HashTable.h:Contains all method & variable protypes for HashTable class
*/
#include <vector>
#include <iostream>

#ifndef _HASHTABLE_H
#define _HASHTABLE_H
#include "List.h"
using namespace std;

class HashTable{
	private:
		vector<List*> table;//Vector to contain List*
		// Hashes a string into an integer number based on each characters alphabetical place and adds them together
		int hash(string input);
		
	public:
		//Deconstructor of HashTable
		~HashTable();
		//Adds a person to the table
		void addToTable(string key, Person* value);
		//Deletes a person from the table
		bool delFromTable(string key);
		//Returns a person from the table
		Person* getFromTable(string key);
		//Save table to file
		void saveToFile(string filename);
		//Load table from saved file
		void loadFromFile(string filename);
};
#endif
