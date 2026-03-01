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

const int MOD = 1e9 + 7;

ll binpow(int b,int e){
	ll ret = 1;
	while( e > 0){
		if( e&1){
			ret = ret *1ll* b %MOD;
		}
		b = b *1ll* b%MOD;
		e >>= 1;
	}
	return ret;
}

ll inv(int nu){
	return binpow(nu,MOD-2);
}

void so(int test){
	ll n;
	cin >> n;
	vii div;
	forsn(i,2,sqrt(n) +  3){
		int co = 0;
		while(n % i == 0){
			co++;
			n /= i;
		}
		if(co > 0){
			div.push_back({i,co});
		}
	}
	ll ans = 1;
	if(n > 1){
		div.push_back({n,1});
	}
	for(auto [di,co] : div){
		ans = ans*((binpow(di,co+1) - 1 + MOD) % MOD)% MOD * inv(di-1) % MOD;
	}
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

