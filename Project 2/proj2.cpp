// Simon Shrestha
// proj2.cpp
// CS 202
// Lab Section 1102

#include<iostream> 
#include<fstream>
using namespace std;

size_t myStrlen(const char *str);
int myStrcmp(const char *str1, const char *str2);
char *myStrcpy(char *dest, const char *source);
char *myStrcat(char *dest, const char *source);
int getOption();


struct RentalCar {
    int year;
    char make[10];
    char model[10];
    float price;
    bool available;
};

void Option1(RentalCar cars[5]); // function protoypes after struct due to the usage of struct
void Option2(RentalCar cars[5]);
void Option3(RentalCar cars[5]); 
void Option4(RentalCar cars[5], RentalCar temp);
void Option5(RentalCar cars[5], RentalCar temp);
void Option6(RentalCar cars[5]);

int main(){
    int i;
    
    RentalCar cars[5]; // struct objects
    RentalCar temp;
    
    for(;;){ //infinite for loop for multiple option inputs
      i = getOption();
        switch(i){
            case 1:
            Option1(cars);
            break;
            
            case 2:
            Option2(cars);
            break;
            
            case 3:
            Option3(cars);
            break;
            
            case 4:
            Option4(cars, temp);
            break;
            
            case 5:
            Option5(cars, temp);
            break;
            
            case 6:
            Option6(cars);
            break;
            
            case 7:
            return 0;
        }
    }

return 0;
}
/*
Name: Option1
Purpose: gets data from input file and places data into an array of structs
*/
void Option1(RentalCar cars[5]){
    char filename[50];
    ifstream filep;
    
    cout << "Enter the file name: ";
    cin.getline(filename,50);
    cin.getline(filename,50);
    
    if(!filep){ //check to make sure that the file is avialiable
        cout << "Can't open file, try again" << endl;
        cin.getline(filename,50);
   
    }
    
    filep.open(filename);
    
    for(int i = 0; i < 5; i++){ // for ever row, data is seperated into individual strcut members
        filep >> cars[i].year; 
        filep >> cars[i].make;
        filep >> cars[i].model;
        filep >> cars[i].price; 
        filep >> cars[i].available;    
    }
    
    cout << "The data from the file has sucessfully moved" << endl;
    
    filep.close();
}
/*
Name: Option2
Purpose: prints out the contents of the array of strcuts into a specific structure
*/
void Option2(RentalCar cars[5]){
    cout << endl;
    
    for(int i = 0; i < 5; i++){ 
        cout << cars[i].year << " ";
        cout << cars[i].make << " ";
        cout << cars[i].model << ", ";
        cout << "$" << cars[i].price << " per day" << ", ";
        cout << "Available: " << boolalpha << cars[i].available << " ";
        cout << endl;
    }
}
/*
Name: Option3
Purpose: Asks user for output file and moves the data from the a array of structs into the file
*/
void Option3(RentalCar cars[5]){
    char filename[50];
    
    ofstream fileout;
    
    cout << "Please enter output file: ";
    cin.getline(filename, 50);
    cin.getline(filename, 50);
    
    fileout.open(filename);
    
    for(int i = 0; i < 5; i++){ // prints out the data of each struct into new file
        fileout << cars[i].year << " ";
        fileout << cars[i].make << " ";
        fileout << cars[i].model << ", ";
        fileout << "$" << cars[i].price << " per day" << ", ";
        fileout << "Available: " << boolalpha << cars[i].available << " ";
        fileout << endl;
    }
    
    cout << "Data has been sucessfully moved to output file" << endl;
    
    fileout.close();
}
/*
Name: Option4
Purpose: Sorts the array of structs by asending in price
*/
void Option4(RentalCar cars[5], RentalCar temp){
    int i, j;
    
    for(i=0; i<4; ++i){ //bubble sort for sorting the structs
        for(j=i+1; j<5;++j){
            if(cars[i].price > cars[j].price){
                temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
                
            }
        }
    }
     cout << endl;
     cout << "Sorted by price\n"
          << "===============" << endl;
    
    for(int i = 0; i < 5; i++){ // printing out new sorted data
        cout << cars[i].year << " ";
        cout << cars[i].make << " ";
        cout << cars[i].model << ", ";
        cout << "$" << cars[i].price << " per day" << ", ";
        cout << "Available: " << boolalpha << cars[i].available << " ";
        cout << endl;
    }
}
/*
Name: Option5
Purpose: Ask the user for amount of days of rent and show available cars as well as price
Return: ascending total price of cars available

*/
void Option5(RentalCar cars[5], RentalCar temp){
    float days;
    int i, j;
    int num;
    
    cout << "How many days would you like to rent a car? : "; //asks the user for number of days for renting
    cin >> days;
    
    for(int i = 0; i < 5; i++){
        cars[i].price = days * cars[i].price; // changes the price member of each struct by multiplying by days
    }
    
    for(i=0; i < 4; ++i){ //bubble sort for sorting the structs
        for(j=i+1; j < 5;++j){
            if((cars[i].price > cars[j].price) && cars[i].available == true){ // sorts only if the cars are available
                temp = cars[i];
                cars[i] = cars[j];
                cars[j] = temp;
                
            }
        }
    }
    
    for(int i = 0; i < 5; i++){
        if(cars[i].available == true){ // only prints the cars that are available in ascending order
            cout << cars[i].year << " ";
            cout << cars[i].make << " ";
            cout << cars[i].model << ", ";
            cout << "Total Cost: " << "$" << cars[i].price;
            cout << endl;
        }
    }
    
    for(int i = 0; i < 5; i++){ // resets the price of each car for other options
        cars[i].price = cars[i].price / days;
    }
}
/*
Name: Option6
Purpose: Ask the user for car to rent and calculates price depending on number of days
as well as changing availability
Return: price of car chosen for certain number of days
*/
void Option6(RentalCar cars[5]){
   int index;
   int i;
   int num[5] = {0,1,2,3,4};
   int days;
   
   for(i = 0; i < 5; i++){ //prints out the options along with index numbers
        cout << num[i] << " - " << cars[i].year << " ";
        cout << cars[i].make << " ";
        cout << cars[i].model << ", ";
        cout << "$" << cars[i].price << " per day" << ", ";
        cout << "Available: " << boolalpha << cars[i].available << " ";
        cout << endl;
   }
   
   cout << "Choose a number to rent a car: ";
   cin >> index;
   
   while(cars[index].available != true){ //if car is not available then choose again 
        cout << "That car is not available" << endl;
        cout << "Choose again: ";
        cin >> index;
   }
   
   while(index < 0 || index > 4){ //if index number is not within range, choose again
        cout << "That number isn't available" << endl;
        cout << "Choose again: ";
        cin >> index;
   }
   
   cout << "How many days would you like to rent the car? :";
   cin >> days;
   
   cars[index].available = 0; // changes avialability of car chosen
   cars[index].price = cars[index].price * days;
   
   cout << "Your total cost will be: " << "$" << cars[index].price << endl; // prints out price 
   cars[index].price = cars[index].price / days; // resets price member of the car chosen
   
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
    << "3 - Print out data to Output file\n"
    << "4 - Sort cars by ascending price\n"
    << "5 - Total renting price and availbility\n"
    << "6 - Choose Car\n"
    << "7 - Exit program\n"
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
























































































































































































