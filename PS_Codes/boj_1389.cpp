#include<iostream>
#include<vector>

int main() {
	int n, m;
	std::vector<std::vector<int>> arr;
	std::cin >> n >> m;
	int x, y;
	std::vector<int> fri;
	arr.push_back(fri);
	for (int i = 1; i <= n; i++) {
		arr.push_back(fri);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	int min;
	std::cout << min;
}