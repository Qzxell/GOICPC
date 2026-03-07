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

void so(int test){
	int n;
	cin >> n;
	vl a(n),b(n);
	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];
	vl uwu(n,0);
	ll prev = n;
	ll au = n - 2;
	const int MOD = 998244353;
	forn(i,n/2 + (n&1)){
		uwu[i] = prev%MOD;
		prev += au;
		au -= 2;
	}
	forsn(i,n/2 + (n&1),n){
		uwu[i] = uwu[n-i-1];
	}
	forn(i,n){
		uwu[i] *= a[i];
		uwu[i] %= MOD;
	}

	sort(all(uwu));
	sort(rall(b));
	ll ans = 0;
	forn(i,n){
		ans += uwu[i]*b[i]%MOD;
		ans %= MOD;
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

