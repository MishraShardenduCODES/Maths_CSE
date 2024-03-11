
#include <iostream>
#include <cmath>
#include <vector>

// Define the matrix size
const int N = 3;

// Define the matrix A
double A[N][N] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};

// Function to compute dot product of two vectors
double dotProduct(const std::vector<double>& v1, const std::vector<double>& v2) {
    double result = 0;
    for (int i = 0; i < N; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Function to normalize a vector
void normalize(std::vector<double>& v) {
    double norm = std::sqrt(dotProduct(v, v));
    for (int i = 0; i < N; ++i) {
        v[i] /= norm;
    }
}

// Function to perform power iteration method
void powerIteration(const double A[N][N], std::vector<double>& eigenvector, double& eigenvalue) {
    // Initialize eigenvector to [1, 1, ..., 1]
    for (int i = 0; i < N; ++i) {
        eigenvector[i] = 1.0;
    }

    // Iterate to find dominant eigenvector
    const int maxIterations = 100;
    const double epsilon = 1e-6;
    for (int iter = 0; iter < maxIterations; ++iter) {
        std::vector<double> prevEigenvector = eigenvector;
        for (int i = 0; i < N; ++i) {
            eigenvector[i] = 0;
            for (int j = 0; j < N; ++j) {
                eigenvector[i] += A[i][j] * prevEigenvector[j];
            }
        }
        normalize(eigenvector);
        eigenvalue = dotProduct(eigenvector, prevEigenvector);
        if (std::abs(eigenvalue - 1) < epsilon) {
            break;
        }
    }
}

int main() {
    // Initialize eigenvector and eigenvalue
    std::vector<double> eigenvector(N);
    double eigenvalue;

    // Perform power iteration method
    powerIteration(A, eigenvector, eigenvalue);

    // Print results
    std::cout << "Eigenvalue: " << eigenvalue << std::endl;
    std::cout << "Eigenvector: ";
    for (int i = 0; i < N; ++i) {
        std::cout << eigenvector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
