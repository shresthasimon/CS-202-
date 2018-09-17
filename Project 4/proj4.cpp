// Simon Shrestha
// CS 202
// Lab 1102

/*
	Layout
	------
	- Declaration of classes and functions
	- Function prototypes
	- Main
	- Functions for main
	- Class Sensor Functions
	- Class Car Functions
	- Class Agency Functions
*/ 

#include <iostream>
#include <fstream>

using namespace std;

// Sensor Class
class Sensor{

	public:
		Sensor();
		Sensor(char *m_type);
		Sensor(const Sensor& other);
		
		char *gettype();
		void settype(const char *type); //get function and reset functions

		float getcost();

		static int getgps();
		void resetgps();
		
		static int getcamera();
		void resetcamera();

		static int getlidar();
		void resetlidar();
	
		static int getradar();
		void resetradar();
		
		bool operator == (Sensor sensor);
		
		
	private:
		char m_type[256];
		float m_extracost;
		static int gps_cnt;
		static int camera_cnt;
		static int lidar_cnt;
		static int radar_cnt;
};

// intializing static varaibles
int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;
// Car class
class Car{

	public:
		Car(); 
		Car(char *make, char *model, int year, float price, Sensor *sensor);
		Car(const Car& car);

		char *getmake(); 
		void setmake(char *make);

		char *getmodel();
		void setmodel(char *model);

		int getyear();
		void setyear(int year);  // get and set functions

		float getbprice();
		void setbprice(float price);

		bool getavailable();
		void setavailable(bool available);
	
		char *getowner();
		void setowner(char *name);
		
		float getfprice();
		Sensor *getsensor();
		
		float estimatecost(int days); //estimates cost
		void *print();
		
		float updateprice();
		void readsensor(char *a);
		
		void readdata(ifstream &filep);
		void readdata2(ifstream &filep);

		Car& operator+(const char *name);
		Car& operator+(Sensor sensor);
		
	private:
		char m_make[256];
		char m_model[256];
		int m_year;
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char m_owner[256];
		Sensor m_sensor[3];
};

class Agency{
	public:
		Agency();
		Car& operator[](const int i);
		void ReadAllData();
		void PrintAllData();
		void PrintAvailableCars();
		void PrintSensors();
		void MostCostCar();
	private:
		char name[256];
		int zipcode;
		Car m_inventory[5];

};
 // Functions Initalaizers
int getOption();
void option1(Agency *ag);
void option2(Agency *ag);
void option3(Agency *ag);
void option4(Agency *ag);

int main () {
	int i;
	Agency ag[1]; 
	Agency *aptr = ag; // pointer to agency class

	for (;;){
		i = getOption();
		switch(i){
            case 1:
       			option1(ag);
            break;
            
            case 2:
            	option2(ag);
            break;
            
            case 3:
            	option3(ag);
            break;
            
            case 4:
     			option4(ag);
            break;
            
            case 5:
            	return 0;
        }
	}
return 0; 
}



/* 
Name : getOption
Purpose: Displays option menu and returns the option number
Return : the number that the user decides
*/
int getOption(){
     int choice;

    cout << endl
    << "1 - File Input to obtain car data\n"
    << "2 - Print out Agency and Cars\n"
    << "3 - Total number of sensors\n"
    << "4 - Find most expensive car and renting\n"
    << "5 - Exit\n"
	<< "Always choose option 1 first to read in data\n"
	<< "IF FILE NAME IS NOT EXACT THEN IT WILL NOT READ IN CORRECTLY\n"
    << "Enter your choice: ";
    
    cin >> choice; 
    return choice;
}
/*
Name: option1
Purpose: Gets data from file
*/
void option1(Agency *ag){
	Agency *aptr = ag;
	
	aptr -> ReadAllData(); //function that reads in all data
	
	cout << "File data has been sucessfully moved";
	
	
}
/*
Name: option2
Purpose: Prints all agency and car data
*/
void option2(Agency *ag){
	Agency *aptr = ag;

	aptr -> PrintAllData(); // function to print all data
}
/*
Name: option3
Purpose: print the total amount of sensors by name
*/
void option3(Agency *ag){
	Agency *aptr = ag;
	
	aptr -> PrintSensors(); //Function to print sensors
	
}
/*
Name: option4
Purpose: Prints most expensive car and asks user if they want to rent and updates availability and lessee if they do want to rent
*/ 
void option4(Agency *ag){
	Agency *aptr = ag;

	aptr -> MostCostCar(); // function for the entire option 4
}

 ///////////////////////////////// SENSOR CLASS FUNCTIONS ///////////////////
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

