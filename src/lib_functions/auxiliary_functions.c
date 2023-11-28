#include "../s21_matrix.h"

void find_minor(matrix_t src, int remove_i, int remove_j, matrix_t *result) {
  if (remove_i >= 0 && remove_j >= 0 && remove_i < src.rows &&
      remove_j < src.columns) {
    s21_create_matrix(src.rows - 1, src.columns - 1, result);

    for (int i = 0, i_res = 0; i < src.rows; i++) {
      if (i == remove_i) {
        continue;
      }
      for (int j = 0, j_res = 0; j < src.columns; j++) {
        if (j == remove_j) {
          continue;
        }
        result->matrix[i_res][j_res] = src.matrix[i][j];
        j_res++;
      }
      i_res++;
    }
  }
}

double determinant_2(matrix_t src) {
  double result = 0;
  result =
      src.matrix[0][0] * src.matrix[1][1] - src.matrix[0][1] * src.matrix[1][0];
  return result;
}