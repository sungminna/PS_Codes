#include<iostream>
#include<vector>
#include<algorithm>

int main() {
	unsigned int n;
	std::cin >> n;
	unsigned int cnt = 0;

	std::vector<std::pair<unsigned int, unsigned int>> data;
	std::pair<unsigned int, unsigned int> pr;
	for (unsigned int i = 0; i < n; i++) {
		std::cin >> pr.first >> pr.second;
		if (pr.first == pr.second) {
			cnt++;
		}
		else {
			data.push_back(pr);
		}
	}
	std::sort(data.begin(), data.end());

	unsigned int a;
	unsigned int hit = data[0].first;
	unsigned int min;
	n -= cnt;
	for (unsigned int i = 0; i < n; i++) {
		a = data[i].first;
		if (hit <= a) {
			min = data[i].second;
			for (unsigned int j = i; j < n; j++) {
				if (a < data[j].first) {
					break;
				}
				if (min > data[j].second) {
					min = data[j].second;
				}
			}
			std::cout << min;
			hit = min;
			cnt++;
		}

	}

	std::cout << cnt;
}