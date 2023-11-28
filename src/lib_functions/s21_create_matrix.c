#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int fn_result = WORK_MATRIX_OK;
  if (result && rows > 0 && columns > 0) {
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
    result->rows = rows;
    result->columns = columns;
  } else {
    fn_result = WORK_MATRIX_INCORRECT;
  }
  return fn_result;
}