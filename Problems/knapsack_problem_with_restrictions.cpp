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
	
	ll inf = -(1ll<<60);
	vector<ll> dp(C+1,0);

	dp[0] = 0;
	f(i,0,n){
		int vv,ww,mm;
		cin >> vv >> ww >> mm;
		f(k,0,mm){
			vector<ll> ndp = dp;
			for(int j = C; j >= 0;j--){
				if(j + ww <= C and ndp[j]!= inf){
					ndp[j+ww] = max(ndp[j+ww],ndp[j] + vv);
				}
			}
			swap(dp,ndp);
		}
	}
	ll ans = 0;
	f(i,0,C+1){
		ans = max(dp[i],ans);
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
