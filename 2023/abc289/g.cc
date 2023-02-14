// https://atcoder.jp/contests/abc289/tasks/abc289_g
// Answer from SSRS

// N customers budget B_i, M items value C_j, how to set price?
// customers buy each item B_i + C_j >= P_j
// So each item is independent in sale

#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct li_chao_tree{
  struct line{
    T a, b;
    line(): a(0), b(-INF){
    }
    line(T a, T b): a(a), b(b){
    }
    T get(T x){
      return a * x + b;
    }
  };
  int N;
  vector<T> x;
  vector<line> ST;
  li_chao_tree(){
  }
  li_chao_tree(const vector<T> &x2){
    x = x2;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int N2 = x.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    x.resize(N);
    for (int i = N2; i < N; i++){
      x[i] = x[N2 - 1];
    }
    ST = vector<line>(N * 2 - 1);
  }
  void line_add(line L, int i, int l, int r){
    T la = L.get(x[l]);
    T lb = ST[i].get(x[l]);
    T ra = L.get(x[r - 1]);
    T rb = ST[i].get(x[r - 1]);
    if (la <= lb && ra <= rb){
      return;
    } else if (la >= lb && ra >= rb){
      ST[i] = L;
    } else {
      int m = (l + r) / 2;
      T ma = L.get(x[m]);
      T mb = ST[i].get(x[m]);
      if (ma > mb){
        swap(L, ST[i]);
        swap(la, lb);
        swap(ra, rb);
      }
      if (la > lb){
        line_add(L, i * 2 + 1, l, m);
      }
      if (ra > rb){
        line_add(L, i * 2 + 2, m, r);
      }
    }
  }
  void line_add(T a, T b){
    line_add(line(a, b), 0, 0, N);
  }
  T get(T x2){
    int p = lower_bound(x.begin(), x.end(), x2) - x.begin();
    p += N - 1;
    T ans = -INF;
    ans = max(ans, ST[p].get(x2));
    while (p > 0){
      p = (p - 1) / 2;
      ans = max(ans, ST[p].get(x2));
    }
    return ans;
  }
};
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    cin >> B[i];
  }
  vector<long long> C(M);
  for (int i = 0; i < M; i++){
    cin >> C[i];
  }
  sort(B.begin(), B.end(), greater<int>());
  li_chao_tree<long long> LCT(C);
  for (int i = 0; i < N; i++){
    LCT.line_add(i + 1, (long long) (i + 1) * B[i]);
  }
  for (int i = 0; i < M; i++){
    cout << LCT.get(C[i]) << endl;
  }
}