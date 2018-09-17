// Simon Shrestha
// rentalcar.h
// CS 202

#ifndef RENTALCAR_H_
#define RENTALCAR_H_
#include <iostream>

struct RentalAgency; // defining struct here to allow use later

class RentalCar{
public:
	RentalCar();
	RentalCar(int year, char *make, char *model, float price, bool available); 

	int getyear();
	char *getmake(); 
	char *getmodel();
	float getprice();
	bool getavailable();

	void setyear(int year);
	void setmake(char *make); 
	void setmodel(char *model);
	void setprice(float price);
	void setavailable(bool available);

	void print();
	float estimatecost(int days);
	void Option1(RentalAgency *agency);
	
private:
	int m_year;
	char m_make[255];
	char m_model[255];
	float m_price;
	bool m_available;
};
#endif
