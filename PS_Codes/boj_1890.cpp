#include<iostream>
#include<queue>

int main() {
	int n;
	std::cin >> n;
	int arr[101][101];
	int vis[101][101] = { {0, } };
	for (int i = 0; i < n; i++) {
		std::cin >> arr[n][0] >> arr[n][1] >> arr[n][2] >> arr[n][3];
	}
	int x, y;
	int jump;
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(0, 0));
	while (1) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == n - 1 && y == n - 1) {
			std::cin >> vis[n - 1][n - 1];
		}
		jump = arr[x][y];
		if (x + jump < n && vis[x+jump][y] == 0) {
			vis[x + jump][y] = vis[x][y] + 1;
			q.push(std::make_pair(x + jump, y));
		}
		if (x - jump >= 0 && vis[x-jump][y] == 0) {
			vis[x - jump][y] = vis[x][y] + 1;
			q.push(std::make_pair(x - jump, y));
		}
		if (y + jump < n && vis[x][y+jump] == 0) {
			vis[x][y + jump] = vis[x][y] + 1;
			q.push(std::make_pair(x, y + jump));
		}
		if (y - jump >= 0 && vis[x][y-jump] == 0) {
			vis[x][y - jump] = vis[x][y] + 1;
			q.push(std::make_pair(x, y - jump));
		}

	}


}