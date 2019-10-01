#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;
int m[1000001];
map<vector<int>, int>d;
void precal(int n) {
	vector<int>p(n);
	for (int i = 0; i < n; ++i) p[i] = i + 1;
	queue<vector<int>>q;
	q.push(p);
	d[p] = 1;
	while (!q.empty()) {
		vector<int>now = q.front(); q.pop();
		int cost = d[now];
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				reverse(now.begin() + i, now.begin() + j + 1);
				if (d.count(now) == 0) {
					q.push(now);
					d[now] = cost + 1;
				}
				reverse(now.begin() + i, now.begin() + j + 1);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 8; ++i) {
		precal(i);
	}
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int>a(n);
		vector<int>b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			m[a[i]] = 0;
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < n; ++i) {
			if (m[b[i]] == 0) {
				m[b[i]] = i + 1;
			}
		}
		for (int i = 0; i < n; ++i) {
			a[i] = m[a[i]];
		}
		cout << d[a] - 1 << '\n';
	}
}
