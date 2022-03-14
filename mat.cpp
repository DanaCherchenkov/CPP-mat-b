#include <iostream>
#include <stdlib.h>
#include "mat.hpp"
#include <string>
#include <stdexcept>
#include <limits>
#include <vector>
using namespace std;


namespace ariel{
    string mat(int col, int row, char a, char b){
        const int constRow = row;
        const int constCol = col;

        //These are the limits for a valid char in ASCII table
        const int minLim = 33; 
        const int maxLim = 126;

        string str;
        
        int trace_row = 0;
        int trace_col = 0;
        
        char last_char = 0;
        
        if(col % 2 == 0 || row % 2 == 0){
            throw invalid_argument("The coloms or the rows cannot be even!");
        }
    
        if(col <= 0 || row <= 0){
            throw invalid_argument("Cannot ba a negative value or equal to zero!");
        }

        //check if the chat in the input are valid
        if(a < minLim || a > maxLim || b < minLim || b > maxLim){
            throw invalid_argument("The input entered is invalid!");
        }
        
        vector<vector<char>> myMat (row,vector<char>(col));

        while(col > 0 && row > 0){
            //if the cols and rows even this means we are in a more inner loop and will have to use the second char - b    
            if(col % 2 == 0 && row % 2 == 0){
                last_char = b;
            }
            else {
                last_char = a;
            }

            // run on the first col and in each row we will put the exact char
            for(int i = trace_col; i < row; i++){
                myMat[i][trace_col] = last_char;
            }

            // run on the last col and in each row we will put the exact char
            for(int i = trace_col; i < row; i++){
                myMat[i][col-1] = last_char;
            }

            // run on the first row and in each col we will put the exact char
            for(int i = trace_row; i < col; i++){
                myMat[trace_row][i] = last_char;
            }

            // run on the last row and in each col we will put the exact char
            for(int i = trace_row; i < col; i++){
                myMat[row - 1][i] = last_char;
            }

            col--;
            row--;
            trace_row++;
            trace_col++;
        }  
        
        for(int i = 0; i < constRow; i++){
            for(int j = 0; j < constCol; j++){
                str += myMat[i][j];
            }
            str += "\n";
        }
        return str;
    }
        
}