#include <iostream>
#include <string>
#include <queue>
#include <memory.h>
using namespace std;
int compare[26][26];
char a[1001][21];
int indegree[26];
bool check[26];
char answer[26];
int pn;
bool stringCmp(const char* a, const char* b) {
	int i = 0;
	while (a[i] != 0) {
		if (a[i] != b[i]) {
			break;
		}
		++i;
	}
	if (a[i] != 0 && b[i] != 0) {
		int x = a[i] - 'a';
		int y = b[i] - 'a';
		if (compare[y][x] != 0) return false;
		if (compare[x][y] == 0) indegree[y]++;
		compare[x][y] = 1;
		return true;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(compare, 0, sizeof(compare));
		memset(check, false, sizeof(check));
		memset(indegree, 0, sizeof(indegree));
		pn = 0;
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		bool ans = true;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				ans &= stringCmp(a[i], a[j]);
			}
		}
		if (!ans) {
			cout << "INVALID HYPOTHESIS\n";
			continue;
		}
		queue<int>q;
		for (int i = 0; i < 26; ++i) {
			if (indegree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int now = q.front(); q.pop();
			answer[pn++] = (char)(now + 'a');
			for (int i = 0; i < 26; ++i) {
				if (compare[now][i] == 1) {
					indegree[i]--;
					if (indegree[i] == 0) {
						q.push(i);
					}
				}
			}
		}
		for (int i = 0; i < 26; ++i) {
			cout << answer[i];
		}
		cout << '\n';
	}
}