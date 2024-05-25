#include <bits/stdc++.h>
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define X first
#define Y second

using namespace std;

vector<pair<int,int>> v[10002];
int dist[10002];
int D,N;
int from,to,dis;

int main(void){
    cin >> N >> D;
    for(int i=0; i<N; i++){
        cin >> from >> to >> dis;
        v[from].push_back({to,dis});
    }

    for(int i=0; i<10002; i++) dist[i] = i;

    int now = 0;
    while (true){
        if(now==D){
            cout << dist[now];
            break;

        }
        
        for(int i=0; i<v[now].size(); i++){
            int disSum = dist[now] + v[now][i].Y;
            if(disSum > D) continue;

            if(disSum < dist[v[now][i].first]){
                dist[v[now][i].X] =  disSum;

                for(int j = v[now][i].X+1; j<=D; j++){
                    if(disSum >= dist[j]) break;
                    else dist[j] = ++disSum;
                }
            }
        }
        now++;

    }

}

