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
	f(i,0,n)v[i] = i+1;


	ll ans =0 ;
	f(i,0,n){
		ll ma = 0;
		ll sum = 0;
		reverse(v.begin()+i,v.begin()+n);
		f(j,0,n){
			sum += v[j]*(j+1);
			ma = max(ma, v[j]*(j+1));
		}
		reverse(v.begin()+i,v.begin()+n);
		ans = max(ans, sum - ma);
	}
	cout << ans  << ln;

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
