#include <iostream>
using namespace std;
int n;
int a[101][101];
int d[101][101];
int max(int x, int y) { return x > y ? x : y; }
int solve(int x, int y) {
	if (d[x][y]) return d[x][y];
	if (x == n - 1) return a[x][y];
	return d[x][y] = a[x][y] + max(solve(x + 1, y), solve(x + 1, y + 1));
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cin >> a[i][j];
				d[i][j] = 0;
			}
		}
		cout << solve(0, 0) << '\n';
	}
}