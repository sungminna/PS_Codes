#include<iostream>
#include<math.h>
int n, r, c;
int cnt = 0;
int ext = 0;
void sol(int n, int x, int y);
int main() {
	std::cin >> n >> r >> c;
	sol(n, r, c);
	
}

void sol(int n, int r, int c) {
	cnt = 0;
	int x = 0;
	int y = 0;
	while (n > 0) {
		n -= 1;
		if (r < pow(2, n) && c < pow(2, n)) {
			cnt += (pow(2, n)) * pow(2, n) * 0;
		}
		if (r < pow(2, n) && c >= pow(2, n)) {
			cnt += (pow(2, n)) * pow(2, n) * 1;
			c -= pow(2, n);

		}
		if (r >= pow(2, n) && c < pow(2, n)) {
			cnt += (pow(2, n)) * pow(2, n) * 2;
			r -= pow(2, n);

		}
		if (r >= pow(2, n) && c >= pow(2, n)) {
			cnt += (pow(2, n)) * pow(2, n) * 3;
			r -= pow(2, n);
			c -= pow(2, n);
		}
	}
	std::cout << cnt;

}
