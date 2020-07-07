//
//  main.cpp
//  problem14
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
	int maxNumTerms = 0, result = 0;
	
	for (int i = 1000000; i > 1; i --) {
		unsigned int number = i, count = 0;
		while (number != 1) {
			if (number % 2 == 0) {
				number = number / 2;
			} else {
				number = 3 * number + 1;
			}
			count ++;
		}

		
		if (count > maxNumTerms) {
			maxNumTerms = count;
			result = i;
		}
	}
	
	cout << result << endl;
	
    return 0;
}
