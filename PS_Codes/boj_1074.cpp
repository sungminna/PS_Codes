#include<iostream>
int n, r, c;
int cnt = 0;
void dfs(int size, int x, int y);
int main() {
	std::cin >> n >> c >> r;
	dfs(n, 0, 0);
	
}

void dfs(int size, int x, int y) {
	if (size == 1) {
		if (x == r && y == c) {
			std::cout << cnt;
			return;
		}
		cnt++;
		if (x+1 == r && y == c) {
			std::cout << cnt;
			return;
		}
		cnt++;
		if (x == r && y+1 == c) {
			std::cout << cnt;
			return;
		}
		cnt++;
		if (x+1 == r && y+1 == c) {
			std::cout << cnt;
			return;
		}
		cnt++;
	}
	else {
		dfs(size -1, x, y);
		dfs(size -1, x + ((size - 1) * 2), y);
		dfs(size -1, x, y + ((size - 1) * 2));
		dfs(size -1, x+ ((size - 1) * 2), y + ((size - 1) * 2));
	}
}