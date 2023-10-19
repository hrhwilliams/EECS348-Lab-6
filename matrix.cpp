#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

const int max_size = 100;

int read_input(const char *fp, int matrix1[max_size][max_size], int matrix2[max_size][max_size]);
void matrix_print(int matrix[max_size][max_size], int size);
void matrix_add(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);
void matrix_mul(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);
void matrix_sub(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size);

int main() {
    int matrix1[max_size][max_size];
    int matrix2[max_size][max_size];
    int result_matrix[max_size][max_size];
    int size = read_input("matrix_input.txt", matrix1, matrix2);

    std::cout << "Matrix A:\n";
    matrix_print(matrix1, size);

    std::cout << "Matrix B:\n";
    matrix_print(matrix2, size);

    std::cout << "Matrix Sum (A + B):\n";
    matrix_add(matrix1, matrix2, result_matrix, size);
    matrix_print(result_matrix, size);

    std::cout << "Matrix Product (A * B):\n";
    matrix_mul(matrix1, matrix2, result_matrix, size);
    matrix_print(result_matrix, size);

    std::cout << "Matrix Difference (A - B):\n";
    matrix_sub(matrix1, matrix2, result_matrix, size);
    matrix_print(result_matrix, size);

    return 0;
}

int read_input(const char *fp, int matrix1[max_size][max_size], int matrix2[max_size][max_size]) {
    std::string line;

    std::ifstream input_file;
    input_file.open("matrix_input.txt");
    input_file >> line;

    int size = std::stoi(line);
    if (size > max_size) {
        return 0;
    }

    // read first matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input_file >> line;
            matrix1[i][j] = std::stoi(line);
        }
    }

    // read second matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            input_file >> line;
            matrix2[i][j] = std::stoi(line);
        }
    }

    return size;
}

void matrix_print(int matrix[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void matrix_add(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_mul(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int dot_product = 0;

            for (int k = 0; k < size; k++) {
                dot_product += matrix1[i][k] * matrix2[k][j];
            }

            result[i][j] = dot_product;
        }
    }
}

void matrix_sub(int matrix1[max_size][max_size], int matrix2[max_size][max_size], int result[max_size][max_size], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
