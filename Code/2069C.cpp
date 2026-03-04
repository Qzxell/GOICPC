#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int mod = 998244353;

ll fpow(ll base, int exp){
	ll ret = 1;
	while(exp){
		if(exp&1) ret = (ret *base)%mod;
		exp >>= 1;
		base = (base*base)%mod;
	}
	return ret;
}

void so(int test){
	//cout << "===================Test " << test << " =========="<< ln;
	int n;
	cin >> n;
	vi v(n);
	vi ps(n+1,0);// index -> 1
	vi un;
	int ul = -1;
	f(i,0,n){
		cin >> v[i];
		ps[i+1] = ps[i] + (v[i] == 2 ? 1 : 0);
		if(v[i] == 1){
			if(ul != -1){
				un.pb(ps[i+1] - ps[ul+1]);
			}
			ul = i;
		}
	}
	if(ul == -1){
		cout << 0 << ln;
		return;
	}
	vi was;
	f(i,0,n)if(v[i] == 3){
		int dos = ps[i+1] - ps[ul+1];
		was.pb(dos);
	}
	ll ans = 0;
	int le = sz(was) - 1;
	ll aux = 0;//anterior
	int au = 0;//aumento
	int dis = 0;//longitud
	int ad = 0;
	for(int i = sz(un)-1; i >= -1;i--){
		aux = ((aux + dis)*1ll*fpow(2,au) - dis)%mod;
		while(le >=0 and was[le] + ad > 0){
			aux = (aux+ fpow(2,was[le]+ad) - 1)%mod;
			le--;
			dis++;
		}
		ans = (ans + aux)%mod;
 		if(i >= 0)au = un[i],ad += un[i];
	}
	cout << ans << ln;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
