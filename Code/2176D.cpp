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


const int mod = 998244353;
const int N = 2e5 + 5;
const ll MAX = 1e18;
vii T[N];
vii edg(N);
int n,m;
ll a[N];
ll dp[N];
vl dp2[N];
bool vis[N];

ll add(ll a,ll b){
	return (a+b)%mod;
}
ll dfs(int id){
	if(vis[id])return dp[id];
	auto [u,v] = edg[id];
	if(a[u] > MAX - a[v])return dp[id] = 1;

	vis[id] = 1;
	ll &ret = dp[id];
	ret = 1;

	int lo = -1 , lf = sz(T[v]), mid;
	while(lf - lo > 1){
		mid = (lo+lf)/2;
		if(a[T[v][mid].fi] >= a[u]+a[v])lf = mid;
		else lo = mid;
	}
	int ind1 = lf;
	if(ind1 < sz(T[v]) && a[u] + a[v] == a[T[v][ind1].fi]){
		if(dp2[v][ind1] != -1){
			ret = add(ret, dp2[v][ind1]);
		}else{
			int ind = ind1;
			ll &n_d = dp2[v][ind1];
			n_d = 0;
			while(ind < sz(T[v])){
				auto [to,i] = T[v][ind];
				if(a[to] != a[u] + a[v])break;
				n_d = add(n_d,dfs(i));
				ind++;
			}
			ret = add(ret,n_d);
		}
	}
	return ret;
}

void so(int test){
	cin >> n >> m;
	forn(i,n)
		T[i].clear();
	forn(i,m)
		vis[i] = 0;
	forn(i,n)
		cin >> a[i];
	forn(i,m){
		int u,v;
		cin >> u >> v;
		u--;v--;
		edg[i] = {u,v};
		T[u].pb({v,i});
	}
	ll ans = 0;
	forn(i,n){
		sort(all(T[i]),[](ii x, ii y){
			return a[x.fi] < a[y.fi];});
		dp2[i].assign(sz(T[i]),-1);
	}

	forn(i,m)
		ans = add(ans,dfs(i));
	//debug
	forn(i,m){
		//cout << dfs(i) << ' ';
	}
	//cout << '\n';
	//debug
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

