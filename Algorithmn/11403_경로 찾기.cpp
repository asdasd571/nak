#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int visit1[100];
void dfs(int x){
    for(int i=0;i<v[x].size();i++){
        if(!visit1[v[x][i]]){
            visit1[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }
}
int main(){
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            if(a)v[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        memset(visit1,0,sizeof(visit1));
        dfs(i);
        for(int j=0;j<n;j++)
            cout<<visit1[j]<<" ";
        cout<<"\n";
    }
}
// visit 이름의 배열 쓰면 충돌 일어나서 배열 이름 바꿔줘야 함!