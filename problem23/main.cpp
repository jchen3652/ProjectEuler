//
//  main.cpp
//  problem23
//
//  Created by James Chen on 7/8/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool isAbundant(int input) {
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
	
	return divisorSum > input;
}

bool searchComparison(int a, int b) {
	return a < b;
}

int main(int argc, const char * argv[]) {
	vector<int> abundantNumbers;
	
	for (int i = 12; i < 28123; i ++) {
		if (isAbundant(i)) {
			abundantNumbers.push_back(i);
		}
	}
	
	int sum = 0;
	
	for (int i = 1; i <= 28123; i ++) {
		bool found = false;
		
		for (int j = 0; j <= i / 2; j ++) {
			if (binary_search(abundantNumbers.begin(), abundantNumbers.end(), j, searchComparison)) {
				if (binary_search(abundantNumbers.begin(), abundantNumbers.end(), i - j, searchComparison)) {
					found = true;
					break;
				}
			}
		}
		
		if (!found)
			sum += i;
	}
	
	cout << sum << endl;
	
	return 0;
}
