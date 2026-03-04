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

const int N = 2e5 +1;
vi adj[N];
vi v(N);
vi kk(N,0);
vector<bool> vis(N,0);
vi memo(N,0);

bool dfs(int root){
	bool  ret = 0;
	if(kk[root]) ret = 1;
	vis[root] = 1;
	for(int x : adj[root])if(!vis[x]){
		ret |= dfs(x);
	}
	return memo[root]=ret;
}

void so(int test){
	int n,k;
	cin >> n >> k;
	f(i,0,n-1){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	f(i,0,k){
		cin >>v[i];
		kk[v[i]] = 1;
	}
	int wasa = dfs(v[0]);
	int ans = 0;
	for(int i = 1 ;i <=n;i++)if(memo[i])ans++;
	cout<<  ans << ln;


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
