#include <bits/stdc++.h>

using namespace std;

using ii = pair<long long,long long>;
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
        int n,m,x;
        cin >> n>>m >> x;
        vii adj[2*n + 4];
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                adj[u].pb({v,1});
                adj[v+n].pb({u+n,1});
                adj[v].pb({v+n,x});
                adj[v+n].pb({v,x});
                adj[u].pb({u+n,x});
                adj[u+n].pb({u,x});
        }
        priority_queue<ii,vii,greater<>> pq;
        ll ga = (1ll<<61);
        vector<ll> dist(2*n + 4,ga);
        dist[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
                auto [d,u] = pq.top();pq.pop();
                if(d > dist[u])continue;

                for(auto [v,w]: adj[u]){
                        if(dist[u] + w < dist[v]){
                                dist[v] = dist[u] + w;
                                pq.push({dist[v],v});
                        }
                }

        }
        cout << min(dist[n],dist[2*n]) << ln;
        
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
