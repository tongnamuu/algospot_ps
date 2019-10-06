#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
	int to;
	int cost;
	bool operator<(const Edge& a) const {
		return a.cost < this->cost;
	}
};
const int INF = 1000000000;
vector<Edge>a[1001];
int dist[1001];
int fire[1001];
int main() {
	int T; cin >> T;
	while (T--) {
		int v, e; cin >> v >> e;
		int n, m; cin >> n >> m;
		for (int i = 0; i <= v; ++i) {
			dist[i] = INF;
			a[i].clear();
		}
		for (int i = 0, u, v, c; i < e; ++i) {
			cin >> u >> v >> c;
			a[u].push_back({ v,c });
			a[v].push_back({ u,c });
		}
		for (int i = 0; i < n; ++i) {
			cin >> fire[i];
		}
		for (int i = 0, u; i < m; ++i) {
			cin >> u;
			a[0].push_back({ u,0 });
		}
		priority_queue<Edge>q;
		q.push({ 0,0 });
		dist[0] = 0;
		while (!q.empty()) {
			int now = q.top().to;
			int cost = q.top().cost;
			q.pop();
			if (dist[now] < cost) continue;
			for (auto x : a[now]) {
				int next = x.to;
				int nextcost = cost + x.cost;
				if (dist[next] > nextcost) {
					dist[next] = nextcost;
					q.push({ next,nextcost });
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += dist[fire[i]];
		}
		cout << ans << '\n';
	}
}