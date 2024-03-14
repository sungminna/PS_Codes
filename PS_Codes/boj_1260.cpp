#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
// DNF

std::vector<std::vector<int>> vec;
std::vector<int> visited;
std::vector<int> vist;

void dfs(int v);
void dfstack(int v);
void bfsque(int v);

int main() {
	int n, m, v;
	std::cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i < n+1; i++) {
		std::vector<int> ls;
		visited.push_back(0);
		vec.push_back(ls);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < n + 1; i++) {
		std::sort(vec[i].begin(), vec[i].end());
	}
	dfs(v);
	std::cout << '\n';
	dfstack(v);
	std::cout << '\n';
	bfsque(v);
}


void dfs(int v) {
	visited.push_back(v);
	std::vector<int> tmp;
	std::cout << v << ' ';
	tmp = vec[v];
	for (std::vector<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
		if (std::find(visited.begin(), visited.end(), *itr) == visited.end()) {
			dfs(*itr);
		}
	}
}

void dfstack(int v) {
	std::stack<int> stk;
	std::vector<int> tmp;
	std::vector<int> vis;
	stk.push(v);
	vis.push_back(v);
	std::cout << v << ' ';
	int n;
	int iso;
	while (stk.size() != 0) {
		iso = 1;
		n = stk.top();
		tmp = vec[n];
		for (std::vector<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
			if (std::find(vis.begin(), vis.end(), *itr) == vis.end()) {
				stk.push(*itr);
				vis.push_back(*itr);
				std::cout << *itr << ' ';
				iso = 0;
				break;
			}
		}
		if (iso == 1) {
			stk.pop();
		}
	}
}

void bfsque(int v) {
	std::queue<int> que;
	std::vector<int> tmp;
	std::vector<int> vis;
	que.push(v);
	vis.push_back(v);
	int n;
	while (que.size() != 0) {
		n = que.front();
		que.pop();
		std::cout << n << ' ';
		tmp = vec[n];
		for (std::vector<int>::iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
			if (std::find(vis.begin(), vis.end(), *itr) == vis.end()) {
				que.push(*itr);
				vis.push_back(*itr);
			}
		}
	}
}
