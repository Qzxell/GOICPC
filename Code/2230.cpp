#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()


void so(int test){
	int n;
	cin >> n;
	vector<int> a(n),b(n),dp(n+1,0);
	for(auto &x : a)cin >> x;
	for(auto &x : b)cin >> x;

	ll ans = 0;
	for(int i = n-1 ; i >= 0 ; i--){
		if((a[i] != 1 && b[i] != 1) || (a[i] == 1 && b[i] == 1)){
			dp[i] += 1 + dp[i+1];
			ans += dp[i];
		}
	}
	cout << ans << '\n';
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

