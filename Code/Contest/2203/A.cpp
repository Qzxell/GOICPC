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
	ll s,m;
	cin >> s >> m;
	vi v;
	forn(i,62)if((m>>i)&1)
		v.push_back(i);
	reverse(all(v));
	vl uwu;
	ll mx = 0;
	forn(i,sz(v)){
		ll pot = (1ll<<v[i]);
		ll cnt = s/pot;
		uwu.push_back(cnt);
		mx = max(mx,cnt);
		s -= cnt*1ll*pot;
	}
	if(s > 0){
		cout << -1 << '\n';
		return;
	}
	ll lo = 0 , lf = mx, mid;
	auto f = [&](ll mi)->bool{
		ll acu = 0;
		vl cur = uwu;
		forn(i,sz(v)){
			ll pot = (1ll<<v[i]);
			cur[i] += acu/pot;
			acu %= pot;

			ll sob = max<ll>(cur[i] - mi,0);
			acu += sob*(1ll<<v[i]);
		}
		return acu == 0;
	};
	while(lf-  lo > 1){
		mid = (lo+lf)/2;
		if(f(mid)) lf = mid;
		else lo = mid;
	}
	cout << lf << '\n';


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

