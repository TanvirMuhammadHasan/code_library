#include<bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define bug(a) cout<< #a << ':' << a << endl;
const ll INF= LONG_LONG_MAX;
const int N = 1e3+10, inf=1e9;
const double pi = 2 * acos (0.0);
const ll mod=1e9+7;
string s[N];
pair<int,int> par[N][N];
bool can_go[N][N];
int di[] = {0, -1, 0, +1, -1, -1, +1, +1};
int dj[] = {+1, 0, -1, 0, +1, -1, -1, +1};
int n, m;

bool is_valid(int x,int y)
{
  return ( x >= 0 and x < n and y >= 0 and y < m);
}

vector<vector<int>> bfs(vector<pair<int,int>> starting_cells)
{
  vector<vector<int>> d(n,vector<int> (m,inf));
  queue<pair<int,int>> q;
  for(auto x:starting_cells){
    q.push(x);
    d[x.first][x.second]=0;
  }
  while(!q.empty()){
    auto [i, j]=q.front();
    q.pop();
    for(int k=0;k<4;++k){
      int nxt_i=di[k]+i;
      int nxt_j=dj[k]+j;
      if( is_valid(nxt_i,nxt_j) and s[nxt_i][nxt_j]!='#' and (d[nxt_i][nxt_j] > ( d[i][j]+1 )) ){
        d[nxt_i][nxt_j]=d[i][j]+1;
        q.push(make_pair(nxt_i,nxt_j));
      }
    }
  }
  return d;
}
void solve(int test)
{
  cin >> n >> m;
  for(int i=0;i<n;++i){
    cin >> s[i];
  }
  pair<int,int> my_start;
  vector<pair<int,int>> monsters;
  for(int i=0;i<n;++i){
    for(int j=0;j< m;++j){
      if(s[i][j]=='A'){
        my_start=make_pair(i,j);
      }
      else if(s[i][j]=='M'){
        monsters.push_back(make_pair(i,j));
      }
    }
  }
  vector<pair<int,int>> startting;
  startting.push_back(my_start);
  auto dist_from_me = bfs(startting);
  auto dist_from_monster = bfs(monsters);

  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
      can_go[i][j] = ( s[i][j]!='#' and ( dist_from_me[i][j] < dist_from_monster[i][j]) );
    }
  }
  vector<vector<int>> d(n,vector<int> (m,inf));
  queue<pair<int,int>> q;
  q.push(my_start);
  d[my_start.first][my_start.second]=0;
  while(!q.empty()){
    auto [i, j]=q.front();
    q.pop();
    for(int k=0;k<4;++k){
      int nxt_i=di[k]+i;
      int nxt_j=dj[k]+j;
      if( is_valid(nxt_i,nxt_j) and can_go[nxt_i][nxt_j]==1 and (d[nxt_i][nxt_j] > ( d[i][j]+1 )) ){
        d[nxt_i][nxt_j]=d[i][j]+1;
        q.push(make_pair(nxt_i,nxt_j));
        par[nxt_i][nxt_j] = make_pair(i, j);
      }
    }
  }

  for(int i=0;i<n;++i){
    for(int j=0;j<m ;++j){
      if(i==0 || i==n-1 || j==0 || j==m-1){
        if(d[i][j]!=inf){
          cout <<"YES\n";
          cout << d[i][j] << '\n';
          vector<pair<int,int>> path;
          auto cur=make_pair(i,j);
          while(cur != my_start){
            path.push_back(cur);
            cur=par[cur.first][cur.second];
          }
          path.push_back(cur);
          reverse(path.begin(),path.end());
          for (int k = 0; k + 1 < path.size(); k++) {
            int di = path[k].first - path[k + 1].first;
            int dj = path[k].second - path[k + 1].second;
            if (di == +1) {
              cout << 'U';
            }
            else if (di == -1) {
              cout << 'D';
            }
            else if (dj == +1) {
              cout << 'L';
            }
            else {
              cout << 'R';
            }
          }
          cout << '\n';
          return;
        }
      }
    }
  }
  cout << "NO\n";
}
int main()
{
  Start
  int t;
  t=1;  
  //cin >> t;
  for(int test = 1;test <= t;++test) solve(test);
}
