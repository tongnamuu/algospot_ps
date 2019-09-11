#include <iostream>
#include <map>
using namespace std;
map<int, int>m;
void remove(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.begin()) return;
	--it;
	while (true) {
		if (it->second > y) break;
		if (it == m.begin()) {
			m.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			m.erase(it);
			it = jt;
		}
	}
}
bool contains(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.end()) return false;
	return it->second > y;
}
int newpoint(int x, int y) {
	if (contains(x, y)) return m.size();
	remove(x, y);
	m[x] = y;
	return m.size();
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int ans = 0;
		m.clear();
		for (int i = 0, p, q; i < n; ++i) {
			cin >> p >> q;
			ans += newpoint(p, q);
		}
		cout << ans << '\n';
	}
}