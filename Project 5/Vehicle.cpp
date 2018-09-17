#include <iostream>
#include "Vehicle.h"
#include <cstring>
using namespace std;

// initalizing static int variables
int Vehicle::s_idgen = 1;

// Defualt constructor
Vehicle::Vehicle(): m_vin(s_idgen++){ // initializer list to increment m_vin based on teh value of s_idgen
	
	cout << "Vehicle " << m_vin << ": Default-ctor"<<endl;
}

//parametrized constructor
Vehicle::Vehicle( int vin, float lla[3]): m_vin(vin > s_idgen ? vin : s_idgen){ // inialization list to check for m_vin and to change m_vin
	if(vin > s_idgen)
		s_idgen = vin;
	s_idgen++;
	setlla(lla);
	
	cout << "Vehicle " << m_vin << ": Parametrized-ctor";
}

//copy constructor
Vehicle::Vehicle(const Vehicle &v99_cpy):m_vin(s_idgen++){ //intializer list to change m_vin to s_idgen
	for(int i = 0; i < 3; i++){
		m_lla[i] = v99_cpy.m_lla[i];
	}

	cout << "Vehicle " << m_vin << ": Copy-ctor";
}

// vehicle class dtor
Vehicle:: ~Vehicle(){
	cout << "Vehicle " << m_vin << ": Dtor" << endl;
};

//get and set functions
int Vehicle:: getIdgen(){
	return s_idgen;
}

int Vehicle::getvin(){
	return m_vin;
}

void Vehicle::setlla(float lla[3]){
	for(int i = 0; i < 3; i++){
		m_lla[i] = lla[i];
	}
}

float *Vehicle::getlla(){
	return m_lla;
}

// Assignemnt operator
Vehicle& Vehicle::operator = (const Vehicle &v){
	for(int i = 0; i < 3; i++){
		m_lla[i] = v.m_lla[i];
	}

	cout << "Vehicle " << m_vin << ": Assignment";
}

// insertion operator
ostream& operator << (ostream &out, Vehicle &v){
	out << endl;
	out << "Vehicle " << v.getvin() << " @ ";
	out << "[";

	for(int i = 0; i < 3; i++){
		out << v.m_lla[i]; 
		
		if(i < 2){out << ", ";}; // if statement to place commas correctly
	}
	out << "]";
}
// move method
void Vehicle::move(float lla[3]){
	cout << "Vehicle " << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW";

}
// function to increment s_idgen
void Vehicle::incIdgen(){
	s_idgen++;
}
	
