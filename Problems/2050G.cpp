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


int fun(int root, int source, int pat , vector<vi> &adj){

    int ans1 = 0;
    int son = 0;
    int add = 0;
    vi wasa;
    for(int v : adj[root])if(v != source){
        wasa.pb(fun(v,root,pat,adj));
        son++;
    }
    sort(rall(wasa));
    int owo;
    if(sz(wasa) == 1) add = wasa[0];
    else owo = wasa[0] + wasa[1] + max(0,son-2);
    return max({owo,son, son -1 + add});
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
    if(n == 2 ){
        cout << 1 << ln;
        return;
    }
    int ans ;
    for(int i = 1; i <= n;i++)if(sz(adj[i]) != 0){
        ans =  fun(i,-1,0,adj);
        ans =  max(fun(i,-1,1,adj),ans);
        break;
    }

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
