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

int n,m;
const int N = 1e5 + 2;
vi adj[N];
int cat[N];
vector<bool> vis(N,0);

int dfs(int nod, int cat_op){
    vis[nod] = 1; 
    int nek = cat[nod];
    int shop = 0;
    bool con = 1;

    if (cat_op - nek < 0) {
        return 0; 
    }
    for(int v : adj[nod]){
        if (vis[v]) {
            continue; 
        }
        con = 0;
        if(nek)shop += dfs(v,cat_op - nek);
        else shop += dfs(v,m);
    }
    if (con) {
        if (cat_op - nek >= 0) {
            return 1; 
        }else return 0;
    }
    return shop;
}
void so(int test){
    cin >> n >> m;
    f(i,1,n+1)cin >> cat[i];
    f(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = dfs(1,m);
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
