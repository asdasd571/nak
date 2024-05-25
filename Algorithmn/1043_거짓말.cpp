#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int parent[52];
vector<int> party[52];

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x] = getParent(parent[x]);
}

void unionParent(int r, int s){
    r = getParent(r);
    s = getParent(s);
    parent[s] = r;
}

bool findParent(int p, int q){
    p = getParent(p);
    q = getParent(q);
    if(p==q) return false;
    else return true;
}


int main(void){
    int N,M,num,number,a,b;
    vector<int> v;
    cin >> N >> M;
    for(int i=1; i<N; i++) parent[i] = i;
    cin >> num;
    
    for(int i=0; i<num; i++){
        cin >> number;
        v.push_back(number);
    }

    for(int i=0; i<M; i++){
        cin >> a;
        for(int i=0; i<a; i++){
            party[i].push_back(a);
        }
    }
    
    // 파티 사람들의 parent와  비교

    for(int i=0; i<party[i].size(); i++){
        
    }

}