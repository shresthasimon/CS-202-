//Author:Simon Shrestha
//Title: ArrayList.cpp
// Purpose: cpp file for ArrayList class
#include "ArrayList.h"
#include <iostream>
using namespace std;

//resize function
void ArrayList::resize(size_t count){
	DataType *temp = new DataType[m_size];
	for(size_t i = 0; i < m_size; i++){ // allocates and copies
		temp[i] = m_array[i];
	}
	
	if(m_array) {
		delete [] m_array; // deletes previous array
	}
	
	m_maxsize = count;
	m_array = new DataType [m_maxsize]; //allocates for new size

	if(m_maxsize <= m_size){
		m_size = m_maxsize; // changes size if needed
	}

	for(size_t i = 0; i < m_size; i++){
		m_array[i] = temp[i]; // copies back the array 
	}
}

// defualt constructor
ArrayList:: ArrayList(){
	m_array = NULL;
	m_size = 0; // initalizes everything 
	m_maxsize = 0;
	cout << "Default Constructor works" << endl;
}

//paramterized constructor
ArrayList:: ArrayList(size_t count, const DataType & value){
	m_array = new DataType [count];
	m_size = count; // allocates and sets necessary size
	m_maxsize = count;

	for(size_t i = 0; i < m_maxsize; i++){
		m_array[i] = value; //makes everything same value
	}
}

//copy constructor
ArrayList:: ArrayList(const ArrayList & other){
	m_maxsize = other.m_maxsize;
	m_size = other.m_size; // copies size from other array and allocates
	m_array = new DataType [m_maxsize];
	
	for(size_t i = 0; i < m_size; i++){
		m_array[i] = other.m_array[i]; // copies contents
	}
}

//Destrcutor
ArrayList::  ~ArrayList(){
	if(m_array != NULL){
		delete [] m_array; // deletes each position in array
		m_array = NULL;
	}
	m_maxsize = 0;// resets size
	m_size = 0;
	cout << "destruct" << endl;
}

//operator =
ArrayList & ArrayList::operator= (const ArrayList & rhs){
	if(this != &rhs){
		m_size = rhs.m_size;
		m_maxsize = rhs.m_maxsize; // copies size and allocates
		m_array = new DataType [m_maxsize];
		
		for(size_t i = 0; i < m_size; i++){
			m_array[i] = rhs.m_array[i]; // copies contents
		}
	}
	return *this;
}

//front function
DataType * ArrayList::front(){
	if(m_array != NULL){
		return m_array; // returns the first array position
	}
	return NULL;
}

// back function
DataType * ArrayList::back(){
	DataType *curr = m_array;
	if(m_array == NULL){
		for(size_t i = 0; i < m_size-1; i++){
			curr++; // iterates until last position and returns it
		}
		return curr;
	}
	return NULL;
}

//find function
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start){
	if(m_array[0] == target){
		previous = NULL; // if target is in the beginning
		return &m_array[0];
	}

	for(size_t i = 1; i < m_size; i++){
		if(m_array[i] == target){
			previous = &m_array[i-1]; //if target is in middle or end
			return &m_array[i];
		}
	}
	
	previous = NULL;
	return NULL;
}

//insert after function
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value){
	for(size_t i = 0; i < m_size; i++){
		if(m_array[i] == target){
			m_size++;
			if(m_size > m_maxsize){ //finds target and adjusts size if needed
				m_maxsize = m_size;
				resize(m_size);
			}
			for(size_t j = m_size-1; i < j; j--){
				m_array[j] = m_array[j-1]; // changes all values while moving
			}
			m_array[i+1] = value;
			return &m_array[i+1];
		}	
	}
	return NULL;
}

//insert before function
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value){
	for(size_t i = 0; i < m_size; i++){
		if(m_array[i] == target){
			m_size++; // finds targett and adjusts size if needed
			if(m_size > m_maxsize){
				m_maxsize = m_size;
				resize(m_size);
			}
			for(size_t j = m_size-1; i <= j; j--){
				m_array[j] = m_array[j-1]; // changes all values whil moving
			}
			m_array[i] = value;
			return &m_array[i];
		}	
	}
	return NULL;
}

//erase function
DataType * ArrayList::erase(const DataType & target){
	for(size_t i = 0; i < m_size;i++){
		if(m_array[i] == target){
			m_size--; // finds target and deletes it 
			if(m_size == 0){
				delete [] m_array;
				return NULL;
			}
			for(size_t j = (i+1); i < m_size; j++){
				m_array[j-1] = m_array[j]; // moves all values after deletion 
			}
			return &m_array[i];
		}
	}
	return NULL;
}

//operator [] overload
 DataType & ArrayList:: operator[] (size_t position){
	return m_array[position]; // retruns position within array
}

// size function
size_t ArrayList::size() const{
	return m_size; // returns size of array
}

//empty function 
bool ArrayList::empty() const{
	if(m_size == 0 && m_array == NULL){
		return true;
	} // checks if function is empty, true if empty, otherwise false
	return false; 
}

//clear function
void ArrayList:: clear(){
	if(m_array != NULL){
		delete [] m_array; // deletes each element in array 
		m_array = NULL;
	}
	m_size = 0; 
	m_maxsize = 0; // resets sizes
}

//operator <<
ostream & operator<<(std::ostream & os, const ArrayList & arrayList){
	for(size_t i = 0; i < arrayList.m_size; i++){
		os << "[" << arrayList.m_array[i] << "]"; // prints out data from each element in array
	}
	return os;
}
