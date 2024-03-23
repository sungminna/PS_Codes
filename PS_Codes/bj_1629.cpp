#include<iostream>
long long a, b, c, temp;
long long power(long long p);
int main() {
	std::cin >> a >> b >> c;
	
	std::cout << power(b);
	return 0;
}

long long power(long long p) {
	
	if (p == 0) {
		return 1;
	}
	if (p == 1) {
		return a % c;
	}
	temp = power(p / 2) % c;
	if (p % 2 == 0) {
		return temp * temp % c;
	}
	else {
		return temp * temp % c * a % c;
	}
}