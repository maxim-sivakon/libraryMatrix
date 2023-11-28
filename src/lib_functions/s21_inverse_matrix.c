#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int fn_result = WORK_MATRIX_OK;
  if (!A || !result) {
    fn_result = WORK_MATRIX_INCORRECT;
  } else if (A->rows != A->columns) {
    fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
  } else {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (determinant == 0) {
      fn_result = WORK_MATRIX_INCORRECT_CALCULATION;
    } else {
      matrix_t complements, transposed_complements;
      s21_calc_complements(A, &complements);
      s21_transpose(&complements, &transposed_complements);
      s21_remove_matrix(&complements);
      s21_mult_number(&transposed_complements, 1.0 / determinant, result);
      s21_remove_matrix(&transposed_complements);
    }
  }
  return fn_result;
}