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

int n,k,x,y;
const int N = 2e5 + 5;
//indx - 1
vi G[N];
int val[N];
int dis[N];
ll dp[N];
int pes[N];

void dfs(int nod , int p){
	dp[nod] = 1;
	pes[nod] = val[nod];
	for(auto x : G[nod]) if( x != p){
		dis[x] = dis[nod] + 1;
		dfs(x , nod);
		pes[nod] += pes[x];
		if(pes[x] > 0)
			dp[nod] += dp[x];
	}
}

void clean(){
	forn(i,n+1)val[i] = 0;
	forn(i,n+1) 
		G[i].clear();
	dis[x] = 0;
}

void so(int test){
	int u,v;
	cin >> n >> k;
	cin >> x >> y;
	clean();


	forn(i,k){
		cin >> u;
		val[u] = 1;
	}
	forn(i,n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	val[y] = 1;
	dfs(x,-1);

	ll ans = 2*dp[x] -2 - dis[y];
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