/*
Name: myStrcmp
Purpose: Compares two string and returns different numbers depending on the difference of the two strings
Return: the difference between the values of str1 and str2
*/
int myStrcmp(const char *str1, const char *str2){
    while(*str1 == *str2){
        if(*str1 == '\0'){
            return 0;
        }
        str1++;
        str2++;
    }
    return(*str1-*str2);
}
// defualt constructor
Sensor::Sensor(){
	m_extracost = 0.0;
}
// parameterized constructor
Sensor::Sensor(char *type){
	settype(type);
}
// copy constructor
Sensor::Sensor(const Sensor &sensor){
	settype(sensor.m_type);
}
// set methods 
char *Sensor::gettype(){
	return m_type;
}
// sets the type of sensor depending on name.
void Sensor::settype(const char *type){
	myStrcpy(m_type, type); //copies type into m_type depending on sensor type
	if(myStrcmp(type, "gps") == 0){
		m_extracost = m_extracost + 5; // adds to extracost
		gps_cnt++;//increases count 
	}
	else if(myStrcmp(type, "camera") == 0){
		m_extracost = m_extracost + 10;
		camera_cnt++;
	}
	else if(myStrcmp(type, "lidar") == 0){
		m_extracost = m_extracost + 15;
		lidar_cnt++;
	}
	else if(myStrcmp(type, "radar") == 0){
		m_extracost = m_extracost + 20;
		radar_cnt++;
	}
	else{
		myStrcpy(m_type, "none");
		 // if there are no sensor types
	}
}

float Sensor::getcost(){ // get methods
	return m_extracost;
}

 int Sensor::getgps(){
	return gps_cnt;
}

 int Sensor::getcamera(){
	return camera_cnt;
}

 int Sensor::getlidar(){
	return lidar_cnt;
}

 int Sensor::getradar(){
	return radar_cnt;
}

void Sensor::resetgps(){ //reset methods
	 gps_cnt = 0;
} 

void Sensor::resetcamera(){
	camera_cnt = 0;
}

void Sensor::resetlidar(){
	lidar_cnt = 0;
}

void Sensor::resetradar(){
	radar_cnt = 0;
}

bool Sensor::operator == (Sensor sensor){ //overload operator to check if sensor objects are  the same
	return (myStrcmp(m_type, sensor.m_type));
}
 //////////////////////////// CAR CLASS FUNCTIONS /////////////////////
