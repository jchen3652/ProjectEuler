//
//  main.cpp
//  problem19
//
//  Created by James Chen on 7/8/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>

using namespace std;

int main (int argc, const char * argv[]) {
	unsigned int result = 0;
	
	unsigned char weekday = 1;
	unsigned char month = 1;
	unsigned char day = 1;
	unsigned short year = 1900;
	
	while (year <= 2000) {
		if (year >= 1901 && weekday == 0 && day == 1) {
			result ++;
		}
		
		weekday = (weekday + 1) % 7;
		day ++;
		
		unsigned char daysInMonth;
		if (month == 9 || month == 4 || month == 6 || month == 11) {
			daysInMonth = 30;
		} else if (month == 2) {
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
				daysInMonth = 29;
			} else {
				daysInMonth = 28;
			}
		} else {
			daysInMonth = 31;
		}
		
		if (day > daysInMonth) {
			day = 1;
			month ++;
		}
		
		if (month > 12) {
			month = 1;
			year ++;
		}
	}
	
	cout << result << endl;
	
}
