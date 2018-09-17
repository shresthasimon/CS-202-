//Author: Simon Shrestha
//Title: NodeQueue.cpp
//Purpose: cpp file for NodeQueue.cpp
#include "NodeQueue.h"
#include <iostream>
using namespace std;

//Defualt Constructor
NodeQueue::NodeQueue(){
	m_front = NULL; // makes both front and back null
	m_back = m_front;
	cout << "Defualt Works" << endl;
}

//Parameterized Constrcutor
NodeQueue::NodeQueue(size_t size, const DataType & value){
	if(size <= 0){
		m_front = NULL; //checks if empty
		m_back = NULL;
	}else{
		m_front = new Node(value, NULL); //alocates
		Node * temp = m_front; // node pointer to front
		size_t i = 0;
		while(--size > 0){ 
			temp->m_next = new Node(value, NULL);
			temp = temp->m_next; // until size hits 0, allocate and move positions of elements
			m_back = temp;
			++i;
		}
		temp = NULL;
		delete temp;
	}
	
}

//Copy Constructor
NodeQueue::NodeQueue(const NodeQueue & other){
	Node * othertemp = other.m_front;
	m_front = new Node(othertemp->m_data, NULL);
	Node * temp = m_front; //allocates and assigns pointers to the queues
	othertemp = othertemp -> m_next;
	
	while(othertemp != NULL){
		temp->m_next = new Node(othertemp->m_data);
		temp = temp -> m_next; //copies over all elements
		m_back = temp;
		othertemp = othertemp->m_next;
	}
	temp = NULL;
	othertemp = NULL;
	delete temp; // deletes pointers
	delete othertemp;
}

//Destructor
NodeQueue::~NodeQueue(){
	Node *temp;
	temp = m_front;
	if(m_front != NULL){ //checks if empty
		m_back = NULL; 
		while(m_front != NULL){
			m_front = m_front -> m_next;
			temp->m_next = NULL; //deletes each element one by one
			delete temp;
			temp = m_front;
		}
		temp = NULL; // deletes pointer
		delete temp;
	}
	m_front = NULL;
	delete m_front; // deletes if empty queue
	cout << "Destrcutor Node Called" << endl;
}

//operator =
NodeQueue & NodeQueue:: operator= (const NodeQueue & rhs){
	if(m_front){
		m_back = NULL;
		Node * temp = m_front; //deletes and lists that still exist
		while(m_front){
			m_front = m_front -> m_next;
			temp->m_next = NULL;
			delete temp;
			temp = m_front;
		}
		temp = NULL;
		delete temp;
	}

	if(!rhs.m_front){
		m_front = NULL;
		m_back = NULL; //if list is empty
		return *this;
	}else if(!rhs.m_front->m_next){
		m_front = new Node(rhs.m_front->m_data);
        m_back = m_front; //if list ony has one element 
        return *this;
	}else{
		Node * rhstemp = rhs.m_front;
		m_front = new Node(rhstemp->m_data); //creates pointers and allocates
		Node * temp = m_front;
	
		rhstemp = rhstemp->m_next; //copies over all elements
		while(rhstemp){
			temp->m_next = new Node(rhstemp->m_data);
			temp = temp->m_next;
			m_back = temp;
			rhstemp = rhstemp->m_next;
		}
		temp = NULL;
		rhstemp = NULL;
		delete temp;
		delete rhstemp; //deletes any pointers that were called
		return *this;
	}
	
}

//front function
DataType & NodeQueue::front(){
			return m_front->m_data; // returns front element
}

//front function
const DataType & NodeQueue::front() const{
			return m_front->m_data;
}

//back function
DataType & NodeQueue::back(){
	return m_back->m_data; //returns back element
	
}

//back function
const DataType & NodeQueue::back() const{
	return m_back->m_data;
}

//push function
void NodeQueue::push(const DataType & value){
	if(!m_front){
		m_front = new Node(value, NULL); //if Queue only has one element
		m_back = m_front;
	}else{
	m_back->m_next = new Node(value, NULL); //otherwise push everything and copy value into new back element
	m_back = m_back->m_next;
	}
}

//pop function
void NodeQueue::pop(){
	Node * temp = m_front;
	if(!m_front->m_next){
		m_back = NULL;
		delete m_front; //checks if list only has one element
		m_front = NULL;	
	}else{
		m_front = m_front ->m_next;
		delete temp;
		temp = NULL; //otherwise delete first element
	}

}

//size function 
size_t NodeQueue::size() const{
	size_t count = 0;
	for (Node *curr = m_front; curr!=NULL; curr = curr->m_next){
		count++; // count increases until reaching end and returns
	}
	return count;
}

//empty function
bool NodeQueue::empty()  const{
	if(m_front == NULL){
		cout << "Queue is empty";
		return true; //checks if Queue is empty and returns statement
		
	}
	cout << "Queue is not empty";
	return false;
	
}

//full function
bool NodeQueue::full()  const{
	cout << "Queue is not full";
	return false; //node queue is never full
}

//clear function
void NodeQueue::clear(){
	Node * temp = m_front;
	if(m_front != NULL){
		while(m_front != NULL){ // checks if empty and deletes each element one by one
			m_front = m_front -> m_next;
			temp->m_next = NULL;
			delete temp;
			temp = m_front;
		}
		temp = NULL;
		delete temp;
	}
	cout << "Queue is now empty" << endl;
}

//serialize function
void NodeQueue::serialize(ostream & os) const{
	for (Node *curr = m_front; curr!=NULL; curr = curr->m_next){
		os << curr->m_data << " "; //prints out queue data
	}
}

//operator <<
ostream & operator<<(ostream & os, const NodeQueue & nodeQueue){
	nodeQueue.serialize(os); //prints out queue
	return os;
}
