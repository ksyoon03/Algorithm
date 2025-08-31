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
		// y = 다음 탐색 대상인 x와 연결된 컴퓨터
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