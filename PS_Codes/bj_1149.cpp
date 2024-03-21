#include<iostream>
#include<vector>

int choose(int n, int level, std::vector<std::vector<int>> house, int sum, int last, std::vector<int> levmin);
int main() {
	int n;
	std::vector<int> levmin;
	std::vector<std::vector<int>> house;
	std::cin >> n;
	int r, g, b;
	for (int i = 0; i < n; i++) {
		std::cin >> r >> g >> b;
		std::vector<int> rgb;
		rgb.push_back(r);
		rgb.push_back(g);
		rgb.push_back(b);
		house.push_back(rgb);
		levmin.push_back(1000 * 2000);
	}

	int res = choose(n, 0, house, 0, 9, levmin);
	std::cout << res;
}

int choose(int n, int level, std::vector<std::vector<int>> house, int sum, int last, std::vector<int> levmin) {
	std::vector<int> rgb;
	rgb = house[level];
	int tsum = 0;
	int min = 1000 * 2000;
	for (int i = 0; i < 3; i++) {
		if (i == last) {
			continue;
		}
		else {
			if (level < n - 1) {
				tsum = choose(n, level + 1, house, sum, i, levmin) + rgb[i];
				if (tsum < min) {
					min = tsum;
				}
			}
			if (level == n - 1) {
				tsum = rgb[i];
				if (tsum < min) {
					min = tsum;
				}
			}
		}
	}
	if (levmin[level] < min) {
		return levmin[level];
	}
	else {
		levmin[level] = min;
	}
	return min;
}