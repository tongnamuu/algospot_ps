#include <iostream>
using namespace std;
long long d[101];
const int mod = 1000000007;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= 100; ++i) {
		d[i] = (d[i - 1] + d[i - 2]) % mod;
	}
	for (int test_case = 1; test_case <= T; ++test_case) {
		int n; cin >> n;
		if(n&1) cout << (d[n] - d[n / 2] + mod) % mod << '\n';
		else {
			int ans = (d[n] - d[n / 2] - d[(n / 2) - 1]) % mod;
			if (ans < 0) ans += mod;
			cout << ans << '\n';
		}
	}
}