//
//  main.cpp
//  problem15
//
//  Created by James Chen on 7/7/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
	unsigned int SIZE = 21;
	
	vector<vector<unsigned long long int>> array(SIZE, vector<unsigned long long int>(SIZE, 0));
	
	for (int i = 0; i < SIZE; i ++) {
		array[0][i] = 1;
		array[i][0] = 1;
	}
	
	for (int i = 1; i < SIZE; i ++) {
		for(int j = 1; j < SIZE; j ++) {
			array[i][j] = array[i - 1][j] + array[i][j - 1];
		}
	}
	
//	for (vector<unsigned long long int> o: array) {
//		for (unsigned long long int p: o) {
//			cout << p << " ";
//		}
//		cout << endl;
//	}
	
	cout << array[SIZE - 1][SIZE - 1] << endl;
	
    return 0;
}
