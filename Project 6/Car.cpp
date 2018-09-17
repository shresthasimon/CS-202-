#include <iostream>
#include "Car.h" 
#include <cstring>
using namespace std;

// defualt constructor
Car::Car(){
	m_throttle = 0;
	cout << "Car: Default-ctor"<<endl;;
}

//parameterized constructor
Car::Car(float lla[3]){
	SetLLA(lla); // sets lla values

	cout << "Car: Parameterized-ctor"<<endl;
}

// copy contructor
Car::Car(const Car &c_cpy){
	
	for(int i = 0; i < 3; i++){
		m_lla[i] = c_cpy.m_lla[i]; // copies lla values
	}

	cout << "Car: Copy-ctor"<<endl;
}

//virtual destructor
 Car:: ~Car(){
	cout << "Car: Dtor"<<endl;
}

// assignment operator
Car& Car::operator = (const Car &c){	
	for(int i = 0; i < 3; i++){
		m_lla[i] = c.m_lla[i]; // makes lla the same
	}
	cout << "Car: Assignment"; 
}

//get and set functions
int Car::getthrottle(){
	return m_throttle;
}

void Car::setthrottle(int throttle){
	m_throttle = throttle;
}

// drive method
void Car::drive(int throttle){
	setthrottle(throttle); 
}

// defines the pure virtual function in Car class
void Car::Move(float lla[3]){
	cout << "Car: DRIVE to destination, with throttle @ 75"<<endl; 
	drive(75); 
}

//serialize function
void Car:: serialize(ostream& os){
	os << "Car: Throttle: " << getthrottle() << "@ [" << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]"; // overwrites the serialize for car class specifically
}

