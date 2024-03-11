#include <bits/stdc++.h>
using namespace std;
double a=-10,b=10;

double equ(double x){
    return 1*pow(x,3)+1*pow(x,2)-1;
}
double deter(double x){
    return 1/(pow((1+x),0.5));
}
int main(){
    for (int i = -10; i <= 10; i++) {
        double fx = equ(i);
        if(fx < 0){
            a = max(a,(double)i);
        }else if(fx > 0){
            b = min(b,(double)i);
        }else{
            cout<<"The root is : "<<fixed<<setprecision(8)<<i<<"\n";
            break;
        }
    }
    double Xn=(a+b)/2;
    while(1){
        double val=deter(Xn);
        if(abs(val-Xn)<0.000000001){
            break;
        }
        Xn=val;
    }
    cout<<"Roots are : "<<Xn<<"\n";
}