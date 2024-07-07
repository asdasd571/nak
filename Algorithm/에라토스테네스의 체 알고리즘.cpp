#include <bits/stdc++.h>
#define fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int n=1000;
vector<int> isPrime(n+1,true);
int main(void){
    for(int i=2; i<=sqrt(n); i++){
        if(isPrime[i]==true){
            int j = 2;
            while(i*j <= n){
                isPrime[i*j] = false;
                j+=1;
            }
        }
    }

    for(int i=2; i<=n; i++){

        if(isPrime[i]) cout << i << ' ';
    }
}