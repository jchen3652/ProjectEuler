//
//  main.cpp
//  problem11
//
//  Created by James Chen on 7/5/20.
//  Copyright © 2020 James Chen. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    unsigned int SIZE = 20;
    unsigned int array[SIZE][SIZE];
    
	ifstream myInput;
	
	myInput.open("input.txt");
	
    for(unsigned int i = 0; i < SIZE; i ++) {
        for(unsigned int j = 0; j < SIZE; j++) {
            myInput >> array[i][j];
        }
    }

	myInput.close();
	
    
    unsigned int max = 0;
    
    for(int i = 0; i < SIZE; i ++) {
        for(int j = 0; j < SIZE; j ++) {
			// Down
            if (i + 3 < SIZE) {
                unsigned int current = array[i][j] * array[i + 1][j] * array[i + 2][j] * array[i + 3][j];
                if (current > max)
                    max = current;
            }
            
			// Down and right
            if (i + 3 < SIZE && j + 3 < SIZE) {
                unsigned int current = array[i][j] * array[i + 1][j + 1] * array[i + 2][j + 2] * array[i + 3][j + 3];
                if (current > max)
                    max = current;
            }
            
			// Right
            if (j + 3 < SIZE) {
                unsigned int current = array[i][j] * array[i][j + 1] * array[i][j + 2] * array[i][j + 3];
                if (current > max)
                    max = current;
            }
			
			// Down and left
			if (i + 3 < SIZE && j - 3 >= 0) {
				unsigned int current = array[i][j] * array[i + 1][j - 1] * array[i + 2][j - 2] * array[i + 3][j - 3];
				   if (current > max)
					   max = current;
			}
            
        }
    }
    
    cout << max << endl;
    
    return 0;
}
