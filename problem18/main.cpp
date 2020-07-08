//
//  main.cpp
//  project18
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
	const unsigned char SIZE = 15;
	
	vector<vector<short unsigned int>> myVector(SIZE, vector<short unsigned int> (0, 0));
	
	ifstream myInput;
	myInput.open("input.txt");
	
	for(unsigned char i = 0; i < SIZE; i ++) {
		for(short unsigned int j = 0; j <= i; j ++) {
			int number;
			myInput >> number;
			myVector[i].push_back(number);
		}
	}
	
	myInput.close();
	
	for (char row = SIZE - 2; row >= 0; row --) {
		for(char column = 0; column <= row; column ++) {
			myVector[row][column] += max(myVector[row + 1][column], myVector[row + 1][column + 1]);
		}
	}
	
//	for (vector<short unsigned int> o : myVector) {
//		for(short unsigned int p : o) {
//			cout << p << " ";
//		}
//		cout << endl;
//	}
	
	cout << myVector[0][0] << endl;
	
    return 0;
}
