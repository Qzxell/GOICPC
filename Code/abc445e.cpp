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

const int N = 1e7 + 5;
const int mod = 998244353;
bitset<N> crib;
int pri[N];
vi primos;

ll mul(ll a, ll b){
	return (a%mod * b%mod )%mod;
}

ll binpow(ll b,ll e){
	ll ret = 1;
	while(e > 0){
		if( e&1){
			ret = ret * b %mod;
		}
		b = b * b %mod;
		e >>= 1;
	}
	return ret;
}

ll inv(ll nu){
	return binpow(nu,mod-2);
}

void init(){
	forsn(i,2,N){
		if(!crib[i]){
			primos.pb(i);
			pri[i] = i;
		}
		for(auto x : primos){
			if(x*1ll*i < N){
				crib[x*i] = 1;
				pri[x*i] = x;
			}else
				break;
			if(i % x == 0)break;
		}
	}
}

void so(int test){
	int n;
	cin >> n;
	map<int,vii> m;
	forn(i,n){
		int x;
		cin >> x;
		int prev_pr = -1;
		int co = 0;
		while(x > 1){
			int mi_pr = pri[x];
			if(prev_pr != mi_pr){
				if(prev_pr != -1)
					m[prev_pr].push_back({co,i});
				prev_pr = mi_pr;
				co = 1;
			}else{
				co++;
			}

			x /= mi_pr;
		}
		if(prev_pr != -1)
			m[prev_pr].push_back({co,i});
	}
	vl ans(n+1,1);
	for(auto [x,vec] : m){
		vec.push_back({0,-1});
		sort(rall(vec));
		auto [ex,ind] = vec[0];
		auto [ex_1,ind_1] = vec[1];
		ans[0] = mul(ans[0] , binpow(x,ex));
		ans[ind] = mul(ans[ind] , inv(binpow(x,ex)));
		ans[ind+1] = mul(ans[ind+1] , binpow(x,ex));

		ans[ind] = mul(ans[ind] , binpow(x,ex_1));
		ans[ind+1] = mul(ans[ind+1] , inv(binpow(x,ex_1)));
	}
	forsn(i,1,n)
		ans[i] = mul(ans[i],ans[i-1]);
	forn(i,n)
		cout << ans[i] << ' ';
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	init();
        int test = 1;
	cin >> tt;
        while(tt--) so(test++);
        return 0;
}