/*
Name: myStrcpy1
Purpose: copies characters from source to destination array until a NULL-character '\0' is found in source, then it NULL-terminates destination too 
Return: pointer to the destination array  
*/
char *myStrcpy1(char *dest, const char *source){
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

/*
Name: myStrcat
Purpose: appends the content of source to the destination array 
this means that the NULL-terminator of destination is overwritten by the first character of source and a NULL-character '\0' is appended at the end of the concatenated Cstring in destination 
Return: pointer to the destination array  
*/
char *myStrcat(char *dest, const char *source){
    char *result = dest;
    
    if(('\0' != dest) && ('\0' != source)){
        // iterate until the end of dest
        while('\0' != *dest){
            dest++;
        }
        // copying source into dest starting from the null of dest
        while('\0' != *source){
            *dest++ = *source++;
        }
        // put null termination
        *dest = '\0';
    }
    return result;
}

/*
Name: myStrlen
Purpose: counts characters in str array until a NULL-character '\0' is found, 
Return: The number excluding the null character
*/
size_t myStrlen(const char *str){
    int i = 0;
    int total = 0;
    char c = str[0];
    
    while(c != '\0'){
        total++;
        c = str[++i];
    }
    return total;
}

// default constructor 
Car::Car(){

}
// parameterized constructor
Car::Car(char *make, char *model, int year, float price, Sensor *sensor){
	setyear(year);
	setmake(make);
	setmodel(model);
	setbprice(price);
	getsensor();
}

char *Car::getmake(){  // get methods
	return m_make;
}

char *Car::getmodel(){
	return m_model;
}

int Car::getyear(){
	return m_year;
}

float Car::getbprice(){
	return m_baseprice;
}

float Car::getfprice(){
	return m_finalprice;
}

bool Car::getavailable(){
	return m_available;
}

char *Car::getowner(){
	return m_owner;
}

Sensor *Car:: getsensor(){
	return m_sensor;
}

void Car::setmake(char *make){ //set methods
	myStrcpy1(m_make,make);
}

void Car::setmodel(char *model){
	myStrcpy1(m_model,model);
}

void Car::setyear(int year){
	m_year = year;	
}

void Car::setbprice(float price){
	m_baseprice = price;
}

void Car::setavailable(bool available){
	m_available = available;
}

void Car::setowner(char *name){
	myStrcpy1(m_owner,name);
}

float Car::estimatecost(int days){ //estimates the cost for days of renting 
	float total;
	total = m_finalprice * days;
	cout << "Estimated cost is: " << "$"<< total <<endl;	
}
// calculates the final price
float Car::updateprice(){
	Sensor *sptr = m_sensor; // point to the sensor class
	m_finalprice = m_baseprice; // makes final price equal to base price
	for(int i =0 ; i < 3; i++){
			m_finalprice += sptr -> getcost(); // adds the price of the sensors to the base price
			sptr++;
	}
	// adds baseprice with m_estimate cost times the number of sensors.
}

void *Car::print(){ //print car data for everything 
	Sensor *sptr = m_sensor;
	cout << m_year << " ";
    cout << m_make << " ";
    cout << m_model << ", ";
    cout << "$" << m_baseprice << " per day" << ", ";

	cout << "Sensors: ";
	cout << "{";
	// Goes until the max number of sensors
	for(int i = 0; i < 3; i++){
		if(myStrcmp(sptr -> gettype(),"none") == 0 || myStrcmp(sptr -> gettype(),"gps") == 0 || myStrcmp(sptr -> gettype(),"radar") == 0 || myStrcmp(sptr -> gettype(),"lidar") == 0 || myStrcmp(sptr -> gettype(),"camera") == 0){ // compares the sensor read in to the ones allowed
			cout << sptr -> gettype() << ", "; // prints out the sensor
		}
	 sptr++; 
	}

	cout << "}, ";
	
    cout << "Available: " << boolalpha << m_available << ", "; // prints out available and owner
	if(m_available == 0){
		cout << "Owner: " << m_owner << " ";
	}
	updateprice();
	cout << " Final Price: " << "$" << m_finalprice; // prints final price of the car, baseprice + costs of all sensors
	cout << endl;
}

void Car::readsensor(char *a){ // function to specifically get sensor from file
	char *x;
	char *c = a; 
	Sensor *sptr = m_sensor; //pointer to sensor class

			for(int i = 0; i < myStrlen(c); i++){ // goes to the length of the c string from each file for each line
				x = c + 1;
				if( *c == '{' && *x == '\0'){   // sets the type depending on what is in the c string
					sptr -> settype("none");
					sptr++;		
				}
				if(*c == 'g' && *x == 'p'){
					sptr -> settype("gps");
					sptr++;
				}
				if(*c == 'r' && *x == 'a'){
					sptr -> settype("radar");	
					sptr++;
				}
				if(*c == 'l' && *x == 'i'){
					sptr -> settype("lidar");
					sptr++;
				}
				if(*c == 'c' && *x == 'a'){
					sptr -> settype("camera");
					sptr++;
				}
			c++; 
			}
		
			
			
			
}
// Function to read in the data fo year, make, model, and baseprice from file
void Car::readdata(ifstream &filep){
	filep >> m_year >> m_make >> m_model >> m_baseprice;
}
// Function to read in the data for available and owner
void Car::readdata2(ifstream &filep){
	filep >> m_available;
	if(m_available == 0){ // if available is false then there is no owner
			filep >> m_owner;
		}
}

// operator overload to add a lessee
Car& Car::operator+(const char *name){
	myStrcpy1(m_owner, name); //adds name to the m_owner member
	return *this;
}

Car& Car::operator+(Sensor sensor){
	
}
//////////////////////// AGENCY CLASS FUNCTIONS ////////////////////

// defualt constructor
Agency::Agency(){

}
// operater overload to iterate through an array of classes
Car& Agency::operator[](const int i){
	return m_inventory[i];
}
// function to read read in data from the file
void Agency::ReadAllData(){
	Car *cptr = m_inventory;
	char filename[256];
	char s;
	char c[50];

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

	filep >> name; //reads in agency name and zipcode
	
	filep >> zipcode;
	for(int i = 0; i < 5; i++){
		cptr -> readdata(filep); // read in year, make, model, baseprice			
		filep.getline(c, 50, '}'); //getline to read from "{" to "}" in each line of the txt file
		cptr -> readsensor(c); // arrange what is read from the getline into the correct sensors
		cptr -> readdata2(filep); // read in available and owner	
		cptr++;
		
	}
	filep.close();
}
// function to print everything that is being read from the final
void Agency::PrintAllData(){
	Car *cptr = m_inventory;
	
	cout << name << " ";
	cout << zipcode; // printing agency name and zipcode
	cout << endl;

	for(int i = 0; i < 5; i++){
	 	cptr -> print(); //function to print all of the car stuff
		cptr++;
		
	}
	
}
// function that prints amount of sensorsfor each type of sensor
void Agency:: PrintSensors(){
	Car *cptr = m_inventory;
	Sensor *sptr = cptr -> getsensor(); // pointer to allow the agency class to access the sensor class
	
	cout << "Total number of sensors by type:" << endl;
	cout << "gps: " << sptr -> getgps() << endl;
	cout << "lidar: " << sptr -> getlidar() << endl;
	cout << "radar: " << sptr -> getradar() << endl;
	cout << "camera: " << sptr -> getcamera() << endl;
}
// function to print out most expensive car and ask the user if they want to rent and update availability and lessee if they want to update
void Agency:: MostCostCar(){
	Car *cptr = m_inventory;
	float max = 0.0;
	Car *maxcar; // pointer to point specifically to the car that is most expensive
	char answer;
	bool available = 0; // sets m_available to false if they do decide to rent
	char owner[5] = "You"; // sets owner to "you" if they decide to rent
	
	for(int i = 0; i < 5; i++){
			cptr -> updateprice(); // updates price for each row in the texfile to get the final price for all 5 cars
		if(cptr -> getfprice() > max){
			maxcar = cptr;
			max = cptr -> getfprice(); // sets max to the finalprice to compare to other final prices during the loop
		}
		cptr++;
	}
	
	cout << "Most Expensive Car: ";
	cout << maxcar -> getyear() << " ";
	cout << maxcar -> getmake() << " "; //prints out the year, make and model for most expensive car
	cout << maxcar -> getmodel() << " ";
	cout << "$" << maxcar -> getfprice(); 
	cout << endl;

	cout << "Would you like to rent this car? "; // ask the user if they would like to rent the car
	cout << "(y or n): ";
	cin >> answer;

	if(answer == 'y' || answer == 'Y'){
		maxcar -> setavailable(available); // if yes then set available to false and owner to "You"
		maxcar -> setowner(owner);
		cout << "Thank you for renting" << endl;
	}else{
		cout << "Come back next time" << endl;
	}
}
// Function to print the available cars
void Agency::PrintAvailableCars(){
	Car *cptr = m_inventory;

	for(int i = 0; i < 5; i++){
		if(cptr -> getavailable() == 1){ // checks if the cars are available
			cout << cptr -> print();
		}
	}
}
