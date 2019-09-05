#include <iostream>
#include <queue>
using namespace std;
long long nextnumber;
int getnextnumber() {
	long long x = nextnumber;
	nextnumber = ((nextnumber * 214013u + 2531011u)&4294967295);
	return x % 10000 + 1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long k, n; cin >> k >> n;
		queue<int>q;
		int sum = 0;
		int ans = 0;
		nextnumber = 1983LL;
		for (int i = 0; i < n; ++i) {
			int num = getnextnumber();
			sum += num;
			q.push(num);
			if (sum > k) {
				while (!q.empty() && sum > k) {
					sum -= q.front();
					q.pop();
				}
			}
			if (sum == k) {
				++ans;
			}
		}
		cout << ans << '\n';
	}
}
