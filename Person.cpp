/*
MARC GIANNANDREA
AC21008
Person.cpp:Contains all method definitions for Person class
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Person.h"
using namespace std;
//Constructor of Person. Set all fields to empty
Person::Person()
{
    setName("");
	setAddress("");
	setPostCode("");
	setNumber("");
}
//Constructor for person with passed fields
Person::Person(string name , string addr , string postc, string num)
{
    setName(name);
	setAddress(addr);
	setPostCode(postc);
	setNumber(num);
}
//Returns name
string Person::getName(void){
	return fullname;
}
//Returns Addresss
string Person::getAddress(void){
	return address;
}
//Returns Post Code
string Person::getPostCode(void){
	return postcode;
}
//Returns Number
string Person::getNumber(void){
	return phonenumber;
}
//Sets Name
void Person::setName(string name){
	fullname = name;
}
//Sets Addresss
void Person::setAddress(string addr){
	address = addr;
}
//Sets PostCode
void Person::setPostCode(string postc){
		postcode = postc;
}
//Sets Number
void Person::setNumber(string num){
	phonenumber = num;
}
