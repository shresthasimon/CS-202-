//Author: Simon Shrestha
//Title: proj8.cpp
//Purpose: test driver for NodeList and ArrayList
#include <iostream>

#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){

  // 1 
	cout << "--------- Defualt Constructor test------" << endl;
	ArrayList al;
    NodeList nl;

	//2 
	cout << "--------- Parameterized Constructor test------" << endl;
	DataType value1(300, 25.0);
    DataType value2(30, 2.0);
	 ArrayList al2(5, value1);
	cout << al2 << endl;
	NodeList nl2(5, value2);
	cout << nl2 << endl;
	//3
	cout << "--------- Copy Constructor test------" << endl;
	ArrayList al3(al2);
	cout << al3 << endl;
	NodeList nl3(nl2);
	cout << nl3 << endl;

	//5, 
	cout << "--------- operator = test------" << endl;
	DataType al5(6, 2.0), nl5(6, 1.0);
	 ArrayList al6(6, nl5);
	cout << "Before" << al6 << endl;
    al6 = ArrayList(6, al5);
	
    cout << "After" <<  al6 << endl;

	NodeList nl6(6, nl5);
	nl6 = NodeList(6, al5);
	cout<< nl6 << endl;

	//6, 7
	cout << "--------- Front and Back function test------" << endl;
	cout << al6 << endl;
	ArrayList firstal(al6), lastal(al6); 
	 DataType* printFirst = firstal.front();
	cout << "Front" << *printFirst << endl;
	 DataType* printLast = lastal.front();
	cout << "Back" << *printLast << endl;
	
	NodeList firstnl(nl6), lastnl(nl6);
	 Node* printfirst = firstnl.front();
    if (printfirst != NULL)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "There is a front node" << endl;
    }
    Node* printlast = lastnl.front();
    if (printlast != NULL)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "there is last node" << endl;
    }
	

	//8
	cout << "---------Find Funtion test------" << endl;
	DataType access(6, 3.0);
	 ArrayList al_access(6, access);
	NodeList nl_access(6, access);
    cout << al_access << endl;
	 DataType* data = NULL;
	DataType* find = al_access.find(access, data);
	cout << "Find first position" << *find << endl;
	cout << "Find first position " << *find << endl;

	//9
	cout << "---------Insert after test----" << endl;
	cout << al2 << endl;
	
	//10 
	cout << "--------Insert before test-----" << endl;
	cout << al2 << endl;	

	//11
	cout << "-------erase test-------" << endl;
	cout << al2 << endl;

	//12
	cout << "--------operator[]  test------" << endl;
	 cout << al_access << endl;
	cout << "second position on list" << al_access[2] << endl;
	cout << "Second node" << al_access[2] << endl;

	//13
	cout << "---------size test--------" << endl;
	cout << al2 << endl;
	cout << "size of list: " <<  al2.size() << endl;
	cout << "size of list: " <<  al2.size() << endl;
	
		
  return 0;

}
