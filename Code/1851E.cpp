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

void so(int test){
	int n , k;
	cin >> n >> k;
	vi prices(n+1);
	set<int> inf; // ind que son ilimitados
	vi adj[n+1];
	f(i,1,n+1)cin >> prices[i];
	f(i,0,k){
		int x;
		cin >> x;
		inf.insert(x);
	}
	f(i,1,n+1){
		int m;
		cin >> m;
		f(j,0,m){
			int x;cin >> x;
			adj[i].pb(x);
		}
	}
	vector<ll> memo(n+1,-1);
	function<ll(int)> fu = [&](int ind) -> ll{
		if(memo[ind] != -1)return memo[ind];
		if(inf.count(ind))return 0;
		if(adj[ind].empty())return memo[ind] = prices[ind];
		ll ret = prices[ind];
		ll acu =0 ;
		for(auto x : adj[ind]){
			acu += fu(x);
		}
		return memo[ind] = min(acu,ret);
	};
	f(i,1,n+1){
		int ans = fu(i);
		cout << ans << ' ' ;
	}
	cout << ln;
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
