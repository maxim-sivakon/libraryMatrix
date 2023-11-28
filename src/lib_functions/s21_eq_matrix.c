#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int fn_result = FAILURE;
  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    fn_result = SUCCESS;
    for (int i = 0; i < A->rows && fn_result; i++) {
      for (int j = 0; j < A->columns && fn_result; j++) {
        if ((long int)(A->matrix[i][j] * 10000000) !=
            (long int)(B->matrix[i][j] * 10000000)) {
          fn_result = FAILURE;
        }
      }
    }
  }
  return fn_result;
}