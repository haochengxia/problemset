// https://atcoder.jp/contests/abc289/tasks/abc289_f
// Answer from SSRS

// xy-plane S (s_x, s_y) to T (t_x, t_y)
// find pivot in Rectangle R to mapping from S to T


#include <bits/stdc++.h>
using namespace std;
int main(){
  int sx, sy;
  cin >> sx >> sy;
  int tx, ty;
  cin >> tx >> ty;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (sx % 2 != tx % 2 || sy % 2 != ty % 2){
    // symmetry requirement
    cout << "No" << endl;
  } else {
    // defaults to ok
    bool ok = true;
    vector<pair<int, int>> ans; // store all pivots
    if (a == b){
      // special case: R is a line (y-axis) y in [c, d]
      if (tx == sx){
      } else if (tx == a * 2 - sx){
        ans.push_back(make_pair(a, c));
        sx = a * 2 - sx;
        sy = c * 2 - sy;
      } else {
        ok = false; // x-axis ok
      }
    }
    if (c == d){
      // special case: R is a line (x-axis) x in [a, b]
      if (ty == sy){
      } else if (ty == c * 2 - sy){
        ans.push_back(make_pair(a, c));
        sx = a * 2 - sx;
        sy = c * 2 - sy;
      } else {
        ok = false;
      }
    }
    // general case: a real rect
    if (a < b){
      if (sx < tx){
        for (int i = 0; i < (tx - sx) / 2; i++){
          ans.push_back(make_pair(a, c));
          ans.push_back(make_pair(a + 1, c));
        }
      } else {
        for (int i = 0; i < (sx - tx) / 2; i++){
          ans.push_back(make_pair(a + 1, c));
          ans.push_back(make_pair(a, c));
        }
      }
      sx = tx;
    }
    if (c < d){
      if (sy < ty){
        for (int i = 0; i < (ty - sy) / 2; i++){
          ans.push_back(make_pair(a, c));
          ans.push_back(make_pair(a, c + 1));
        }
      } else {
        for (int i = 0; i < (sy - ty) / 2; i++){
          ans.push_back(make_pair(a, c + 1));
          ans.push_back(make_pair(a, c));
        }
      }
      sy = ty;
    }
    if (sx != tx || sy != ty){
      ok = false;
    }
    if (!ok){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      int d = ans.size();
      for (int i = 0; i < d; i++){
        cout << ans[i].first << ' ' << ans[i].second << endl;
      }
    }
  }
}