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
	int n;
	cin >> n;
	vector<vi> T(n);
	vector<vi> T_(n);
	vi deg(n,0);
	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		T[u].push_back(v);
		T[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	vi vis(n,0);
	int ans = 1;
	forn(i,n-1){
		if(deg[i] == 3){
			for(auto x : T[i])if(deg[x] == 3)
				ans = 2;
		}
	}

	queue<int> qu;
	auto bfs = [&](int nod){
		qu.push(nod);
		vis[nod] = 1;
		while(!qu.empty()){
			int fr = qu.front();qu.pop();
			for(auto x : T[fr])if(deg[x] >= 4 and !vis[x]){
				T_[fr].push_back(x);
				T_[x].push_back(fr);
				qu.push(x);
				vis[x] = 1;
			}
		}
	};
	queue<ii> qu1;
	int ul = -1;
	auto bfs1 = [&](int nod)->int{
		qu1.push({nod,1});
		vis[nod] = 1;
		int mx = 1;
		while(!qu1.empty()){
			auto [fr,dis] = qu1.front();qu1.pop();
			mx = max(mx,dis);
			ul = fr;
			for(auto x : T_[fr])if(!vis[x]){
				qu1.push({x,dis+1});
				vis[x] = 1;
			}
			for(auto x : T[fr])if(deg[x] == 3){
				mx = max(mx,dis+1);
			}

		}
		return mx;
	};
	auto diametro = [&](int nod)->int{
		int ans = 1;
		ul = -1;
		ans = max(bfs1(nod),ans);

		ans = max(bfs1(ul),ans);
		return ans;
	};
	forn(i,n)if(deg[i] >= 4)
		bfs(i);
	forn(i,n)
		vis[i] = 0;
	forn(i,n)if(deg[i] >= 4)
		ans = max(ans,diametro(i));
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

