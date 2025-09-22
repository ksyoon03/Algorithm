# 2606번 바이러스

<aside>

## 문제

신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

<img width="239" height="157" alt="Image" src="https://github.com/user-attachments/assets/0764f7a8-e35a-4442-af54-e81a2108feed" />

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

</aside>

<aside>

## 입력

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

</aside>

<aside>

## 출력

1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

</aside>

이 문제는 DFS나 BFS를 이용해서 풀기 좋은 문제다. 따라서, 해당 문제를 풀기 전에 DFS와 BFS를 먼저 공부하는 것이 좋다.

[BFS와 DFS](https://www.notion.so/BFS-DFS-255e73cfe03f800db327e462dc82de2a?pvs=21)

### BFS 활용

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> com[101];
// 최대 101개의 정보를 저장하는 인접 리스트
bool check[101];
// 방문 체크
int cnt = 0;	// 감염된 컴퓨터 수

void bfs(int x) {		// bfs (너비 우선 탐색) 함수
	queue <int> q;		// BFS 탐색을 위한 큐
	q.push(x);		// 시작 노드 x를 큐에 넣음
	check[x] = true;		// 시작 노드 x를 방문했다고 표시

	while (!q.empty()) {	// 큐가 비어있지 않다면
		int y = q.front();	// 현재 탐색 중인 노드 y를 큐에서 꺼냄
		q.pop();	// 꺼낸 노드는 큐에서 제거
		
		for (int i = 0; i < com[y].size(); i++) {		// 현재 노드 y와 연결된 모든 노드들을 순회
			int z = com[y][i];	// 다음으로 이동할 연결 노드 z
			if (!check[z]) {	//  다음 노드 z를 아직 방문하지 않았다면
				check[z] = true;	// 다음노드 z는 방문했다고 표시
				q.push(z);		// 다음 노드 z를 큐에 추가
				cnt++;	// 감염된 컴퓨터 수 + 1
			}
		}
	}
}

int main() {
	int n, m;
	// 전체 컴퓨터 수, 네트워크에 연결된 컴퓨터 수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;		// 서로 연결된 두 컴퓨터
		cin >> a >> b;
		com[a].push_back(b);	// a번 컴퓨터에 b번 컴퓨터 연결됨
		com[b].push_back(a);	// b번 컴퓨터에 a번 컴퓨터 연결됨
		// 양방향 연결
	}
	bfs(1);	// 1번 컴퓨터부터 깊이 우선 탐색 실행
	cout << cnt << endl;
}
```

### DFS 활용 (문제에 좀 더 적합)

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector <int> com[101];
// 최대 101개의 정보를 저장하는 인접 리스트
bool check[101];
// 방문 체크
int cnt = 0;	// 감염된 컴퓨터 수

void dfs(int x) {		// dfs (깊이 우선 탐색) 함수
	check[x] = true;		// 현재 컴퓨터가 감염됐음을 표시 (true)
	for (int i = 0; i < com[x].size(); i++) {	
		// 현재 컴퓨터와 모든 컴퓨터를 순회
		int y = com[x][i];
		// y: 다음 탐색 대상인 x와 연결된 컴퓨터
		if (!check[y]) {
			// y 컴퓨터가 아직 감염되지 않았다면 (true가 아니라면)
			dfs(y);	// y번째 컴퓨터로 깊이 우선 탐색 실행
			cnt++;	// 감염된 컴퓨터 수 + 1
		}
	}
}

int main() {
	int n, m;
	// 전체 컴퓨터 수, 네트워크에 연결된 컴퓨터 수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;		// 서로 연결된 두 컴퓨터
		cin >> a >> b;
		com[a].push_back(b);	// a번 컴퓨터에 b번 컴퓨터 연결됨
		com[b].push_back(a);	// b번 컴퓨터에 a번 컴퓨터 연결됨
		// 양방향 연결
	}
	dfs(1);	// 1번 컴퓨터부터 깊이 우선 탐색 실행
	cout << cnt << endl;
}
```
