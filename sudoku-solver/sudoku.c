#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sudoku.h"

/* Index order: [col][row], think x, y from upper-left corner. */

sudoku_t * sudoku_alloc()
{
	return malloc(sizeof(sudoku_t));
}

int sudoku_verify_set(int vals[9])
{
	char digits[11];

	int i;
	strcpy(digits, "xxxxxxxxxx");
	for (i = 0; i < 9; ++i) {
		if (vals[i] != 0) {
			if (digits[vals[i]] != 'x') {
				return 0;
			}
			digits[vals[i]] = ' ';
		}
	}
	return 1;
}

int sudoku_verify(sudoku_t * this) {

	int row, col, sq, sq_start_col, sq_start_row;

	for (row = 0; row < 9; ++row) {
		int vals[9];
		for (col = 0; col < 9; ++col) {
			vals[col] = (*this)[9*row+col];
		}
		if (sudoku_verify_set(vals) == 0)
			return 0;
	}	

	for (col = 0; col < 9; ++col) {
		int vals[9];
		for (row = 0; row < 9; ++row) {
			vals[row] = (*this)[9*row+col];
		}
		if (sudoku_verify_set(vals) == 0)
			return 0;
	}	

	for (sq = 0; sq < 9; ++sq) {
		sq_start_col = 3 * (sq % 3);
		sq_start_row = 3 * (sq / 3);

		int vals[9];
		for (col = sq_start_col; col < sq_start_col + 3; ++col) {
			for (row = sq_start_row; row < sq_start_row + 3; ++row) {
				vals[3*(col-sq_start_col)+(row-sq_start_row)] = (*this)[9*row+col];
			}
		}
		if (sudoku_verify_set(vals) == 0)
			return 0;
	}

	return 1;
}

void sudoku_setplace(sudoku_t * this, int place, int value)
{
	(*this)[place] = value;
}

int sudoku_get(sudoku_t * this, int place)
{
	return (*this)[place];
}

void sudoku_set(sudoku_t * this, const char values[])
{
	int digits[255];

	digits[' '] = 0;
	digits['0'] = 0;
	digits['1'] = 1;
	digits['2'] = 2;
	digits['3'] = 3;
	digits['4'] = 4;
	digits['5'] = 5;
	digits['6'] = 6;
	digits['7'] = 7;
	digits['8'] = 8;
	digits['9'] = 9;

	int i;
	for (i = 0; i < 81; ++i) {
		(*this)[i] = digits[(int) values[i]];
	}
}

int sudoku_cmp(sudoku_t * this, const char values[])
{
	int digits[255];

	digits[' '] = 0;
	digits['0'] = 0;
	digits['1'] = 1;
	digits['2'] = 2;
	digits['3'] = 3;
	digits['4'] = 4;
	digits['5'] = 5;
	digits['6'] = 6;
	digits['7'] = 7;
	digits['8'] = 8;
	digits['9'] = 9;

	int i, d;
	for (i = 0; i < 81; ++i) {
		d = digits[(int) values[i]] - (*this)[i];
		if (d != 0)
			return d;
	}

	return 0;
}

int sudoku_solve(sudoku_t * this, int start_place)
{

	int r;

	if (start_place == 81)
		return 1;

	if ((*this)[start_place] != 0) {
		r = sudoku_solve(this, start_place+1);
		return r;
	}

	int proposed_value;
	for (proposed_value = 1; proposed_value <= 9; ++proposed_value) {
		int r;
		sudoku_setplace(this, start_place, proposed_value);
		if (sudoku_verify(this)) {
			r = sudoku_solve(this, start_place+1);
			if (r == 1)
				return 1;
		}
	}
	sudoku_setplace(this, start_place, 0);
	return 0;
}

void sudoku_print(sudoku_t * this) {
	int x,y;
	for (y=0; y<9; y++) {
		for (x=0; x<9; x++) {
			printf("%d", (*this)[9*y+x]);
			if (x%3 == 2)
				printf(" ");
		}
		printf("\n");
		if (y%3 == 2)
			printf("\n");
	}
}

void sudoku_free(sudoku_t * this)
{
	free(this);
}
