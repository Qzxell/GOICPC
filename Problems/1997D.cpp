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

bool dfs(int node, ll myq, vector<vi> &adj, vi &v){
    ll value_cur = v[node];
    //cout << "dfs  :"<< v[node] << ln;
    if (adj[node].empty()) {
        if (value_cur >= myq) {
            return 1; 
        } 
        return 0;
    }
    bool ret = 1;
    if (node != 1) {
        ll dif = myq - value_cur;
        dif = max(dif,0ll);
        myq += dif;
        if (myq >= 1e10) {
            return 0; 
        }
    }
    for(int x : adj[node]){
        ret &= dfs(x,myq, adj,v);
    }
    return ret;
}
void so(int test){
    //cout << "test " << test <<  ":" << ln;
    int n;
    cin >> n;
    vi v(n+1);

    f(i,1,n+1)cin >> v[i];
    vector<vi> adj(n+1);
    f(i,2,n+1){
        int x; cin >> x;
        adj[x].pb(i);
    }
    ll lo = v[1];
    ll lf = 2e9 + 2;
    ll mid;
    //for(int i = 0 ; i <= 6;i++){
        //cout << i << ' ';
    //}
    //cout << ln;
    //for(int i = 0 ; i <= 6;i++){
        //cout << dfs(1,max(0,i-v[1]),adj,v) + (i<=v[1]) << ' ';
    //}
    //cout << ln;
    while(lo < lf){
        mid = (lo+lf)/2;
        if (dfs(1,max(0ll,mid-v[1]),adj,v) or mid <= v[1]) {
            lo = mid+1; 
        }else {
            lf = mid;
        }
    }
    while(!(dfs(1,lo-v[1],adj,v) or lo <= v[1])){
        lo--;
    }
    cout<< lo << ln;

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
