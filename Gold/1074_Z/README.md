# 1074번 Z

<aside>

## 문제

한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

<img width="342" height="340" alt="Image" src="https://github.com/user-attachments/assets/68cdd01a-9e0b-4478-a19b-db09619396b5" />

N > 1인 경우, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

다음 예는 22 × 22 크기의 배열을 방문한 순서이다.

<img width="646" height="650" alt="Image" src="https://github.com/user-attachments/assets/601caf18-653c-42c8-a066-b39f196513e9" />

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음은 N=3일 때의 예이다.

<img width="1066" height="1070" alt="Image" src="https://github.com/user-attachments/assets/177ccc54-d8dc-4bcf-b6dd-3aaa3e65bda0" />

</aside>

<aside>

## 입력

첫째 줄에 정수 N, r, c가 주어진다.

</aside>

<aside>

## 출력

r행 c열을 몇 번째로 방문했는지 출력한다.

</aside>

이 문제는 재귀함수를 활용해서 푸는 문제로 2630번 문제와 유사한 문제이다.

[2630번 색종이 만들기](https://www.notion.so/2630-261e73cfe03f80728188f4a59a464e1e?pvs=21)

문제를 풀기 위해서는 정해진 범위를 4등분하여 풀 수 있어야 한다.

<img width="742" height="740" alt="Image" src="https://github.com/user-attachments/assets/1ce76557-5ab3-4fa7-8b9d-d48b84f82039" />

위와 같이 주어진 범위를 4등분 하고, 좌측 위부터 1, 2, 3, 4사분면으로 정해서 문제를 풀면 어렵지 않게 풀 수 있다.  

```cpp
visit(0, 0, pow(2, n));
```

위 코드와 같이 정해진 범위의 첫 번째 위치 (0, 0)에서부터 탐색을 시작한다.

```cpp
if (c < x + size && c >= x && r < y + size && r >= y) {
	size /= 2;	// 2^n-1
	visit(x, y, size);	// 1사분면 탐색
	visit(x + size, y, size);		// 2사분면 탐색
	visit(x, y + size, size);		// 3사분면 탐색
	visit(x + size, y + size, size);	// 4사분면 탐색
}
```

찾고자 하는 값이 정해진 범위 내에 있다면, 해당 범위를 4등분해서 1,2,3,4분면으로 만든 후 재귀호출을 시작한다.

```cpp
else {
	ans += size * size;
}
```

찾고자 하는 값이 정해진 범위 내에 없다면, 해당 사분면의 크기를 제곱해서 마지막에 출력할 값에 더한다.

```cpp
if (x == c && y == r) {
	cout << ans << endl;
	return;
}
```

찾고자 하는 값을 찾았다면 최종 결과값을 출력하고, 함수를 종료한다.

<aside>

## 예시

<img width="646" height="650" alt="Image" src="https://github.com/user-attachments/assets/ceca3aea-bfe2-4de2-a769-2e9fc94dfe84" />

위 좌표에서 찾고자 하는 값이 (1, 2) (6)라고 할 때, 앞서 설명한대로 탐색을 시작한다.

처음 정해진 범위 내에는 당연히 찾고자 하는 값이 있기 때문에 4등분해서 탐색을 시작한다.

```cpp
visit(x, y, size);	// 1사분면 탐색
visit(x + size, y, size);		// 2사분면 탐색
visit(x, y + size, size);		// 3사분면 탐색
visit(x + size, y + size, size);	// 4사분면 탐색
```

재귀호출은 1사분면부터 순서대로 진행된다.

<img width="637" height="634" alt="Image" src="https://github.com/user-attachments/assets/d48d43a8-2133-4e80-95c6-50e2f080be72" />

1사분면에는 원하는 값이 없기 때문에 해당 사분면은 탐색을 할 이유가 없다.

따라서, 해당 사분면은 건너뛰면 된다. 이때, 건너뛴다는 의미로 `2 * 2`를 수행한다.

이렇게 하면 해당 사분면 내에 있는 모든 좌표를 한 번씩 방문했다는 의미가 될 수 있다.

```cpp
ans += size * size;
```

그리고 해당 값을 최종 출력 값에 더한다.

마찬가지로 2사분면에서 탐색을 시작한다.

<img width="627" height="628" alt="Image" src="https://github.com/user-attachments/assets/426a673f-47be-4328-9987-cbc31ccefb12" />

이때, 2사분면에는 찾는 값이 있기 때문에 다시 한번 사분면을 나눠서 재귀호출을 실행한다.

<img width="323" height="320" alt="Image" src="https://github.com/user-attachments/assets/27dc1ab7-e8a6-4b0c-91fa-2b286486d67a" />

그렇게 하면 위와 같이 1*1 크기의 사분면이 생기게 된다.

이를 앞서 했던대로 반복하면 최종적으로 찾고자 하는 좌표에 도달하게 된다.

```cpp
if (x == c && y == r) {
cout << ans << endl;
return;
}
```

해당 좌표에 도달하면 위와 같은 조건문을 활용해서 최종 결과를 출력하고, 함수를 종료한다.

</aside>

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans = 0;	// 답

void visit(int x, int y, int size) {
	if (x == c && y == r) {
	// 행, 열의 값이 일치할 떄
		cout << ans << endl;
		// 답 출력
		return;
		// 함수 종료
	}

	if (c < x + size && c >= x && r < y + size && r >= y) {
	// 찾고자하는 값이 정해진 범위 내에 있을 때
		size /= 2;	// 2^n-1
		visit(x, y, size);	// 1사분면 탐색
		visit(x + size, y, size);		// 2사분면 탐색
		visit(x, y + size, size);		// 3사분면 탐색
		visit(x + size, y + size, size);	// 4사분면 탐색
	}
	else {	// r, c가 정해진 범위 내에 없으면 
		ans += size * size;
		// 현재 사분면의 크기^2을 답에 더한다
	}
}

int main() {
	cin >> n >> r >> c;
	visit(0, 0, pow(2, n));
	// 0행, 0열, 2^n
}
```
