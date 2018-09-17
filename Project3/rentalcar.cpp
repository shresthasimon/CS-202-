//Simon Shrestha
//rentalcar.cpp
//CS 202

#include <iostream>
#include <fstream> 
#include "rentalcar.h"
using namespace std; 

struct RentalAgency{ // struct that has an array of classes as one of its members
	char name[255];
	int zipcode;
	RentalCar inventory[5];
		
};


/*
Name: myStrcpy
Purpose: copies characters from source to destination array until a NULL-character '\0' is found in source, then it NULL-terminates destination too 
Return: pointer to the destination array  
*/
char *myStrcpy(char *dest, const char *source){
    char *result = dest;
    
    if(('\0' != dest) && ('\0' != source)){
        // starts copying source pointer into destination pointer
        while('\0' != *source){
            *dest++ = *source++;
        }
        // puts NULL termination
        *dest = '\0';
    }
    return result;
}

RentalCar::RentalCar(){ //default constructor
	
}
RentalCar::RentalCar(int year, char *make, char *model, float price, bool available){ //parameterized constructor
	setyear(year);
	setmake(make);
	setmodel(model);
	setprice(price);
	setavailable(available);
}

int RentalCar::getyear(){     // get and set functions for all private members
	return m_year;
}

char *RentalCar::getmake(){
	return m_make;
} 

char *RentalCar::getmodel(){
	return m_model;
}

float RentalCar::getprice(){
	return m_price;
}

bool RentalCar::getavailable(){
	return m_available;
}

void RentalCar::setyear(int year){
	m_year = year;	
}
	
void RentalCar::setmake(char *make){
	myStrcpy(m_make,make);
}

void RentalCar::setmodel(char *model){
	myStrcpy(m_model,model);
}

void RentalCar::setprice(float price){
	m_price = price;
}
void RentalCar::setavailable(bool available){
	m_available = available;
}

void RentalCar::print(){ 
	cout << m_year << " ";
    cout << m_make << " ";
    cout << m_model << ", ";
    cout << "$" << m_price << " per day" << ", ";
    cout << "Available: " << boolalpha << m_available << " ";
    cout << endl;
}
float RentalCar::estimatecost(int days){ //estimates the cost for days of renting 
	float total;
	total = m_price * days;
	cout << "Estimated cost is: " << "$"<< total <<endl;	
}

/*
Name: Option1
Purpose: Gets data from the txt file entered by user
returns nothing.
it is in my rentalcar.cpp file so that i can directly access the private member variables.
*/
void RentalCar::Option1(RentalAgency *agency){
	RentalAgency *aptr = agency; // pointer to agency array.
	RentalCar *cptr;	//pointer to RentalCar class.
	char filename[255];

	ifstream filep; // opens file
	
	cout << "Enter the file name: ";
    cin.getline(filename,255); // user input for file
    cin.getline(filename,255);

	cout << "Data sucessfully extracted" << endl; 

	if(!filep){ //check to make sure that the file is avialiable
        cout << "Can't open file, try again" << endl;
        cin.getline(filename,255);
   
    }

	filep.open(filename);

	
	for(int i = 0; i < 3; i++){ // iterates 3 times for agency array
		 filep >> aptr-> name; // gets name data
		filep >> aptr-> zipcode; // gets zipcode data
		cptr = aptr -> inventory; // pointer to point to the array of RentalCar classes inside the struct
		for(int j = 0; j < 5; j++){
			filep >> cptr -> m_year; 
			filep >> cptr -> m_make;
			filep >> cptr -> m_model;
			filep >> cptr -> m_price;
			filep >> cptr -> m_available;
			cptr++;
		}
	aptr++;
	}
	
}



