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

int ans = 0;
const int N = 1e5 + 1;
vi adj[N];
bool vis[N];

int dfs(int node){
    vis[node] = 1; 
    int ret = 1;
    int co = 0;
    for(int x : adj[node]){
        if(vis[x])continue;
        ret += dfs(x);
        co++;
    }
    if(co == 0)return 1;
    if(ret%2==0){
        ans++;
        return 0;
    }
    return ret;
    
}
void so(int test){
    int n;
    cin >> n;
    f(i,0,n-1){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if(n&1){
        cout << -1 << ln ;
        return;
    }
    int df = dfs(1);
    cout << ans-1;

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
