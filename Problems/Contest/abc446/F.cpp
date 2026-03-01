#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n,m;
	cin >> n >> m;
	vecto<vi> G(n),G_(n);
	forn(i,m){
		int u,v;
		cin >> u >> v;
		u--;v--;
		G[u].push_back(v);
		G_[v].push_back(u);
	}
	vi reach(n,0);
	auto dfs = [&](auto && self, int nod)->void{
		vis[nod] = 1;
		for(auto x : G[nod]) {
			self(self, x);
		}
	};
	dfs(dfs,0);
	bool ok = 1;
	forn(i,n) ok &= reach[i];
	if(!ok){
		cout << -1 << '\n';
		return;
	}

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

