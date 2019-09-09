#include <iostream>
#include <vector>
using namespace std;
int a[101];
int b[101];
void postorder(int prei, int prej, int ini, int inj) {
	if (prei >= prej) return;
	if (ini >= inj) return;
	int root = a[prei];
	int left;
	int cnt = 1;
	for (left = ini; left < inj; ++left) {
		if (b[left] == root) break;
		++cnt;
	}
	postorder(prei + 1, prei + cnt , ini, left);
	postorder(prei + cnt, prej, left + 1, inj);
	cout << root << ' ';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int>preorder(n);
		vector<int>inorder(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		postorder(0, n, 0, n);
		cout << '\n';
	}
}