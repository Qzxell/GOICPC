#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
	int n;
	cin >> n;
	vi a(n),b(n);
	vi uwu;
	forn(i,n){
		cin >> a[i];
		uwu.push_back(a[i]);
	}
	forn(i,n){
		cin >> b[i];
		uwu.push_back(b[i]);
	}
	const int N = 2e5 +5 ;
	ll dp[N][2];
	ll ans = 0;
	forsn(i,1,n+1){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1] + a[i-1]);
		dp[i][1] = max(dp[i-1][1],dp[i-1][0] + b[i-1]);
		ans = max({dp[i][0],dp[i][1],ans});
	}
	cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

