#include<iostream>
#include<queue>

bool arr[501][501] = { {0, } };
int n, m;

int bfs(int a, int b);

int main() {
	std::cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> temp;
			arr[i][j] = temp;
		}
	}

	int cnt = 0;
	int size = 0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				size = bfs(i, j);
				cnt++;
				if (size > max) {
					max = size;
				}
			}
		}
	}
	std::cout << cnt<< '\n' << max;
}

int bfs(int x, int y) {
	std::queue<std::pair<int, int>> q;
	int size = 1;
	int a, b;
	q.push(std::make_pair(x, y));
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		arr[a][b] = 0;
		q.pop();
		if (a - 1 >= 0 && arr[a - 1][b] == 1) {
			size++;
			arr[a - 1][b] = 0;
			q.push(std::make_pair(a - 1, b));
		}
		if (a + 1 < n && arr[a + 1][b] == 1) {
			size++;
			arr[a + 1][b] = 0;
			q.push(std::make_pair(a + 1, b));
		}
		if (b - 1 >= 0 && arr[a][b - 1] == 1) {
			size++;
			arr[a][b - 1] = 0;
			q.push(std::make_pair(a, b - 1));
		}
		if (b + 1 < m && arr[a][b + 1] == 1) {
			size++;
			arr[a][b + 1] = 0;
			q.push(std::make_pair(a, b + 1));
		}
	}
	return size;
}