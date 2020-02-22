/*
 * palindrome.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: smohammed730
 */
#include <string.h>
#include <iostream>
using namespace std;


bool check_palindrome(const string &s)
{
	if(s.length() <= 1)
	{
		return true;
	}else{
		return s[0] == s[s.length() - 1] && check_palindrome(s.substr(1, s.length() - 2));
	}
}



