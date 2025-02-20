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


void so(int test){
	int n;
	cin >> n;
	vi v(n);
	f(i,0,n) cin >> v[i];
	vector<pair<ll,int>> wasa;
	int i = 0;
	while(i < n){
		bool pos = (v[i] > 0 ? 1 : 0);
		ll cur = 0;
		while(i < n and (v[i] > 0 ? 1 : 0) == pos)cur += (1ll)*abs(v[i]),i++;
		wasa.pb({cur,pos});
	}
	int le = sz(wasa);
	if(le == 1){
		cout << wasa[0].fi << ln;
		return;
	}
	ll ans = 0;
	if(wasa[0].se){
		ll cur = wasa[0].fi;
		for(int i = 1;i < le;i+=2)cur += wasa[i].fi;
		ans = cur;
		for(int i = 2;i < le;i+=2){
			cur += wasa[i].fi;
			cur -= wasa[i-1].fi;
			ans = max(ans,cur);
		}
	} else{
		ll cur = 0;
		for(int i = 0;i < le;i+=2)cur += wasa[i].fi;
		ans = max(ans,cur);
		for(int i = 1;i < le;i+=2){
			cur += wasa[i].fi;
			cur -= wasa[i-1].fi;
			ans = max(ans,cur);
		}
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
