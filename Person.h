/*
MARC GIANNANDREA
AC21008
Person.h:Contains all method & variable prototypes for Person class
*/
#include <iostream>
#include <string>
#ifndef _PERSON_H
#define _PERSON_H

using namespace std;

class Person{   // Declare PERSON struct type
	private:  
					string fullname;   // Declare member types  
					string address;  
					string postcode;
					string phonenumber;
	public:
				Person();//Constructor for person with no parameters
				Person(string name, string addr,string postc, string num);//Constructor with parameters
				string getName();// Returns name
				string getAddress();// Returns Address
				string getPostCode();//Returns PostCode
				string getNumber();//Returns Number
				
				void setName(string name);//Sets name
				void setAddress(string address);//Sets Address
				void setPostCode(string postcode);//Sets Post Code
				void setNumber(string num);//Sets Number
};


#endif
