#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;

int N,M;
int parent[1002];
vector<int> v[1001],result;
int in[1001];
queue<int> q;
int x,a,one,num;

void topologySort(){
    for(int i=1; i<=N; i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
       int x = q.front(); q.pop();
       result.push_back(x);
       for(int i=0; i<v[x].size(); i++){
            int nx = v[x][i];
            in[nx]--;
            if(in[nx]==0) q.push(nx);
       }
    }
}

int main(void){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a;
        cin >> one;
        for(int j=1; j<a; j++){
            cin >> num;
            v[one].push_back(num);
            in[num]++;
            one = num;
        }
    }
    topologySort();
    if(result.size()==N){
        for(auto c : result){
            cout << c << endl;
        }
    }else{
        cout << 0;
    }
}