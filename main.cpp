/*
Creating and working with dynamic arrays v0.0.0.1
creator: Tarique Ali Mirza <tarique1988@gmail.com>
date of inception: 22nd August 2019
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <string>
#include "Array.h"

using namespace std;

template <typename A>
void getInputReturnArray(Array<A> &arr);

int main(){
	int userChoice = -1;
	cout << "What type of array do you want?" << endl;
	cout << "1. String Array." << endl;
	cout << "2. Char Array." << endl;
	cout << "3. Integer Array." << endl;
	cout << "Your selection:" << endl;
	if(cin >> userChoice){
		if(userChoice == 1){
			Array<string> arr;
			getInputReturnArray(arr);
			arr.print();
		} else if(userChoice == 2){
			Array<char> arr;
			getInputReturnArray(arr);
			arr.print();
		} else if(userChoice == 3){
			Array<int> arr;
			getInputReturnArray(arr);
			arr.print();
		} else{
			cout << "@main: Invalid Input. Program will exit.." << endl;
			return -1;
		}
	} else{
		cout << "Invalid Input. Program will exit.." << endl;
		return -1;
	}
	
  	return 0;
}


template <typename A>
void getInputReturnArray(Array<A> &ar){
	A temp;
	int userChoice = 0;
	bool keepGoing = false;
	cin.clear();
	cin.ignore();
	do{
		cout << "Please enter a value to add to the array!" << endl;
		if(cin >> temp){
			ar.add(temp);
		} else{
			cout << "Invalid Input." << endl;
		}
		cin.clear();
		cin.ignore();
		cout << "What would you like to do next?" << endl;
		cout << "1. Add more values." << endl;
		cout << "2. Print existing values and continue." << endl;
		cout << "3. Print existing values and Exit." << endl;
		cout << "4. Exit." << endl;
		cout << "Your selection: " << endl;
		cin >> userChoice;
		switch(userChoice){
			case 1:
				keepGoing = true;
				break;
			case 2:
				ar.print();
				keepGoing = true;
				break;
			case 3:
				ar.print();
				keepGoing = false;
				break;
			case 4:
				keepGoing = false;
				break;
			default:
				cout << "@getInputFunc(): Invalid Input. Program will exit." << endl;
				break;
		}
	} while(keepGoing);
}
