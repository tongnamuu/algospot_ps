#include <iostream>
using namespace std;
int min(int x, int y) { return x > y ? y : x; }
void swap(int* x, int* y) {
	int* temp = x;
	x = y;
	y = temp;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		int number = 1;
		int number2 = 0;
		for (int i = 2; i <= n; ++i) {
			number = (number + k - 1) % i + 1;
			number2 = (number2 + k - 1) % i + 1;
		}
		number = number - k % n + 1;
		number2 = number2 - k % n + 1;
		if (number <= 0) number += n;
		if (number2 <= 0) number2 += n;
		if (number > number2) swap(number, number2);
		cout << number << ' ' << number2 << '\n';
	}
}