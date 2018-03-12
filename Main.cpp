/*
MARC GIANNANDREA
AC21008
Main.cpp:Contains a Command Line UI to operate the hashtable
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include "HashTable.h"
using namespace std;
//Main menu for HashTable operation
void main_menu(){
	int choice;
	HashTable* ht = NULL;
	do{
		cout << "HashTable" << endl;
		cout << "-MAIN MENU-" << endl;
		cout << "-----------" << endl;
		cout << "1.Add to HashTable" << endl;
		cout << "2.Delete from HashTable" << endl;
		cout << "3.Create HashTable" << endl;
		cout << "4.Save HashTable" << endl;
		cout << "5.Load HashTable" << endl;
		cout << "6.Exit" << endl;
		cout << "Always create a Hashtable before attempting any other options" << endl;
		cout << "-----------" << endl << endl;
		cout << "Please enter menu choice(1,2,3)" << endl;
		cin >> choice;
		switch(choice){

			case 1://Add a person to the hastable
				if(ht == NULL){
					cout << "You have to create the HashTable first!" << endl;
				}else{
					cin.ignore(1000,'\n'); //Clear any remaining chars from the use of cin
					string name,addr,postc,num;
					cout << "Please enter the name of the person to be added: " << endl;
					getline(cin,name);
					cout << "Please enter the address of the person to be added: " << endl;
					getline(cin,addr);
					cout << "Please enter the postcode of the person to be added: " << endl;
					getline(cin,postc);
					cout << "Please enter the phone number of the person to be added: " << endl;
					getline(cin,num);

					Person* newPerson = new Person(name,addr,postc,num);
					ht->addToTable(name,newPerson);
					cout << "Person Added Unless Name Was Already In Table" << endl;
				}
			break;

			case 2://Delete a person from the hashtable
				if(ht == NULL){
					cout << "You have to create the HashTable first!" << endl;
				}else{
					cin.ignore(1000,'\n');//Used to flush cin input
					string name;
					cout << "Please enter the name of the person to be deleted: " << endl;
					getline(cin,name);
					if(ht->delFromTable(name)){
						cout << "Person Deleted" << endl;
					}else{
						cout << "Could not delete" << endl;
					}
					
				}
			break;

			case 3://Create a hashtable
				if(ht == NULL){
					ht = new HashTable();
					cout << "HashTable Created" << endl;
				}else{
					cout << "HashTable Already Exists" << endl;
				}
			break;

			case 4://Delete a person from the hashtable
				if(ht == NULL){
					cout << "You have to create the HashTable first!" << endl;
				}else{
					cin.ignore(1000,'\n');//Used to flush cin input
					string filename;
					cout << "Please enter the filename icluding extension to save the table to:" << endl;
					getline(cin,filename);
					ht->saveToFile(filename);
					cout << "File Saved" << endl;
				}
			break;

			case 5://Delete a person from the hashtable
				if(ht == NULL){
					cout << "You have to create the HashTable first!" << endl;
				}else{
					cin.ignore(1000,'\n');//Used to flush cin input
					string filename;
					cout << "Please enter the filename including extension to load the table from:" << endl;
					getline(cin,filename);
					ht->loadFromFile(filename);
					cout << "If file is valid and exists then HashTable will be loaded" << endl;
				}
			break;



			case 6://Exit the program
				delete ht; // Call destructor for ht
				exit(0);
			break;

			default:
				cout << "Invalid Choice" << endl;
			break;	
		}
		cout << endl << endl << endl;
	}while(choice != 6);
}
