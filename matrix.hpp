#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

// float scalar_prod(const std::vector<float> & u, const std::vector<float> &
// v);
template <class T> float scalar_prod(const std::vector<float> &u, const T &v);
std::vector<float> random_vector(int dim, float a, float b);

class Matrix {

public:
  std::vector<float> rows;
  std::vector<std::vector<float>> mat;

  // public:
  int num_rows, num_cols;

  Matrix();
  Matrix(int row, int col);
  Matrix(std::vector<std::vector<float>> m);
  Matrix(const Matrix &M) = default;
  Matrix(Matrix &&M) = default;
  Matrix &operator=(const Matrix &M) = default;
  Matrix &operator=(Matrix &&M) = default;
  ~Matrix() = default;

  float &operator()(int row, int col) { return mat.at(row).at(col); }
  std::vector<float> &operator[](int j) { return mat.at(j); }

  void point_divide(const std::vector<float> &v);

  void random(int a, int b);
  void normalize();
  Matrix transpose() const;
  Matrix operator+(Matrix &M);
  Matrix operator-(Matrix &M);
  std::vector<float> operator*(const std::vector<float> &u) const;
  std::vector<float> operator*(const std::vector<bool> &u) const;
  friend std::ostream &operator<<(std::ostream &os, const Matrix &M);
};

Matrix MatrixIn(int n);

bool compare(const std::vector<float> &u, const std::vector<float> &v);
bool compare_strict(const std::vector<float> &u, const std::vector<float> &v);

template <class T> int hamming_d(const T &rep1, const T &rep2) {
  auto it_1 = rep1.begin();
  auto it_2 = rep2.begin();
  int result = 0;

  for (; it_1 != rep1.end() && it_2 != rep2.end();) {
    if (*it_1 != *it_2) {
      result += 1;
    }
    ++it_1;
    ++it_2;
  }

  return result;
}

#endif // MATRIX_H
