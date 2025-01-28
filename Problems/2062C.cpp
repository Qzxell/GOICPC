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
	int n ;
	cin >> n;
	vector<ll> v(n);
	ll ans = 0;
	f(i,0,n){
		cin >> v[i];
		ans += v[i];
	}
	while(n > 1){
		n--;
		ll ga = 0;
		f(i,0,n){
			v[i] = v[i+1] - v[i];
			ga += v[i];
		}
		ans = max(ans,max(ga,-ga));
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
