
#include "NodeStack.h"
#include <iostream>
using namespace std;

//Default Constructor
NodeStack::NodeStack(){
	m_top = NULL;
	cout << "Defualt Works" << endl;
}

//Parameterized Constructor
NodeStack::NodeStack(size_t count, const DataType & value){
	m_top = NULL;
	for(size_t i = 0; i < count; i++){
		push(value);
	}
}

//Copy Constructor
NodeStack::NodeStack(const NodeStack & other){
	Node * temp = other.m_top;
	m_top = NULL;
	while(temp != NULL){
		push(temp->m_data);
		temp = temp->m_next;
	}
	
}

//Destructor
NodeStack::~NodeStack(){
	while(!empty()){
		pop();
	}
	cout << "Destructed" << endl;
}

//operator =
NodeStack & NodeStack::operator= (const NodeStack & rhs){
	clear();
	Node * temp = rhs.m_top;
	while(temp != NULL){
		push(temp->m_data);
		temp = temp->m_next;
	}
	return *this;
}

//top function
DataType & NodeStack::top(){
	return m_top -> m_data;
}

//top function 
const DataType & NodeStack::top() const{
	return m_top -> m_data;
}

//push function
void NodeStack::push(const DataType & value){
		Node *temp = new Node(value, m_top);
		m_top = temp;

}

//pop function
void NodeStack::pop(){
	if(m_top != NULL){
		Node * temp = m_top->m_next;
		delete m_top;
		m_top = temp;
	}
}

//size function
size_t NodeStack::size()const{
	Node * temp = m_top;
	size_t count;
	for(count = 0; temp != NULL; temp = temp->m_next){
		count++;
	}
	return count;
}

//empty function
bool NodeStack::empty() const{
	return (m_top == NULL);
}

//full function
bool NodeStack::full() const{
	cout << "Stack is not FULL" << endl; 
	return false;
}

//clear function
void NodeStack::clear(){
	while(!empty()){
		pop();
	}
	cout << "Stack is now empty" << endl;
}

//serialize function
void NodeStack::serialize(std::ostream & os) const{
	Node * temp = m_top;
	while(temp != NULL){
		os << temp->m_data << " ";
		temp = temp->m_next;
	}
}

//operator <<
ostream & operator<<(ostream & os, const NodeStack & nodeStack){
	nodeStack.serialize(os);
	return os;
}
