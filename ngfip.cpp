#include <iostream>
#include <vector>

double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

double forwardInterpolation(const std::vector<double>& x, const std::vector<double>& y, double xi) {
    int n = x.size();
    double result = y[0];
    double h = x[1] - x[0];
    double u = (xi - x[0]) / h;
    double term = u;
    
    for (int i = 1; i < n; ++i) {
        result += (term * y[i]) / factorial(i);
        term *= (u - i);
    }
    
    return result;
}

int main() {
    std::vector<double> x = {0, 1, 2, 3};
    std::vector<double> y = {1, 2, 4, 8};
    double xi = 1.5;
    
    double interpolatedValue = forwardInterpolation(x, y, xi);
    
    std::cout << "Interpolated value at xi = " << xi << ": " << interpolatedValue << std::endl;
    
    return 0;
}
