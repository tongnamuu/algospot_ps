#include <iostream>
#include<memory.h>
#include <algorithm>
using namespace std;
long long sum[100001];
long long cnt[100001];
int previous[100001];
int ret[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	int n, k;
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		memset(previous, -1, sizeof(previous));
		memset(ret, 0, sizeof(ret));
		cin >> n >> k;
		cnt[0]++;
		for (int i = 1, num; i <= n; ++i) {
			cin >> num;
			sum[i] = sum[i - 1] + num;
			cnt[sum[i] % k]++;
		}
		long long ans = 0;
		for (int i = 0; i < k; ++i) {
			ans += (cnt[i] * (cnt[i] - 1) / 2) % 20091101;
		}
		for (int i = 0; i <= n; ++i) {
			if (i > 1) ret[i] = ret[i - 1];
			else ret[i] = 0;
			int loc = previous[sum[i] % k];
			if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
			previous[sum[i] % k] = i;
		}
		cout << ans % 20091101 << ' ' << ret[n] << '\n';
	}
}