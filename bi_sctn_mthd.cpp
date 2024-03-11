#include<bits/stdc++.h>
using namespace std;
double a=-100,b=100;

double equ(double x){
    return 1*pow(x,3 )-3*x-1;
}

int main(){
    for(int i=-10;i<=10;i++){
        double temp1 = equ(i);
        if(temp1<0){
            a=min(a,(double)i);
        }else if(temp1>0){
            b=max(b,(double)i);
        }else if(temp1==0){
            cout<<"The root of the equation is : "<<i;
            return 0;
        }
    }
    while((int)(a*10000)!=(int)(b*10000)){
        double x=(a+b)/2,cmp=equ(x);
        if(cmp<0){
            a=x;
        }else if(cmp>0){
            b=x;
        }else{
            cout<<"The root of the equation is : "<<x;
            return 0;
        }
    }
    cout<<"The root of the equation is : "<<a;
}
