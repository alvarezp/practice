#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sudoku.h"

int main(void) {

	/* Preliminary test */

	int vals_wrong[9] = {7,1,4,1,2,3,4,7,9};
	assert(sudoku_verify_set(vals_wrong) == 0);

	int vals_right[9] = {5,6,1,3,9,8,2,4,7};
	assert(sudoku_verify_set(vals_right) == 1);

	/* Sudoku class test */

	sudoku_t *s;
	s = (sudoku_t *)sudoku_alloc();

	sudoku_setplace(s, 0, 5);
	if (sudoku_get(s, 0) != 5) {
		printf("FAILED[%4d]: sudoku_get(s, 0) == 5\n", __LINE__);
		sudoku_free(s);
		return EXIT_FAILURE;
	}

	sudoku_set(s, "714562938123479685268953471341785296857291364592346817675834129439618752986127543");
	assert(sudoku_verify(s) == 0);

	sudoku_set(s, "954712683173486925268953471341875296827691354596324817685237149419568732732149568");
	assert(sudoku_verify(s) == 1);

	sudoku_set(s, "     2   1 34    52   5 4 134   5 9 8 7   3 4 9 3   176 5 3   94    87 2   1     ");
	assert(sudoku_cmp(s, "     2   1 34    52   5 4 134   5 9 8 7   3 4 9 3   176 5 3   94    87 2   1     ") == 0);

	sudoku_solve(s, 0);
	assert(sudoku_cmp(s, "954712683173486925268953471341875296827691354596324817685237149419568732732149568") == 0);

	sudoku_set(s, "3     1  2  86 7   7   462 7   82 3    4 6    8 97   6 375   6   5 28  9  8     1");
	sudoku_solve(s, 0);
	assert(sudoku_cmp(s, "364257198251869743879314625796182534512436987483975216937541862145628379628793451") == 0);

	sudoku_free(s);

	return EXIT_SUCCESS;
}
