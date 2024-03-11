#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
// DNF

void dfs(std::vector<std::vector<int>> vec, int v);

int main() {

	int n, m, v;
	std::cin >> n >> m >> v;
	int a, b;
	std::vector<std::vector<int>> vec;
	for (int i = 0; i < n+1; i++) {
		std::vector<int> ls;
		vec.push_back(ls);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(vec, v);
}

void dfs(std::vector<std::vector<int>> vec, int v) {
	std::vector<int> ls;
	std::vector<int> tmp;
	std::stack<int> stk;
	stk.push(v);
	int n;
	while (stk.size() != 0) {
		n = stk.top();
		stk.pop();
		if (std::find(ls.begin(), ls.end(), n) == ls.end()) {
			ls.push_back(n);
			tmp = vec[n];
			for (std::vector<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
				stk.push(*itr);
			}
		}
	}
	for (std::vector<int>::iterator itr = ls.begin(); itr != ls.end(); ++itr) {
		std::cout << *itr;
	}
}
