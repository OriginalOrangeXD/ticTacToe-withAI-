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
int updatePosition(vector<int> &move, int &count, vector<string> &position);
int checkWin(vector<string> &position);
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
    int isWin;
    while(game)
    {
        printBoard(positions);
        vector<int> nextMove = getMoves(count, positions);
//        cout << nextMove[0] << endl << nextMove[1] << endl;
        if(nextMove[0] == -1){
            game = false;
        }
        updatePosition(nextMove, count, positions);
        isWin = checkWin(positions);
        if(isWin != 0){
            if(isWin == 1){
                cout << "X wins" << endl;
                game = false;
            }else if(isWin == -1){
                cout << "O wins" << endl;
                game = false;
            }
        }
        count++;
    }
    return 0;
}

vector<int> aiMove(vector<string> positions){
    int bestScore = -1000;
    vector<int> bestMove;
    bestMove.push_back(0);
    bestMove.push_back(0);
    int score;
    for(int i = 0; i < 3; i++){
        for(int x = 0; x < 3; x++){
            if(positions[i][x] == ' '){
                positions[i][x] = 'X';
                score = minimax(positions, 0, false);
                positions[i][x] = ' ';
//                cout << score << endl;
//                cout << bestScore << endl;
                if(score > bestScore){
                    cout << "score is bigger than best score " << endl;
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
    int isWin = checkWin(position);
    if(isWin != 4){
//        cout << "terminal" << endl;
        return isWin;
    }else if(isMax){
        int bestScore = -100;
        for(unsigned int i = 0; i < 3; i++){
            for(unsigned int x = 0; x < 3; x++){
                if(position[i][x] == ' '){
                    position[i][x] = 'X';
                    int score = minimax(position, depth+1, false);
                    position[i][x] = ' ';
                    bestScore = max(score, bestScore);
//                    cout << "Checking max" << endl;
                    }
                    }
                }
            return bestScore;
        }else{
            int bestScore = 100;
            for(unsigned int i = 0; i < 3; i++){
                for(unsigned int x = 0; x < 3; x++){
                    if(position[i][x] == ' '){
                        position[i][x] = 'O';
                        int score = minimax(position, depth+1, true);
                        position[i][x] = ' ';
                        bestScore = min(score, bestScore);
//                        cout << "Checking min" << endl;
                        }
                    }
                }
            return bestScore;
        }
}

int checkWin(vector<string> &position){
    char win = ' ';
    int count = 0;
    for(unsigned int i = 0; i < 3; i++){
    if((position[i][0] == position[i][1]) and (position[i][1] == position[i][2]) and (position[i][0] != ' ')){
        win = position[i][0];
    }else if((position[0][i] == position[1][i]) and (position[1][i] == position[2][i]) and (position[0][i] != ' ')){
        win = position[0][i];
    }else if((position[0][0] == position[1][1]) and (position[1][1] == position[2][2]) and (position[0][0] != ' ')){
        win = position[0][0];
    }else if((position[2][0] == position[1][1]) and (position[1][1] == position[0][2]) and (position[2][0] != ' ')){
        win = position[2][0];
    }
        }
    for (unsigned int x = 0; x < 3;x++){
        for (unsigned int y = 0; y < 3;y++){
            if(position[x][y] != ' '){
                count++;
            }
        }
    }
    if(win == 'X'){
        return 1;
    }else if(win == 'O'){
        return -1;
    }else if(count == 9){
        return 0;
    }else{
        return 4;
    }
}

int updatePosition(vector<int> &move, int &count, vector<string> &position){
    if(position[move[0]][move[1]] == ' '){
    if(count % 2 == 0){
        position[move[0]][move[1]] = 'O';
        return 1;
    }else{
        position[move[0]][move[1]] = 'X';
        return 1;
    }
    }else{
        count--;
        return 0;
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
        int xMoveX;
        int xMoveY;
        cout << "Enter your move player O in the format '3\n2'" << endl;
        cin >> xMoveX;
        cin >> xMoveY;
        move.push_back(xMoveX);
        move.push_back(xMoveY);
    }else{
        return aiMove(moves);
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
