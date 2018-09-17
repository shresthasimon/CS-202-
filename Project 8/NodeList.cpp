//Author: Simon Shrestha
//Title: NodeList.cpp
//Purpose: cpp file for NodeList.h
#include "NodeList.h"
#include <iostream>
using namespace std;

//default 
NodeList::NodeList(){
	m_head = NULL;
	cout << "Default Constructor works" << endl;
}
//parameterized 
NodeList:: NodeList(size_t count, const DataType & value){
	Node *curr = m_head; // pointer to head of list
	for(size_t i = 0; i < count; i++){ //loop till count 
		curr = new Node (value); //allocates for each node
		curr = curr->m_next; // makes new link for each node
		
	}
}
//copy
NodeList::NodeList(const NodeList & other){
	Node *curr2 = m_head;
	for (Node *curr = other.m_head; curr!=NULL; curr = curr->m_next){// loop through list
		curr2 = new Node (curr->m_data); // allocate memory for copied list
		curr2 = curr2->m_next;
	}
}
//destructor
NodeList::~NodeList(){
	for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		m_head = m_head->m_next; // iterate through each node
		delete curr;
		curr = NULL;  // delete curr and reassign head
		curr = m_head; 
	}
	cout << "destruct" << endl;
}
//operator=
NodeList & NodeList:: operator= (const NodeList & rhs){
	if(m_head != NULL){ // cheks if null
		for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		m_head = m_head->m_next; // iterates through and deletes the list being copied
		delete curr; 
		curr = NULL;
		curr = m_head; 
		}
	}
	Node *curr2 = m_head;
	for (Node *curr = rhs.m_head; curr!=NULL; curr = curr->m_next){
		curr2 = new Node (curr->m_data); //copies the list over to a new list
		curr2 = curr2->m_next;
	}
	return *this;
}
//front function
Node * NodeList:: front(){
	return m_head; // returns head of function
}
//back function
Node * NodeList:: back(){
	Node *curr = m_head;
	for (; curr->m_next!=NULL; curr = curr->m_next);
	return curr; // iterates till the last node and returns it
}
// find function
Node * NodeList:: find(const DataType & target, Node * & previous, const Node * start){
	Node *curr = m_head;
	Node *temp = m_head;
	for (; curr->m_next!=NULL; curr = curr->m_next){
		if(target == curr->m_next->m_data){ // iterates through until matching
			previous = curr; // makes previous that node
			return curr->m_next;
		}
		temp = curr;
	}

	if(target == curr->m_next->m_data){
			previous = temp; //test if target is at the beginning
			return curr;
	}
	
	previous = NULL;
	return NULL;
	
}
// insertafter
Node * NodeList::insertAfter(const DataType & target, const DataType & value){
	for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		if(target == curr->m_data){ // iterates until finding target
			curr->m_next = new Node(value, curr -> m_next);
			return curr->m_next; //allocates and adds after the target node
		}
	}
	return NULL;	
}
// insertbefore
Node * NodeList::insertBefore(const DataType & target, const DataType & value){
	for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		if(target == curr->m_next->m_data){ // iterates until finding target
			curr->m_next = new Node(value, curr -> m_next);
			return curr->m_next;// allocates and adds after the target node
		}
	}
	return NULL;
}

// erase
Node * NodeList:: erase(const DataType & target){
	Node *curr = m_head;
	if(target == m_head->m_data){
		Node *nextptr = m_head -> m_next;
		delete m_head; // if  target is head then erase
		m_head = nextptr;
		return m_head;
	}

	for (; curr->m_next!=NULL; curr = curr->m_next){
		if(target == curr->m_next->m_data){
			Node * next = curr -> m_next -> m_next;
			delete curr->m_next; // if target is in the middle then delete 
			curr->m_next = next;
			return curr ->m_next;
		}
	}
	
	if (target == curr->m_data){
		delete curr;
		curr = NULL; // if target is at the end of list then delete
	}
	return NULL;
}

//operator []
DataType & NodeList::operator[] (size_t position){
	Node * curr = m_head; 
	for (size_t i = 0; i < position; i++){
		curr++; // iterates until reaching position
	}
	return curr -> getData(); // returns data
}

// operator [] const
const DataType & NodeList:: operator[] (size_t position) const{
	Node * curr = m_head; 
	for (size_t i = 0; i < position; i++){ 
		curr++;
	}
	return curr -> getData();
}

// size function
size_t NodeList::size() const{
	size_t count = 0;
	for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		count++; // count increases until reaching end and returns
	}
	return count;
}	

//empty function
bool NodeList::empty() const{
	if (m_head == NULL){
		return true; // returns true if empty otherwise false
	}
	return false;
}

// clear function
void NodeList::clear(){
	for (Node *curr = m_head; curr!=NULL; curr = curr->m_next){
		m_head = m_head->m_next;
		delete curr; // same as dstructor function
		curr = NULL; 
		curr = m_head; 
	}
}

// operator << 
ostream & operator<<(std::ostream & os,	const NodeList & nodeList){
	for(size_t i = 0; i < nodeList.size() ; i++){
		os << "[" << nodeList[i] << "]"; // prints out each node data
	}
	return os;
}

