//
//  main.cpp
//  problem12
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
	unsigned int currentTriangle = 0;
	unsigned int triangleIncrement = 1;
	
	while (true) {
		currentTriangle += triangleIncrement;
		
//		cout << currentTriangle;
		
		triangleIncrement ++;
		
		unsigned int squareRoot = sqrt(currentTriangle);
		
		unsigned int divisorCount = 0;
		
		for (unsigned int i = 1; i <= squareRoot; i ++) {
			if (currentTriangle % i == 0)
				divisorCount += 2;
		}
		
		if (pow(squareRoot, 2) == currentTriangle)
			divisorCount --;
		
//		cout << ", " << divisorCount << endl;
		
		if (divisorCount > 500)
			break;
		
	}
	cout << currentTriangle << endl;
	
	return 0;
}
