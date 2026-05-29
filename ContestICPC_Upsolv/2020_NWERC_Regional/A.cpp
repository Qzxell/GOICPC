#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define ll long long

void so(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	int m = 0;
	for(int & x: a)
		cin >> x;
	for(int i = 0 ; i < n ;i++)
		if(a[i] *1ll* (m+1) < a[m] *1ll*(i+1))
			m = i;
	int N = n*n + n + 5;
	ll inf = (1ll<<62);
	vector<ll> dp(N,inf);
	for(int i = 1; i < N ;i++){
		if(i <= n)
			dp[i] = a[i-1];
		for(int j = 1; j <= n && j + i < N ;j++){
			dp[i+j] = min(dp[i+j] , dp[i] + a[j-1]);
		}
	}

	for(int i = 1; i <= q ;i++){
		int k;
		cin >> k;
		if(k < N){
			cout << dp[k] << '\n';
			continue;
		}
		int cn = (k - N + m + 1)/(m+1);
		ll ans = cn*1ll*a[m] + dp[ k - cn*(m+1)];
		cout << ans << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	so();
	return 0;
}
