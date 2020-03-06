#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct{
    int row;
    int column;
}parameters;

    int sudoku [9][9] = {
        5, 3, 4, 6, 7, 8, 9, 1, 2,
        6, 7, 2, 1, 9, 5, 3, 4, 8,
        1, 9, 8, 3, 4, 2, 5, 6, 7,
        8, 5, 9, 7, 6, 1, 4, 2, 3,
        4, 2, 6, 8, 5, 3, 7, 9, 1,
        7, 1, 3, 9, 2, 4, 8, 5, 6,
        9, 6, 1, 5, 3, 7, 2, 8, 4,
        2, 8, 7, 4, 1, 9, 6, 3, 5,
        3, 4, 5, 2, 8, 6, 1, 7, 9
    };
    
    void *checkRow(parameters *rowParam){
        int r = rowParam->row;
        int c = rowParam->column;
        
        for(int i = 0; i < 9; i++){
            for(int j = i+1; j < 9; j++){
                if(sudoku[r][i] = sudoku[r][j]){
                    printf("Sudoku is not valid");
                    pthread_exit(NULL);
                }
                else{
                    printf("Sudoku is valid");
                }
            }            
        }
    }
    
  
int main(void)
{
    
}