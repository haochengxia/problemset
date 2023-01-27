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
const int N = 1e6 + 7, mod = 998244353;
int n, cnt[26];
char s[N], t[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> (s + 1) >> (t + 1);
	L(i, 1, n) {
		if(s[i] > t[i]) {
			swap(s[i], t[i]);
		}
	}
	int x = 0, y = 0;
	L(i, 1, n) 
		x = ((ll) x * 10 + s[i] - '0') % mod;
	L(i, 1, n) 
		y = ((ll) y * 10 + t[i] - '0') % mod;
	cout << (ll) x * y % mod << '\n';
	return 0;
}