#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int d[10001];
int a[10001];
const int INF = 1000000000;
string s;
int n;
int min(int x, int y) { return x > y ? y : x; }
int check(int start, int end) {
	int x = a[start];
	bool allsame = true;
	for (int i = start; i <= end; ++i) {
		if (a[i] != x) {
			allsame = false;
			break;
		}
	}
	if (allsame) return 1;

	bool secondcondition = true;
	int dif = a[start] - a[start + 1];
	for (int i = start + 1; i+1 <= end; ++i) {
		if (a[i] - a[i + 1] != dif) {
			secondcondition = false;
			break;
		}
	}
	if (secondcondition && (dif == 1 || dif == -1)) return 2;

	bool thirdcondition = true;
	x = a[start];
	for (int i = start+2; i <= end; i+=2){
		if (a[i] != x) {
			thirdcondition = false;
			break;
		}
	}
	x = a[start + 1];
	for (int i = start + 3; i <= end; i+=2) {
		if (a[i] != x) {
			thirdcondition = false;
			break;
		}
	}
	if (thirdcondition) return 4;

	if (secondcondition) return 5;

	return 10;
}
int go(int index) {
	if (index == n) {
		return 0;
	}
	if (d[index] != -1) return d[index];
	d[index] = INF;
	for (int L = 3; L <= 5; ++L) {
		if (index + L <= n ) {
			d[index] = min(go(index + L) + check(index, index + L - 1), d[index]);
		}
	}
	return d[index];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(d, -1, sizeof(d));
		cin >> s;
		for (n = 0; s[n]; ++n) a[n] = s[n] - '0';
		cout << go(0) << '\n';
	}
}