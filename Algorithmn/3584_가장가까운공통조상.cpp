#include <bits/stdc++.h>
using namespace std;

int parent[10001];
bool visit[10001];
int T, N, A, B, u, v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;

		// 초기화
		for (int i = 1; i <= N; i++)
		{
			visit[i] = false;
			parent[i] = i;
		}

		// 간선정보 입력
		for (int i = 0; i < N - 1; i++)
		{
			cin >> A >> B;
			parent[B] = A;
		}

		// LCA 찾기 공통 조상 찾기 알고리즘
		cin >> u >> v;
		visit[u] = true;

		while (u != parent[u])
		{
			u = parent[u];
			visit[u] = true;
		}// 16 7에서 16의 부모를 방문 표시 계속 함
		while (true)
		{
			if (visit[v])
			{
				cout << v << '\n';
				break;
			}
			v = parent[v];
		} // 7의 부모를 따라 방문한 적이 있다면 계속 출력
		
	}
}