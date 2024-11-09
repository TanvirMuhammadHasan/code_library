#include<bits/stdc++.h>
using namespace std;

#define Start ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll unsigned long long
#define bug(a) cout<< #a << ':' << a << endl;
const ll INF= LONG_LONG_MAX;
const ll N = 1e5+10;
const double pi = 2 * acos (0.0);
const ll mod=1e9+7;

void solve(ll test)
{
  ll k;
  cin >> k;
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  vector<ll> pow(62,1);
  for(ll i=1;i<=61;++i){
    pow[i] = 2ll * pow[i-1];
  }
  ll n=s.size(),num=0;
  for(ll i=0;i<n;++i){
    if(s[i]=='1'){
      num+=pow[i];
    }
  }
  if(num <= k){
    cout << "0\n";
    return;
  }

  string t="";
  num=k;
  while(num > 0){
    if(num%2==0) t+='0';
    else t+='1';
    num/=2;
  }
  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());
  ll n=s.size(),len=t.size();
  
  for(ll i=0;i<n;++i){
    if(i==0 || s[i]=='0'){

    }
  }
}
int main()
{
  Start
  ll t;
  t=1;  
  //cin >> t;
  for(ll test = 1;test <= t;++test) solve(test);
}