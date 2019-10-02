#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
int number[10];
int d[20001];
int from[20001];
int choose[20001];
void print(int now) {
	if (from[now] == now) {
		return;
	}
	print(from[now]);
	cout << choose[now];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string s;
		int n, m;
		cin >> s >> n >> m;
		for (int i = 0; i <= 9; ++i) number[i] = 0;
		memset(d, -1, sizeof(d));
		memset(from, -1, sizeof(from));
		memset(choose, -1, sizeof(choose));
		for (int i = 0; s[i]; ++i) {
			number[s[i] - '0'] = 1;
		}

		queue<int>q;
		q.push(0);
		from[0] = 0;
		
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int i = 0; i <= 9; ++i) {
				if (number[i] == 0) continue;
				int next = (now * 10 + i);
				if (next >= n) next = next % n + n;
				else next %= n;
				if (d[next] == -1) {
					d[next] = d[now] + 1;
					q.push(next);
					from[next] = now;
					choose[next] = i;
				}
			}
		}
		if (d[n + m] == -1) cout << "IMPOSSIBLE" << '\n';
		else {
			print(n + m);
			cout << '\n';
		}
	}
}