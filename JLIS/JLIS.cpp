#include <iostream>
#include <memory.h>
using namespace std;
int a[101];
int b[101];
int d[101][101];
int n, m;
int max(int a, int b) { return a > b ? a : b; }
int go(int x, int y, int prevvalue) {
	if (d[x][y] != -1) return d[x][y];
	d[x][y] = 0;
	for (int nextx = x + 1; nextx <= n; ++nextx) {
		if ((x == 0 && y == 0) || prevvalue < a[nextx]) {
			d[x][y] = max(go(nextx, y, a[nextx]) + 1, d[x][y]);
		}
	}
	for (int nexty = y + 1; nexty <= m; ++nexty) {
		if ((x == 0 && y == 0) || prevvalue < b[nexty]) {
			d[x][y] = max(go(x, nexty, b[nexty]) + 1, d[x][y]);
		}
	}
	return d[x][y];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= m; ++i) cin >> b[i];
		cout << go(0, 0, 0) << '\n';
	}
}