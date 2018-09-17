#ifndef CAR_H
#define CAR_H
#include <iostream> 
#include "Vehicle.h"

class Car: public Vehicle{
	public:
		Car();
		virtual ~Car();
		Car(float lla[3]); 
		Car(const Car &c_cpy);
		Car& operator = (const Car &c); 
		void Move(float lla[3]);

		int getthrottle();
		void setthrottle(int throttle);
		void drive(int throttle);

	protected:

	private:
		int m_throttle;
		void serialize(ostream& os);
};
#endif 
