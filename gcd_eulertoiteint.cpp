#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
long long phi(long long n){
    double res=n;
    //prime factorisation of a number n
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)
              n=n/i;
            res=res*(1.0 - (1.0 / (double)i));//general euler toiteint formula
        }
    }
    //only happens onece when n is reduced to a prime number itself which donot have any factor rather then itself
    if(n>1) 
    res*=(1.0 - (1.0 / (float)n));

    return (long long)res;
}
//problem was to calculate all a+x such that gcd(a,b)=gcd(a+x,b)
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long g=gcd(a,b),m=b;
        m=m/g;
        cout<<phi(m)<<endl;
    }
    return 0;
}