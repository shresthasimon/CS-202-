//Author: Simon Shrestha
//Title: ArrayQueue.cpp
//Purpose: cpp file for ArrayQueue.h
#include "ArrayQueue.h"
#include <iostream>
using namespace std;

//default constructor
ArrayQueue::ArrayQueue(){
	m_front = 0;
	 m_back = -1;   //sets values to NULL or 0
	 m_size = 0;
	cout << "Defualt Constructor works" <<endl;
}

//parameterized constructor
ArrayQueue::ArrayQueue(size_t count, const DataType & value){
	m_front = 0; //sets front to 0
	m_size = count; //sets size to count
	for(size_t i = 0; i < m_size; i++){
		m_back = i; // copies values over and moves m_back
		m_array[i] = value;
	}
	
}

//copy constructor
ArrayQueue::ArrayQueue(const ArrayQueue & other){
	m_front = other.m_front;
	m_back = other.m_back; //copies over m_size, m_back, and m_front
	m_size = other.m_size;
	
	for(size_t i = m_front; i < m_size; i++){
		m_array[i] = other.m_array[i]; // copies over values
	}	
}

//destructor
ArrayQueue:: ~ArrayQueue(){
	cout << "Destructor array called" << endl;
	clear(); //uses clear function to destruct
}

//operator = 
ArrayQueue & ArrayQueue:: operator= (const ArrayQueue & rhs){
	if(this != &rhs){
		m_size = rhs.m_size; // checks if they are the same and thn copies over values
		m_front = rhs.m_front;
		m_back = rhs.m_back;
		for(size_t i = m_front; i < m_size; i++){
			m_array[i] = rhs.m_array[i]; // copies over array
		}
	}
	return *this;
}

//front function
DataType & ArrayQueue::front(){
	if(m_size != 0){
		return m_array[m_front]; //returns front element
	}
	
}

//front function
const DataType & ArrayQueue::front() const{
	if(m_size != 0){
		return m_array[m_front]; 
	}
	
}

//back function
DataType & ArrayQueue::back(){
	if(m_size != 0){
		return m_array[m_back]; //returns back element
	}
	
}

//back function
const DataType & ArrayQueue::back() const{
	if(m_size != 0){
		return m_array[m_back];
	}
	
}

//push function
void ArrayQueue::push(const DataType & value){
		m_back = (m_back+1)%ARRAY_MAX; //pushes elements back one by one
		m_size++; // increase size
	
	m_array[m_back] = value; //makes new back the value
}

//pop function
void ArrayQueue::pop(){

	m_front = (m_front+1)%ARRAY_MAX; //moves elements to front one by one
	m_size--; // decreases size
		
}

//size function
size_t ArrayQueue::size() const{
	return m_size; // returns size
}

//empty function
bool ArrayQueue::empty() const{
	if(m_size == 0){
		cout << "Queue is empty" << endl;
		return true; // checks if empty or not and returns a statement
	}
	cout << "Queue is full" << endl;
	return false;
}

//full function
bool ArrayQueue::full() const{
	if(m_size == ARRAY_MAX){
		cout << "Queue is full" << endl;
		return true; //checks if full or not and returns a statement
	}
	cout << "Queue is not full" << endl;
	return false;
}

//clear function
void ArrayQueue::clear(){
	m_size = 0;
	m_front = 0; //makes all values 0
	m_back = 0;
}

//serialize function
void ArrayQueue::serialize(ostream & os) const{
	if(m_size > 0){
		for(size_t i = m_front; i <= m_back; i++){
			os << m_array[i] << " "; //prints out data 
		}
		os << endl;
	}else{
	os <<"empty array" << endl; // prints out empty array if array is empty
	}
}

//operator <<
ostream &operator<<(ostream & os, const ArrayQueue & arrayQueue){
	arrayQueue.serialize(os); //prints out the queue
	return os;
}
