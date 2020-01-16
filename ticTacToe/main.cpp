//
//  main.cpp
//  ticTacToe
//
//  Created by Robert De Angelis on 2020-01-16.
//  Copyright © 2020 Rob		ert De Angelis. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<int> &moves);

int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    return 0;
}

void printBoard(vector<vector<string>> &moves)
{
    for(unsigned int i = 0; i < 3; i++){
        cout << moves[i][0] << '|' << moves[i][1] << '|' << moves[i][2] << endl;
        cout << "______" << endl;
    }
}
