#include<iostream>
#include<queue>
int visited[100001] = { 0, };
int n, k;
int main() {
	int n, k;
	std::cin >> n >> k;
	std::queue<int> q;
	q.push(n);
	int x;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x < 0 || x > 100000) continue;

		if (x == k) {
			std::cout << visited[k];
			break;
		}
		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			visited[x + 1] = visited[x] + 1;
			q.push(x + 1);
		}
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			visited[x - 1] = visited[x] + 1;
			q.push(x - 1);
		}
		if (x * 2 <= 100000 && visited[x * 2] == 0) {
			visited[x * 2] = visited[x] + 1;
			q.push(x * 2);
		}
	}
}
