#include<iostream>
#include<vector>

int ispri(int n);

int main() {
	int n = 1;
	std::vector<int> vec;
	while (n != 0) {
		std::cin >> n;
		vec.push_back(n);
	}
	vec.pop_back();
	int min = 123457;
	int max = 0;
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		if (*itr > max) {
			max = *itr;
		}
	}
	max = max * 2;
	std::vector<int> net;
	for (int i = 0; i < max + 1; i++) {
		net.push_back(1);
	}
	net[0] = 0;
	net[1] = 0;
	int mul;
	for (int i = 2; i < max + 1; i++) {
		for (int j = 2; i * j < max+1; j++) {
			mul = i * j;
			net[mul] = 0;
		}
	}
	int cnt;
	for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cnt = 0;
		for (int i = *itr + 1; i < *itr * 2 + 1; i++) {
			if (net[i] == 1) {
				cnt++;
			}
		}
		std::cout << cnt << '\n';
	}
}
