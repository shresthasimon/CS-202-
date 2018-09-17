//	Title: SmartPtr.cpp
//	Author: Simon shrestha 
//	Purpose: cpp file for SmartPtr header file
#include <iostream>
#include "SmartPtr.h"
#include "DataType.h"
using namespace std;

//defualt constructor
SmartPtr::SmartPtr(){
	m_ptr = new DataType; //allocates for m_ptr
	m_refcount = new size_t(1); //allocates for m_refcount
	cout << "SmartPtr Default Constructor for new allocation, RefCount= " << *m_refcount << endl; 
}
//parameterized constructor
SmartPtr::SmartPtr( DataType * data ){
	if(data == NULL){ // checks of the object passed in is NULL or not
		m_refcount = new size_t(0); // makes refcount 0 if null
	}else{
		m_refcount = new size_t(1); // makes refcount 1 if null
	}
	m_ptr = data; // points m_ptr to object passed in 
	cout << "SmartPtr Parametrized Constructor from data pointer, RefCount= " << *m_refcount << endl;
}
// copy constructor 
SmartPtr:: SmartPtr( const SmartPtr & other ){
	if(other.m_ptr){ // checks if the pointer in the object points to anything
		m_refcount = other.m_refcount; // copies refcount
		(*m_refcount)++; // increments refcount
	}else{
		m_refcount = new size_t(0); // if pointer does not point to anything, make refcount 0
	}
	m_ptr = other.m_ptr; // copies pointer
	cout << "SmartPtr Copy Constructor, RefCount= " << *m_refcount << endl;	
}
// Destructor
SmartPtr::~SmartPtr( ){	
	if(*m_refcount != 0){ // checks if it is not null
		*m_refcount = *m_refcount - 1; // if not null then deincrement
		
	}
	if(*m_refcount == 0){ // if object is the last one the deallocate
		delete m_refcount; 
		delete m_ptr; 
	}
	cout << "SmartPtr Destrcutor, RefCount= " << *m_refcount <<endl;
}

//operator = overload
SmartPtr & SmartPtr::operator=( const SmartPtr & rhs ){
	if(rhs.m_ptr){ // checks if pointer is true
		m_refcount = rhs.m_refcount - 1; // deincrements refcount
		if(m_refcount == 0){ //if it is the last object, then deallocate it
			delete m_refcount; 
			delete m_ptr;
		}
		m_refcount = rhs.m_refcount; // copies refcount
		(*m_refcount)++; // increments refcount

	}else{
		m_refcount = new size_t(0); // if pointer is not true then make refcount 0
	}
	m_ptr = rhs.m_ptr; // copies pointer
	
	cout << "SmartPtr Copy Assignment, RefCount= " << *m_refcount << endl;
}

//operator * overload
DataType & SmartPtr::operator*( ){
	return *m_ptr; // derefrence to object
}

//operator -> overload
DataType * SmartPtr::operator->( ){
	return m_ptr; // access via pointer 
}
