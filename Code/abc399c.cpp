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

const int N = 2e5 + 1;
vi vis(N,0);
vi adj[N];
int cic = 0;

int dfs(int r,int p){
        vis[r] = 1;
        for(auto x : adj[r])if(x != p){
                if(vis[x] == 1){
                        cic++;
                        continue;
                }
                if(vis[x]==0)dfs(x,r);
        }
        vis[r] = 2;
        return vis[r];
}

void so(int test){
        int n,m;
        cin >> n >> m;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        f(i,1,n+1){
                if(vis[i] == 0)int wa = dfs(i,-1);
        }
        cout << cic;
	
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
