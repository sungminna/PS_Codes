#include<iostream>

int main() {
	long long n;
	std::cin >> n;
	long long arr[101][101];
	long long vis[101][101] = { {0,  } };
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			std::cin >> arr[i][j];
		}
	}
	long long jump;
	vis[0][0] = 1;
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < n; j++) {
			jump = arr[i][j];
			if (i + jump < n && jump != 0) {
				vis[i + jump][j] += vis[i][j];
			}
			if (j + jump < n  && jump != 0) {
				vis[i][j + jump] += vis[i][j];
			}
		}
	}
	std::cout << vis[n - 1][n - 1];
}