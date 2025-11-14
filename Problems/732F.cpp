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

const int N = 4e5 + 5;
vector<vii> G(N);
vector<vii> tre(N);
vii edg(N);
vi es_puente(N,0);

vi in_edg(N,0);
vi ou_edg(N,0);

vi color(N,0);
vi color2(N,0);
vi color_(N,0);
vi group(N,0);
vi peso(N,0);

vi papi(N,0);
vi par_id(N,-1);
vi dp(N,0);
vii puentes;

int fun(int nod,int pat){
        int ret = ou_edg[nod] - in_edg[nod];
        color_[nod] = 1;
        for(auto [x,_] : G[nod])if(x != pat){
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
                        par_id[x] = id;
                        dfs(x,nod);
                }
                if(color[x] == 1){
                        in_edg[x]++;
                        ou_edg[nod]++;
                }
        }
        color[nod] = 2;
}

void dfs2(int nod,int pat,int col){
        color2[nod] = 1;
        group[nod] = col;
        peso[col]++;
        for(auto [x,id] : G[nod])if(x != pat){
                if(es_puente[id])continue;
                if(color2[x] != 2)edg[id] = {nod,x};
                if(!color2[x]){
                        dfs2(x,nod,col);
                        continue;
                }
        }
        color2[nod] = 2;
}

void dfs3(int nod,int pat){
        for(auto [x,id] : tre[nod])if(x != pat){
                auto &[u,v] = edg[id];
                if(nod == group[u]){
                        swap(u,v);
                }
                dfs3(x,nod);
        }
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
        f(i,1,n+1)sort(all(G[i]));
        dfs(1,-1);
        fun(1,-1);
        f(i,2,n+1){
                if(dp[i] == 0){
                        int id = par_id[i];
                        //assert(id != -1);
                        es_puente[id] = 1;
                        puentes.pb({i,id});
                }
        }
        int uwu = 1;
        f(i,1,n+1)if(!color2[i]){
                dfs2(i,-1,uwu++);
        }
        for(auto [x,id] : puentes){
                int gru_cur = group[x];
                int gru_papi = group[papi[x]];
                tre[gru_cur].pb({gru_papi,id});
                tre[gru_papi].pb({gru_cur,id});
        }
        int nod_mw = -1;
        int ans = -1;
        f(i,1,uwu){
                if(ans < peso[i]){
                        ans = peso[i];
                        nod_mw = i;
                }
        }
        dfs3(nod_mw,-1);

        cout << ans << ln;
        f(i,0,m){
                auto [a,b] = edg[i];
                cout << a << ' ' << b << ln;
        }

        //cout << "tree ------------------" << ln;

        //for(int i = 1; i < uwu;i++){
                //cout << '\t' << i << ln;
                //for(auto [x,id] : tre[i]){
                        //cout << x << ' ';
                //}
                //cout << ln;
        //}

        //cout << "     ";
        //f(i,1,n+1)cout << i << ' ';
        //cout << ln;
        //cout << "in : ";
        //f(i,1,n+1)cout << in_edg[i] << ' ';
        //cout << ln;
        //cout << "ou : ";
        //f(i,1,n+1)cout << ou_edg[i] << ' ';
        //cout << ln;
        //cout << "     ";
        //f(i,1,n+1){
                //cout << dp[i] << ' ';
        //}
        //cout << ln;
        //cout << "col  ";
        //f(i,1,n+1){
                //cout << group[i] << ' ';
        //}
        //cout << ln;
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

