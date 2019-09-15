#include <iostream>
using namespace std;
long long num;
long long a, b;
void next_number() {
	num = ((num*a) % 20090711 + b) % 20090711;
}
struct maxheap {
	int a[100001];
	int hsize = 0;
	void init() {
		hsize = 0;
	}
	void push(int x) {
		int i = ++hsize;
		for (; i > 1 && x > a[i / 2]; i /= 2) a[i] = a[i / 2];
		a[i] = x;
	}
	int top() { return a[1]; }
	void pop() {
		if (hsize == 0) return;
		int temp = a[hsize];
		int parent = 1, child = 2;
		while (child < hsize) {
			if (child + 1 < hsize && a[child] < a[child + 1]) ++child;
			if (a[child] <= temp) break;
			a[parent] = a[child];
			parent = child;
			child *= 2;
		}
		a[parent] = temp;
		--hsize;
	}
	int size() { return hsize; }
};
maxheap maxq;
struct minheap {
	int a[100001];
	int hsize;
	void init() {
		hsize = 0;
	}
	void push(int x) {
		int i = ++hsize;
		for (; i > 1 && x < a[i / 2]; i /= 2) a[i] = a[i / 2];
		a[i] = x;
	}
	int top() { return a[1]; }
	void pop() {
		if (hsize == 0) return;
		int parent = 1, child = 2;
		int temp = a[hsize];
		while (child < hsize) {
			if (child + 1 < hsize && a[child] > a[child + 1]) ++child;
			if (temp <= a[child]) break;
			a[parent] = a[child];
			parent = child;
			child *= 2;
		}
		a[parent] = temp;
		--hsize;
	}
	int size() { return hsize; }
};
minheap minq;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		maxq.init();
		minq.init();
		num = 1983LL;
		int n;
		cin >> n >> a >> b;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (maxq.size()>minq.size()){
				if (maxq.size()>0 && num < maxq.top()) {
					minq.push(maxq.top());
					maxq.pop();
					maxq.push(num);
				}
				else {
					minq.push(num);
				}
			}
			else if(maxq.size()==minq.size()){
				if(minq.size()>0 && num>minq.top()){
					maxq.push(minq.top());
					minq.pop();
					minq.push(num);
				}
				else {
					maxq.push(num);
				}
			}
			ans += maxq.top();
			ans %= 20090711;
			next_number();
		}
		cout << ans << '\n';
	}
}