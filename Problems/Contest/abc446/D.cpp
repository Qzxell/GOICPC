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
	cin >> n ;
	vi a(n);
	vi s;
	forn(i,n)cin >> a[i];

	for(auto x : a){
		s.push_back(x-1);
		s.push_back(x);
	}
	sort(all(s));
	s.erase(unique(all(s)),s.end());
	for(auto &x : a){
		x = lower_bound(all(s),x) - s.begin();
	}
	int lim = sz(s) + 3;
	vi dp(lim,0);


	int ans = 1;
	forn(i,n){
		ans = max(ans,dp[a[i] - 1] + 1);
		dp[a[i]] = max(dp[a[i]-1] + 1 ,dp[a[i]]);
	}
	cout << ans  << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

