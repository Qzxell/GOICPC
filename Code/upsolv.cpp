#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ll long long

const int N = 2e5 + 5;

int n;
int nc;
int c[N];
bool vis[N];
vector<int> G[2][N];

void dfs(int id, int u, vector<int> &z) {
	vis[u] = 1;
	for (int v : G[id][u]) {
		if (vis[v]) continue;
		dfs(id, v, z);
	}
	z.push_back(u);
}

void so(){
	int k,q;
	cin >> n >> k >> q;
	nc = 0;
	fill(vis, vis + n, 0);
	for(int i = 0; i < n; i++) {
		G[0][i].clear();
		G[1][i].clear();
	}
	vector<vector<int>> m(k,vector<int>(n));
	vector<vector<int>> led(k,vector<int>(n));
	vector<vector<int>> in(k,vector<int>(n));
	vector<vector<ll>> ps(k,vector<ll>(n));
	for (int i = 0; i < k; i++) {
		for(int j = 0 ; j < n ;j++){
			cin >> m[i][j];
			m[i][j]--;
		}
		for(int j = 0 ; j < n - 1 ;j++){
			int u = m[i][j];
			int v = m[i][j + 1];
			G[0][u].push_back(v);
			G[1][v].push_back(u);
		}
	}

	vector<int> order;
	for (int i = 0; i < n; i++) if (!vis[i])
		dfs(0, i, order);
	reverse(all(order));

	fill(vis, vis + n, 0);

	for (int u : order) {
		if (vis[u]) continue;
		vector<int> comp;
		dfs(1, u, comp);
		for (int v : comp) c[v] = nc;
		nc++;
	}
	for (int i = 0; i < k; i++) {
		for(int j = 0 ; j < n ;j++){
			int u =  m[i][j];
			led[i][c[u]] = j;
		}
		for(int j = n-1 ; j >= 0 ;j--){
			int u =  m[i][j];
			in[i][c[u]] = j;
		}
		int cur = -1;
		int ind = -1;
		for(int j = 0 ; j < n ;j++){
			int u =  m[i][j];
			ll va = 0;
			if(j == led[i][c[u]]){
				int lon = led[i][c[u]] - in[i][c[u]] + 1;
				va = lon*1ll*(lon-1)/2;
			}
			ps[i][j] = (j-1 >= 0 ? ps[i][j-1] : 0) + va;
		}
	}
	ll prev = 0;
	auto query = [&](int l,int r,int id)->ll{
		if (l > r) swap(l, r);
		int u = m[id][r];
		int v = m[id][l];
		if (c[u] == c[v]) {
			ll len = r - l + 1;
			return len * 1ll * (len - 1) / 2;
		}
		ll dif = ps[id][r] - (l -1 >= 0 ? ps[id][l-1] : 0);
		//int d1 = r - in[id][c[u]] + 1;
		int d2 = led[id][c[v]] - in[id][c[v]] + 1;
		int d3 = led[id][c[v]] - l + 1;
		//ll v1 = d1*1ll*(d1-1)/2;
		ll v2 = d2*1ll*(d2-1)/2;
		ll v3 = d3*1ll*(d3-1)/2;
		//dif += v1;
		dif -= v2;
		dif += v3;
		if (r < led[id][c[u]]) {
			int d1 = r - in[id][c[u]] + 1;
			ll v1 = d1 * 1ll * (d1 - 1) / 2;
			dif += v1;
		}
		return dif; 
	};
	for(int i = 0 ; i < q; i++){
		int id,l,r;
		cin >> id >> l >> r;
		id = (id + prev) % k;
		l = (l + prev) % n;
		r = (r + prev) % n;
		prev = query(l,r,id);
		cout << prev << '\n';
	}

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt--)
		so();
	return 0;
}

