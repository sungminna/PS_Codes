#include<iostream>
#include<vector>
void dfs(int**, int, int, int, int);

int main() {
	int t, m, n, k;
	std::cin >> t;
	int a, b;
	std::vector<int> res;

	for (int c = 0; c < t; c++) {
		std::cin >> n >> m >> k;

		int** arr = new int* [m];
		for (int i = 0; i < m; i++) {
			arr[i] = new int[n];
			std::fill_n(arr[i], n, 0);
		}
		for (int i = 0; i < k; i++) {
			std::cin >> b >> a;
			arr[a][b] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					cnt++;
					dfs(arr, m, n, i, j);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			delete [] arr[i];
		}
		delete [] arr;
		res.push_back(cnt);
	}
	
	for (std::vector<int>::iterator itr = res.begin(); itr != res.end(); ++itr) {
		std::cout << *itr << '\n';
	}
	return 0;
}

void dfs(int** arr, int m, int n, int x, int y) {
	if (arr[x][y] == 1) {
		arr[x][y] = 2;
		if (x > 0) {
			dfs(arr, m, n, x - 1, y);
		}
		if (x < m-1) {
			dfs(arr, m, n, x + 1, y);
		}
		if (y > 0) {
			dfs(arr, m, n, x, y - 1);
		}
		if (y < n-1) {
			dfs(arr, m, n, x, y + 1);
		}
	}
}