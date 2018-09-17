#include <iostream>

#include "ArrayStack.h"
#include "NodeStack.h"


using namespace std;

int main (){

	cout << "=========Testing Node Stack==========" << endl;

	cout <<"(1)Default constructor" << endl;
	NodeStack<DataType> nlist;

	cout <<"(2) Parameterized Constructor" << endl;
	DataType dlist(2, 2.5);
	NodeStack<DataType> n2list(5, dlist);
	cout << n2list << endl;	

	cout <<"(3) Copy Constructor" << endl;
	NodeStack<DataType> n3list(n2list);
	cout << n3list << endl;

	cout <<"(5) operator= " << endl;
	NodeStack<DataType> n4list;
	n4list = n2list;
	cout << n4list << endl;
	
	cout << "(7) Push Fuunction" << endl;
	DataType dlist2(3, 4.5);
	n4list.push(dlist2);
	cout << n4list << endl;

	cout << "(6) top function" << endl;
	cout << "top element is" << n4list.top() << endl;
	
	cout << "(8) Pop Function" << endl;
	n4list.pop();
	cout << n4list << endl;

	cout << "(9) size function" << endl;
	cout << "size of the stack is:" << n4list.size() << endl;

	cout << "(10) empty function" << endl;
	cout << boolalpha << n4list.empty() << endl;

	cout << "(11) full function" << endl;
	cout << boolalpha << n4list.full() << endl;
	
	cout << "(12) clear function" << endl;
	 n4list.clear();
	cout << n4list << endl;
	

	cout <<"==========Testing Array Stack=========" << endl;
	
	cout <<"(1) Defualt Constructor" << endl;
	ArrayStack<DataType> alist;

	cout <<"(2) Parameterized Constructor" << endl;
	DataType dlist3(1, 5.6);
	ArrayStack<DataType> alist2(5, dlist3);
	cout << alist2 << endl;
	
	cout <<"(3) Copy Constructor" << endl;
	ArrayStack<DataType> alist3(alist2);
	cout << alist3 << endl;

	cout <<"(5) operator =" << endl;
	ArrayStack<DataType> alist4;
	alist4 = alist3;
	cout << alist4 << endl;

	cout<< "(7) push function" << endl;
	DataType dlist4(7, 7.8);
	alist4.push(dlist4);
	cout << alist4 <<endl; 

	cout <<"(6) top function" << endl;
	cout << "top element is" << alist4.top() << endl;

	cout <<"(8) pop function" << endl;
	alist4.pop();
	cout << alist4 <<endl;

	cout << "(9) size function" << endl;
	cout << "The size of the Stack is: " << alist4.size() << endl;

	cout << "(10) empty function" << endl;
	cout << boolalpha << alist4.empty() << endl;
	
	cout << "(11) full function" <<endl;
	cout << boolalpha << alist4.full() <<endl;

	cout << "(12) erase function" << endl;
	alist4.clear();
	cout << alist4 << endl;
return 0;
}
