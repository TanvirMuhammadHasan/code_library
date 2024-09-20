#include<bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define bug(a) cout<< #a << ':' << a << endl;
const ll INF= LONG_LONG_MAX;
const int N = 1e5+10;
const double pi = 2 * acos (0.0);
const ll mod=1e9+7;

int main()
{
  Start
  int n;
  cin >> n;
  int cnt=0;
  for(int i=0;i<n;++i){
    int x,y;
    cin >> x >> y;
    if((x+2)<=y){
      ++cnt;
    }
  }
  cout << cnt << '\n';
}
