//
//  main.cpp
//  problem21
//
//  Created by James Chen on 7/8/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int d(int input) {
	
	unsigned int squareRoot = sqrt(input);
	
	unsigned int divisorSum = 1;
	
	for (unsigned int i = 2; i <= squareRoot; i ++) {
		if (input % i == 0) {
			divisorSum += i;
			divisorSum += input / i;
		}
	}
	
	if (pow(squareRoot, 2) == input)
		divisorSum -= squareRoot;
	
	return divisorSum;
}

int main(int argc, const char * argv[]) {
	unsigned int sum = 0;
	
	for (int i = 2; i < 10000; i ++) {
		unsigned short divisorSum = d(i);
		
		if (d(divisorSum) == i && i != divisorSum) {
			sum += i;
		}
	}
	
	cout << sum << endl;
}
