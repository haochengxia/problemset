// https://atcoder.jp/contests/abc290/tasks/abc290_d
// Answer from SSRS

#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int N, D, K;
    cin >> N >> D >> K;
    K--;
    int L = N / gcd(N, D);
    cout << (long long) D * (K % L) % N + K / L << endl;
  }
}