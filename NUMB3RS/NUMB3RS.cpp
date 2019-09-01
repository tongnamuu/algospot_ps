#include<iostream>
#include<memory.h>
using namespace std;
int a[51][51];
double d[101][51];
int outdegree[51];
int n, start;
double go(int day, int position) {
	if (day == 0) {
		if (position == start) {
			return 1.0;
		}
		else return 0.0;
	}
	if (d[day][position] > -1) return d[day][position];
	d[day][position] = 0.0;
	for (int i = 0; i < n; ++i) {
		if (a[position][i]) {
			d[day][position] += (double)(go(day - 1, i) / outdegree[i]);
		}
	}
	return d[day][position];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout << fixed;
	cout.precision(10);
	int T; cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		int day; cin >> n >> day >> start;
		for (int i = 0; i < n; ++i) {
			outdegree[i] = 0;
			for (int j = 0; j < n; ++j) {
				cin >> a[i][j];
				if(a[i][j]) outdegree[i]++;
			}
		}
		int m; cin >> m;
		for (int i = 0, u; i < m; ++i) {
			cin >> u;
			cout << go(day, u) << ' ';
		}
		cout << '\n';
	}
}