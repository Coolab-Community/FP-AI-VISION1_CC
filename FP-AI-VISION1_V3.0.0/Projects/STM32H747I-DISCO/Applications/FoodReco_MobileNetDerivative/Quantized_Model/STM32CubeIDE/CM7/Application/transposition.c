/*
 * transposition.c
 *
 *  Created on: 3 mai 2022
 *      Author: Gothmog
 */

static int transposed = 0;
int rowMax = 480;
int colMax = 640;

void Transposition_image( int input[rowMax][colMax],int output[colMax][rowMax])
{
	int row, col;
	for (row = 0; row < rowMax; row++) {
		for (col = 0; col < colMax; col++) {
			output[col][row] = input[row][col];
        }
    }
	transposed = 1-transposed;
}

