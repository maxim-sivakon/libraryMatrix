#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int fn_result = WORK_MATRIX_OK;
  if (!A || !result) {
    fn_result = WORK_MATRIX_INCORRECT;
  } else if (A->rows != A->columns) {
    fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t minor_matrix;
    double determinant = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        find_minor(*A, i, j, &minor_matrix);
        s21_determinant(&minor_matrix, &determinant);
        result->matrix[i][j] = determinant;
        s21_remove_matrix(&minor_matrix);
      }
    }
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] *= pow(-1, i + j);
      }
    }
  }
  return fn_result;
}
