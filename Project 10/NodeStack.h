#ifndef NODESTACK_H_
#define NODESTACK_H_

#include "DataType.h"

class Node{

  friend class NodeStack;  //allows direct accessing of link and data from class NodeList

  public:
    Node() :
	  m_next( NULL )
	{
	}
	Node(const DataType& data, Node * next = NULL) :
	  m_next( next ),
	  m_data( data )
	{
	}
	Node(const Node & other) :
	  m_next( other.m_next ),
	  m_data( other.m_data )
	{
	}
	
    DataType & getData(){  //gets non-const reference, can be used to modify value of underlying data
      //return const_cast<DataType &>(static_cast<const Node &>(*this).getData());  //an alternative implementation, just for studying reference
	  return m_data;
    }
    const DataType & getData() const{  //gets const reference, can be used to access value of underlying data
      return m_data;
    }

  private:
    Node * m_next; 						
    DataType m_data;
};

class NodeStack{
	friend std::ostream & operator<<(std::ostream & os, const NodeStack & nodeStack); //(i)
	public:
		NodeStack(); //(1) 
		NodeStack(size_t count, const DataType & value);              		//(2) 	
		NodeStack(const NodeStack & other);                     			 //(3) 
		~NodeStack();                                                        //(4)
		 NodeStack &operator= (const NodeStack & rhs);      				 //(5) 
		DataType &top();                                       			  //(6a) 
		const DataType & top() const;  										//(6b)
		void push(const DataType & value);           //(7) 
		void pop();                                                //(8)
		size_t size() const;                //(9) 
		bool empty() const;             //(10) 
		bool full() const;             //(11)
		void clear();                                            //(12)
		void serialize(std::ostream & os) const;                               //(13) 
	private: 
		Node * m_top; 

};

#endif 
