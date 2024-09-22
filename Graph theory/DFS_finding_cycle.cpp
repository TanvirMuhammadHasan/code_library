#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int col[N], par[N];
bool found;
vector<int> cycle;
void dfs(int u,int p) {
  if (found) return;
  col[u] = 1;
  par[u]=p;
  for (auto v: g[u]) {
    if (found) return;
    if (col[v] == 0) {
      par[v] = u;
      dfs(v,u);
    }
    else if (col[v] == 1 and v!=p) { ///for directed just remove the 2nd condition(v!=p)
      found = true;
      int st = u;
      while (u != v) {
        cycle.push_back(u);
        u = par[u];
      }
      cycle.push_back(v);
      cycle.push_back(st);
      reverse(cycle.begin(), cycle.end());
      return;
    }
  }
  col[u] = 2;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!col[i]) {
      dfs(i,0);
      if (found) {
        cout << cycle.size() << '\n';
        for (auto u: cycle) {
          cout << u << ' ';
        }
        cout << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return 0;
}
