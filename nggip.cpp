#include <iostream>
#include <vector>

double dividedDifference(const std::vector<double>& x, const std::vector<double>& y, int n) {
    if (n == 0) {
        return y[0];
    }
    return (dividedDifference(x, y, n - 1) - dividedDifference(x, y, n - 1)) / (x[n] - x[0]);
}

double generalInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    double result = y[0];
    
    for (int i = 1; i < n; ++i) {
        double term = 1;
        for (int j = 0; j < i; ++j) {
            term *= (xi - x[j]);
        }
        result += (term * dividedDifference(x, y, i));
    }
    
    return result;
}

int main() {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {1, 2, 4, 8};
    double xi = 1.5;
    
    double interpolatedValue = generalInterpolation(x, y, xi);
    
    std::cout << "Interpolated value at xi = " << xi << ": " << interpolatedValue << std::endl;
    
    return 0;
}
