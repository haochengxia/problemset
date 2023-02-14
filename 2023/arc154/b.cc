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
int n, cnt[26];
char s[N], t[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	cin >> (s + 1) >> (t + 1);
	L(i, 1, n) {
		cnt[s[i] - 'a'] += 1;
	}
	L(i, 1, n) {
		cnt[t[i] - 'a'] -= 1;
	}
	L(i, 0, 25) 
		if(cnt[i]) {
			cout << -1 << '\n';
			return 0;
		}
	int pos = n;
	R(i, n, 1) {
		if(s[pos] == t[i]) {
			--pos;
		}
	}
	cout << pos << '\n';
	return 0;
}