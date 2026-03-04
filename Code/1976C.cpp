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
	int n,m;
	cin >> n >> m;
	int tot = n + m + 1;
	vi a(tot);
	vi b(tot);
	vi pa(tot,0); // prefix sum with 1 or 0
	vi pb(tot,0);
	vector<ll> rea(tot+1,0); // 1 or 0 , valor original
	vector<ll> reb(tot+1,0);
	vector<ll> psa(tot+1,0);// prefix sum of a y b
	vector<ll> psb(tot+1,0);
	f(i,0,tot)cin >> a[i];
	f(i,0,tot)cin >> b[i];
	f(i,0,tot){
		if(a[i] > b[i]){
			pa[i] = 1;
			rea[i+1] = a[i];
		} else{
			pb[i] = 1;
			reb[i+1] = b[i];
		}
	}
	f(i,1,tot+1){
		psa[i] = psa[i-1] + a[i-1];
		psb[i] = psb[i-1] + b[i-1];
		rea[i] += rea[i-1];
		reb[i] += reb[i-1];
	}

	f(i,1,tot){
		pa[i] += pa[i-1];
		pb[i] += pb[i-1];
	}
	auto bfb = [&] (int ign , int pos ){
		int owo = (a[ign] < b[ign] ? 1 : 0);
		int wa = pb[pos];
		if(pos >= ign) wa -= owo;
		return wa;
	};
	auto bfa = [&] (int ign , int pos ){
		int owo = (a[ign] > b[ign] ? 1 : 0);
		int wa = pa[pos];
		if(pos >= ign) wa -= owo;
		return wa;
	};
	for(int i = 0 ; i < tot;i++){
		int lo = 0,lf = tot-1;	
		int mid;
		if(bfa(i,tot-1) >= n ){
			while(lo < lf){
				mid = (lo + lf )/2;
				if(bfa(i,mid) >= n)lf = mid;
				else lo = mid+1;
			}
			ll ans = rea[lo+1] + reb[lo+1] ;
			ans += psb[tot] - psb[lo+1];
			if(lo >= i)ans -= max(a[i],b[i]);
			else ans -= b[i];
			if(bfa(i,lo) > n){
				ans -= a[lo];
				ans += b[lo];
			}
			cout << ans << ' ';
		}else{
			while(lo < lf){
				mid = (lo + lf )/2;
				if(bfb(i,mid) >= m)lf = mid;
				else lo = mid+1;
			}
			ll ans = rea[lo+1] + reb[lo+1] ;
			ans += psa[tot] - psa[lo+1];
			if(lo >= i)ans -= max(a[i],b[i]);
			else ans -= a[i];
			if(bfb(i,lo) > m){
				ans -= b[lo];
				ans += a[lo];
			}
			cout << ans << ' ';

		}
	}
	cout << ln;

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
