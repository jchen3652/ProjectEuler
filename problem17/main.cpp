//
//  main.cpp
//  problem17
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;



string getSpecialString(unsigned int number) {
	switch (number) {
		case 0:
			return "";
		case 1:
			return "one";
		case 2:
			return "two";
		case 3:
			return "three";
		case 4:
			return "four";
		case 5:
			return "five";
		case 6:
			return "six";
		case 7:
			return "seven";
		case 8:
			return "eight";
		case 9:
			return "nine";
		case 10:
			return "ten";
		case 11:
			return "eleven";
		case 12:
			return "twelve";
		case 13:
			return "thirteen";
		case 14:
			return "fourteen";
		case 15:
			return "fifteen";
		case 16:
			return "sixteen";
		case 17:
			return "seventeen";
		case 18:
			return "eighteen";
		case 19:
			return "nineteen";
		case 20:
			return "twenty";
		case 30:
			return "thirty";
		case 40:
			return "forty";
		case 50:
			return "fifty";
		case 60:
			return "sixty";
		case 70:
			return "seventy";
		case 80:
			return "eighty";
		case 90:
			return "ninety";
			
	}
	return "GAY";
}


string getCombinedString(unsigned int number) {
	if (number == 1000)
		return "onethousand";
	
	string result = "";
	short unsigned int lastTwoDigits = number % 100;
	short unsigned int lastDigit = number % 10;
	bool moreThan2Digits = number > 99;
	
	if (moreThan2Digits) {
		result += getSpecialString(number / 100);
		result += "hundred";
	}
	
	if (lastTwoDigits != 0) {
		result += moreThan2Digits ? "and" : "";
		result += lastTwoDigits / 10 >= 2 ? getSpecialString(lastTwoDigits / 10 * 10) + getSpecialString(lastDigit):getSpecialString(lastTwoDigits);
	}
	
	return result;
	
}

int main(int argc, const char * argv[]) {
	unsigned long int sum = 0;
	
	for (int i = 1; i <= 1000; i ++) {
		sum = sum + getCombinedString(i).size();
	}
	
	cout << sum << endl;
	
}
