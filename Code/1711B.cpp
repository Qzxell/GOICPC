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
        int n,m;
        cin >> n >> m;
        vi adj[n+1];
        vi deg(n+1,0);
        vi disg(n+1);
        vi vis(n+1,0);
        vi vis_(n+1,0);
        f(i,1,n+1){
                cin >> disg[i];
        }
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
                deg[u]++;deg[v]++;
        }
        if(not(m&1)){
                cout << 0 << ln;
                return;
        }
        int ans = INT_MAX;
        f(i,1,n+1){
                if(deg[i]&1){
                        ans = min(ans,disg[i]);
                }else{
                        vis[i] = 1;
                        int va =disg[i];
                        for(auto x : adj[i])if(!vis[x]){
                                if(deg[x]&1)continue;
                                ans = min(ans,va + disg[x]);
                        }
                }
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
