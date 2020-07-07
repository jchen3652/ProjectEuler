//
//  main.cpp
//  problem16
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, const char * argv[]) {
	vector<unsigned short> myVector{1};

	for (int i = 0; i < 1000; i ++) {
		unsigned short carry = 0;
		
		for (int j = 0; j < myVector.size(); j ++) {
			unsigned short product = myVector[j] * 2 + carry;
			myVector[j] = product % 10;
			carry = 0;

			if (product > 9) {
				if (myVector.size() == j + 1) {
					myVector.push_back(1);
					break;
					
				} else {
					carry = 1;
				}
			}
		}
	}
	
	cout << accumulate(myVector.begin(), myVector.end(), 0) << endl;
	
}
