#ifndef ARRAYSTACK_H_
#define ARRAYSTACK_H_

#include "DataType.h"

const size_t MAX_STACKSIZE = 1000;

class ArrayStack{
	friend std::ostream &operator<<(std::ostream & os, const ArrayStack & arrayStack); //(i)
  public:
    	
	ArrayStack();//(1) 
	ArrayStack(size_t count, const DataType & value);          //(2)
	ArrayStack(const ArrayStack & other);                    //(3)
	~ArrayStack();                                                                 //(4)
	ArrayStack &operator= (const ArrayStack & rhs);         //(5) 		
	DataType & top();                                         //(6a) 
	const DataType & top() const;                              //(6b)	
	void push(const DataType & value);           //(7) 		
	void pop();                                                //(8)	
	size_t size() const;                //(9)
	bool empty() const;             //(10) 	
	bool full() const;             //(11) 	
	void clear();                                            //(12)
	void serialize(std::ostream & os) const;                               //(13)
	
  private:
  
   DataType m_container[MAX_STACKSIZE]; 
	size_t m_top; 
};


#endif
