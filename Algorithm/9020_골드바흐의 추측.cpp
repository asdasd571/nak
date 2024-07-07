#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    else{
        for(int i=2; i<x; i++){
            if(x%i==0) return false;
        }
    }
    return true;
}

int main(void){
    int T,n,a,b;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n;
        a= n/2;
        b= n/2;
        while(1){
            if(isPrime(a) && isPrime(b)){
                cout << a << " " << b << endl;
                break;
            
            }
            a-=1;
            b+=1;
        }
    }
}