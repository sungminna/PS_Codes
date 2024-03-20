#include<iostream>
#include<algorithm>

int main() {
	int n;
	int house[1001][3];
	std::cin >> n;
	int r, g, b;
	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		std::cin >> r >> g >> b;
		house[i][0] = std::min(house[i - 1][1], house[i - 1][2]) + r;
		house[i][1] = std::min(house[i - 1][0], house[i - 1][2]) + g;
		house[i][2] = std::min(house[i - 1][0], house[i - 1][1]) + b;
	}

	int res = std::min(house[n][2], std::min(house[n][1], house[n][0]));
	std::cout << res;
}