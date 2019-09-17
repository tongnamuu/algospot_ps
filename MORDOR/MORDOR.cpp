#include <iostream>
using namespace std;
int a[100001];
int seg[400004];
int minseg[400004];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = a[start];
		minseg[node] = a[start];
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
	minseg[node] = min(minseg[node * 2], minseg[node * 2 + 1]);
}
int maxquery(int node, int start, int end, int i, int j) {
	if (end<i || start>j) return 0;
	if (i <= start && end <= j) return seg[node];
	return max(maxquery(node * 2, start, (start + end) / 2, i, j), maxquery(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int minquery(int node, int start, int end, int i, int j) {
	if (end<i || start>j) return 1000000;
	if (i <= start && end <= j) return minseg[node];
	return min(minquery(node * 2, start, (start + end) / 2, i, j), minquery(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int query(int n, int a, int b) {
	return maxquery(1, 0, n - 1, a, b) - minquery(1, 0, n - 1, a, b);
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, q; cin >> n >> q;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		init(1, 0, n - 1);
		for (int i = 0, a, b; i < q; ++i) {
			cin >> a >> b;
			cout << query(n, a, b) << '\n';
		}
	}
}