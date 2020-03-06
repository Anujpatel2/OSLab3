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
    
void *checkRow(void* param) {
	parameters *params = (parameters*) param;
	int row = params->row;
	int col = params->column;		
	if (col != 0 || row > 8) {
		fprintf(stderr, "Invalid row or column for row subsection! row=%d, col=%d\n", row, col);
		pthread_exit(NULL);
	}

	int valid[9] = {0};
	int i;
	for (i = 0; i < 9; i++) {
		int num = sudoku[row][i];
		if (num < 1 || num > 9 || valid[num - 1] == 1) {
			pthread_exit(NULL);
		} else {
			valid[num - 1] = 1;		
		}
	}
	validity[9 + row] = 1;
	pthread_exit(NULL);
}

void* checkColumn(void* colparam) {
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
 pthread_t threads[num_threads];
	
	int threadIndex = 0;	
	int i,j;
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {						
			if (i%3 == 0 && j%3 == 0) {
				parameters *data = (parameters *) malloc(sizeof(parameters));	
				data->row = i;		
				data->column = j;
				pthread_create(&threads[threadIndex++], NULL, is3x3Valid, data); // 3x3 subsection threads
			}
			if (i == 0) {
				parameters *columnData = (parameters *) malloc(sizeof(parameters));	
				columnData->row = i;		
				columnData->column = j;
				pthread_create(&threads[threadIndex++], NULL, isColumnValid, columnData);	// column threads
			}
			if (j == 0) {
				parameters *rowData = (parameters *) malloc(sizeof(parameters));	
				rowData->row = i;		
				rowData->column = j;
				pthread_create(&threads[threadIndex++], NULL, isRowValid, rowData); // row threads
			}
		}
	}

	for (i = 0; i < num_threads; i++) {
		pthread_join(threads[i], NULL);			
	}

	for (i = 0; i < num_threads; i++) {
		if (validity[i] == 0) {
			printf("Sudoku solution is invalid!\n");
			return EXIT_SUCCESS;
		}
	}
	printf("Sudoku solution is valid!\n");
	return EXIT_SUCCESS;   
}
