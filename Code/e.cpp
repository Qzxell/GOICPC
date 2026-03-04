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

int n,m,x,y;
bool dfs(int nod, int pa,vector<vi> &adj,vector<bool> &vis,vector<bool> &go,vector<vi> &outs){
        if(nod == y)return go[nod] = 1;
        bool ret = 0;
        vis[nod] = 1;
        for(auto x: adj[nod])if(x != pa){
                bool ga = (vis[x] ? go[x] :  dfs(x,nod,adj,vis,go,outs));
                if(ga)outs[nod].pb(x);
                ret |= ga;
        }
        return go[nod] = ret;
}
void so(int test){
        cin >> n >> m >> x >> y;
        vector<vi> adj(n+1);
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        vector<bool> vis(n+1,0);
        vector<bool> go(n+1,0);
        vector<bool> vis_(n+1,0);
        vector<vi> outs(n+1);
        dfs(x,-1,adj,vis,go,outs);

        queue<int> qu;
        vi ans;
        int ma = INT_MAX;
        auto fu = [&](int nod){
                int ret = 0;
                for(auto x:outs[nod]){
                        ret += vis_[x];
                }
                return ret;
        };
        qu.push(x);
        f(i,1,n+1){
                cout << i << ';' << ln;
                cout << '\t' ;
                for(auto x : outs[i])cout << x << ' ';
                cout << ln;
        }
                cout << ln;
        while(!qu.empty()){
                auto u = qu.front();qu.pop();
                if(ans.empty())ans.pb(u);
                vis_[u] = 1;
                int mi = ma;
                for(auto x : adj[u])if(!vis_[x] and fu(x)){
                        mi= min(mi,x);
                }
                if(mi == ma)continue;
                ans.pb(mi);
                qu.push(mi);
        }
        for(auto x : ans)cout << x << ' ';
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
