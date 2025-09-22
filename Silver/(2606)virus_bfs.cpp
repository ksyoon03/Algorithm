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
