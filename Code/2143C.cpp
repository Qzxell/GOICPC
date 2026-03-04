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
#define point complex<long long>

const int N = 2e5 + 3;
vi adj[N];
vi w(N,-1);

int dfs(int nod){
        if(w[nod] != -1)return w[nod];
        int ret = 1;
        for(auto x : adj[nod]){
                ret += dfs(x);
        }
        return w[nod] = ret;
}

void so(int test){
        int n;
        cin >> n;
        f(i,0,n+1){
                w[i] = -1;
                adj[i].clear();
        }
        f(i,0,n-1){
                int u,v,x,y;
                cin >> u >> v >> x >> y;
                if(x == y)continue;
                if(x < y){
                        adj[v].pb(u);
                }else{
                        adj[u].pb(v);
                }
        }
        f(i,1,n+1)if(w[i] == -1)dfs(i);
        vii so;
        f(i,1,n+1){
                so.pb({w[i],i});
        }
        sort(all(so));
        vi ans(n+1);
        f(i,0,n){
                ans[so[i].se-1] = i+1;
        }
        f(i,0,n){
                cout << ans[i] << ' ';
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



