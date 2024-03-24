#include<iostream>
#include<queue>
bool visited[100001] = { 0, };
void bfs(int a);
int n, k;
int main() {
	int n, k;
	std::cin >> n >> k;
	visited[n] = true;
	bfs(n);
}

void bfs(int a) {
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(a, false));
	int x, cnt;
	while (!q.empty()) {
		x = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (x == k) {
			std::cout << cnt;
			break;
		}
		if (x + 1 <= 100000) {
			if (!visited[x + 1]) {
				visited[x + 1] = true;
				q.push(std::make_pair(x + 1, cnt + 1));
			}
		}
		if (x - 1 >= 0) {
			if (!visited[x - 1]) {
				visited[x - 1] = true;
				q.push(std::make_pair(x - 1, cnt + 1));
			}
		}
		if (x * 2 <= 100000) {
			if (!visited[x * 2]) {
				visited[x * 2] = true;
				q.push(std::make_pair(x * 2, cnt + 1));
			}
		}
	}
}
