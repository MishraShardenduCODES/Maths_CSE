#include <bits/stdc++.h>
using namespace std;
double a=0,b=1;
double equ(double x){
    return 1*pow(x,3)-5*x+1;
}

int main(){
    int n;
    cout<<"Tell how many iterations you want : ";
    cin>>n;
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