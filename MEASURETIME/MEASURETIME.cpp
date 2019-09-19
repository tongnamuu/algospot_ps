#include <iostream>
using namespace std;
int a[500000];
int temp[500000];
long long ans;
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid); sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] > a[j]) {
			temp[k++] = a[j++];
			ans += (mid - i + 1);
		}
		else temp[k++] = a[i++];
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= end) temp[k++] = a[j++];
	for (int s = start; s <= end; ++s) {
		a[s] = temp[s - start];
	}
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(0, n - 1);
		cout << ans << '\n';
	}
}