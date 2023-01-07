// https://atcoder.jp/contests/abc284/tasks/abc284_d

#include <bits/stdc++.h>
typedef long long ll;

int main() {
    int T;
    ll n;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%lld", &n);
        for (ll i=2; i*i*i <= n; i++) {
            if (n % (i*i) == 0) {
                // case 1: p >= q
                printf("%lld %lld\n", i, n /( i * i));
				break;
            } else if (n % i == 0) {
                // case 2: p < q
                ll v = ceil(sqrt(n / i));
                if (i * v * v == n) {
                    printf("%lld %lld\n", v, i);
					break;
                }
            }
        }
    }
    return 0;
}