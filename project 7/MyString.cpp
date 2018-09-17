// Name: MyString.cpp
// Author: Simon Shrestha 
// Purpose: .cpp file for MyString class

#include <iostream>
#include "MyString.h"
#include <cstring>
#include <string.h>
using namespace std;

// Default Constructor
MyString::MyString(){
	m_size = 0; // initalizes m_size to 0
	m_buffer = NULL; // makes m_buffer NULL so that it doesn't point to garbage
}

//Parameterized Constructor
MyString::MyString(const char *str){
	m_size = 0; // same as the default constructor so that garbage 
	m_buffer = NULL; // isn't called when function is called
	m_size = strlen(str); // makes m_size the length of the string passed in
	buffer_allocate(m_size); // allocates space for that size
	strcpy(m_buffer, str); // copies string into m_buffer
	
}

//copy constructor
MyString::MyString(const MyString & other_myStr){
	m_size = 0; // same reason as parameterized function
	m_buffer = NULL;
	m_size = other_myStr.m_size; // copies the same size of the string being copied
	this -> buffer_allocate(m_size); // allocates space for that string
	strcpy(m_buffer, other_myStr.m_buffer); // copies string
}

//length function
size_t MyString::length() const{
	return m_size - 1; // returns -1 to compensate for null-terminating character
}
//size function
size_t MyString::size() const{
	return m_size; // returns size of allocated string
}

//c_str function
const char* MyString::c_str() const{
	return m_buffer; //returns m_buffer 
}

//deconstructor
MyString::~MyString(){
	buffer_deallocate(); // deletes m_buffer
}

//function to access a specific character index
char& MyString::operator[](size_t index){
	return m_buffer[index]; // allows for manipulation without the const
}

//function to access a specific character index
const char& MyString::operator[](size_t index) const{
	return m_buffer[index]; // allows for manipulation with the const
}

//buffer deallocate
void MyString::buffer_deallocate(){
	delete[] m_buffer; // deletes m_buffer
}

//buffer allocate
void MyString::buffer_allocate(size_t size){
	if(m_buffer != NULL){ //deletes m_buffer if it is not NULL
		delete[] m_buffer;
		m_size = 0; // resets size
	}
	m_size = size; // makes m_size equal to size passed in 
	m_buffer = new char [size]; // allocates space for that size

	if(m_buffer == NULL){ // prints success if the string was read in and allocated correctly
		cout << "Fail" << endl; 
	}else{
		cout << "Success" << endl;
	}
	
}

//operator+ overload
MyString MyString::operator+(const MyString& other_myStr) const{
	char *buffer = m_buffer; // temp array to store m_buffer
	size_t size = m_size + other_myStr.length(); // makes a new size of the two arrays
	char *array =  NULL;
    array = new char [size]; // allocates memory based on size given
	strcpy(array, buffer); // copies string
	strcat(array, other_myStr.m_buffer); // appends the string 
	return array; 
}	

//operator= overload
MyString& MyString::operator=(const MyString& other_myStr){
	size_t size = strlen(other_myStr.c_str()); //gets size of the string
	buffer_allocate(size); // allcoates space
	strcpy(m_buffer, other_myStr.c_str()); // copies string
}

//operator== overload, checks if two strings are the same
bool MyString::operator==(const MyString & other_myStr) const{
	 return strcmp(m_buffer, other_myStr.c_str()) == 0; // returns true of false depeding on 
	// what the string compare equals

}
// operator overload to print string
ostream &operator<<(ostream &os, const MyString & myStr){
	os << myStr.c_str(); // prints out the string
}















 
