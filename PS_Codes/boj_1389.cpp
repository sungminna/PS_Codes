#include<iostream>
#include<vector>

int search(int n, int t, int depth, std::vector<int> flist[101], int usr[101]);

int main() {
	int n, m;
	std::vector<int> flist[101];
	std::cin >> n >> m;
	int usr[101] = { 0, };
	int x, y;
	std::vector<int> link;
	for (int i = 0; i < 101; i++) {
		flist[i] = link;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;
		flist[x].push_back(y);
		flist[y].push_back(x);
	}
	int min = 5000 * 101;
	int res;
	for (int i = 1; i <= n; i++) {
		int usr[101] = {0, };
		int found[101] = { 0, };
		res = search(n, i, 1, flist, usr);
		if (res < min) {
			min = res;
		}
	}
	std::cout << min;

}

int search(int n, int t, int depth, std::vector<int> flist[101], int usr[101]) {
	std::vector<int> link = flist[t];
	int sum = 0;
	for (std::vector<int>::iterator itr = link.begin(); itr != link.end(); ++itr) {
		if (usr[t] == 0) {
			usr[t] == depth;
		}
	}
	for (int i = 1; i <= n; i++) {
		sum += usr[i];
		if (usr[i] == 0) {
			search(n, i, depth++, flist, usr);
		}
	}
	return sum;
}