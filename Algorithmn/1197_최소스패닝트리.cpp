#include <bits/stdc++.h>
#define fast cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define x first
#define y second
using namespace std;

int V,E;
int a,b,c;
vector<pair<int,pair<int,int>>> v;
int parent[10001];

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x] = getParent(parent[x]);
}

void unionParent(int r, int s){
    r = getParent(r);
    s = getParent(s);
    parent[s] = r;
}
//여기서 틀렸었음
/*
void unionParent(int r, int s){
    if(r<s) parent[s] = r;
    else parent[r] = s;
}
*/
bool findParent(int p, int q){
    int r = getParent(p);
    int s = getParent(q);
    if(r==s) return false;
    else return true;
}


int main(void){
    int sum=0;
    cin >> V >> E;
    for(int i=1; i<V; i++){
        parent[i] = i;
    }

    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }
    
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        if(findParent(v[i].y.x,v[i].y.y)){
            unionParent(v[i].y.x,v[i].y.y);
            sum+=v[i].x;
        }
    }
    cout << sum;
    
}