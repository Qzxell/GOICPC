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

const int N = 2e5 + 5;
int c[N];
int dis[N];

ll dp[N];
int dp_m[N];
ll dp2[N];
ll w[N];

vi G[N];
vi suf[N];
vi pref[N];

void dfs( int nod , int pat){
	auto it = find(all(G[nod]), pat);
	if (it != G[nod].end()) G[nod].erase(it);
	w[nod] = c[nod];
	dp[nod] = 0;
	dp_m[nod] = 0;
	pref[nod].resize(sz(G[nod]) + 1, -1);
	suf[nod].resize(sz(G[nod]) + 2, -1);
	for(auto x : G[nod]) if( x != pat){
		dis[x] = dis[nod] + 1;
		dfs(x,nod);
		dp_m[nod] = max(dp_m[nod], dp_m[x] + 1);
		w[nod] += w[x];
		dp[nod] += dp[x] + w[x];
	}
	forsn(i,1,sz(G[nod]) + 1){
		int x = G[nod][i-1];
		pref[nod][i] = max(pref[nod][i-1],dp_m[x] + 1);
	}
	for(int i = sz(G[nod]) ; i >= 1; i--){
		int x = G[nod][i-1];
		suf[nod][i] = max(suf[nod][i+1],dp_m[x] + 1);
	}
}


void dfs2( int nod , int pat){
	dp2[nod] = 0;
	for(auto x : G[nod]) if( x != pat){
		dfs2(x,nod);
		dp2[nod] = max(dp2[x],dp2[nod]);
	}
	forsn(i,1,sz(G[nod]) + 1){
		int x = G[nod][i-1];
		int pf,sf,mx;
		pf = pref[nod][i-1];
		sf = suf[nod][i+1];
		mx = max({pf,sf});
		if(mx == -1)continue;
		dp2[nod] = max((mx)*1ll*w[x],dp2[nod]);
	}
}

void so(int test){
	int n;
	cin >> n;
	forn(i,n) cin >> c[i];
	forn(i,n)G[i].clear();
	forn(i,n)suf[i].clear();
	forn(i,n)pref[i].clear();
	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dis[0] = 0;
	dfs(0,-1);
	dfs2(0,-1);
	//cout << "=====================\n";
	//forn(i,n){
		//cout << dp[i] << ' ';
	//}
	//cout << '\n';
	//forn(i,n){
		//cout << dp2[i] << ' ';
	//}
	//cout << '\n';
	forn(i,n){
		cout << dp[i] + dp2[i] << ' ';
	}
	cout << '\n';
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

