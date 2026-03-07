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

const int N = 3e5 + 5;
const int MOD = 998244353;
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

ll C(int n,int k){
	if(n == 0)return 0;
	if(k <= 0 or k > n)return 0;
	return fac[n]*1ll* invfac[n-k] %MOD *invfac[k]%MOD;
}
ll add(ll a, ll b){
	return (a%MOD + MOD + b%MOD + MOD)%MOD;
}
ll mul(ll a, ll b){
	return (a%MOD * b%MOD)%MOD;
}
	

void so(int test){
	int n,k;
	cin >> n >> k;
	fill(crib,crib+n+1,0);
	fill(fre,fre+n+1,0);
	fill(cnt,cnt+n+1,0);
	forn(i,n){
		int x;
		cin >> x;
		fre[x]++;
	}
	vi primos;
	forsn(i,2,n+1){
		if(crib[i])continue;
		int con = 0;
		for(int j = i ; j < n+1; j += i){
			con += fre[j];
			crib[j] = 1;
		}
		cnt[i] = con;
		if(con > 0)
			primos.push_back(i);
	}
	ll ans = 0;
	//cout << "===============\n";
	for(auto x : primos){
		//cout << x << ' ' << C(n,k) << ' ' << C(n - cnt[x],k) << '\n';
		//cout << add(C(n,k), -C(n - cnt[x],k)) << '\n';
		ans = add(ans , mul(x,add(C(n,k), -C(n - cnt[x],k))));
	}
	//cout << '\n';
	cout << ans << '\n';
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	init();
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

