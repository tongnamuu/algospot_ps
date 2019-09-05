#include <iostream>
using namespace std;
char a[10001];
char stack[10001];
int pn;
void init() { pn = 0; }
void push(char x) { stack[pn++] = x; }
char top() { return stack[pn - 1]; }
void pop() { if (pn > 0) --pn; }
bool empty() { return pn == 0; }
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		init();
		bool ans = true;
		cin >> a;
		for (int i = 0; a[i]; ++i) {
			if (a[i] == '(' || a[i] == '{' || a[i] == '[') {
				push(a[i]);
			}
			else {
				if (a[i] == ')') {
					if (empty() || top() != '(') {
						ans = false;
						break;
					}
					pop();
				}
				else if (a[i] == '}') {
					if (empty() || top() != '{') {
						ans = false;
						break;
					}
					pop();
				}
				else if (a[i] == ']') {
					if (empty() || top() != '[') {
						ans = false;
						break;
					}
					pop();
				}
			}
		}
		if (!empty()) ans = false;
		if (ans) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
