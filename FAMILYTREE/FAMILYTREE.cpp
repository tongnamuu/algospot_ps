#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
vector<int>a[100001];
int depth[100001];
int parent[100001][17];
int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		int temp = u;
		u = v; v = temp;
	}
	int log = 1;
	for (; (1 << log) <= depth[u]; ++log) {};
	--log;
	for (int i = log; i >= 0; --i) {
		if (depth[u] - depth[v] >= (1 << i)) {
			u = parent[u][i];
		}
	}
	if (u == v) return u;
	else {
		for (int i = log; i >= 0; --i) {
			if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		return parent[u][0];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i <= n; ++i) {
			a[i].clear();
			depth[i] = 0;
			for (int j = 0; j < 17; ++j) {
				parent[i][j] = -1;
			}
		}
		for (int i = 1, u; i <= n - 1; ++i) {
			cin >> u;
			parent[i][0] = u;
			a[u].push_back(i);
		}
		queue<int>q;
		q.push(0);
		depth[0] = 1;
		parent[0][0] = -1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int next : a[now]) {
				if (depth[next] == 0) {
					depth[next] = depth[now] + 1;
					q.push(next);
				}
			}
		}
		for (int j = 1; (1 << j) <= n; ++j) {
			for (int i = 0; i < n; ++i) {
				if(parent[i][j - 1]!= -1)
					parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}
		
		for (int i = 0, a, b; i < m; ++i) {
			cin >> a >> b;
			cout << depth[a] + depth[b] - 2 * depth[lca(a, b)] << '\n';
		}
	}
}