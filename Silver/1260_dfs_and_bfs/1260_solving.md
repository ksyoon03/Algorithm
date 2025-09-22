# 1260번 DFS와 BFS

<aside>

## 문제

그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

</aside>

<aside>

## 입력

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

</aside>

<aside>

## 출력

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.

</aside>

문제의 제목과 같이 DFS와 BFS를 활용하여 푸는 문제이다.

단, 이 문제는 앞서서 풀었던 무조건 1번 노드부터 탐색을 시작했던 바이러스 문제와 달리 BFS와 DFS 탐색을 실행할 때 정점의 번호가 작은 숫자부터 탐색을 할 수 있도록 배열을 정렬해주어야 한다.

또한, DFS 탐색을 먼저 실행하기 때문에 BFS 탐색을 실시하기 전, 각 노드에 방문했음을 체크하는 배열을 초기화 해주어야 한다.

[2606번 바이러스](https://www.notion.so/2606-260e73cfe03f80e18369ec3c9b7d53c8?pvs=21)

```cpp
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
```

또한, 반복문을 작성할 때 C++11부터 도입된 기능인 범위 기반 for문을 사용하는 것도 좋다.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
vector <int> node[1001];
bool check[1001];

void dfs(int x) {
	check[x] = true;
	cout << x << " ";

	for (int y : node[x]) {  // 범위 기반 for 문
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
		cout << y << " ";

		for (int z : node[y]) {  // 범위 기반 for문
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
	}
	dfs(v);
	cout << endl;
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}
	bfs(v);
}
```