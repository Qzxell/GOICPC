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

const int N = 2e5 + 5;
vii G[N];
vii edg(N);
int es_puente[N];

int in_edg[N];
int ou_edg[N];

int color[N];
int color_[N];

int papi[N];
int dp[N];
vii puentes;

int fun(int nod,int pat){
        int ret = ou_edg[nod] - in_edg[nod];
        color_[nod] = 1;
        for(auto [x,id] : G[nod])if(x != pat){
                if(!color_[x]){
                        ret += fun(x,nod);
                }
        }
        color_[nod] = 2;
        return dp[nod] = ret;
}

void dfs(int nod,int pat){
        color[nod] = 1;
        papi[nod] = pat;
        for(auto [x,id] : G[nod])if(x != pat){
                if(!color[x]){
                        edg[id] = {nod,x};
                        dfs(x,nod);
                }
                if(color[x] == 1){
                        edg[id] = {nod,x};
                        in_edg[x]++;
                        ou_edg[nod]++;
                }
        }
        color[nod] = 2;
}

void so(int test){
        int n,m;
        cin >> n >> m;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                G[u].pb({v,i});
                G[v].pb({u,i});
                edg[i] = {u,v};
        }
        dfs(1,-1);
        fun(1,-1);
        f(i,2,n+1){
                if(dp[i] == 0){
                        cout << "IMPOSSIBLE" << '\n';
                        return;
                }
        }
        f(i,0,m){
                auto [a,b] = edg[i];
                cout << a << ' ' << b << '\n';
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

