#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

struct node{
	int w,s,va;
};
const int MX = 2e4 + 5;
ll dp[MX];

void so(int test){
	int n;
	cin >> n;
	vector<node> v(n);
	forn(i,n)
		cin >> v[i].w >> v[i].s >> v[i].va;
	sort(all(v), [&](auto a, auto b){
			return min(a.s, b.s - a.w) > min(b.s, a.s - b.w);
			});
	forn(i,MX)dp[i] = -1;
	dp[0] = 0;
	forn(i,n){
		auto [w_ , s_, va_] = v[i];
		for(int j = MX -1 ; j >= 0 ;j--) if(dp[j] != -1 && j <= s_){
			dp[j + w_] = max(dp[j + w_] , dp[j] + va_);
		}
	}
	ll ans = 0;
	forn(i,MX) ans = max(ans, dp[i]);
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

