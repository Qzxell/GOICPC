#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 2e5 + 5;
vector<tuple<int,int>> G[N];
vector<tuple<int,int>> edg;
int pes[N];
bool vis[N][32];
bool vivo[N];//edges alive?
int n,m;

bool f(int b){
	queue<int> qu;
	qu.push(0);
	vis[0][b] = 1;
	int nod = 0;
	vector<bool> used(m,0);
	//cout << " b - nod ---------------\n ";
	while(!qu.empty()){
		int fr = qu.front();qu.pop();
		nod++;
		for(auto [v,id] : G[fr]){
			//cout << v <<  ' ' << pes[id] << '\n';
			if(!vivo[id] or ((pes[id] >> b)&1) == 1)continue;
			used[id] = 1;
			if(!vis[v][b])
				qu.push(v);
			vis[v][b] = 1;
		}
	}
	//cout << b << ' ' << nod << '\n';
	if(nod != n)
		return false;
	forn(i,m)
		vivo[i] &= used[i];
	return true;
}

void so(int test){
	cin >> n >> m;
	//clean
	forn(i,n)G[i].clear();
	forn(i,n) forn(j,32)vis[i][j] = 0;
	forn(i,m) vivo[i] = 1;// edges
	edg.clear();
	//

	forn(i,m){
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;
		G[u].emplace_back(v,i);
		G[v].emplace_back(u,i);
		pes[i] = w;
		edg.emplace_back(u,v);
	}
	int ans = 0;
	for(int b = 30; b >= 0 ;b--)if(!f(b)){
		ans |= (1<<b);
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

