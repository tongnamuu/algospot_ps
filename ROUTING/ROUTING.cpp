#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
struct Edge {
	int to;
	double cost;
	bool operator<(const Edge& a) const {
		return this->cost < a.cost;
	}
};
vector<Edge>adj[10001];
const double INF = pow(3.0, 10000);
double dist[10001];
struct pq {
	Edge a[10001];
	int hsize = 0;
	void init() { hsize = 0; }
	void push(Edge x) {
		int i = ++hsize;
		for (; i > 1 && x < a[i / 2]; i /= 2) a[i] = a[i / 2];
		a[i] = x;
	}
	Edge top() {
		return a[1];
	}
	void pop() {
		int parent = 1, children = 2;
		Edge temp = a[hsize];
		while (children < hsize) {
			if (children + 1 < hsize && a[children + 1] < a[children]) ++children;
			if (temp < a[children]) break;
			a[parent] = a[children];
			parent = children;
			children *= 2;
		}
		a[parent] = temp;
		--hsize;
	}
	bool empty() { return hsize == 0; }
}; pq q;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;

		for (register int i = 0; i < n; ++i) {
			adj[i].clear();
			dist[i] = INF;
		}
		for (register int i = 0, u, v; i < m; ++i) {
			double c;
			cin >> u >> v >> c;
			adj[u].push_back({ v,c });
			adj[v].push_back({ u,c });
		}
		dist[0] = 1;
		q.init();
		q.push({ 0,1 });
		while (!q.empty()) {
			int now = q.top().to;
			double cost = q.top().cost;
			q.pop();
			if (dist[now] < cost) continue;
			for (auto x : adj[now]) {
				int next = x.to;
				double nextcost = cost * x.cost;
				if (dist[next] > nextcost) {
					dist[next] = nextcost;
					q.push({ next,nextcost });
				}
			}
		}
		cout << fixed;
		cout.precision(15);
		cout << dist[n - 1] << '\n';
	}
}
