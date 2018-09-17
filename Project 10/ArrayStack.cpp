
#include "ArrayStack.h"
#include <iostream>
using namespace std;

//Defualt Constructor
ArrayStack::ArrayStack(){
	m_top = 0;
	cout << "Default Works" << endl;
}

//Parameterized constructor
ArrayStack::ArrayStack(size_t count, const DataType & value){
	m_top = 0;
	for(size_t i = 0; i < count; i++){
		m_container[m_top] = value;
		m_top++;
	}
}

//copy constructor
ArrayStack::ArrayStack(const ArrayStack & other){
	m_top = 0;
	for(size_t i = 0; i < other.m_top; i++){
		m_container[i] = other.m_container[i];
		m_top++;
	}
	
}

//Destructor
ArrayStack::~ArrayStack(){
	cout << "Array Destructed" << endl;
	m_top = 0;
}

//operator=
ArrayStack & ArrayStack::operator= (const ArrayStack &rhs){
	if(this != &rhs){
		m_top = 0;
		for(size_t i = 0; i < rhs.m_top; i++){
			m_container[i] = rhs.m_container[i];
			m_top++;
		}
	}
	return *this;
}

//top function 
DataType & ArrayStack::top(){
	if(!empty()){
		return m_container[m_top];
	}else{
		return m_container[m_top];
	}
}

//top function 
const DataType & ArrayStack::top() const{
	if(!empty()){
		return m_container[m_top];
	}else{
		return m_container[m_top];
	}
}

//push function
void ArrayStack::push(const DataType & value){
	if(!full()){
		m_container[m_top] = value;
		m_top++;
	}else{
		cout << "Cannot push, stack is full" << endl;
	}
}

//pop function
void ArrayStack::pop(){
	if(!empty()){
		m_top--;
	}else{
		cout << "Cannot pop, stack is empty" << endl;
	}
}

//size function
size_t ArrayStack::size() const{
	size_t count = 0;
	for(size_t i = 0; i < m_top; i++){
		count++;
	}
	return count;
}

//empty function 
bool ArrayStack:: empty() const{
	return(m_top == 0);
}

//full function
bool ArrayStack:: full() const{
	return(m_top == MAX_STACKSIZE);
}

//clear function
void ArrayStack::clear(){
	m_top = 0;
}

//serialize function
void ArrayStack::serialize(ostream & os) const{
	if(m_top > 0){
		for(size_t i = m_top; i >= 1; --i){
			os << m_container[i-1] << " ";
		}
	}else{
		os << "Empty Array Stack" << endl;
	}

}

//operator <<
ostream &operator<<(ostream & os, const ArrayStack & arrayStack){
	arrayStack.serialize(os);
	return os;
}   
