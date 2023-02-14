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
int n, x[N], tp;
int a[N], b[N];
void Main() {
	cin >> n;
	L(i, 1, n) 
		cin >> a[i];
	L(i, 1, n) 
		cin >> b[i];
	bool ok = false;
	L(i, 1, n) 
		if(b[i] == b[i % n + 1]) 
			ok = true;
	if(!ok) {
		L(i, 1, n) 
			if(a[i] != b[i]) {
				cout << "No\n";
				return ;
			}
		cout << "Yes\n";
		return ;
	}
	tp = 0;
	L(i, 1, n) 
		if(b[i] != b[i % n + 1]) x[++tp] = b[i];
	if(tp == 0) 
		x[++tp] = b[1];
	L(p, 1, n) {
		int pos = 0;
		L(i, 1, n) {
			int s = a[(i + p) % n + 1];
			if(pos < tp && x[pos + 1] == s) 
				++pos;
		}
		if(pos == tp) {
			cout << "Yes\n";
			return ;
		}
	}
	cout << "No\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}