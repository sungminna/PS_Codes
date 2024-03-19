#include<iostream>
#include<vector>

int main() {
	int n;
	std::vector<int> rgb;
	std::vector<int> nrgb;

	std::vector<std::vector<int>> house;
	std::cin >> n;
	int r, g, b;
	for (int i = 0; i < n; i++) {
		std::cin >> r >> g >> b;
		std::vector<int> rgb;
		rgb.push_back(r);
		rgb.push_back(g);
		rgb.push_back(b);
		house.push_back(rgb);
	}
	int x, y, z;
	int arr[6];
	int res = 0;
	int last = 9;
	for (int h = 0; h < n; h++) {
		rgb = house[h];
		if (h == n-1) {
			std::vector<int> nrgb;
			nrgb.push_back(0);
			nrgb.push_back(0);
			nrgb.push_back(0);
		}
		else {
			nrgb = house[h+1];
		}
		int min = 1000 * 1001;
		arr[0] = rgb[0] + nrgb[1];
		arr[1] = rgb[0] + nrgb[2];
		arr[2] = rgb[1] + nrgb[0];
		arr[3] = rgb[1] + nrgb[2];
		arr[4] = rgb[2] + nrgb[0];
		arr[5] = rgb[2] + nrgb[1];
		if (last == 0) {
			arr[0] = 1000 * 2001;
			arr[0] = 1000 * 2001;
		}
		if (last == 1) {
			arr[1] = 1000 * 2001;
			arr[1] = 1000 * 2001;
		}
		if (last == 2) {
			arr[2] = 1000 * 2001;
			arr[2] = 1000 * 2001;
		}
		for (int i = 0; i < 6; i++) {
			if (arr[i] < min) {
				min = arr[i];
				last = i / 2;
			}
		}
		res += rgb[last];
	}

	std::cout << res;
}