#include<iostream>
#include<vector>
#include<stack>

int res[6];
int num[14];
int k = 1;
void dfs(int start, int dep);

int main() {
	while (1) {
		std::cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			std::cin >> num[i];
		}

		dfs(0, 0);
		std::cout << '\n';
	}

}

void dfs(int start, int dep) {
	if (dep == 6) {
		for (int i = 0; i < 6; i++) {
			std::cout << res[i] << ' ';
		}
		std::cout << '\n';
	}
	else {
		for (int i = start; i < k; i++) {
			res[dep] = num[i];
			dfs(i+1, dep+1);
		}
	}
}