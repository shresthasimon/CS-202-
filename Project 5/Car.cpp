#include <iostream>
#include "Car.h" 
#include <cstring>
using namespace std;

// defualt constructor
Car::Car(){
	m_throttle = 0;
	cout << "Car " << m_vin << ": Default-ctor";
}

// destructor
Car::~Car(){
	cout << "Car " << m_vin << ": Dtor" << endl;
}

//parameterized constructor
Car::Car(char plates[256], int vin, float lla[3]){
	setplates(plates);
	setlla(lla);

	cout << "Car " << m_vin << ": Parameterized-ctor";
}

// copy contructor
Car::Car(const Car &car999_cpy){
	strcpy(m_plates, car999_cpy.m_plates);
	incIdgen();//increments s_idgen
	
	for(int i = 0; i < 3; i++){
		m_lla[i] = car999_cpy.m_lla[i];
	}

	cout << "Car " << m_vin << ": Copy-ctor";
}

char *Car::getplates(){  // get and set methods for private variables
	return m_plates;
}

void Car::setplates(char *plates){
	strcpy(m_plates, plates);
}

int Car::getthrottle(){
	return m_throttle;
}

void Car::setthrottle(int throttle){
	m_throttle = throttle;
}
// assignment operator
Car& Car::operator = (const Car &c){	
	for(int i = 0; i < 3; i++){
		m_lla[i] = c.m_lla[i]; // makes lla and plate name the same
	}
	strcpy(m_plates, c.m_plates);
	cout << "Car " << m_vin << ": Assignment"; 
}

// drive method
void Car::drive(int throttle){
	setthrottle(throttle); 
}

//move method
void Car::move(float lla[3]){
	cout << "Car " << m_vin << ": DRIVE to destination, with throttle @ 75"<<endl;
	drive(75);
}

//insertion operator
ostream& operator << (ostream &out, Car &c){
	out << endl;
	out << "Car " << c.getvin() << " Plates: " << c.getplates() <<", Throttle: " << c.getthrottle() << "@ [";
	
	float *lla = c.getlla();
	
	out << lla[0] <<", "<<lla[1]<<", "<<lla[2]<<"]";
	out << endl;
	
}

