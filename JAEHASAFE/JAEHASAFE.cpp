#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> fail(const string p) {
	int m = p.length();
	vector<int>pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && p[i] != p[j]) j = pi[j - 1];
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j++;
		}
		else pi[i] = 0;
	}
	return pi;
}
int kmp(const string& s, const string& p) {
	vector<int>pi = fail(p);
	vector<int>pos;
	int n = s.length();
	int m = p.length();
	int j = 0;
	int ans = m;
	for (int i = 0; i < n; ++i) {
		while (j > 0 && s[i] != p[j]) j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans = min(ans, (i - m + 1));
				j = pi[j];
			}
			else j++;
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			string p;
			cin >> p;
			if (i & 1) ans += kmp(s + s, p);
			else ans += kmp(p + p, s);
			s = p;
		}
		cout << ans << '\n';
	}
}