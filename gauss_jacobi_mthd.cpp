#include <bits/stdc++.h>
using namespace std;

double equ1(double x, double y, double z) {
    return (3 + 5*y + 2*z) / 10;
}

double equ2(double x, double y, double z) {
    return (4*x + 3*z + 3) / 10;
}

double equ3(double x, double y, double z) {
    return (-3 - x - 6*y) / 10;
}

int main(){
    double x0, y0, z0;
    double x1, y1, z1;
    int maxIterations = 100;
    double tol = 0.000000001;
    
    cout << "Enter the starting point for 3 different points: ";
    cin >> x0 >> y0 >> z0;
    int i=maxIterations;
    while(i){
        x1 = equ1(x0, y0, z0);
        y1 = equ2(x0, y0, z0);
        z1 = equ3(x0, y0, z0);
        
        if(abs(x1-x0)<tol && abs(y1-y0)<tol && abs(z1-z0)<tol){
            break;
        }
        
        x0 = x1;
        y0 = y1;
        z0 = z1;

        --i;
    }
    
    cout << "The value of x: " << fixed << setprecision(8) << x0 << endl;
    cout << "The value of y: " << fixed << setprecision(8) << y0 << endl;
    cout << "The value of z: " << fixed << setprecision(8) << z0 << endl;
    
    return 0;
}
