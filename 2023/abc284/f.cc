// https://atcoder.jp/contests/abc284/tasks/abc284_f

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string T;
	cin >> N;
	cin >> T;
	string S = T;
	reverse(S.begin() + N, S.end());

	vector<int> next(2 * N + 1);
	// KMP
    for (int i = 1, j = 0; i < 2 * N; i++) {
        while (j && S[i] != S[j]) j = next[j];
        j += (S[i] == S[j]);
        next[i + 1] = j;
    }

	vector<int> ok(N+1);
    for (int i = 2 * N; ; i = next[i]) {
        if (i <= N) ok[i]++;
        if (!i) break;
    }

	reverse(S.begin(), S.begin() + N);
    reverse(S.begin() + N, S.end());
    
    for (int i = 1, j = 0; i < 2 * N; i++) {
        while (j && S[i] != S[j]) j = next[j];
        j += (S[i] == S[j]);
        next[i + 1] = j;
    }
    
    for (int i = 2 * N; ; i = next[i]) {
        if (i <= N) ok[N - i]++;
        if (!i) break;
    }
    
    for (int i = 0; i <= N; i++) {
        if (ok[i] == 2) {
            cout << T.substr(0, i) + T.substr(N + i)  << "\n";
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << -1 << "\n";
	return 0;
}
