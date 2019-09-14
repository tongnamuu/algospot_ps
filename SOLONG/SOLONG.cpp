#include <iostream>
#include <assert.h>
using namespace std;
int min(int x, int y) { return x > y ? y : x; }

void my_strcpy( char * a, char * b) {
	int i = 0;
	while (a[i] != 0) {
		b[i] = a[i];
		i++;
	}
	b[i] = 0;
}

int my_strcmp(const char * a, const char * b) {
	int i = 0;
	while (a[i] != 0) {
		if (a[i] != b[i]) break;
		i++;
	}
	return a[i] - b[i];
}

int my_strlen(const char * a) {
	int i = 0;
	while (a[i] != 0) ++i;
	return i;
}

struct words {
	char word[11];
	int priority;
	bool operator<(const words& a) const {
		if(a.priority!=this->priority) return a.priority < this->priority;
		else return my_strcmp(this->word, a.word) < 0;
	}
};
words wordset[10000];
words temp[10001];
void sort(int start, int end) {
	if (start == end) return;
	int mid = (start + end) / 2;
	sort(start, mid); sort(mid + 1, end);
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (wordset[i] < wordset[j]) {
			temp[k++] = wordset[i++];
		}
		else {
			temp[k++] = wordset[j++];
		}
	}
	while (i <= mid)temp[k++] = wordset[i++];
	while (j <= end) temp[k++] = wordset[j++];
	for (int s = start; s <= end; ++s) {
		wordset[s] = temp[s - start];
	}
}

struct Trie {
	int children[26];
	int first;
	bool terminal;
};
Trie trie[600001];
int nodeCnt;
void init(int x) {
	for (int i = 0; i < 26; ++i) {
		trie[x].children[i] = -1;
	}
	trie[x].first = -1;
	trie[x].terminal = false;
}
int nodeNumber() {
	nodeCnt++;
	init(nodeCnt);
	return nodeCnt; 
}
void insert(int node, const char* str, int num) {
	if (str[0]==0) {
		if(trie[node].first==-1)trie[node].first = num;
		trie[node].terminal = true;
		return;
	}
	int next = str[0] - 'A';
	int& nextnode = trie[node].children[next];
	if (nextnode == -1) {
		nextnode = nodeNumber();
		if(trie[nextnode].first==-1) trie[nextnode].first = num;
		assert(nodeCnt <= 60000);
	}
	insert(nextnode, str + 1, num);
}
int search(int node, const char* str,int index) {
	if (node == -1) return -1;
	if (str[index] == '\0') {
		if (!trie[node].terminal) return -1;
		int x = trie[node].first;
		if (my_strcmp(str, wordset[x].word) == 0) return x;
		else return -1;
	}
	int next = str[index] - 'A';
	int nextnode = trie[node].children[next];
	return search(nextnode, str, index+1);
}
int typeCnt(int node, const char* str, int key) {
	if (str[0] == 0) {
		return 0;
	}
	if (trie[node].first == key) return 1;
	int nextnode = trie[node].children[str[0] - 'A'];
	return 1 + typeCnt(nextnode, str + 1, key);
}
char a[11];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T; cin >> T;
	while (T--) {
		nodeCnt = 0;
		init(0);
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> wordset[i].word >> wordset[i].priority;
		}
		sort(0, n - 1);
		for (int i = 0; i < n; ++i) {
			insert(0, wordset[i].word, i);
		}
		int ans = m - 1;
		for (int i = 0; i < m; ++i) {
			cin >> a;
			int k = search(0, a, 0);
			if (k == -1) ans += my_strlen(a);
			else {
				int cnt = typeCnt(0, a, k);
				cnt = min(cnt, my_strlen(a));
				ans += cnt;
			}
		}
		cout << ans << '\n';
	}
}