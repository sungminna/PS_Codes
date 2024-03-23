#include<iostream>
#include<algorithm>

int main() {
	int n, m;
	std::cin >> n >> m;
	int x, y;
	int frd[101][101];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				frd[i][j] = 0;
			}
			else {
				frd[i][j] = 999999;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;
		frd[x][y] = 1;
		frd[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				frd[a][b] = std::min(frd[a][b], frd[a][k] + frd[k][b]);
			}
		}
	}
	int min = 999999;
	int sum;
	int min_p = -1;
	for (int a = 1; a <= n; a++) {
		sum = 0;
		for (int b = 1; b <= n; b++) {
			sum += frd[a][b];
		}
		if (sum < min) {
			min = sum;
			min_p = a;
		}
	}
	std::cout << min_p;
}