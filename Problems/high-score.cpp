#include <bits/stdc++.h>

using namespace std;

using ii = pair<long long,int>;
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

const int N = 2505;
vii G[N];//G[i] = {v,w}

vector<bool> stac(N,0);
vector<bool> vis(N,0);
vi papa(N,0);
vector<ll> dp(N,LLONG_MIN);
vector<bool> cic(N,0);
 
vector<vi> G_ma(N,vi(N));

ll ad(ll a, ll b){
        if(max(a,b) == LLONG_MAX)return max(a,b);
        return a + b;
}

void dfs(int nod,int pat){
        stac[nod] = 1;
        papa[nod] = pat;
        vis[nod] = 1;
        for(auto [x,w] : G[nod]){
                if(vis[x]){
                        if(stac[x]){
                                int cur = nod;
                                ll acu = G_ma[nod][x];
                                while(cur != x){
                                        acu += G_ma[papa[cur]][cur];
                                        cur = papa[cur];
                                }
                                if(acu > 0){
                                        cur = nod;
                                        while(cur != x){
                                                cic[cur] = 1;
                                                cur = papa[cur];
                                        }
                                        cic[cur] = 1;
                                }
                        }
                }else{
                        dfs(x,nod);
                }
        }
        stac[nod] = 0;
}

void so(int test){
        int n,m;
        cin >> n >> m;
        f(i,0,m){
                int u,v,w;
                cin >> u >> v >> w;
                G_ma[u][v] = w;
                G[u].pb({v,w});
        }
        dfs(1,-1);
        priority_queue<ii> pq;
        vector<bool> vis_(n+1,0);
        dp[1] = 0;
        pq.push({dp[1],1});
        f(i,1,n+1)cout << cic[i] << ' ';
        cout << ln;
        return;
        while(!pq.empty()){
                ii fr = pq.top();pq.pop();
                ll cur_d =fr.fi, nod = fr.se;
                if(cur_d < dp[nod])continue;
                for(auto [to,wei] : G[nod]){
                        ll val = ad(cur_d,wei);
                        val = (cic[to] or cic[nod] ? LLONG_MAX : val);
                        if(val > dp[to]){
                                dp[to] = val;
                                pq.push({dp[to],to});
                        }
                }
        }
        if(dp[n] == LLONG_MAX){
                cout << -1 << ln;
                return;
        }
        cout << dp[n] << ln;
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
