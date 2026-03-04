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

const int N = 1e5 + 1;
vector<pair<int,ll>> adj[N];
vi vis(N,0);
vi vis1(N,0);
vector<ll> dp(N,-1);

ll dfs1(int root){
	ll sum = 0;
	vis1[root] = 1;
	for(auto [x,w] : adj[root])if(!vis1[x]){
		sum += w + dfs1(x);
	}
	return dp[root] = sum;

}
ll dfs(int root){
	vis[root] = 1;	
	ll sum = 0;
	ll ret = (1ll<<60);
	for(auto [x,w] : adj[root])if(!vis[x])
		sum += 2*dp[x] + 2*w;

	int c = 0;
	for(auto [x,w] : adj[root])if(!vis[x]){
		sum -= 2*dp[x] + w;
		ll wasa = dfs(x);
		sum += wasa;
		ret = min(sum,ret);
		sum -= wasa;
		sum += 2*dp[x] + w;
		c++;
	}
	if(c == 0)return 0;
	return ret;
}

void so(int test){
	int n;
	cin >> n;
	f(i,0,n-1){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	ll wasa = dfs1(1);
	ll ans = dfs(1);
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
