//
//  main.cpp
//  ticTacToe
//
//  Created by Robert De Angelis on 2020-01-16.
//  Copyright © 2020 Rob		ert De Angelis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void printBoard(vector<string> &moves);
vector<int> getMoves(int count, vector<string> &moves);
void updatePosition(vector<int> &move, int &count, vector<string> &position);
bool checkWin(vector<string> &position);
vector<int> aiMove(vector<string> positions);
int minimax(vector<string>position, int depth, bool isMax);

int main(int argc, const char * argv[]) {
    vector<string> positions;
    int count = 1;
    positions.push_back("   ");
    positions.push_back("   ");
    positions.push_back("   ");
//    cout << "Hello, World!\n";
    bool game = true;
    while(game)
    {
        printBoard(positions);
        vector<int> nextMove = getMoves(count, positions);
//        cout << nextMove[0] << endl << nextMove[1] << endl;
        if(nextMove[0] == -1){
            game = false;
        }
        updatePosition(nextMove, count, positions);
        game = checkWin(positions);
        count++;
    }
    return 0;
}

vector<int> aiMove(vector<string> positions){
    int bestScore = -1000;
    vector<int> bestMove;
    bestMove.push_back(0);
    bestMove.push_back(0);
    for(int i = 0; i < 3; i++){
        for(int x = 0; x < 3; x++){
            if(positions[i][x] == ' '){
                positions[i][x] = 'X';
                int score = minimax(positions, 0, true);
                positions[i][x] = ' ';
                if(score > bestScore){
                    bestScore = score;
                    bestMove[0] = i;
                    bestMove[1] = x;
                }
            }
        }
    }
    return bestMove;
}
int minimax(vector<string>position, int depth, bool isMax){
    
    return 1;
}

bool checkWin(vector<string> &position){
    for(unsigned int i = 0; i < 3; i++){
    if((position[i][0] == position[i][1]) and (position[i][1] == position[i][2]) and (position[i][0] != ' ')){
        cout << endl << position[i][1] << " : Wins the game" << endl;
        return false;
    }else if((position[0][i] == position[1][i]) and (position[1][i] == position[2][i]) and (position[0][i] != ' ')){
        cout << endl << position[1][i] << " : Wins the game" << endl;
        return false;
    }else if((position[0][0] == position[1][1]) and (position[1][1] == position[2][2]) and (position[0][0] != ' ')){
        cout << endl << position[1][1] << " : Wins the game" << endl;
        return false;
    }else if((position[2][2] == position[1][1]) and (position[1][1] == position[2][0]) and (position[2][0] != ' ')){
        cout << endl << position[1][1] << " : Wins the game" << endl;
        return false;
    }
        }
    return true;
}

void updatePosition(vector<int> &move, int &count, vector<string> &position){
    if(position[move[0]][move[1]] == ' '){
    if(count % 2 == 0){
        position[move[0]][move[1]] = 'O';
    }else{
        position[move[0]][move[1]] = 'X';
    }
    }else{
        cout << "SPOT IS TAKEN" <<endl;
        count--;
    }
    
}

vector<int> getMoves(int count, vector<string> &moves){
    vector<int> move;
    if(count %2 == 0)
    {
//        int oMoveX;
//        int oMoveY;
//        cout << "Enter your move player O in the format \n'3\n2'" << endl;
//        cin >> oMoveX;
//        cin >> oMoveY;
//        move.push_back(oMoveX);
//        move.push_back(oMoveY);
        return aiMove(moves);

    }else{
        int xMoveX;
        int xMoveY;
        cout << "Enter your move player X in the format '3\n2'" << endl;
        cin >> xMoveX;
        cin >> xMoveY;
        move.push_back(xMoveX);
        move.push_back(xMoveY);
    }
    
    return move;
}

void printBoard(vector<string> &moves)
{
    for(unsigned int i = 0; i < 3; i++){
        cout << moves[i][0] << '|' << moves[i][1] << '|' << moves[i][2] << endl;
        if(i < 2){
        cout << "______" << endl;
        }
    }
}
