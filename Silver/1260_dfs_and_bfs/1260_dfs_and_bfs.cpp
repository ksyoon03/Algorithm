#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> node[1001];
bool check[1001];

void dfs(int x) {
	check[x] = true;
	cout << x << " ";		// 탐색을 시작하는 노드를 출력한다.

	for (int i = 0; i < node[x].size(); i++) {
		int y = node[x][i];
		if (!check[y]) {
			dfs(y);
		}
	}
}

void bfs(int x) {
	queue <int> q;
	q.push(x);
	check[x] = true;

	while (!q.empty()) {
		int y = q.front();
		q.pop();
		cout << y << " ";		// 큐에서 꺼낸 노드를 출력한다.

		for (int i = 0; i < node[y].size(); i++) {
			int z = node[y][i];
			if (!check[z]) {
				check[z] = true;
				q.push(z);
			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		sort(node[i].begin(), node[i].end());
		// 정점의 숫자가 작은 수부터 탐색을 실시할 수 있도록 정렬해준다.
	}

	dfs(v);
	cout << endl;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
		// DFS 탐색을 먼저 실시했기 때문에 각 노드는 방문된 것으로 되어있다.
		// 때문에 BFS 탐색을 실시하기 전에 배열을 먼저 초기화 해주어야 한다.
	}
	bfs(v);
}
