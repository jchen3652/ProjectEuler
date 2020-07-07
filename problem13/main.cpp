//
//  main.cpp
//  problem13
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
	stack<int> myStack;
	
	ifstream myInput;
	myInput.open("input.txt");
	
	vector<string> myVector;
	
	for (unsigned int i = 0; i < 100; i ++) {
		string myString;
		getline(myInput, myString);
		myVector.push_back(myString);
	}
	
	myInput.close();
	
	int cumulativeSum = 0;
	
	for (int charIndex = 49; charIndex >=0; charIndex --) {
		for (int stringIndex = 0; stringIndex < 100; stringIndex ++) {
			cumulativeSum += (myVector[stringIndex][charIndex] - '0');
		}
		myStack.push(cumulativeSum % 10);
		cumulativeSum /= 10;
	}
	
	cout << cumulativeSum;
	
	while (!myStack.empty()) {
		cout << myStack.top();
		myStack.pop();
	}
	
	cout << endl;

}
