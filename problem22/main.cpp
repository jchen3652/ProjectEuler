//
//  main.cpp
//  problem22
//
//  Created by James Chen on 7/8/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool sorter(string first, string second) {
	return first < second;
}

int main(int argc, const char * argv[]) {
	ifstream myInput("p022_names.txt");
	
	vector<string> names;
	bool stop = false;
	
	while (!stop) {
		string line;
		
		
		while (true) {
			char nextCharacter = myInput.get();
			
			if (nextCharacter == '\n') {
				stop = true;
				break;
			} else if (nextCharacter == ',') {
				break;
			} else if (nextCharacter != '"') {
				line.push_back(nextCharacter);
			}
		
		}
		names.push_back(line);
//		cout << line << endl;

	}
	
	myInput.close();
	
	
	sort(names.begin(), names.end(), sorter);
	
	unsigned int sum = 0;
	
	for (unsigned int i = 0; i < names.size(); i ++) {
		unsigned int score = 0;
		for (char o : names[i]) {
			score += (o - '@');
		}
		sum += (score * (i + 1));
		
	}
	
	cout << sum << endl;
	
    return 0;
}
