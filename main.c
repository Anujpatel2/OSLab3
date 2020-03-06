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

void* isColumnValid(void* colparam) {
		parameters* params = (parameters*)colparam;
		int r = params->row;
		int c = params->column;

		if (r != 0 || c > 8) {
			fprintf(stderr, "The Column is Invalid! row=%d, col=%d\n", r, c);
			pthread_exit(NULL);
		}

		int valid[9] = { 0 };
		for (int i = 0; i < 9; i++) {
			int n = sudoku[i][c];
			if (n < 1 || n > 9 || valid[n - 1] == 1) {
				pthread_exit(NULL);
			}
			else {
				validityArray[n - 1] = 1;
			}
		}
		valid[18 + c] = 1;
		pthread_exit(NULL);
	}
    
  
int main(void)
{
    
}
