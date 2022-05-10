#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;
typedef vector<int> Row;

Matrix tildeMatrix(Matrix& M, int n, int except_row, int except_col) {
  Matrix result(1, Row(n + 1, 0));
  for (int row = 1; row <= n; row++) {
    Row tilde_row(1, 0);
    for (int col = 1; col <= n; col++) {
      if (row != except_row && col != except_col) {
        tilde_row.push_back(M[row][col]);
      }
    }
    if (row != except_row) result.push_back(tilde_row);
  }
  return result;
}

int determinant(Matrix M, int n) {
  int result = 0;

  if (n == 2) {
    // threshold
    return M[1][1] * M[2][2] - M[1][2] * M[2][1];
  } else {
    for (int j = 1; j <= n; j++) {
      result += (int)pow(-1, 1 + j) * M[1][j] *
                determinant(tildeMatrix(M, n, 1, j), n - 1);
    }
  }
  return result;
}

int main() {
  cout << "Enter the size of Matrix(n x n)" << endl;
  int n;
  cin >> n;

  Matrix M = Matrix(n + 1, Row(n + 1, 0));

  cout << "Enter the Matrix elements" << endl;
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      cin >> M[row][col];
    }
  }
  cout << "Determinant is " << determinant(M, n) << endl;

  return 0;
}