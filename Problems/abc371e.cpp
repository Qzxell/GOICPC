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

const int N = 2e5 + 1;
vi num[N];
vi v(N);
ll ans = 0;

ll fu( int ind){
	if(ind == 0) return 1;
	ll ret =fu(ind-1);
	int wa = lower_bound(all(num[v[ind]]),ind) - num[v[ind]].begin();
	if(wa == 0)ret += ind+1;
	else ret += num[v[ind]][wa] - num[v[ind]][wa-1];
	ans += ret;
	return ret;
}

void so(int test){
	int n;
	cin >> n;
	f(i,0,n){
		cin >> v[i];
		num[v[i]].pb(i);
	}
	ll wd = fu(n-1);
	//cout << fu(0) << ' ' << fu(1) << ' ' << fu(2) << ln;
	cout << ans + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
