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
#define pb push_back
#define imp(v) {for(auto x:v)cout<<x<<' ';cout<<'\n';}


void so(int test){
	int n;
	cin >> n;
	vector<vi> T(n);
	vi deg(n,0);
	vi color(n,0);
	vi dis(n,0);
	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		T[u].pb(v);
		T[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	queue<int> qu;// nod, dis
	auto bfs = [&](int nod,int col){
		qu.push(nod);
		color[nod] = col + 1; // !!!
		int ul;
		dis[nod] = 1;

		while(!qu.empty()){
			int fr = qu.front();qu.pop();
			ul = fr;
			if(col == 0 && deg[fr] == 3)
				continue;
			for(auto x : T[fr]){
				if(col == 0){
					if(color[x] == 0 && deg[x] >= 4){
						qu.push(x);
						color[x] = 1;
					}
					if(deg[x] == 3){
						qu.push(x);
						color[x] = 1;
					}
				}
				if(col == 1){
					if(color[x] == 1){
						dis[x] = dis[fr] + 1;
						color[x] = 2;
						qu.push(x);
					}
				}
			}
		}
		return ul;
	};
	int ans = 1;

	forn(i,n)if(deg[i] == 3){
		if(ans == 2)break;
		for(auto x : T[i])if(deg[x] == 3){
			ans = 2;
			break;
		}
	}
	forn(i,n)if(deg[i] >= 4 && color[i] == 0){
		int ul = bfs(i,0);
		int nd_ma = bfs(ul,1);
		ans = max(ans,dis[nd_ma]);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt = 1;
	cin >> tt;
	int test = 1;
	while(tt--) so(test++);
	return 0;
}

