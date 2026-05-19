#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

const int N = 3e5 + 5;
const int MOD = 1e9 + 7;;
int fre[N] , cnt[N], crib[N] ,fac[N],inv[N],invfac[N];

int add(int a, int b){
	return (a + 0ll + b ) %MOD;
}

int mul(int a, int b){
	return (a * 1ll * b ) %MOD;
}

int binpow(ll b,ll e){
	ll ret = 1;
	while(e > 0){
		if( e&1){
			ret = ret * b % MOD;
		}
		b = b * b %MOD;
		e >>= 1;
	}
	return ret;
}

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
	if(n == 0)return 1;
	if(k <= 0 or k > n)return 1;
	return fac[n]*1ll* invfac[n-k] %MOD *invfac[k]%MOD;
}

int nu_inv(int nu){
	return binpow(nu,MOD - 2);
}

void so(int test){
	int n,k;
	cin >> n >> k;
	int tot = n;
	forn(i,k){
		int r,c;
		cin >> r >> c;
		tot -= 1 + (r != c);
	}
	int ans = 0;
	forn(x,tot + 1){
		int yy = tot - x;
		if(yy&1)continue;
		int va = mul( mul(C(tot,x) , fac[yy] ), invfac[yy/2]);
		//cout << va << ' '  ;
		ans = add(ans , va );
	}
	//cout << '\n';
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
	init();
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

