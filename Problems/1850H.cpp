#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

const int N = 2e5 + 5;
vector<ii> G[N];

void so(int test){
	int n,m;
	cin >> n >> m;
	forn(i,n)G[i].clear();
	forn(i,m){
		ll u,v,d;
		cin >> u >> v >> d;
		u--;v--;
		if(d < 0)swap(u,v);
		d = abs(d);
		G[v].push_back({u,d});
		G[u].push_back({v,-d});
	}
	queue<int> qu;
	vl dis(n+1,0);
	vi vis(n+1,0);

	auto bfs = [&](int nod)->bool{
		qu.push(nod);
		vis[nod] = 1;
		dis[nod] = 0;
		while(!qu.empty()){
			int fr = qu.front();qu.pop();
			for(auto [to,w] : G[fr]){
				if(vis[to]){
					if(dis[to] != dis[fr] +w)
						return false;
				}else{
					dis[to] = dis[fr] + w;
					vis[to] = 1;
					qu.push(to);
				}
			}
		}
		return true;
	};
	forn(i,n)if(vis[i] == 0 && !bfs(i)){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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

