#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define num_threads 27

int validity[num_threads] = { 0 };


typedef struct{
    int row;
    int column;
}parameters;

    FILE* file = fopen("Sudoku_puzzle.txt", "r");
	int num;
	int row = 0;
	int col = 0;
	int sudoku[9][9];

	while (row < 9) {
		while (col < 9) {
			fscanf(file, "%d", &num);
			sudoku[col][row] = num;
			col++;
		}
		col = 0;
		row++;
	}
    
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
				valid[n - 1] = 1;
			}
		}
		validity[18 + c] = 1;
		pthread_exit(NULL);
	}


void *chcekSubGrid(paramenters *gridParam){
		int r = gridParam->row;
        int c = gridParam->column;


		if (r > 6 || r % 3 != 0 || c > 6 || c % 3 != 0) {
			fprintf(stderr, "Invalid row or column for subgrid row=%d, col=%d\n", r, c);
			pthread_exit(NULL);
		}
		int valid[9] = {0};
		for (int i = r; i < r + 3; i++) {
			for (int j = c; j < c + 3; j++) {
				int n = sudoku[i][j];
				if (n < 1 || n > 9 || valid[n - 1] == 1) {
					pthread_exit(NULL);
				} else {
					valid[n - 1] = 1;		
				}
			}
		}
		validity[r + c/3] = 1;
		pthread_exit(NULL);
	}
    
  
int main(void)
{
    
}
