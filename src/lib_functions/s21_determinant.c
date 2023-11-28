#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int fn_result;
  if (!A || !result) {
    fn_result = WORK_MATRIX_INCORRECT;
  } else if (A->columns != A->rows) {
    fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
  } else {
    fn_result = WORK_MATRIX_OK;
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = determinant_2(*A);
    } else {
      double determinant = 0;
      int sign = 1;
      matrix_t minored_matrix;
      double value_mul = 0;
      double buf = 0;
      for (int i = 0; i < A->rows; i++) {
        buf = 0;
        value_mul = A->matrix[0][i];
        find_minor(*A, 0, i, &minored_matrix);
        s21_determinant(&minored_matrix, &buf);
        buf *= value_mul * sign;
        determinant += buf;
        sign = -sign;

        s21_remove_matrix(&minored_matrix);
      }
      *result = determinant;
    }
  }
  return fn_result;
}