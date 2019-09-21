#include <iostream>
using namespace std;
int my_strcmp(const char * a, const char * b) {
	int i = 0;
	while (a[i] != 0) {
		if (a[i] != b[i]) break;
		++i;
	}
	return a[i] - b[i];
}
int n, m;
int p[10000];
int Rank[10000];
int enemy[10000];
int cnt[10000];
bool check[10000];
void init() {
	for (int i = 0; i < n; ++i) {
		p[i] = i;
		Rank[i] = 0;
		enemy[i] = -1;
		cnt[i] = 1;
		check[i] = false;
	}
}

int findparent(int x) {
	if (p[x] == x) return x;
	else return p[x] = findparent(p[x]);
}

void merge(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x == y) return;
	if (Rank[x] < Rank[y]) {
		p[x] = y;
		cnt[y] += cnt[x];
	}
	else {
		p[y] = x;
		cnt[x] += cnt[y];
		if (Rank[x] == Rank[y]) ++Rank[x];
	}
}

bool go_friend(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	int a = enemy[x];
	int b = enemy[y];
	
	if (a == -1 && b != -1) {
		b = findparent(b);
		enemy[x] = b;
		enemy[y] = b;
	}
	else if (b == -1 && a != -1) {
		a = findparent(a);
		enemy[x] = a;
		enemy[y] = a;
	}
	else if (a != -1 && b!=-1) {
		a = findparent(a);
		b = findparent(b);
		if (a != b) merge(a, b);
		a = findparent(a);
		x = findparent(x);
		y = findparent(y);
		if (x == a || y == a) return false;
		enemy[x] = a;
		enemy[y] = a;
	}
	merge(x, y);
	return true;
}

bool go_enemy(int x, int y) {
	x = findparent(x);
	y = findparent(y);
	if (x == y) return false;
	int a = enemy[x];
	int b = enemy[y];
	if (a != -1) {
		merge(a, y);
	}
	if (b != -1) {
		merge(b, x);
	}
	y = findparent(y);
	x = findparent(x);
	enemy[x] = y;
	enemy[y] = x;
	return true;
}

int get_maxsize() {
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i < n; ++i) {
		p[i] = findparent(p[i]);
		if (check[p[i]]) continue;
		check[p[i]] = true;
		int cnt1 = cnt[p[i]];
		int cnt2 = enemy[p[i]];
		if (cnt2 == -1) {
			ans1 += cnt1;
		}
		else {
			cnt1 = cnt[p[i]];
			enemy[p[i]] = findparent(enemy[p[i]]);
			cnt2 = cnt[enemy[p[i]]];
			check[enemy[p[i]]] = true;
			if (cnt1 > cnt2) {
				ans1 += cnt1;
				ans2 += cnt2;
			}
			else {
				ans1 += cnt2;
				ans2 += cnt1;
			}
		}
	}
	return ans1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
		char cmd[4];
		bool ans = false;
		int max_size = 0;
		for (int i = 1, a, b; i <= m; ++i) {
			cin >> cmd >> a >> b;
			if (ans) continue;
			if (my_strcmp(cmd, "ACK") == 0) {
				if (!go_friend(a, b)) {
					cout << "CONTRADICTION AT " << i << '\n';
					ans = true;
				}
			}
			else {
				if (!go_enemy(a, b)) {
					cout << "CONTRADICTION AT " << i << '\n';
					ans = true;
				}
			}
		}
		if (!ans) cout << "MAX PARTY SIZE IS " << get_maxsize() << '\n';
	}
}