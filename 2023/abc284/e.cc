// https://atcoder.jp/contests/abc284/tasks/abc284_e

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N=200001;
int n, m, vis[N], ans;

// adjacent matrix
vector<int> e[N];

void dfs(int x) {
	vis[x]=1; // mark visited
	++ans;
	if (ans>=1000000) {
		printf("%d\n",ans);
		exit(0);
	}
	for (auto v:e[x]) if (!vis[v]) {
		dfs(v);
	}
	vis[x]=0;
}

int main() {
	scanf("%d%d", &n, &m);
    // read
	for (int i=1; i<=m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].pb(v);
		e[v].pb(u);
	}

	dfs(1);
	printf("%d\n", ans);
    return 0;
}