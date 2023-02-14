// https://atcoder.jp/contests/abc289/tasks/abc289_d
// Answer from SSRS

#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int M;
  cin >> M;
  vector<int> B(M);
  for (int i = 0; i < M; i++){
    cin >> B[i];
  }
  int X;
  cin >> X;
  vector<bool> ok(X + 1, true);
  for (int i = 0; i < M; i++){
    ok[B[i]] = false; // mark the trap steps
  }
  vector<bool> dp(X + 1, false);
  dp[0] = true;
  for (int i = 0; i < X; i++){
    if (dp[i]){
      for (int j = 0; j < N; j++){
        if (i + A[j] <= X){
          if (ok[i + A[j]]){
            dp[i + A[j]] = true;
          }
        }
      }
    }
  }
  if (dp[X]){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}