#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)


map<ll,vector<ll>> vec;
map<ll,ll> memo;

ll dp(ll dis){
	if(vec.count(dis) ==0)return dis;
	if(memo.count(dis))return memo[dis];
	ll ret = dis;
	for(ll x : vec[dis]){
		ret = max(dp(x),ret);	
	}
	return memo[dis]= ret;
}
void so(int test){
	vec.clear();
	memo.clear();
	int n;
	cin >> n;
	vector<ll> v(n);
	f(i,0,n) cin >> v[i];
	f(i,0,n){
		ll num = n-i;
		ll dif = v[i] -num;
		if(v[i] < num) continue;
		ll u,v;
		u = n+0ll+dif;
		v = n+0ll+dif+i;
		if(i)vec[u].pb(v);
	}
	ll ans = dp(n);

	cout << ans << ln;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
