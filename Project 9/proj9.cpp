//Author: Simon Shrestha
//Title: proj9.cpp
//Purpose: test driver for queue classes 
#include <iostream>

#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main (){
	cout << "=========Testing Node Queue==========" << endl;

	cout <<"=======(1)Default constructor========" << endl;
	NodeQueue nlist;
	
	cout <<"========(2) Parameterized Constructor=======" << endl;
	DataType dlist(2, 2.5);
	NodeQueue n2list(5, dlist);
	cout << n2list << endl;	
	
	cout <<"(3) Copy Constructor" << endl;
	NodeQueue n3list(n2list);
	cout << n3list << endl;
	
	cout <<"(5) operator= " << endl;
	NodeQueue n4list;
	n4list = n3list;
	cout << n4list << endl;

	cout << "(8) Push Fuunction" << endl;
	DataType dlist2(3, 4.5);
	n4list.push(dlist2);
	cout << n4list << endl;

	cout << "(9) Pop Function" << endl;
	n4list.pop();
	cout << n4list << endl;

	cout << "(6) front function" << endl;
	cout << "front element is" << n4list.front() << endl;

	cout << "(7) Back function" << endl;
	cout << "back function is" << n4list.back() << endl;

	cout << "(10) size function" << endl;
	cout << "size of the queue is:" << n4list.size() << endl;

	cout << "(11) empty function" << endl;
	cout << n4list.empty() << endl;

	cout << "(12) full function" << endl;
	cout << n4list.full() << endl;
	
	cout << "(13) clear function" << endl;
	 n4list.clear();
	cout << n4list << endl;

	cout <<"==========Testing Array Queue=========" << endl;
	
	cout <<"(1) Defualt Constructor" << endl;
	ArrayQueue alist;
	
	cout <<"(2) Parameterized Constructor" << endl;
	DataType dlist3(1, 5.6);
	ArrayQueue alist2(5, dlist3);
	cout << alist2 << endl;
	
	cout <<"(3) Copy Constructor" << endl;
	ArrayQueue alist3(alist2);
	cout << alist3 << endl;
	
	cout <<"(5) operator =" << endl;
	ArrayQueue alist4;
	alist4 = alist3;
	cout << alist4 << endl;

	cout<< "(8) push function" << endl;
	DataType dlist4(7, 7.8);
	alist4.push(dlist4);
	cout << alist4 <<endl; 

	cout <<"(9) pop function" << endl;
	alist4.pop();
	cout << alist4 <<endl;

	cout <<"(6) front function" << endl;
	cout << "front element is" << alist4.front() << endl;

	cout << "(7) back function" << endl;
	cout << "back element is" << alist4.back() << endl;
	
	cout << "(10) size function" << endl;
	cout << "The size of the queue is: " << alist4.size() << endl;

	cout << "(11) empty function" << endl;
	cout << alist4.empty() << endl;
	
	cout << "(12) full function" <<endl;
	cout << alist4.full() <<endl;

	cout << "(13) erase function" << endl;
	alist4.clear();
	cout << alist4 << endl;
return 0;
}
