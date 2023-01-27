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
const int N = 1e6 + 7, mod = 998244353, inv2 = (mod + 1) / 2;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, 
		ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, m, W[N];
int f[N], g[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	init(n + m);
	L(p, 1, n) {
		int all = qpow((ll) n * (n + 1) / 2 % mod, m) % mod;
		W[p] = all;
		int sum = 0;
		(sum += (ll) p * (p - 1) / 2 % mod) %= mod;
		(sum += (ll) (n - p) * (n - p + 1) / 2 % mod) %= mod;
		sum = qpow(sum, m);
		(W[p] += (ll) (all + mod - sum) * (n + 1) % mod * inv2 % mod) %= mod;
		(W[p] += (ll) sum * p % mod) %= mod;
	}
	int ns = 0;
	L(i, 1, n) {
		int x;
		cin >> x;
		int buf = (n - x) - (x - 1);
		(buf += mod) %= mod;
		(ns += (ll) buf * W[i] % mod) %= mod;
	}
	int sum = 0;
	L(d, 1, n) 
		(sum += (ll) d * (n - d) % mod) %= mod;
	sum = (ll) sum * qpow((ll) n * (n + 1) / 2 % mod, m) % mod;
	cout << (ll) (sum + ns) * inv2 % mod << '\n';
	return 0;
}