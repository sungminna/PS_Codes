#include<iostream>
#include<vector>

int main() {
	int k = 1;
	int n;
	while (1) {
		std::cin >> k;
		if (k == 0) {
			break;
		}
		std::vector<int> vec;
		vec.push_back(0);
		for (int i = 0; i < k; i++) {
			std::cin >> n;
			vec.push_back(n);
		}
		

	}

}