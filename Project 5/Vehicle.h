#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle{
	public:
	Vehicle();
	Vehicle(const int vin, float lla[3]);  
	~Vehicle();
	Vehicle(const Vehicle &v99_cpy);
	Vehicle& operator = (const Vehicle &v);
	friend ostream & operator << (ostream &out, Vehicle &v);
	void move(float lla[3]);

	static int getIdgen();
	void incIdgen();

	int getvin();
	
	void setlla(float lla[3]);
	float *getlla();
 
	protected:
	float m_lla[3];
	const int m_vin;
	private:
	static int s_idgen;
};
#endif
