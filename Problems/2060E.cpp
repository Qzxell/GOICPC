
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
        int n,m1,m2;
        cin >> n >> m1 >> m2;
        vi F[n+1];
        vi G[n+1];
        f(i,0,m1){
                int u,v;
                cin >> u >> v;
                F[u].pb(v);
                F[v].pb(u);
        }
        f(i,0,m2){
                int u,v;
                cin >> u >> v;
                G[u].pb(v);
                G[v].pb(u);
        }
        queue<int> qu;
        vi vis(n+1,0);
        vi paint(n+1,0);// pait[i] := leder of i
        auto bfs_G = [&] (int leder){
                qu.push(leder);
                vis[leder] = 1;
                paint[leder] = leder;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        for(auto to : G[fr])if(!vis[to]){
                                qu.push(to);
                                paint[to] = leder;
                                vis[fr] = 1;
                        }
                }
        };
        vi leder_s;
        f(i,1,n+1){
                if(!vis[i]){
                        leder_s.pb(i);
                        bfs_G(i);
                }
        }

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
