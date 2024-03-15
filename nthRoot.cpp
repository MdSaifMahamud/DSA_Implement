#include<bits/stdc++.h>
using namespace std;
double sqrt(double n,double start,double end){
    if(abs(start-end)<.00000001){
        return (start+end)/2.0;
    }else{
        double mid=(start+end)/2;
        if(mid*mid==n){
            return mid;
        }else if((mid*mid)>n){
            sqrt(n,start,mid);
        }else{
            sqrt(n,mid,end);
        }
    }
}
double qubic_root(double n,double start,double end){
    if(abs(start-end)<.00000001){
        return (start+end)/2.0;
    }else{
        double mid=(start+end)/2;
        if(mid*mid*mid==n){
            return mid;
        }else if((mid*mid*mid)>n){
            qubic_root(n,start,mid);
        }else{
            qubic_root(n,mid,end);
        }
    }
}
int SQRT(int n,int st,int en){
    if(abs(st-en)==1){
        return st;
    }else{
        int mid=(st+en)/2;
        if((mid*mid)==n)return mid;
        else if((mid*mid)>n){
            SQRT(n,st,mid);
        }else{
            SQRT(n,mid,en);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout<<sqrt(n,0,n)<<endl;
    cout<<qubic_root(n,0,n)<<endl;
    cout<<SQRT(n,0,n)<<endl;    
}