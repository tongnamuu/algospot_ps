#include <iostream>
using namespace std;
int d[101];
int n;
const int MOD = 1000000007;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= 101; ++i) {
		d[i] = (d[i - 1] + d[i - 2])%MOD;
	}
	while (T--) {
		cin >> n;
		cout << d[n] << '\n';
	}
}