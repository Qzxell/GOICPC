#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
ll w[N];
vector<int> G[N];

int add (int a, int b){
	return (a + 0ll + b)%MOD;
}

int mul (int a, int b){
	return (a *1ll* b)%MOD;
}

int binpow(ll b,ll e){
	ll ret = 1;
	while(e > 0){
		if( e&1){
			ret = ret * b %MOD;
		}
		b = b * b%MOD;
		e >>= 1;
	}
	return ret;
}
int inv_nu(int nu){
	return binpow(nu, MOD - 2);
}

void dfs(int nod,int fa){
	w[nod] = 1;
	for(auto to : G[nod])if(to != fa){
		dfs(to, nod);
		w[nod] += w[to];
	}
}
int fre[N] , cnt[N], crib[N] ,fac[N],inv[N],invfac[N];

void init(){
	fac[0] = 1;
	inv[1] = 1;
	invfac[0] = 1;
	forsn(i,1,N){
		fac[i] = fac[i-1]*1ll*i%MOD;
	}
	forsn(i,2,N){
		inv[i] = (MOD - (MOD/i)*1ll*inv[MOD%i]%MOD)%MOD;
	}
	forsn(i,1,N){
		invfac[i] = invfac[i-1]*1ll*inv[i]%MOD;
	}
}

int C(int n,int k){
	if(n == 0)return 0;
	if(k <= 0 or k > n)return 0;
	return fac[n]*1ll* invfac[n-k] %MOD *invfac[k]%MOD;
}

void so(int test){
	int n,k;
	cin >> n >> k;

	forn(i,n)G[i].clear();
	vector<pair<int,int>> edg;

	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		edg.emplace_back(u,v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if( k &1){
		cout << 1 << '\n';
		return;
	}

	dfs(0,-1);
	ll ans = 0;

	for(auto [u,v] : edg){
		if(w[u] > w[v])
			swap(u,v);
		ans = add(ans,mul(2,mul(C(w[u],k/2) , C(n - w[u], k/2))));
	}
	cout << ans << ' ';

	ans = 16;
	ans = mul(2,ans);
	ans = mul(ans, inv_nu( mul(n,n-1) ));
	cout << ans << '\n';
	//cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	//cin >> tt;
	init();
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

