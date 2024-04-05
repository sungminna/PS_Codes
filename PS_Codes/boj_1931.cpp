#include<iostream>
#include<vector>
#include<algorithm>
int main() {
	unsigned int n, a, b;
	unsigned int cnt = 0;
	std::cin >> n;
	
	std::vector<std::pair<unsigned int, unsigned int>> data;
	std::pair<unsigned int, unsigned int> pr;
	for (unsigned int i = 0; i < n; i++) {
		std::cin >> pr.first >> pr.second;
		if (pr.first == pr.second) {
			cnt++;
		}
		data.push_back(pr);
	}
	n -= cnt;
	std::sort(data.begin(), data.end());
	for (unsigned int i = 0; i < n; i++) {
		std::cout << data[i].first << data[i].second;
	}
	unsigned int min = 
	for (unsigned int i = 0; i < n; i++) {
		a = data[i].first;
		b = data[i].second;

		while()
	}

}