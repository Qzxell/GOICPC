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

const int N =1e5 + 5;
vi G[N];
vector<bool> vis(N,0);

void so(int test){
        int n,m;
        cin >> n >> m;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                G[u].pb(v);
                G[v].pb(u);
        }
        queue<int> qu;
        vector<vi> ans;
        auto bfs = [&](int nod){
                qu.push(nod);
                vi PU;
                vis[nod] = 1;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        PU.pb(fr);
                        for(auto x: G[fr])if(!vis[x]){
                                qu.push(x);
                                vis[x] = 1;
                        }
                }
                ans.pb(PU);
        };
        f(i,1,n+1)if(!vis[i])bfs(i);
        cout << sz(ans) << ln;
        f(i,0,sz(ans)){
                cout << sz(ans[i]) << ' ';
                sort(all(ans[i]));
                for(auto x : ans[i])cout << x << ' ';
                cout << ln;
        }

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
