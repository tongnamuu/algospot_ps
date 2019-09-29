#include <iostream>
#include <vector>
using namespace std;
vector<int>a[1001];
bool visit[1001];
int ans;
int dfs(int now) {
	visit[now] = true;
	int children[3] = { 0, };
	for (int next : a[now]) {
		if (!visit[next]) {
			++children[dfs(next)];
		}
	}
	if (children[0]) {
		++ans;
		return 2;
	}
	if (children[2]) {
		return 1;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			a[i].clear();
			visit[i] = false;
		}
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		ans = 0;
		for (int i = 0; i < n; ++i) {
			if (!visit[i])
				ans += (dfs(i) == 0);
		}
		cout << ans << '\n';
	}
}