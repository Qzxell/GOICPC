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
        int n;
        cin >> n;
        vi adj[n+1];
        vi vis(n+1,0);
        vi dp(n+1,0);
        f(i,0,n-1){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        function<int(int)>dfs;
        dfs = [&](int u) -> int{
                vis[u] = 1;
                int hojas = 0;
                bool cont = 0;
                for(int x : adj[u])if(!vis[x]){
                        cont = 1;
                        hojas += dfs(x);
                }
                return dp[u] = (!cont ? 1 : hojas);
        };
        int q;
        cin >> q;
        int ga = dfs(1);
        while(q--){
                int u,v;
                cin >> u >> v;
                cout << dp[u]*1ll*dp[v] << ln;
        }
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
