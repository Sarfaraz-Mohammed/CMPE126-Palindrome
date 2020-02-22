//============================================================================
// Name        : Lab5_CMPE126.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

unsigned int lucas(unsigned int n){
	if(n == 0){
		throw "No 0th Lucas Number";
	}
	if(n == 1){
		return 2;
	}
	if(n == 2){
		return 1;
	}
	return lucas(n-1) + lucas(n-2);
}

int main() {
	unsigned int n = 7;
	cout << "The " << n << "th Lucas number is " << lucas(n) << endl;
	return 0;
}
