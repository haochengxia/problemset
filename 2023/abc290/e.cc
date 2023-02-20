// https://atcoder.jp/contests/abc290/tasks/abc290_e
// Answer from SSRS

#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
    A[i]--;
  }
  long long ans = 0;
  for (int i = 2; i <= N; i++){ // count subarr that more than 2 ele
    ans += (long long) (i / 2) * (N - i + 1);
  }
  vector<vector<int>> p(N);
  for (int i = 0; i < N; i++){
    p[A[i]].push_back(i); // record each value's position
  }
  for (int i = 0; i < N; i++){
    if (!p[i].empty()){
      int cnt = p[i].size();  // the number of value i
      vector<long long> S(cnt + 1);
      S[0] = 0;
      for (int j = 0; j < cnt; j++){
        S[j + 1] = S[j] + N - p[i][j];
      }
      for (int j = 0; j < cnt; j++){
        int c = upper_bound(p[i].begin() + j + 1, p[i].end(), N - 1 - p[i][j]) - p[i].begin();
        ans -= (long long) (c - j - 1) * (p[i][j] + 1);
        ans -= S[cnt] - S[c];
      }
    }
  }
  cout << ans << endl;
}