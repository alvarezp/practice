typedef int sudoku_t[81];

sudoku_t * sudoku_alloc();

int sudoku_verify(sudoku_t * this);

void sudoku_setplace(sudoku_t * this, int place, int value);

int sudoku_get(sudoku_t * this, int place);

void sudoku_set(sudoku_t * this, const char values[]);

int sudoku_cmp(sudoku_t * this, const char values[]);

int sudoku_solve(sudoku_t * this, int start_place);

void sudoku_print(sudoku_t * this);

void sudoku_free(sudoku_t * this);

int sudoku_verify_set(int vals[9]);
