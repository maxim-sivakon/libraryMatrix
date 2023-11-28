#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int fn_result;
  if (!A || !B || !result) {
    fn_result = WORK_MATRIX_INCORRECT;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
  } else {
    fn_result = WORK_MATRIX_OK;
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return fn_result;
}