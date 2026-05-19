#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int MOD = 998244353;

ll binpow(ll b,ll e){
	ll ret = 1;
	while(e > 0){
		if( e&1){
			ret = ret * b%MOD;
		}
		b = b * b%MOD;
		e >>= 1;
	}
	return ret;
}
int inv(int nu){
	return binpow(nu,MOD - 2);
}

void so(int test){
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];

	vector<pair<int,int>> alp;

	forn(i,n)forsn(j,i+1,n) if( i!= j)
		alp.push_back({a[i],a[j]});
	sort(all(alp), [&](auto u, auto v){
			return u.first*1ll * v.second > v.first*1ll*u.second;
			});
	ll ans = 0;
	auto f = [&](int mid, int l , int m)->bool{
		if(mid == -1)return true;
		if(mid == sz(alp))return false;
		auto [nu,de] = alp[mid];
		return nu*1ll*m > l*1ll*de;
	};
	forn(i,n)forn(j,n) if( i!= j){
		int l,m;
		l = b[i], m = b[j];
		int lo = -1, lf = sz(alp), mid;
		while(lf - lo > 1){
			mid = (lo+lf)/2;
			if(f(mid,l , m))lo = mid;
			else lf = mid;
		}
		ans += lo + 1;
	}
	ans %= MOD;
	ll uwu = inv(n)*1ll*inv(n-1)%MOD;
	cout << ans * 1ll*uwu%MOD << '\n';
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

