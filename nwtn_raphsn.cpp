#include <bits/stdc++.h>
using namespace std;

// Define the function whose root we want to find
double f(double x) {
    return 1 * pow(x, 3) - 3 * x - 5;
}
// Define the derivative of the function
double df(double x) {
    return 3 * pow(x, 2) - 3;
}
// Implement the Newton-Raphson method
double newtonRaphson(double initialGuess) {
    double x0 = initialGuess;
    double x1 = 0;

    while (abs(x1 - x0) > 0.0001) {
        x0 = x1;
        x1 = x0 - f(x0) / df(x0);
    }
    return x1;
}
int main() {
    double initialGuess;
    cout << "Enter initial guess: ";
    cin >> initialGuess;

    double root = newtonRaphson(initialGuess);
    cout << "Root: " << fixed << setprecision(8) << root;
    return 0;
}