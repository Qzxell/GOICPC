#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
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

bool dfs( int root ,int go ,vector<vi> &adj, vector<bool> &memo, vector<bool> &vis ){
    if(root == go) return memo[root] = true; 
    bool ret = 0;
    vis[root] = 1;
    for(int v : adj[root])if(!vis[v]){
        ret |= dfs(v,go,adj,memo,vis);
    }
    return memo[root] = ret;
}
void so(int test){
    int n;
    cin >> n;
    vector<vi> adj(n+1);
    for(int i = 1 ; i <= n-1 ;i++){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(n==2){
        cout << 1 << ln;
        return;
    }
    vii ord;
    int u ,v;
    queue<int> qu;
    vector<int> dis(n+1,0);
    auto bfs = [&] (int root){
        vector<bool> used(n+1,0);
        qu.push(root);
        int lon = 0;
        while(!qu.empty()){
            int nei = qu.front();
            lon++;
            used[nei] = 1;
            qu.pop();
            for(int to : adj[nei])if(!used[to] and sz(adj[to]) > 1){
                qu.push(to);
            }
        }
        return ultimate;
    };
    f(i,0,n+1)if(sz(adj[i]) > 1){
        u = bfs(i);     
        v = bfs(u);
        u = bfs(v);
        break;
    }


    vector<bool> memo(n+1,0);
    vector<bool> vis(n+1,0);
    bool xd = dfs(u,v,adj,memo,vis);
    qu.push(u);
    int len = 0;
    int ans = 0;
    int fr = u;
    while(true){
        bool cont = 1;
        memo[fr] = 0;
        len++;
        ans += sz(adj[fr]);
        for(int x: adj[fr])if(memo[x]){
                qu.push(x);
                cont = 0;
                fr = x;
        }
        if(cont)break;
    }
    cout << ans - 2*(len-1) << ln;
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
