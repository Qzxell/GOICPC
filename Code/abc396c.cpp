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
	int n,m;
	cin >> n >> m;
	vi b(n,0),w(m,0);
	vector<ll> dp1(max(n,m)+1,0);
	vector<ll> dp2(max(n,m)+1,0);
	f(i,0,n)cin >>b[i];
	f(i,0,m)cin >>w[i];
	sort(rall(w));
	sort(rall(b));
	int N = max(n,m)+1;

	f(i,1,n+1){
		dp1[i] +=dp1[i-1] +b[i-1];
	}

	f(i,1,m+1){
		dp2[i] = max(dp2[i-1],dp2[i-1] + w[i-1]);
	}
	ll ans = 0;
	if ( n<=m){
		f(i,1,n+1){
			ans = max(ans,dp1[i]+dp2[i]);
		}
	} else{
		f(i,1,m+1){
			ans = max(ans,dp1[i]+dp2[i]);
		}
		f(i,m+1,n+1){
			ans = max(ans,dp1[i]+dp2[m]);
		}
	}
	cout << ans ;


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
