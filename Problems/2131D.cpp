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

int dfs(int rot,int pat,vector<vi> &adj){
        int ret = 0;
        for(auto x : adj[rot])if(x != pat){
                ret += dfs(x,rot,adj);
        }
        return (ret == 0 ? 1 : ret);
}
void so(int test){
        int n;
        cin >> n;
        vi deg(n+1,0);
        vector<vi> adj(n+1);
        f(i,0,n-1){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
                deg[u]++;deg[v]++;
        }
        int rot;
        int ma = 0;
        vi fr(n+1,0);
        f(i,1,n+1){
                if(deg[i] == 1){
                        fr[adj[i][0]]++;
                }
        }
        f(i,1,n+1){
                if(ma < fr[i]){
                        ma = fr[i];
                        rot = i;
                }
        }
        int ans = dfs(rot,-1,adj) - fr[rot];
        cout << ans << ln;
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
