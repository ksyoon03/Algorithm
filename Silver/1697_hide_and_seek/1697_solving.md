# 1697번 숨바꼭질

<aside>

## 문제

수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

</aside>

<aside>

## 입력

첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

</aside>

<aside>

## 출력

수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

</aside>

이 문제는 BFS를 활용한 문제이다.

[BFS와 DFS](https://www.notion.so/BFS-DFS-255e73cfe03f800db327e462dc82de2a?pvs=21)

단, 앞서 풀었던 문제들과는 조금 다른 방법으로 풀어야한다.

```cpp
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
```

해당 문제의 로직은 다음과 같다.

1. 현재 위치를 저장하고, 큐에 있는 값을 제거한다.
    
    ```cpp
    int current = q.front();
    q.pop();
    ```
    

1. 현재 위치가 찾아야 하는 위치이면 반복을 종료한다.

```cpp
if (current == k) break;
```

1. 이동 횟수 기록 로직

```cpp
// 뒤로 한 칸 이동
if (back > 0 && board[back] == 0) {
	q.push(back);
	board[back] = board[current] + 1;
}

// 앞으로 한 칸 이동
if (front <= 100000 && board[front] == 0) {
	q.push(front);
	board[front] = board[current] + 1;
}

// 순간이동
if (warp <= 100000 && board[warp] == 0) {
	q.push(warp);
	board[warp] = board[current] + 1;
}
```

<aside>

예시) 

1. `q`에 5를 넣고 `board[5] = 0`으로 시작
2. 1초 후 (board[x] = 1): 큐에서 5를 꺼내고, 5에서 갈 수 있는 4, 6, 10을 큐에 넣는다.
    - `board[4] = board[5] + 1 = 1`
    - `board[6] = board[5] + 1 = 1`
    - `board[10] = board[5] + 1 = 1`
3. 2초 후 (board[x] = 2): 큐에서 4, 6, 10을 순서대로 꺼내고, 각 위치에서 갈 수 있는 곳을 탐색한다.
    - 4를 꺼내고 3, 5, 8을 탐색한다. (5는 이미 방문했으므로 넘어감)
    - `board[3] = board[4] + 1 = 2`
    - `board[8] = borad[4] + 1 = 2`
    - 6을 꺼내고 5, 7, 12를 탐색한다.
    - `board[7] = board[6] + 1 = 2`
    - `board[12] = board[6] + 1 = 2`
4. 3초 후 (board[x] = 3): 큐에 들어있는 다음 위치들을 꺼내 탐색한다.
    - 10을 꺼내고, 9, 11, 20을 탐색한다.
    - `board[9] = board[10] + 1 = 2`
    - `board[11] = board[10] + 1 = 2`
    - `board[20] = board[10] + 1 = 2`

.

.

.

`K`가 꺼내지는 순간, `board[K]`에 기록된 값이 가장 빠른 시간

</aside>

위의 예시와 같이 각 위치마다 탐색된 시간이 기록되고, **찾고자 하는 위치의 값(K)이 처음으로 큐에서 꺼내질 때**, 해당 값의 위치에 기록된 값이 **가장 빠른 시간**이 된다.

위와 같은 방식으로 BFS 탐색을 활용해서 문제를 풀면 된다.