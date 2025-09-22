# 1051번 숫자 정사각형

이 문제에서는 숫자로 이루어진 N*M 크기의 직사각형이 주어진다.

주어진 직사각형에서 4개의 꼭짓점이 모두 같은 숫자로 이루어져 있는 가장 넓이가 큰 정사각형을 구하면 된다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;    // N : 세로, M : 가로
	cin >> N >> M;
	vector <string> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int min_s = 1;   // 정사각형 한 변의 최소값
	for (int s = min(N, M); s > 0; s--) {
		min_s = s;
		for (int i = 0; i <= N - s; i++) {
			for (int j = 0; j <= M - s; j++) {
				if (num[i][j] == num[i][j + s - 1] &&
					num[i][j] == num[i + s - 1][j] &&
					num[i][j] == num[i + s - 1][j + s - 1]) {
					cout << min_s * min_s << endl;
					return 0;
				}
			}
		}
	}
	cout << min_s * min_s << endl;

	return 0;
}
```

```cpp
vector <string> num(N);
```

해당 문제는 숫자를 12345처럼 붙여서 입력 받기 때문에 vector를 사용하여 string형의 배열을 생성하였다.

```cpp
for (int s = min(N, M); s > 0; s--) {
		min_s = s;
		for (int i = 0; i <= N - s; i++) {
			for (int j = 0; j <= M - s; j++) {
				if (num[i][j] == num[i][j + s - 1] &&
					num[i][j] == num[i + s - 1][j] &&
					num[i][j] == num[i + s - 1][j + s - 1]) {
					cout << min_s * min_s << endl;
					return 0;
				}
			}
		}
	}
```

주어진 직사각형의 가로와 세로 중에서 더 작은 수가 정사각형이 가질 수 있는 한 변의 최대값이다.

최대값에서 1씩 감소시키면서 네 꼭짓점이 같은 경우를 찾는다. 이때 s의 값이 정사각형의 한 변이다.

정사각형의 좌상단의 꼭짓점에 위치한 수를 기본값으로 잡고, 네 꼭짓점을 비교하면 된다.

좌상단의 꼭짓점이 (i, j)라면 우상단의 꼭짓점은 좌상단의 꼭짓점에서 s-1의 값만큼 떨어져있기 때문에

(i,  j+s-1)에 위치해 있다. 이런 식으로 각 꼭짓점을 비교하면 된다.

<aside>

   (i, j) ======= (i, j+s-1)

     |                                |

(i+s-1, j) ==== (i+s-1, j+s-1)

</aside>

```cpp
for (int i = 0; i <= N - s; i++)
	for (int j = 0; j <= M - s; j++)
```

**N - s와 M - s**를 해주지 않으면 num 배열이 N-1이나 M-1의 범위를 벗어나 **오버플로우**가 발생할 수 있다.
