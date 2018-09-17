#include <iostream>
#include "Vehicle.h"
#include <cstring>
using namespace std;

//Defualt Constructor
Vehicle::Vehicle(){
	cout << "Vehicle: Default-ctor"<<endl;
}

//parametrized constructor
Vehicle::Vehicle(float lla[3]){
	SetLLA(lla); //sets lla
	cout << "Vehicle: Parametrized-ctor"<< endl;
}

//copy constructor
Vehicle::Vehicle(const Vehicle &v_cpy){ //intializer list to change m_vin to s_idgen
	for(int i = 0; i < 3; i++){
		m_lla[i] = v_cpy.m_lla[i]; // copies lla values
	}

	cout << "Vehicle: Copy-ctor"<<endl;
}

// virtual destructor
Vehicle:: ~Vehicle(){
	cout << "Vehicle: Dtor" << endl;
}

// Assignemnt operator
Vehicle& Vehicle::operator = (const Vehicle &v){
	for(int i = 0; i < 3; i++){
		m_lla[i] = v.m_lla[i];
	}

	cout << "Vehicle: Assignment"<<endl;
}

// get and set methods
void Vehicle::SetLLA(float lla[3]){
	for(int i = 0; i < 3; i++){
		m_lla[i] = lla[i];
	}
}

float *Vehicle::getlla(){
	return m_lla;
}

//virtual serialize method
void Vehicle:: serialize(ostream &os){
	os << "Vehicle @ ["<<m_lla[0] <<", "<<m_lla[1]<<", "<<m_lla[2]<<"]"; // prints out vehicle stuff for the vehicle class
	
}

// insertion operator
ostream & operator << (ostream &out, Vehicle &v){
	v.serialize(out); //uses serialize virtual function based on vehicle object.
}

