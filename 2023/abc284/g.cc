// https://atcoder.jp/contests/abc284/tasks/abc284_g

#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> pow(N);
  pow[0] = 1;
  for (int i = 0; i < N - 1; i++){
    pow[i + 1] = pow[i] * N % M;
  }
  long long P = (long long) N * (N - 1) % M;
  long long ans = 0;
  for (int i = 2; i <= N; i++){
    long long add = P * pow[N - i] % M;
    add *= (long long) i * (i - 1) / 2 % M;
    add %= M;
    ans += add;
    ans %= M;
    if (i < N){
      P *= N - i;
      P %= M;
    }
  }
  cout << ans << endl;
}