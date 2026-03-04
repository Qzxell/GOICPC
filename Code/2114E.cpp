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

void so(int test){
        int n;
        cin >> n;
        vi w(n+1);
        vi vis(n+1,0);
        vi pare(n+1,0);
        f(i,1,n+1)cin >> w[i];
        vi adj[n+1];
        f(i,0,n-1){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        vector<ll> dp(n+1,0);
        queue<int> qu;
        int nod = 1;
        qu.push(nod);
        vis[nod] = 1;
        pare[nod] = -1;
        while(!qu.empty()){
                int fr = qu.front();qu.pop();
                ll val = w[fr];
                if(pare[fr] != -1 ){
                        if(pare[pare[fr]] != -1)
                                val = max(val,dp[pare[pare[fr]]] + w[fr] - w[pare[fr]]);
                }
                dp[fr] = val;
                for(auto x : adj[fr])if(!vis[x]){
                        qu.push(x);
                        pare[x] = fr;
                        vis[x] = 1;
                }
        }
        f(i,1,n+1){
                cout << dp[i] << ' ' ;
        }
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



