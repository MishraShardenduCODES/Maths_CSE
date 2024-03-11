#include<bits/stdc++.h>  // Include the entire standard library
using namespace std;     // Use the standard namespace

// Define a function named solveCubic that takes four double parameters: a, b, c, and d
double solveCubic(double a, double b, double c, double d) {
    // Calculate the value of p using the formula c - (b^2) / (3 * a^2)
    double p = c - (b * b) / (3 * a * a);
    // Calculate the value of q using the formula d + (2 * (b^3)) / (27 * a^3) - (bc) / (3 * a^2)
    double q = d + ((2 * b * b * b) / (27 * a * a * a)) - ((b * c) / (3 * a * a));
    // Calculate the discriminant using the formula (q^2) / 4 + (p^3) / 27
    double delta = (q * q) / 4 + (p * p * p) / 27;

    // If the discriminant is positive
    if (delta > 0) {
        // Calculate the first root using the formula -q / 2 + sqrt(delta)
        double u = pow((-q / 2 + sqrt(delta)),1.0/3.0);
        // Calculate the second root using the formula -q / 2 - sqrt(delta)
        double v = pow((-q / 2 - sqrt(delta)),1.0/3.0);
        // Return the sum of the two roots minus b / (3 * a)
        return u + v - b / (3 * a);
    } 
    // If the discriminant is zero
    else if (delta == 0) {
        // Calculate the root using the formula -q / 2
        double u = pow((-q/2),1/3);
        // Return the root minus b / (3 * a)
        return 2 * u - b / (3 * a);
    } 
    // If the discriminant is negative
    else {
        // Calculate the angle theta using the formula acos(-q / 2 * sqrt(-27 / (p^3)))
        double theta = acos(-q / 2 * sqrt(-27 / (p * p * p)));
        // Calculate the first root using the formula 2 * sqrt(-p / 3) * cos(theta / 3)
        double u = 2 * sqrt(-p / 3) * cos(theta / 3);
        // Return the root minus b / (3 * a)
        return u - b / (3 * a);
    }
}

int main(){
    // Define the coefficients of the cubic equation
    double a = 1, b = 0, c = -18, d = -35;
    // Calculate the root of the cubic equation using the solveCubic function
    double root = solveCubic(a, b, c, d);
    // Print the root of the cubic equation
    cout << "The root of the cubic equation is: " << root << endl;

    // Return 0 to indicate successful program execution
    return 0;
}
