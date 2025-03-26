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

const int N = 1e5 + 2;
vi adj[N];
vi vis(N,0);
vi cam(N,0);
int co, fin;

int dfs(int r){
        if(r == fin)return cam[r] = 1;
        vis[r] = 1;
        int ret = 0;
        for(auto x: adj[r])if(!vis[x]){
                vis[x] = 1;
                ret |= dfs(x);
        }
        return cam[r] = ret;
}
void so(int test){
        int n;
        cin >> n;
        f(i,0,n-1){
                int u,v;
                cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
        }
        queue<int> qu;
        int ul = 1;
        auto bfs = [&](int r){
                qu.push(r);
                vis[r] = 1;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        ul = fr;
                        for(auto x : adj[fr])if(!vis[x]){
                                qu.push(x);
                                vis[x] = 1;
                        }
                }
        };
        int ans = 0;
        int ram = 0;
        auto bfs1 = [&](int r){
                qu.push(r);
                vis[r] = 1;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        ul = fr;
                        int c = 0;
                        for(auto x : adj[fr])if(!vis[x])if(!cam[x]){
                                qu.push(x);
                                c++;
                                vis[x] = 1;
                        }
                        if(c == 0 and !cam[fr])ram++;
                }
        };
        co = 1;
        bfs(1);
        fin = ul;
        f(i,0,n+1)vis[i] = 0;
        bfs(fin);
        co = ul;
        f(i,0,n+1)vis[i] = 0;
        swap(co,fin);
        dfs(co);
        f(i,0,n+1)vis[i] = 0;
        f(i,1,n+1)if(cam[i] and !vis[i]){
                bfs1(i);
        }
        cout << 1 + (ram+1)/2 << ln;
        f(i,1,n+1)adj[i].clear();
        f(i,0,n+1)vis[i] = 0;
        f(i,0,n+1)cam[i] = 0;

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
