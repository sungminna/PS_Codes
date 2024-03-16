#include<iostream>
#include<vector>

void find(int** arr, int x, int y, int a, int b);
int main() {
	int col, row;
	col = 1;
	row = 1;
	std::vector<int> res;
	while (1) {
		std::cin >> col >> row;
		if (row == 0 && col == 0) {
			break;
		}
		int** arr = new int* [row];
		int isl;
		for (int i = 0; i < row; i++) {
			arr[i] = new int[col];
			for (int n = 0; n < col; n++) {
				std::cin >> isl;
				arr[i][n] = isl;
			}
		}
		int cnt = 0;
		for (int a = 0; a < row; a++) {
			for (int b = 0; b < col; b++) {
				if (arr[a][b] == 1) {
					find(arr, row, col, a, b);
					cnt++;
				}
			}
		}
		res.push_back(cnt);
		for (int i = 0; i < row; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
	for (std::vector<int>::iterator itr = res.begin(); itr != res.end(); ++itr) {
		std::cout << *itr << '\n';
	}
}
void find(int** arr, int x, int y, int a, int b) {
	if (arr[a][b] == 1) {
		arr[a][b] = 0;
		if (a > 0) {
			find(arr, x, y, a - 1, b);
		}
		if (b > 0) {
			find(arr, x, y, a, b - 1);
		}
		if (a < x - 1) {
			find(arr, x, y, a + 1, b);
		}
		if (b < y - 1) {
			find(arr, x, y, a, b + 1);
		}
		if (a > 0 && b > 0) {
			find(arr, x, y, a - 1, b-1);
		}
		if (a > 0 && b<y-1) {
			find(arr, x, y, a - 1, b+1);
		}
		if (b > 0 && a < x-1) {
			find(arr, x, y, a+1, b - 1);
		}
		if (a < x - 1 && b < y-1) {
			find(arr, x, y, a + 1, b+1);
		}
	}

}