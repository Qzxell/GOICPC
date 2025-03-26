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

const int N = 300005;
vi cam(N,0);
vi adj[N];
vi vis(N,0);
int n,x,y;

int dfs(int r){
	if(r == y){
		return cam[r] = 1;
	}
	vis[r] = 1;
	for(auto v : adj[r])if(!vis[v]){
		if(dfs(v)){
			return cam[r] = 1;
		}
	}
	return 0;
}

void so(int test){
	cin >> n >> x >> y;
	f(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int ga = dfs(x);
	f(i,0,n+1)vis[i] = 0;
	queue<int> qu;
	auto bfs = [&](int r) -> ll{
		vis[r] = 1;
		ll c = 0;
		qu.push(r);
		while(!qu.empty()){
			int fr = qu.front();qu.pop();
			c++;
			vis[fr] = 1;
			for(auto x : adj[fr])if(!vis[x]){
				if(cam[x])continue;
				qu.push(x);
			}
		}
		return c;
	};
	ll ans = (n*1ll*(n-1));
	ll o = bfs(x);
	ll b = bfs(y);
	ans -= (o*(b));
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
