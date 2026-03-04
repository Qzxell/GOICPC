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

void so(int test){
    int n,k;
    cin >> n >> k;
    vi adj[n+1];
    while(k--){
        int a,b;
        cin >> a>> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi ans;
    vector<bool> vis(n+1,0);
    set<int> qu;
    qu.insert(1);
    while(!qu.empty()){
        int x = *qu.begin();
        ans.pb(x);
        vis[x]=1;
        qu.erase(x);
        for(int i : adj[x]){
            if (vis[i]) {
                continue;    
            }
            vis[i] = 1;
            qu.insert(i);
        }
    }
    f(i,0,sz(ans))cout << ans[i] << ' ';


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
