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


int n,x;
const int N = 2e5 + 2;
int memo[N];
int v[N];
ll ps[N];

int dp(int pos){// index- 0
	if(memo[pos] != -1)return memo[pos];
	if(pos >= n ) return 0;
	int lo,lf,mid;
	lo = pos;lf = n-1;
	while(lo < lf){
		mid = (lo+lf)/2;
		if( ps[mid+1] - ps[pos] <= x) lo = mid+1;
		else lf = mid;
	}
	if(ps[lo+1] - ps[pos] <= x )return memo[pos] = lo - pos + 1;
	int ret = dp(lo+1);
	return memo[pos] = lo - pos + ret;
}

void so(int test){
	cin >> n >> x;
	f(i,0,n)cin >> v[i];
	f(i,1,n+1)ps[i] = ps[i-1] + v[i-1];
	f(i,0,n+1)memo[i] = -1;
	ll ans = 0;
	f(i,0,n){
		ans += dp(i);
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
