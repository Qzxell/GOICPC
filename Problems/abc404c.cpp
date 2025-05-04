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
        if(n != m ){
                cout << "No" ;
                return;
        }
        vi vis(n+1,0);
        vi adj[n+1];

        f(i,0,m){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        queue<int> qu;
        auto dfs= [&](int u){
                vis[u]= 1;
                qu.push(u);
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        vis[fr] = 1;
                        for(auto v : adj[fr])if(!vis[v]){
                                qu.push(v);
                        }
                }
        };
        f(i,1,n+1){
                if(sz(adj[i]) != 2){
                        cout << "No";
                        return;
                }
        }
        int c= 0;
        f(i,1,n+1)if(!vis[i]){
                dfs(i);
                c++;
        }
        if(c > 1){
                cout << "No";
                return;
        }
        cout << "Yes";
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
