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

	int ga = 1e4 + 10;
	int inf = - 2e9;
	vector<ll> dp(ga,inf);// dp[value] := max wight
	dp[0] = 0;

	for(int i = 0; i < n;i++){
		vector<ll> ndp = dp;
		int vv,ww;
		cin >> vv >> ww;
		for(int j = ga; j >= 0;j--){
			if(j + vv <= ga and ndp[j] != inf){
				if(ndp[j+vv]==inf)ndp[j+vv] =ndp[j] + ww;
				else ndp[j+vv] = min(ndp[j+vv],ndp[j] + ww);
			}
		}
		swap(ndp,dp);
	}
	int ans = -1;
	f(i,0,ga){
		if(dp[i] <= C and dp[i]!=inf)ans= i;
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
