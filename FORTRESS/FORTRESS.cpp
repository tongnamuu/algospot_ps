#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;
struct Node {
	int x, y, r;
	bool operator<(const Node& a) const {
		return this->r < a.r;
	}
};
Node node[101];
vector<int>a[101];
int dist[101];
int contains(int a, int b) {
	int len = (node[a].x - node[b].x)*(node[a].x - node[b].x) + (node[a].y - node[b].y)*(node[a].y - node[b].y);
	if (len > (node[a].r + node[b].r)*(node[a].r + node[b].r)) return false;
	return true;
}

void go(int now) {
	for (int next : a[now]) {
		if (dist[next] == -1) {
			dist[next] = dist[now] + 1;
			go(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(dist, -1, sizeof(dist));
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> node[i].x >> node[i].y >> node[i].r;
			a[i].clear();
		}
		sort(node, node + n);
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (contains(i, j)) {
					a[i].push_back(j);
					a[j].push_back(i);
					break;
				}
			}
		}
		dist[0] = 0;
		go(0);

		int farnode = 0;
		int maxdist = 0;
		for (int i = 0; i < n; ++i) {
			if (dist[i] > maxdist) {
				farnode = i;
				maxdist = dist[i];
			}
			dist[i] = -1;
		}
		dist[0] = -1;
		
		dist[farnode] = 0;
		go(farnode);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (ans < dist[i]) {
				ans = dist[i];
			}
			dist[i] = -1;
		}
		cout << ans << '\n';
	}
}