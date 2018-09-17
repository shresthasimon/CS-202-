//Author: Simon Shrestha
//Title: NodeStack.h
// Purpose: template class for node and NodeStack classes along with implementations

#ifndef NODESTACK_H_
#define NODESTACK_H_
#include <iostream>
#include "DataType.h"
using namespace std;

template<class T> class NodeStack;
template<class T> ostream & operator<<(std::ostream & os, const NodeStack<T> & nodeStack);

template<class T>
class Node{

  friend class NodeStack<T>;  //allows direct accessing of link and data from class NodeList

  public:
    Node() :
	  m_next( NULL )
	{
	}
	Node(const T& data, Node<T> * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node<T> & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}
	
    T & getData(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const T & getData() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node<T> * m_next; 						
    T m_data;
};

template<class T>
class NodeStack{
	friend std::ostream & operator<< < > (std::ostream & os, const NodeStack & nodeStack); //(i)
	public:
		NodeStack(); //(1) 
		NodeStack(size_t count, const T & value);              		//(2) 	
		NodeStack(const NodeStack<T> & other);                     			 //(3) 
		~NodeStack();                                                        //(4)
		 NodeStack<T> &operator= (const NodeStack<T> & rhs);      				 //(5) 
		T &top();                                       			  //(6a) 
		const T & top() const;  										//(6b)
		void push(const T & value);           //(7) 
		void pop();                                                //(8)
		size_t size() const;                //(9) 
		bool empty() const;             //(10) 
		bool full() const;             //(11)
		void clear();                                            //(12)
		void serialize(std::ostream & os) const;                               //(13) 
	private: 
		Node<T> * m_top; 

};

//Default Constructor
template<class T>
NodeStack<T>::NodeStack(){
	m_top = NULL; //sets top to NULL
	cout << "Defualt Works" << endl;
}

//Parameterized Constructor
template<class T>
NodeStack<T>::NodeStack(size_t count, const T & value){
	m_top = NULL;
	for(size_t i = 0; i < count; i++){
		push(value); // until count, push stack for the value
	}
}

//Copy Constructor
template<class T>
NodeStack<T>::NodeStack(const NodeStack<T> & other){
	Node<T> * temp = other.m_top; // temp for top of stack being copied
	m_top = NULL;
	while(temp != NULL){
		push(temp->m_data); //pushes stack for the other stacks data
		temp = temp->m_next; //increment the node that is being pointed to
	}
	
}

//Destructor
template<class T>
NodeStack<T>::~NodeStack(){
	while(!empty()){ //check if empty
		pop(); // pop the entire stack
	}
	cout << "Destructed" << endl;
}

//operator =
template<class T>
NodeStack<T> & NodeStack<T>::operator= (const NodeStack<T> & rhs){
	clear(); // removes any prexisting stack
	Node<T> * temp = rhs.m_top; // temp for stack being copied
	while(temp != NULL){ 
		push(temp->m_data); //push data being copied until hitting bottom of stack
		temp = temp->m_next;
	}
	return *this;
}

//top function
template<class T>
T & NodeStack<T>::top(){
	return m_top -> m_data; // return top element's data
}

//top function 
template<class T>
const T & NodeStack<T>::top() const{
	return m_top -> m_data;
}

//push function
template<class T>
void NodeStack<T>::push(const T & value){
		Node<T> *temp = new Node<T>(value, m_top); // allocate for value being pushed
		m_top = temp; //make top the new node

}

//pop function
template<class T>
void NodeStack<T>::pop(){
	if(m_top != NULL){
		Node<T> * temp = m_top->m_next; // point to the node after top
		delete m_top; // delete top
		m_top = temp; // make the next node the top
	}
}

//size function
template<class T>
size_t NodeStack<T>::size()const{
	Node<T> * temp = m_top;
	size_t count;
	for(count = 0; temp != NULL; temp = temp->m_next){
		count++; // increment count until hitting bottom of stack
	}
	return count;
}

//empty function
template<class T>
bool NodeStack<T>::empty() const{
	return (m_top == NULL); // return 0 or 1 depending if it is empty
}

//full function
template<class T>
bool NodeStack<T>::full() const{
	cout << "Stack is not FULL" << endl; 
	return false; //node stack can never be full
}

//clear function
template<class T>
void NodeStack<T>::clear(){
	while(!empty()){
		pop(); // same as destructor
	}
	cout << "Stack is now empty" << endl;
}

//serialize function
template<class T>
void NodeStack<T>::serialize(std::ostream & os) const{
	Node<T> * temp = m_top;
	while(temp != NULL){
		os << temp->m_data << " "; //prints out data of each node until hitting bottom of stack
		temp = temp->m_next;
	}
}

//operator <<
template<class T>
ostream & operator<<(ostream & os, const NodeStack<T> & nodeStack){
	nodeStack.serialize(os); // print out the stack
	return os;
}
#endif 
