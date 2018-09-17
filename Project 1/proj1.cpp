// Author: Simon Shrestha
// Name: proj1.cpp
// Class: CS 202

#include <iostream> 
#include <fstream>
using namespace std;

void myStringCopy(char destination[], const char source[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[], const char str2[]);
void sortNames( char array[10][9], int array2[10]);

int main(){
    char Names[10][9];
    char fileName [50];
    char outputFileName[50];
    int number[10];
    int row, col = 0;
    
    ifstream filep; // opening file for reading

    cout << "Enter the file you would like to sort (please include .txt): ";
    cin.getline(fileName,50);
    
    cout << "Your input file name is: " << fileName << endl;
    
    filep.open(fileName); // opening text file from user input 
    
    if(!filep){ //check to make sure that the file is avialiable
        cout << "Can't open file" << endl;
        return(1);
    }
    
    cout << endl;
    cout << "Unsorted Data" << endl
         <<"================="<<endl;
    
        // goes through the file    
    for(row = 0; row < 10; row++){
        number[row] = row;	// creates numbers 0 to 10 to assign to names
        for(col = 0; col < 9; col++){
            filep.get(Names[row][col]); 
            if(Names[row][col] == '\n'){ // when there is a newline character, it is changed to a null character
                Names[row][col] = '\0';
                break;
            }
        }
        cout << number[row] << " " << Names[row] << endl;
    }
    
    filep.close();

    
    sortNames(Names, number); // function to sort names as well as the number
 
    cout << endl;
    cout << "Sorted Data" << endl
        << "================" << endl;
    
    for( row = 0; row < 10; row++){ // prints names with numbers after sorting
        cout << number[row] <<" "<< Names[row] << endl;
    }

    ofstream filep2;
    
    cout << "Please Enter the file you would like to output the arranged names (please inlcude .txt: "; 
    cin.getline(outputFileName,50); // gets output file from user
    cout << "Your output file is: " << outputFileName << endl;
    
    filep2.open(outputFileName);
    
    if(filep2.is_open()){
        for(row = 0; row < 10; row++){
            filep2 << number[row] << " " << Names[row] << endl; // writes the arragned names to output file along with the number 
        }
    }else{
        cout << "Unable to open file";
    }
    
    cout << "Your arranged list has been sucessfuly been moved to the new file" << endl;
    
    filep2.close();

return 0;
}
// Name: myStringCopy
// Purpose: Copys one array into another array
void myStringCopy(char destination[], const char source[]){
        int i = 0;
        
        while(source[i] != '\0'){
            destination[i] = source[i]; //if source array is not equal to Null character
            i++;                        // move all contents from source to destination array
        }
        destination[i] = '\0';
        
        
}

// Name: myStringLength
//Purpose: outputs the length of an array
int myStringLength(const char str[]){
    int len = 0;
    int i;
    
    for(i=0;str[i] != '\0'; i++){ //increase len value until str[] equals null character
        len++;
    }
    
    return len;
    
}
// Name: myStringCompare
// Purpose: compares one array to another and outputs a value depending on their differences
int myStringCompare(const char str1[], const char str2[]){
    int i = 0;
    
    while(str1[i] && str1[i] == str2[i]){ //checks if str1 and string2 are equal
        i++;
    }
    return str1[i] - str2[i]; // if they arent equal, subractes the value of str1 by str2
                              // this could be 0, negative, or postive number
                              // same as 0, 1, -1
}

// Name: sortNames
// Purpose: alphabetically sorts names provided by a file as well as the number associated with the name. 
void sortNames( char array[10][9], int array2[10]){
    int i, j;
     
    for(i=0;i<9;++i){ // goes through each name and the one after it.
      char temp[10]; // creates temp array to move str1 and str2 around
      int numtemp;
        for(j=i+1;j < 10;++j){
            if(myStringCompare(array[j], array[i]) < 0){ // compares each name to the one after it
                myStringCopy(temp, array[i]);
                numtemp = array2[i]; // bubble sort to switch the numbers along with the names. .
                myStringCopy(array[i], array[j]); // bubble sort to swap the names around
                array2[i] = array2[j];
                myStringCopy(array[j], temp);
                array2[j] = numtemp;
            }
        }
    }
}













































