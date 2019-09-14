#include <iostream>
using namespace std;
int seg[50001 * 4];
int a[50001];
void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = 1;
		return;
	}
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
void update(int node, int start, int end, int index, int val) {
	if (index<start || index>end) return;
	if (start == end) {
		seg[node] += val;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, val);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
int kth(int node, int start, int end, int k) {
	if (start==end) return end;
	if (k <= seg[node * 2]) {
		return kth(node * 2, start, (start + end) / 2, k);
	}
	else return kth(node * 2 + 1, (start + end) / 2 + 1, end, k - seg[2 * node]);
}
int ans[50001];
int pn;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		pn = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		init(1, 1, n);
		for (int i = n; i >= 1; --i) {
			int temp = kth(1, 1, n, i - a[i]);
			ans[pn++] = temp;
			update(1, 1, n, temp, -1);
		}
		for (int i = pn - 1; i >= 0; --i) cout << ans[i] << ' ';
		cout << '\n';
	}
}