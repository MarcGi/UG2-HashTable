/*
MARC GIANNANDREA
AC21008
HashTable.cpp:Contains all method definitions for HashTable Class
*/

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "HashTable.h"
using namespace std;
//Copied header definition of HashTable to easily refrence between the two

/*class HashTable{
	private:
		vector<List*> table;//choose an array or vector here to actually store your data
		int hash(string input);
		
	public:
		~HashTable();
		void addToTable(string key, Person* value);
		bool delFromTable(string key);
		Person* getFromTable(string key);
		void saveToFile(string filename);
		void loadFromFile(string filename);
};
*/

//Deconstructor of HashTable
HashTable::~HashTable(){
	List* temp = NULL;
	//Loop through the entire vector and delete any lists that are in the table.
	for(int i = 0; i < table.size(); i++ ){
		if(table.at(i) != NULL){
			temp = table.at(i);
			delete temp;
			temp = NULL;
		}
	}
}
//Method used for hashing. Takes a string as input then returns an int
int HashTable::hash(string input){
	int loc = 0;
	char cur = 0;
	int returnVal = 0;
	//Loop through out the string and then convert it to uppercase and determine the letters location in the alphabet.
	//It will also ignore any non alphabetical characters
	for (int i = 0; i < input.size(); i++){
    	cur = toupper(input[i]);
    	if( ( ( input[i] >= 'a' && input[i] <= 'z' ) || ( input[i] >= 'A' && input[i] <= 'Z' ) ) ){
    		loc = cur - 64; // -64 to determine alphabetical location due to the use of ascii values
    		returnVal = returnVal + loc;
    	}
    	
    }
    return returnVal;
}
//Method used to add a person to the table by taking in a key to store the person at and the person object itself.
void HashTable::addToTable(string key, Person* value){
	int hashed = hash(key);
	//Check if table needs resized to fit the hashed value
	if(table.size() < hashed){
		table.resize(hashed+1);
	}
	List* list = table.at(hashed);
	//Check if there is already a list at the hash location in the vector
	//E.g if there is a collison
	if(list != NULL){
		if(!list->searchNode(key)){
			list->addNode(value);
		}
	}else{
		//If not collison then create new list and the node to it. Then add the list to the vector/table.
		List* newList= new List();
		newList->addNode(value);
		table.insert(table.begin()+hashed,newList);
	}
}
//Method used for deleting a person from the table. Takes in a string and returns a boolean
bool HashTable::delFromTable(string key){
	int hashed = hash(key);

	//Check if table is too small to store the specified key
	if(table.size() < hashed){
		return false;
	}
	//Get list at hashed location in the vector
	List* list = table.at(hashed);
	if(list != NULL){
		if(list->getSize() > 1 ){
			//If the list has more than 1 node e.g a collison has previously occured
			//Search for the node in list
			ListNode* searched = list->searchNode(key);
			if(searched == NULL){
				return false;
			}else{
				//If it exists then delete it
				list->delNode(searched->getData());
			}
		}else{
			//If there is no other nodes in list then delete the list
			delete(list);
			list = NULL;
			table.at(hashed) = NULL;
			return true;
		}
	}
}

//Method used for returning a person from the table. Takes a string as a parameter
Person* HashTable::getFromTable(string key){
	int hashed = hash(key);
	List* list = table.at(hashed);
	//Check in the list and node exists. If so then return the person associated with the node.
	if(list != NULL){
		ListNode* node = list->searchNode(key);
		if(node == NULL){
			return NULL;
		}
		return node->getData();
	}else{
		return NULL;
	}
	
}
//Method to save HashTable to file. Takes in a string to determine filename
void HashTable::saveToFile(string filename){
	//If filename is empty then set default filename
	if(filename == ""){
		filename = "DefaultSave.txt";
	}
	ofstream savefile(filename.c_str()); // Declare the file as an out stream
	//Check if the file is open
	if(savefile.is_open()){
		//Loop through the table, ignoring any null values. 
		for(int i = 0; i < table.size(); i++){
			if(table.at(i) != NULL){
				//If a list exists then write the data to the text file
				List* tempList = table.at(i);
				ListNode* cur = tempList->getHead();
				ListNode* next = NULL;

				while(cur != NULL){
					//Save each node's person data to a new line with delimeter ','
					next = cur->getNext();
					Person* tempPerson = cur->getData();
					savefile << tempPerson->getName() << ",";
					savefile << tempPerson->getAddress() << ",";
					savefile << tempPerson->getPostCode() << ",";
					savefile << tempPerson->getNumber() << "," << "\n";
					cur = next;
				}

			}
		}
		//Close the file
		savefile.close();
	}
}

//Method used for loading a previous hashtable from a file. Takes in a string to determine filename
void HashTable::loadFromFile(string filename){
	if(filename == ""){
		return;
		cout << "Please enter a valid filename" << endl;
	}
	ifstream savefile(filename.c_str());//Declare an input stream
	if(savefile.is_open()){ //Check if file is open
		string line;
		string del = ","; // Used to split the string up into usuable variables
		Person* tempPerson;
		//Loop through each line
		while(getline(savefile,line)){
			//Spliting code adapted from:
			//http://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
			//First answer
			size_t pos = 0;
			string token;
			int i = 1;
			tempPerson = new Person();
			while ((pos = line.find(del)) != string::npos) {
				//Loop through the amount of variables and then set them based on the current token.
				token = line.substr(0, pos);
			    line.erase(0, pos + del.length());//Delete the variable/token from the variable line
				switch (i) {
					case 1:
						tempPerson->setName(token);
					break;

					case 2:
						tempPerson->setAddress(token);
					break;

					case 3:
						tempPerson->setPostCode(token);
					break;

					case 4:
						tempPerson->setNumber(token);
					break;

				}
			    i++;
			}
			//Add Person to table
			addToTable(tempPerson->getName(),tempPerson);
		}	
		//Close file
		savefile.close();
	}
}
