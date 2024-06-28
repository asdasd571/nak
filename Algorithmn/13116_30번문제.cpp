#include <bits/stdc++.h>
using namespace std;
int T;
int A,B;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        cin >> A >> B;
        vector<int> a;
        vector<int> b;
        if(A>B){
            int tmp = A;
            A = B;
            B = tmp;
        }
        
        while(A>0){
            a.push_back(A);
            A/=2;
        }
        while(B>0){
            b.push_back(B);
            B/=2;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans = 1;
        for(int i = 0; i<a.size(); i++){
            if(a[i]==b[i]) ans = a[i];
        }
        cout << ans*10 << '\n';
    }
}