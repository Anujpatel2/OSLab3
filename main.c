#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
    int row;
    int column;
}parameters;

    int row;  //Index for rows
    int column;  //Index for columns
    int sudoku [9][9] = {
        5, 3, 0, 0, 7, 0, 0, 0, 0,
        6, 0, 0, 1, 9, 5, 0, 0, 0,
        0, 9, 8, 0, 0, 0, 0, 6, 0,
        8, 0, 0, 0, 6, 0, 0, 0, 3,
        4, 0, 0, 8, 0, 3, 0, 0, 1,
        7, 0, 0, 0, 2, 0, 0, 0, 6,
        0, 6, 0, 0, 0, 0, 2, 8, 0,
        0, 0, 0, 4, 1, 9, 0, 0, 5,
        0, 0, 0, 0, 8, 0, 0, 7, 9
    };
    
    void checkRow(){
        
    }
    
    void checkColumn(void* param){
		parameters* params = (parameters*)param;
		int row = params->row;
		int col = params->column;

		if (row!=0 || col>8) {

		}
    }
    
    void checkSubGrid(){
        
    }

int main(void)
{

    
    //printf("%d", sudoku[0][9]);
    for(int i = 0; i<9;i++){
        row = i;
        for(int j = 0; j<9; j++){
            column = j;
            printf("%d", sudoku[row][column]);
        }
        printf("\n");
    }
    return 0;
}