// https://atcoder.jp/contests/abc289/tasks/abc289_e
// Answer from SSRS

// N vertices and M edges, color {0, 1}
// Find a pathe from vertex 1 to vertex N, color distinct 

#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    for (int j = 0; j < N; j++){
      cin >> C[j];
    }
    vector<vector<int>> E(N);
    for (int j = 0; j < M; j++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      E[u].push_back(v);
      E[v].push_back(u);
    }
    vector<vector<int>> d(N, vector<int>(N, -1));
    d[0][N - 1] = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, N - 1));
    while (!Q.empty()){
      int x = Q.front().first;
      int y = Q.front().second;
      Q.pop();
      for (int x2 : E[x]){
        for (int y2 : E[y]){
          if (C[x2] != C[y2] && d[x2][y2] == -1){
            d[x2][y2] = d[x][y] + 1;
            Q.push(make_pair(x2, y2));
          }
        }
      }
    }
    cout << d[N - 1][0] << endl;
  }
}