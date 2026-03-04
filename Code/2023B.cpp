#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using ll = long long;
using vii = vector<ii>  ;
using vll = vector<ll>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n;
	cin >> n;
	vi pri(n+1);
	vi b(n+1);
	vll ps(n+1,0);
	f(i,1,n+1)cin >> pri[i];
	f(i,1,n+1)cin >> b[i];
	f(i,1,n+1)ps[i] = ps[i-1] + pri[i];
	vii adj[n+1];// to,weight
	f(i,1,n+1){
		adj[i].pb({i-1,0});
		adj[i].pb({b[i],pri[i]});
	}
	ll ma = 1e17;
	vll dis(n+1,ma);
	dis[1] = 0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0ll,1});

	while(!pq.empty()){
		auto [cur_d,cur_node] = pq.top();
		pq.pop();
		if( cur_d > dis[cur_node])continue;

		for (auto [to,wei] : adj[cur_node]){
			ll new_dis = cur_d + wei;
			if( new_dis < dis[to]){
				dis[to] = new_dis;
				pq.push({new_dis,to});
			}
		}
	}
	ll ans = 0;
	f(i,1,n+1){
		if(dis[i] == ma)continue;
		ans = max(ans,ps[i] - dis[i]);
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
