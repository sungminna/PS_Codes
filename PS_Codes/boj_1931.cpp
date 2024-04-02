#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	unsigned int n, a, b;
	std::cin >> n;
	
	std::vector<std::pair<unsigned int, unsigned int>> data;
	std::pair<unsigned int, unsigned int> pr;
	for (unsigned int i = 0; i < n; i++) {
		std::cin >> pr.first >> pr.second;
		data.push_back(pr);
	}
	std::sort(data.begin(), data.end());
	for (unsigned int i = 0; i < n; i++) {
		std::cout << data[i].first << data[i].second;
	}
}