#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int mod = 1e9 + 7;
const int N = 1e5 + 1;
vi adj[N];
bool vis[N];

int ffpw(int b, int e){
    int ret = 1;
    while(e > 0){
        if (e&1){
            ret = (ret*1ll*b)%mod;
        }
        b = (b*1ll*b)%mod;
        e >>= 1;
    }
    return ret;
}

int dfs(int node){
    vis[node] = 1;
    int ret = 1;
    int c = 0;
    for (int v : adj[node]){
        if( vis[v] )continue;
        ret += dfs(v);
        c++;
    }
    if(c== 0) return 1;
    return ret;
}

void so(int test){
    int n,k;
    cin >> n >> k;
    for(int i = 0 ;i < n-1; i++){
        int u,v, state;
        cin >> u >> v >> state;
        if(state == 0){
            adj[u].pb(v);          
            adj[v].pb(u);          
        }
    }
    int ans = ffpw(n,k);

    for(int i = 1 ; i <= n ;i++)if(!vis[i]){
        int ga = dfs(i);
        ans -= ffpw(ga,k);
        ans = (ans + mod)%mod;
    }
    cout << ans << ln;
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
