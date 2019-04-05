#include <iomanip>
#include <iostream>
#include <vector>

#include "matrix.hpp"
#include "random_utils.hpp"

template <class T> float scalar_prod(const std::vector<float> &u, const T &v) {
  float result = 0;
  auto it_u = u.begin();
  auto it_v = v.begin();
  while (it_u != u.end() && it_v != v.end()) {
    result += (*it_u) * static_cast<float>(*it_v);
    ++it_u;
    ++it_v;
  }
  return result;
}

std::vector<float> random_vector(int dim, float a, float b) {
  auto result = std::vector<float>(dim);
  for (auto &&x : result) {
    x = random_float_in(a, b);
  }
  return result;
}

std::vector<bool> random_vector_bool(int dim) {
  auto result = std::vector<bool>(dim);
  for (auto &&x : result) {
    x = random_choice();
  }
  return result;
}

Matrix::Matrix()
    : rows(std::vector<float>(0)), mat(std::vector<std::vector<float> >(0)),
      num_rows(0), num_cols(0) {}

Matrix::Matrix(int row, int col) : num_rows(row), num_cols(col) {
  rows = std::vector<float>(col, 0);
  mat = std::vector<std::vector<float> >(row, rows);
  random(1, 10);
}

Matrix::Matrix(std::vector<std::vector<float> > m)
    : mat(m), num_rows(m.at(0).size()), num_cols(m.size()) {}

void Matrix::point_divide(const std::vector<float> & v){
  for(int i = 0; i < num_rows; i++){
    for(int j = 0; j < num_cols; j++){
      mat[i][j] /= v[i];
    }
  }
}

void Matrix::random(int a, int b) {
  for (auto &&row : mat) {
    for (auto &&elem : row) {
      elem = random_float_in(a, b);
    }
  }
}

void Matrix::normalize() {
  float max = 0;
  for (auto &&r : mat) {
    for (auto &&x : r) {
      max = std::max(max, x);
    }
  }
  for (auto &&r : mat) {
    for (auto &&x : r) {
      x = x / max;
    }
  }
}

Matrix Matrix::transpose() const {
  auto result = Matrix(num_rows, num_cols);
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      result[i][j] = mat[j][i];
    }
  }
  return result;
}

Matrix Matrix::operator+(Matrix &M) {
  auto result = Matrix(num_rows, num_cols);
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      result[i][j] = (*this)[i][j] + M[i][j];
    }
  }
  return result;
}

Matrix Matrix::operator-(Matrix &M) {
  auto result = Matrix(num_rows, num_cols);
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_cols; j++) {
      result[i][j] = (*this)[i][j] - M[i][j];
    }
  }
  return result;
}

std::vector<float> Matrix::operator*(const std::vector<float> &u) const {
  auto result = std::vector<float>(this->num_cols);
  auto it_matrix = this->mat.begin();
  for (auto &&elem : result) {
    elem = scalar_prod(*it_matrix, u);
    ++it_matrix;
  }
  return result;
}

std::vector<float> Matrix::operator*(const std::vector<bool> &u) const {
  auto result = std::vector<float>(this->num_rows);
  auto it_matrix = this->mat.begin();
  for (auto &&elem : result) {
    elem = scalar_prod(*it_matrix, u);
    ++it_matrix;
  }
  return result;
}

Matrix MatrixIn(int n) {
  auto result = Matrix(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        result[i][j] = 1;
      } else
        result[i][j] = 0;
    }
  }
  return result;
}

std::ostream &operator<<(std::ostream &os, const Matrix &M) {
  for (auto &&r : M.mat) {
    os << "( ";
    for (auto &&elem : r) {
      os << elem << " ";
    }
    os << ")" << std::endl;
  }
  return os;
}

bool compare(const std::vector<float> &u, const std::vector<float> &v) {
  auto it_u = u.begin();
  auto it_v = v.begin();
  bool result = true;
  while (result == true && it_u != u.end() && it_v != v.end()) {
    result = *it_u >= *it_v;
    ++it_u;
    ++it_v;
  }
  return result;
}

bool compare_strict(const std::vector<float> &u, const std::vector<float> &v) {
  auto it_u = u.begin();
  auto it_v = v.begin();
  bool result = true;
  while (result == true && it_u != u.end() && it_v != v.end()) {
    result = *it_u > *it_v;
    ++it_u;
    ++it_v;
  }
  return result;
}

template float scalar_prod(const std::vector<float> &u,
                           const std::vector<int> &v);
template float scalar_prod(const std::vector<float> &u,
                           const std::vector<bool> &v);
