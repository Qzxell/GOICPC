#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

vi des(int n){
	vi ret;
	forsn(i,2,sqrt(n) + 2){
		int co = 0;
		while( n % i == 0){
			co++;
			n /= i;
		}
		if(co)
			ret.emplace_back(i);
	}
	if(n != 1)
			ret.emplace_back(n);
	return ret;
}

void so(int test){
	ll a,b,n;
	cin >> a >> b >> n;
	vi primes = des(n);
	int tot = sz(primes);

	ll ans = 0;

	forsn(i,1,(1<<tot)){
		int sig = 0;
		ll c = 1;
		forn(j,tot) if( (i >>j)&1){
			sig++;
			c *= primes[j];
		}
		ans += (sig&1 ? 1 : -1 )* (b/c - (a-1)/c);
	}
	//cout << ans << '\n';
	cout << "Case #" << test << ": " <<  b - a + 1 - ans << '\n';
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

