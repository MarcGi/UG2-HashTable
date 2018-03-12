/*
MARC GIANNANDREA
AC21008
HashTableTester.cpp:Contains a tester class to use with HashTable class
*/
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Main.h"

using namespace std;

int main(){
	string choice;
		cout << "Tester|Menu option" << endl;
		cout << "Would you like to run the tester or the main menu?(tester or mainmenu)" << endl;
		getline(cin,choice);
	
	if (choice == "mainmenu"){
		main_menu();
	}else if (choice == "tester"){
	 	string fullname= "Marc Giannandrea"; 
	 	string fullname2= "aMrc Giannandrea";//Collison would be created due to characters being the same even though different string.
		string address = "Dundee ST";  
		string postcode = "DD1 XXX";
		string phonenumber = "07747189342";
		Person* person1 = new Person(fullname,address,postcode,phonenumber);

		Person* person2 = new Person(fullname2,address,postcode,phonenumber);
		
		HashTable* ht = new HashTable();

		//Add one person to the table and then delete
		cout << "Single person add to table" << endl;
		ht->addToTable(person1->getName(),person1);
		cout << "Deleted Singular entry:" << endl;
		cout << ht->delFromTable(person1->getName()) << endl << endl;

		//Add the two persons to the table which will create a collison
		ht->addToTable(person1->getName(),person1);
		ht->addToTable(person2->getName(),person2);

		//Print the head of the list which contains the collisons
		cout << "-Collison Test-" << endl;
		cout << "Person1(Head of list,Collison happened):" << endl;
		Person* returned = ht->getFromTable(person1->getName());
		cout << returned->getName() << endl << endl;

		//Print the second listNode which contains a collison
		cout << "Person2(tail of list,Collison happened):" << endl;
		Person* returned2= ht->getFromTable(person2->getName());
		cout << returned2->getName() << endl << endl;

		//Save test
		ht->saveToFile("Tester123.txt");

		//Delete both from table and print out the boolean result
		cout << "-Delete test-" << endl;
		cout << "Deleted Person1:" << endl;
		cout << ht->delFromTable(person1->getName()) << endl << endl;
		cout << "Deleted Person2:" << endl;
		cout << ht->delFromTable(person2->getName()) << endl << endl;


		//Load test then delete from the load
	 	ht->loadFromFile("Tester123.txt");
	 	cout << "-Loading and delete persons from table test-" << endl;
		cout << "Deleted Person1 from load file:" << endl;
		cout << ht->delFromTable(person1->getName()) << endl << endl;
		cout << "Deleted Person2 from load file:" << endl;
		cout << ht->delFromTable(person2->getName()) << endl;

		delete ht;
	}else{
		cout << "Invalid choice. Run again" << endl;
	}

	return 0;
}
