#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
long long a[101];
long long d[101][11];
int n, k;
const int INF = 1000000000;
long long min(int x, int y) { return x > y ? y : x; }
long long sum[101];
long long squaresum[101];
long long cal(int start, int end) {
	long long L = (end - start + 1);
	long long x = 2*(sum[end] - sum[start - 1]);
	long long m = (sum[end] - sum[start - 1]) / (end - start + 1);
	long long ans = squaresum[end] - squaresum[start - 1] - m * x + L * m*m;
	long long ans2 = squaresum[end] - squaresum[start - 1] - (m + 1)*x + L * (m + 1)*(m + 1);
	return min(ans, ans2);
}
long long go(int index, int groups) {
	if (index >= n + 1) {
		return 0;
	}
	if (groups == 0) return INF;
	if (d[index][groups] != -1) return d[index][groups];
	d[index][groups] = INF;
	for (int groupsize = 1; index+groupsize - 1 <= n; ++groupsize) {
		d[index][groups] = min(go(index + groupsize, groups - 1)+cal(index,index+groupsize-1), d[index][groups]);
	}
	return d[index][groups];
}
int main() {
	int T; cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			sum[i] = sum[i - 1] + a[i];
			squaresum[i] = squaresum[i - 1] + a[i] * a[i];
		}
		cout << go(1, k) << '\n';
	}
}