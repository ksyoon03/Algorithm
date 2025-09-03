#include <iostream>
#include <queue>
using namespace std;

int n, k;
int board[100001];

int bfs(int n) {
	queue <int> q;
	q.push(n);
	board[n] = 0;
	// 처음 탐색을 시작하는 곳은 0으로 지정
	
	while (!q.empty()) {	// 큐가 비어있으면 반복 종료
		int current = q.front();	// 현재 위치 : 큐의 가장 앞 요소
		q.pop();

		if (current == k) break;	// 현재 위치가 k이면 반복 종료

		int back = current - 1;	// 뒤로 한 칸 이동
		int front = current + 1;	// 앞으로 한 칸 이동
		int warp = current * 2;	// 순간이동

		// 뒤로 한 칸 이동
		if (back > 0 && board[back] == 0) {
		// 해당 값이 0보다 크고, 아직 방문하지 않은 위치일 때
			q.push(back);
			// 큐에 해당 위치 추가
			board[back] = board[current] + 1;
			// back까지의 이동 시간 기록 (현재 시간 + 1)
		}

		// 앞으로 한 칸 이동
		if (front <= 100000 && board[front] == 0) {
		// 해당 값이 100000보다 크고, 아직 방문하지 않은 위치일 때
			q.push(front);
			// 큐에 해당 위치 추가
			board[front] = board[current] + 1;
			// front까지의 이동 시간 기록 (현재 시간 + 1)
		}

		// 순간이동
		if (warp <= 100000 && board[warp] == 0) {
		// 해당 값이 100000보다 크고, 아직 방문하지 않은 위치일 때
			q.push(warp);
			// 큐에 해당 위치 추가
			board[warp] = board[current] + 1;
			// warp까지의 이동 시간 기록 (현재 시간 + 1)
		}
	}

	return board[k];
	// k에 도달한 가장 빠른 시간
}

int main() {
	cin >> n >> k;
	cout << bfs(n) << endl;
}