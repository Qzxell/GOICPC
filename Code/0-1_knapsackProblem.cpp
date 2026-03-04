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
	int n,C;
	cin >> n >> C;
	vi v(n);
	vi w(n);
	f(i,0,n){
		cin >> v[i];
		cin >> w[i];
	}
	int inf = - 2e9;
	vector<ll> dp(C+1,inf);
	dp[0] = 0;
	for(int i = 0; i < n ;i++){
		vector<ll> ndp = dp;
		for(int j = C; j >= 0;j--){
			if(j + w[i] <= C and ndp[j] != inf){
				ndp[j+w[i]] = max(ndp[j] + v[i], ndp[j+w[i]]);
			}
		}
		swap(ndp,dp);
	}
	ll ans = 0;
	f(i,0,C+1){
		ans = max(ans,dp[i]);
	}
	cout << ans;
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
