#include <iostream>
#include <string>
using namespace std;
string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string downLeft = reverse(it);
	string downRight = reverse(it);
	return string("x") + downLeft + downRight + upperLeft + upperRight;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	string s;
	while (T--) {
		cin >> s;
		string::iterator it = s.begin();
		string ans = reverse(it);
		cout << ans << '\n';
	}
}