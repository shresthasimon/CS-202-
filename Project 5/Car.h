#ifndef CAR_H
#define CAR_H
#include <iostream> 
#include "Vehicle.h"

class Car: public Vehicle{
	public:
		Car();
		~Car();
		Car(char plates[256], int vin, float lla[3]); 
		Car(const Car &car999_cpy);
		Car& operator = (const Car &c); 
		friend ostream & operator << (ostream &out, Car &c);

		void drive(int throttle);	

		char *getplates();
		void setplates(char *plates);

		int getthrottle();
		void setthrottle(int throttle);

		void move(float lla[3]);

	private:
	char m_plates[256];
	int m_throttle; 
};
#endif
