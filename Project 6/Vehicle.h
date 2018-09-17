#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle{
	public: 
		Vehicle();
		Vehicle(float lla[3]);
		Vehicle(const Vehicle &v_cpy);
		Vehicle& operator = (const Vehicle &v);
		virtual ~Vehicle();
		virtual void Move(float lla[3]) = 0; // pure virtual method
		friend ostream & operator << (ostream &out, Vehicle &v);

		void SetLLA(float lla[3]);
		float *getlla();
		
	protected:
	float m_lla[3];

	private:
	virtual void serialize(ostream& os);
};
#endif
