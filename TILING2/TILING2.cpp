#include <iostream>
using namespace std;
int a[101];
int d[101];
int n;
const int MOD = 1000000007;
int go(int x) {
	if (x == 2) {
		return d[x] = 2;
	}
	if (x == 1) {
		return d[x] = 1;
	}
	int& ret = d[x];
	if (ret != -1) return ret;
	return ret = (go(x - 1) + go(x - 2))%MOD;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i <= n; ++i) {
			d[i] = -1;
		}
		cout << go(n) << '\n';
	}
}