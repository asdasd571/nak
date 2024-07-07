#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define x first
#define y second

using namespace std;

int r,s,x,p,q,N,M;
int parent[1001];
vector<pair<int,pair<int,int>>> v;

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x] = getParent(parent[x]);
}

//여기서 void 안 해서 틀림

void unionParent(int p, int q){
    if(p<q) parent[q] = p;
    else parent[p] = q;
}

bool findParent(int r, int s){
    r = getParent(r);
    s = getParent(s);
    if(r==s) return false;
    else return true;
}

//r의 부모와 s의 부모가 같으면 사이클이 생김

int main(void){
    int a,b,c;
    int sum=0; // sum 초기화를 안 해서 틀림
    int X,Y;
    cin >> N;
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    for(int i=1; i<N+1; i++){
        parent[i]=i;
    }

    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        X = getParent(v[i].y.x);
        Y = getParent(v[i].y.y);
        if(findParent(X,Y)){
            sum+=v[i].x;
            unionParent(X,Y);
        }
    }

    cout << sum;
    return 0;
}