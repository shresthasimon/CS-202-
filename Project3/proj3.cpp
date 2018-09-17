// Simon Shrestha
// proj3.cpp
// CS 202
// Lab Section 1102

#include<iostream> 
#include<fstream>
#include "rentalcar.cpp"
using namespace std;

size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *dest, const char *source);
char *myStrcat(char *dest, const char *source);
int getOption();
void Option2(RentalAgency *agency);
void Option3(RentalAgency *agency);
void Option5(RentalAgency *agency);
void Option4(RentalAgency *agency);

int main(){
    int i;
	RentalAgency agency[3];
	RentalAgency *aptr = agency; 
	RentalCar *cptr;

    for(;;){ //infinite for loop for multiple option inputs
      i = getOption();
        switch(i){
            case 1:
            	cptr -> Option1(agency);
            break;
            
            case 2:
            	Option2(agency);
            break;
            
            case 3:
            	Option3(agency);
            break;
            
            case 4:
            	Option4(agency);
            break;
            
            case 5:
            	Option5(agency);
            break;
            
            case 6:
            return 0;
        }
    }

	return 0;
}
/*
Name: Option 2
Purpose: Print out all the agency and car data
*/
void Option2(RentalAgency *agency){
	RentalAgency *aptr = agency; // pointer to agency array
	RentalCar *cptr; // pointer to class 
	cout << endl;
	
	for(int i = 0; i < 3; i++){
			cout << aptr -> name << " ";
			cout << aptr -> zipcode;
			cout << endl;
			cptr = aptr -> inventory; // pointer to class array in struct
		for(int j = 0; j < 5; j++){
			cptr -> print(); //prints out all data organized
			cptr++;
		}
	aptr++;
	}	
}
/*
Name: Option3
Purpose: Ask the user for car and days of renting and prints out price
*/
void Option3(RentalAgency *agency){
	
	RentalAgency *aptr = agency; //pointer to agency array
	RentalCar *cptr; // pointer to class
	cptr = aptr -> inventory; //  pointer to class array in struct
	int carnum = 0;
	int days = 0;
	char agencyname[20];

	cout << "Enter Agency Name: ";
	cin >> agencyname;

	cout << "Enter car number: ";
	cin >> carnum;

	cout << "Number of Days: ";
	cin >> days;

	carnum--; // account for user entering 1-5

	for(int i =0 ; i < 3; i++){
		for(int k = 0; k < carnum; k++){ //for loop to go through cars while in each agency
			cptr++;
		}
		if((myStrcmp(agencyname, aptr++-> name)== 0)){ //if the name from user is same as an existing one then calculate the cost for the car.
			cptr->estimatecost(days);
			break; // break to stop the loop from calculating more prices.
		}
		cptr = aptr -> inventory; // resets which class it is pointing to
	}

	aptr = NULL;
	cptr = NULL;
}
/*
Name: Option4
Purpose: Finding the most expeensive car in the entire data set
*/
void Option4(RentalAgency *agency){
	float max = 0.0; // intial value for the most expensive car
	RentalCar *maxprice; // pointer to hold the values of most expensive car
	RentalAgency *aptr = agency; // pointer for agency array
	RentalCar *cptr = aptr -> inventory; // pointer for class array

	for(int i =0; i <3; i++){
		for(int j =0;j < 5; j++){
			if(cptr -> getprice() > max){ 
				maxprice = cptr; // if the price is greater than the max price, store that car into maxprice class pointer
				max = cptr-> getprice(); // makes the new price the max price  
			}
			cptr++;
		}
		aptr++;
		cptr = aptr -> inventory;
	}

	cout << "Most Expensive Car: ";
	cout << maxprice -> getyear () << " "; //prints only the values of the maxprice car
	cout << maxprice -> getmake() << " ";
	cout << maxprice -> getmodel() << " ";
	cout << "$ " << maxprice -> getprice();
	cout << endl;
	
	aptr = NULL;
	cptr = NULL;
	maxprice = NULL;
}
/*
Name: Option5
Purpose: Print out only the available cars to an output file
*/
void Option5(RentalAgency *agency){
	RentalAgency *aptr = agency; // pointer to array of structs
	RentalCar *cptr = aptr -> inventory; // pointer to array of classes in the struct
	char filename[50];
	ofstream fileout;
    
    cout << "Please enter output file: ";
    cin.getline(filename, 50);
    cin.getline(filename, 50);
    
    fileout.open(filename);
	
	for(int i =0; i <3; i++){
		for(int j =0;j < 5; j++){
			if(cptr -> getavailable() == 1){ // if any car is available then move it.
				fileout << cptr -> getyear() << " "; 
				fileout << cptr -> getmake() << " ";
				fileout << cptr -> getmodel() << ", "; 
				fileout << "$" << cptr -> getprice() << "per day" << ", ";
				fileout << "Available: " << boolalpha << cptr -> getavailable() << " ";
				fileout << endl; 
			}
			cptr++;
		}
		aptr++;
		cptr = aptr -> inventory;
	}

	cout << "Data has been moved to output file" << endl;
	fileout.close();
	
	cptr = NULL;
	aptr = NULL;
	
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
    << "2 - Print out File data\n"
    << "3 - Estimate car rental cost\n"
    << "4 - Find most expensive car\n"
    << "5 - Print out only available cars\n"
    << "6 - Choose Car\n"
	<< "Always choose option 1 first to read in data\n"
    << "Enter your choice: ";
    
    cin >> choice;
    return choice;
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

















