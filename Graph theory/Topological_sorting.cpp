// it can also be done with dfs by saiving end time of every node but in this way u have to check whether it is an cycle or not seperately 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int indeg[N];
bool vis[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    indeg[v]++;
  }
  queue<int> q;
  for (int u = 1; u <= n; u++) {
    if (indeg[u] == 0) {
      q.push(u);
    }
  }
  vector<int> ord;
  while (!q.empty()) {
    int u = q.front();
    ord.push_back(u);
    q.pop();
    for (auto v: g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }
  if (ord.size() < n) { // cycle detected
    cout << "IMPOSSIBLE\n";
  }
  else {
    for (auto x: ord) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}  ///https://cses.fi/problemset/task/1679
