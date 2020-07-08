//
//  main.cpp
//  problem20
//
//  Created by James Chen on 7/8/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <deque>

using namespace std;

int main(int argc, const char * argv[]) {
	
	deque<int> myDeque;
	
	myDeque.push_front(1);
	
	for (unsigned int i = 1; i <= 100; i ++) {
		
		unsigned int carry = 0;
		
		for (long j = myDeque.size() - 1; j >= 0; j --) {
			
			unsigned int product = i * myDeque[j];
			
			product += carry % 10;
		
			carry /= 10;
			carry += product / 10;

			myDeque[j] = product % 10;
			
		}
		
		while (carry > 0) {
			myDeque.push_front(carry % 10);
			carry /= 10;
		}
	}
	
	unsigned int sum = 0;
	
	while (myDeque.size() > 0) {
		sum += myDeque.front();
		myDeque.pop_front();
	}
	
	cout << sum << endl;
	
    return 0;
}
