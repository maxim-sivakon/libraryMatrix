#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int fn_result;

  if (!A || !B || !result) {
    fn_result = WORK_MATRIX_INCORRECT;
  } else if (A->columns != B->rows) {
    fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
  } else {
    fn_result = WORK_MATRIX_OK;
    s21_create_matrix(A->rows, B->columns, result);
    int buff = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        buff = 0;
        for (int k = 0; k < A->columns; k++) {
          buff += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = buff;
      }
    }
  }

  return fn_result;
}
