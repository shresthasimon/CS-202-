//Author: Simon Shrestha
//Title: ArrayStack.h
//Purpose: template class with implementations

#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_
#include <iostream>
#include "DataType.h"
using namespace std;

template<class T> class ArrayStack;
template<class T> ostream &operator<<(std::ostream & os, const ArrayStack<T> & arrayStack);

const size_t MAX_STACKSIZE = 1000;

template<class T> 
class ArrayStack{
	friend std::ostream &operator<< < > (std::ostream & os, const ArrayStack<T> & arrayStack); //(i)
  public:
    	
	ArrayStack();//(1) 
	ArrayStack(size_t count, const T & value);          //(2)
	ArrayStack(const ArrayStack<T> & other);                    //(3)
	~ArrayStack();                                                                 //(4)
	ArrayStack<T> &operator= (const ArrayStack<T> & rhs);         //(5) 		
	T & top();                                         //(6a) 
	const T & top() const;                              //(6b)	
	void push(const T & value);           //(7) 		
	void pop();                                                //(8)	
	size_t size() const;                //(9)
	bool empty() const;             //(10) 	
	bool full() const;             //(11) 	
	void clear();                                            //(12)
	void serialize(std::ostream & os) const;                               //(13)
	
  private:
  
   T m_container[MAX_STACKSIZE]; 
	size_t m_top; 
};

//Defualt Constructor
template<class T>
ArrayStack<T>::ArrayStack(){
	m_top = 0; //intializes m_top to 0
	cout << "Default Works" << endl;
}

//Parameterized constructor
template<class T>
ArrayStack<T>::ArrayStack(size_t count, const T & value){
	m_top = 0; //intializes m_top
	for(size_t i = 0; i < count; i++){
		m_container[m_top] = value; //intializes m_top to value
		m_top++; //increments m_top each time
	}
}

//copy constructor
template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> & other){
	m_top = 0; //sets top to 0
	for(size_t i = 0; i < other.m_top; i++){
		m_container[i] = other.m_container[i]; //copies each element over
		m_top++; // increments top each time
	}
	
}

//Destructor
template<class T>
ArrayStack<T>::~ArrayStack(){
	cout << "Array Destructed" << endl;
	m_top = 0; // sets top to 0
}

//operator=
template<class T>
ArrayStack<T> & ArrayStack<T>::operator= (const ArrayStack<T> &rhs){
	if(this != &rhs){ // checks if the two stacks are the same
		m_top = 0; 
		for(size_t i = 0; i < rhs.m_top; i++){
			m_container[i] = rhs.m_container[i]; // copies over elements
			m_top++; //incrments top 
		}
	}
	return *this;
}

//top function 
template<class T>
T & ArrayStack<T>::top(){
	if(!empty()){ //checks if empty
		return m_container[m_top-1]; //returns top
	}else{
		return m_container[m_top-1];
	}
}

//top function 
template<class T>
const T & ArrayStack<T>::top() const{
	if(!empty()){
		return m_container[m_top-1];
	}else{
		return m_container[m_top-1];
	}
}

//push function
template<class T>
void ArrayStack<T>::push(const T & value){
	if(!full()){ // checks if full
		m_container[m_top] = value; // makes top the new value
		m_top++; //increments top
	}else{
		cout << "Cannot push, stack is full" << endl;
	}
}

//pop function
template<class T>
void ArrayStack<T>::pop(){
	if(!empty()){ //checks if empty
		m_top--; // deincrements top
	}else{
		cout << "Cannot pop, stack is empty" << endl;
	}
}

//size function
template<class T>
size_t ArrayStack<T>::size() const{
	size_t count = 0; //count to count lol
	for(size_t i = 0; i < m_top; i++){
		count++; //increments count until reaching top
	}
	return count;
}

//empty function 
template<class T>
bool ArrayStack<T>:: empty() const{
	return(m_top == 0); //returns 1 or 0 depending on if it's empty or not 
}

//full function
template<class T>
bool ArrayStack<T>:: full() const{
	return(m_top == MAX_STACKSIZE); //returns 1 or 0 depending on if full or not
}

//clear function
template<class T>
void ArrayStack<T>::clear(){
	m_top = 0; // same as destructor
}

//serialize function
template<class T>
void ArrayStack<T>::serialize(ostream & os) const{
	if(m_top > 0){
		for(size_t i = m_top; i >= 1; --i){ 
			os << m_container[i-1] << " "; // for loop to print from top to bottom
		}
	}else{
		os << "Empty Array Stack" << endl;
	}

}

//operator <<
template<class T>
ostream &operator<<(ostream & os, const ArrayStack<T> & arrayStack){
	arrayStack.serialize(os); // prints out stack
	return os;
}  

#endif
