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

int n,m;
const int N = 1e5 + 5;
int h[N],p[N];
ii dp[N];
vi T[N];
bool ok = 1;

void dfs(int nod, int fa){
	dp[nod] = {0,p[nod]};
	for(auto x : T[nod]) if(x != fa){
		dfs(x,nod);
		dp[nod].fi += dp[x].fi;
		dp[nod].se += dp[x].se;
	}
	int cur = dp[nod].fi - dp[nod].se;
	if((cur&1) != (h[nod] &1) || cur + 2*dp[nod].se < h[nod] || cur > h[nod]){
		ok = 0;
		return;
	}
	dp[nod].se -= (h[nod] - cur)/2;
	dp[nod].fi += (h[nod] - cur)/2;
}

void so(int test){
	cin >> n >> m;
	forn(i,n){
		T[i].clear();
		cin >> p[i];
	}
	forn(i,n)
		cin >> h[i];
	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	ok = 1;
	dfs(0,-1);
	cout << (ok ? "YES\n" : "NO\n");
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

