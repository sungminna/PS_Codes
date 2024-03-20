#include<iostream>
int cnt(int k);
int arr[100000];
int main() {
	int n;
	std::cin >> n;
	arr[1] = 3;
	arr[2] = 7;
	std::cout << cnt(n);
}
int cnt(int k) {
	int x, y;
	if (k == 1) {
		return 3;
	}
	if (k == 2) {
		return 7;
	}
	else {
		if (arr[k - 1] == 0) {
			arr[k - 1] = cnt(k - 1);
		}
		if (arr[k - 2] == 0) {
			arr[k - 2] = cnt(k - 2);
		}
		return (arr[k-1] * 2 + arr[k-2]) % 9901;
	}
}