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

const int N = 1005;
vi G[N];
int x,y;
vector<bool> vis(N,0);
vector<bool> dp(N,0);

vi ans;
bool dfs(int nod){
        if(nod == y)return dp[nod] = 1;
        vis[nod] = 1;
        bool ret = 0;
        for(auto x : G[nod])if(!vis[x]){
                ret |= dfs(x);
        }
        return dp[nod] = ret;
}

void clear(){
        f(i,0,N)G[i].clear();
        f(i,0,N)vis[i] = 0;
        f(i,0,N)dp[i] = 0;
}

void so(int test){
        int n,m;
        cin >> n >> m;
        cin >> x >> y;
        int u,v;
        f(i,0,m){
                cin >> u >> v;
                G[u].pb(v);
                G[v].pb(u);
        }
        f(i,1,n+1)sort(all(G[i]));
        dfs(x);
        vi vis2(n+1,0);
        vi ans;
        int cur = x;
        while(cur != y){
                ans.pb(cur);
                int mi = 1e9;
                for(auto x :G[cur])if(!vis2[x] and dp[x]) mi = min(mi,x);
                cur = mi;
                assert(mi <= n);
                vis2[mi] = 1;
        }
        ans.pb(y);
        for(auto x : ans)cout << x << ' ';
        cout << ln;
        clear();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
        cin >> tt;
	while (tt--){
		so(test++);
	}
	return 0;
}
