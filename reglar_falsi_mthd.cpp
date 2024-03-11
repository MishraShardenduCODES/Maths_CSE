#include <bits/stdc++.h>
using namespace std;
double a=-10,b=10;
double equ(double x){
    return 1*pow(x,3)-2*x-5 ;
}

int main(){
    int n;
    cout<<"Tell how many iterations you want : ";
    cin>>n;
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
    double Xn;
    while(n--){
        Xn = ((a*equ(b)) - (b*equ(a)))/(equ(b)-equ(a));
        double fun = equ(Xn);
        if(fun<0){
            a=Xn;
        }else if(fun>0){
            b=Xn;
        }else{
            cout<<"The root is : "<<fixed<<setprecision(8)<<Xn<<"\n";
            return 0;
        }
    }
    cout<<"The root is : "<<fixed<<setprecision(8)<<Xn<<"\n";
    return 0;
}