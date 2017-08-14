#include "validations.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::numeric_limits;



void getChar(char& userInput, char ch1, char ch2, char ch3, char ch4, char ch5)
{
   //get user input
   cin >> userInput;
      
   //if input is lowercase, make it UPPERCASE
   if(islower(userInput)){
      userInput = toupper(userInput);
   }
 
   //check for valid user input
   while((userInput != ch1 && userInput != ch2 && userInput != ch3 && userInput != ch4 && userInput != ch5) || cin.fail()){
      if(cin.fail()){
         cout << "Input failed.  Please enter a value from the above options." << endl;
      }
      else if(userInput != ch1 && userInput != ch2 && userInput != ch3 && userInput != ch4 && userInput != ch5){
         cout << "Invalid Character. Please enter a value from the above options." << endl;
      }
   
      //remove error flags
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
      //ask user to reenter
      cout << "Please select a valid character: ";
      cin >> userInput;
   
      //if userInput is lowercase, make it UPPERCASE
      if(islower(userInput)){
         userInput = toupper(userInput);
      }
   }
}