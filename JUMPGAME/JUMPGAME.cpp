#include <iostream>
#include <memory.h>
using namespace std;
int n;
int a[101][101];
int d[101][101];
bool range(int x, int y) {
	if (x >= 0 && x < n&&y >= 0 && y < n) return true;
	return false;
}
int go(int x, int y) {
	if (!range(x, y)) return 0;
	if (d[x][y] != -1) return d[x][y];
	if (x == n - 1 && y == n - 1) return 1;
	return d[x][y] = go(x + a[x][y], y) | go(x, y + a[x][y]);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				d[i][j] = -1;
			}
		}
		if (go(0, 0)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}