#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7;
int n;
int p[N];
mt19937_64 orz(time(0) ^ *new int);
int ask(int i, int j, int k) {
	cout << "? " << i << ' ' << j << ' ' << k << endl;
	string w;
	cin >> w;
	return w == "Yes" ? 1 : 0;
	return p[i] + p[j] > p[k];
}
int ord[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	p[1] = 3, p[2] = 1, p[3] = 2, p[4] = 4;
	int cur = 1;
	L(i, 2, n) 
		if(ask(cur, cur, i)) {
			cur = i;
		}
	L(i, 1, n) {
		ord[i] = i;
	}
	stable_sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		if(x == y) return false;
		return !ask(x, cur, y);
	});
	L(i, 1, n) 
		p[ord[i]] = i;
	cout << "! ";
	L(i, 1, n) 
		cout << p[i] << ' ';
	cout << endl;
	return 0;
}